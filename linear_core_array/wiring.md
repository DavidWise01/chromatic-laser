# Linear Core Optical Array — Wiring Notes

A buildable bench version should use low-power visible emitters or LEDs, not high-power lasers.

## Channels
- 16 independently enabled emitter channels in a straight X-axis rail.
- 4 gate/sensor checkpoints between emitter groups.
- 1 final collection/measurement well.

## Control
- Microcontroller or GPIO expander drives each channel through current limiting.
- Each group has a shared enable line and individual PWM/intensity line.
- Gate sensors report pass/fail before the next segment is enabled.

## Safety
- Enclosed beam path.
- Interlock switch on enclosure.
- Emergency stop removes emitter power.
- Current limits are hardware enforced, not only firmware enforced.
