# Safety Notes

This package is a safe low-power optical array reference. It avoids high-power beam combining and avoids instructions for hazardous laser construction.

## Safer defaults

- Use diffused LEDs first.
- Use current limiting on every emitter path.
- Keep duty cycle low during testing.
- Use an enclosure for any laser modules.
- Do not point emitters at eyes, reflective surfaces, vehicles, aircraft, or public spaces.
- Do not combine many laser beams into a free-space focal point.

## Failsafe triggers

The controller should shut down all emitters if:

- current exceeds threshold
- temperature exceeds threshold
- enclosure opens
- center sensor saturates
- firmware watchdog fails
- external stop is pressed

## Recommended development order

1. Browser simulation
2. Addressable LED ring/strip prototype
3. 16-emitter bench version
4. 32-emitter version
5. 128-emitter enclosed version

Never jump straight to a 128 laser module array.
