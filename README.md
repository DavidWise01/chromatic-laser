# Chromatic Laser Kernel

**Author:** David Wise (ROOT0) / TriPod LLC  
**License:** CC-BY-ND-4.0 · TRIPOD-IP-v1.1  
**Mode:** Local simulation only

Chromatic laser cavity kernel series — 17, 32, and 128 spectrum node variants. 16 emitters per spectrum band + 17th pure white coherence core. Photonic processor designs (64-bit, 128-bit, fractal).

---

## Kernel Series

| Kernel | Nodes | Architecture |
|--------|-------|-------------|
| `chromatic17.kernel` | 16 spectrum + 1 white core | Red→Violet spectrum, pure white coherence at 17th |
| `chromatic17_capacitance.kernel` | 17 + capacitance layer | Capacitance-coupled variant |
| `chromatic32.kernel` | 32 nodes | Extended spectrum |
| `chromatic32_rebuilt/` | 32 nodes rebuilt | Rebuilt architecture |
| `chromatic128.kernel` | 128 nodes | Full 128-node spectrum array |
| `chromatic128_phasewell/` | 128 + phasewell | Phase-well coupled variant |
| `cavity.kernel` | Core cavity | Laser cavity base |

## Chromatic 17 — Node Map

```
L01 red_pressure       L09  azure_carrier
L02 orange_gain        L10  blue_coherence
L03 amber_transition   L11  indigo_phase
L04 yellow_lift        L12  violet_resonance
L05 lime_correction    L13  ultraviolet_edge
L06 green_stability    L14  infrared_heat
L07 mint_expansion     L15  thermal_noise
L08 cyan_edge          L16  null_carrier
                       L17  WHITE_CORE (coherence)
```

## Additional Laser Architectures

| Folder | Description |
|--------|-------------|
| `chromatic_17_laser_cavity/` | Full cavity build for chromatic 17 |
| `chromatic_capacitance_well/` | Capacitance well variant |
| `compass_phase_pulse/` | Compass-oriented phase pulse |
| `fixed_6around1_compass/` | 6-around-1 compass cluster |
| `laser_punk_cavity/` | Experimental punk cavity |
| `linear_core.kernel` | Linear core variant |
| `linear_core_array/` | Linear array |
| `linear_infinite_collapse/` | Infinite collapse linear |
| `mountain_triple_pulse/` | Triple pulse mountain |
| `quad16_compass_cluster/` | 16-node quad compass |
| `real_optical_array/` | Realistic optical array spec |
| `wave_core_3around1/` | 3-around-1 wave core |

## Photonic Processors

| File | Description |
|------|-------------|
| `photonic/photonic proc.html` | Base photonic processor |
| `photonic/photonic 64 bit.html` | 64-bit photonic core |
| `photonic/128 bit photonic core.html` | 128-bit photonic core |
| `photonic/photonic fractal.html` | Fractal photonic variant |
| `photonic/photonic fractal 01.html` | Fractal variant 01 |
