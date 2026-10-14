# PCBWay controlled-impedance report

## Selected official construction

PCBWay current published **6-layer regular, 1.6 mm** construction: finished outer copper 1 oz; inner L2–L5 copper 1 oz; L1–L2 and L5–L6 2116 RC58% prepreg, laminated 0.1195 mm, Dk 4.45; two 0.430 mm FR-4 cores, Dk 4.6; center 7628 RC46% prepreg, laminated 0.1750 mm, Dk 4.74. Green solder mask and ENIG are specified.

## USB pair

- Top-layer edge-coupled microstrip referenced to solid L2 ground; no intentional coplanar-ground control.
- Existing width: `0.1537 mm`; edge spacing: `0.2032 mm`; copper: `0.035 mm`; L1–L2 dielectric: `0.1195 mm`.
- IPC-style engineering estimate without mask: `98.31 ohm differential`.
- PCBWay guidance says a solder-mask coat can reduce differential impedance by about 8 ohms; masked estimate: **`90.31 ohm`**.
- Target: **90 ohm differential ±10%**. Therefore the copper artwork is unchanged.

This is a pre-production calculation, not a fabricated coupon result. Mandatory order note: PCBWay CAM shall field-solve and confirm 90 ohm ±10%; adjust dielectric construction, not finished copper artwork, unless written approval is obtained.

Official sources: https://www.pcbway.com/multi-layer-laminated-structure.html ; https://www.pcbway.com/helpcenter/ordering_parameter_instruction/What_is_Impedance_Control_.html ; https://www.pcbway.com/pcb_prototype/impedance_calculator.html
