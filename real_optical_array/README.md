# Real Optical Array — 128-Emitter Low-Power Reference

First-author prototype package for a **safe, low-power optical emitter array** inspired by the Chromatic128 Phasewell model.

This is designed as an engineering reference for a bench-safe prototype using LEDs or very low-power visible laser diode modules with current limiting. It is **not** a high-power laser build guide.

## Core concept

- 128 fixed emitters
- 64 upper emitters
- 64 lower emitters
- 0.001 phase resolution in software
- center target/capacitance-well analog represented by a sensor/collector node
- no free-space hazardous beam combining
- bounded current, bounded duty cycle, local-only controller

## Recommended safe implementation

Use diffused RGB LEDs or Class 1 / Class 2 low-power laser modules for visualization only. Prefer LEDs for first hardware.

## Files

- `index.html` — interactive array visualizer/control surface
- `real_array.kernel` — minimal kernel spec
- `firmware_pseudocode.c` — firmware-style scan/phase model
- `bom.csv` — starter bill of materials
- `wiring.md` — wiring/topology notes
- `safety.md` — safety notes and operating constraints

## Control law

```text
for each tick Δt = 0.001:
    update phase accumulator
    select upper/lower emitter pair
    apply bounded PWM duty
    read center sensor estimate
    clamp current and duty
    report coherence
```

## Physical architecture

```text
64 upper emitters  ┐
                   ├── fire toward center diffuser / sensor target
64 lower emitters  ┘

center = optical collector / photodiode / diffuser well
controller = microcontroller + LED drivers
power = current-limited low-voltage DC
```

## Safety boundary

Do not collimate high-power beams into a shared point. Use diffusers, low-current emitters, current limiting, and enclosed test fixtures.
