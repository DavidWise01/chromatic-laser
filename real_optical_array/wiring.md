# Wiring / Topology Notes

## Recommended first build

Use LEDs, not bare laser diodes.

### Banks

- Bank A: 64 upper emitters
- Bank B: 64 lower emitters
- Center: diffuser target with optional photodiode or light sensor

### Driver approach

Practical options:

1. **LED matrix driver ICs**
   - Example class: constant-current LED matrix drivers
   - Best for 128 LEDs

2. **PWM expanders + MOSFET/current resistors**
   - Easier to prototype
   - Requires careful current budgeting

3. **Addressable RGB LEDs**
   - Easiest visual prototype
   - Not optically precise, but best first proof

## Geometry

Place 64 emitters in an upper arc and 64 in a lower arc pointed at a frosted center diffuser.

```text
UPPER 64  ────────╮
                   ●  center diffuser / sensor
LOWER 64  ────────╯
```

## Center well analog

A real capacitance well can be approximated in the prototype as:

- optical diffuser target
- photodiode / light sensor reading
- software accumulator representing stored charge
- optional capacitor on analog readout for smoothing

## Practical note

The first real prototype should verify timing, phase stepping, and safe bounded current. Optical coherence should be treated as a visualization metaphor unless using lab-grade optics.
