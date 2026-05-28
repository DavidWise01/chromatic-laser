/*
  Real Optical Array 128 — firmware-style reference model
  Safe low-power emitter array. Use LEDs first.
*/

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#define EMITTERS_TOTAL 128
#define BANK_SIZE 64
#define PHASE_SCALE 1000      // 0.001 resolution
#define PWM_MAX_SAFE 80       // example: cap duty to 80/255
#define SENSOR_MAX_SAFE 900   // arbitrary ADC saturation threshold

typedef struct {
    uint16_t phase_milli;     // 0..999 maps to 0.000..0.999
    uint8_t pwm[EMITTERS_TOTAL];
    uint16_t center_sensor;
    uint16_t coherence;
    bool safe_hold;
    bool enclosure_closed;
    bool overtemp;
    bool overcurrent;
} OpticalArray;

static uint8_t clamp_pwm(uint16_t v) {
    if (v > PWM_MAX_SAFE) return PWM_MAX_SAFE;
    return (uint8_t)v;
}

static void all_off(OpticalArray *a) {
    for (int i = 0; i < EMITTERS_TOTAL; i++) a->pwm[i] = 0;
}

static bool failsafe_required(const OpticalArray *a) {
    return !a->enclosure_closed || a->overtemp || a->overcurrent || a->center_sensor > SENSOR_MAX_SAFE;
}

static void select_and_drive_pair(OpticalArray *a) {
    // 0.001 phase selects one of 64 upper/lower pairs.
    uint8_t idx = (uint8_t)((a->phase_milli * BANK_SIZE) / PHASE_SCALE);
    if (idx >= BANK_SIZE) idx = BANK_SIZE - 1;

    all_off(a);

    // Upper emitter idx, lower emitter mirrored idx.
    uint8_t upper = idx;
    uint8_t lower = 64 + (BANK_SIZE - 1 - idx);

    // Coherence controls brightness but remains bounded.
    uint8_t duty = clamp_pwm(20 + (a->coherence / 20));
    a->pwm[upper] = duty;
    a->pwm[lower] = duty;
}

static void tick_001(OpticalArray *a) {
    if (failsafe_required(a)) {
        a->safe_hold = true;
        all_off(a);
        return;
    }

    a->safe_hold = false;
    a->phase_milli = (a->phase_milli + 1) % PHASE_SCALE;

    // Example coherence estimate: center response minus phase drift.
    if (a->center_sensor > 0) {
        a->coherence = (a->coherence * 7 + a->center_sensor) / 8;
    }

    select_and_drive_pair(a);
}

int main(void) {
    OpticalArray array = {0};
    array.enclosure_closed = true;
    array.center_sensor = 320;
    array.coherence = 400;

    for (int t = 0; t < 10; t++) {
        tick_001(&array);
        printf("tick=%d phase=0.%03u safe=%d first_pwm=%u center=%u coherence=%u\n",
               t, array.phase_milli, array.safe_hold, array.pwm[0], array.center_sensor, array.coherence);
    }

    return 0;
}
