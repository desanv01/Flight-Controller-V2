# JLCPCB controlled-impedance calculator record

Accessed 2026-09-13 at:
https://jlcpcb.com/pcb-impedance-calculator

Inputs:

- rigid PCB
- 6 layers
- 1.6 mm order thickness
- 0.5 oz inner copper
- 1 oz outer copper
- 90 ohm differential, non-coplanar
- signal layer L1, reference L2
- edge spacing 0.2032 mm

Selected result: recommended JLC06161H-3313 (standard, finished thickness
1.54 mm +/-10%) with 0.1537 mm trace width.

Stack dimensions shown by the current calculator:

- L1/L6 copper 0.0350 mm
- L2-L5 copper 0.0152 mm
- outer 3313 RC57% prepregs 0.0994 mm
- L2-L3 and L4-L5 core dielectric 0.5500 mm
- center 2116 RC54% prepreg 0.1088 mm

These values are encoded in the KiCad board stack-up and USB netclass.

