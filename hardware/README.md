# Hardware source

Open [Flight Controller.kicad_pro](Flight%20Controller.kicad_pro) in KiCad 10.0.6 or a compatible later version. Install KiCad's standard libraries/models. Project-local symbols, footprints and required local 3D models are bundled. Standard models use `KICAD10_3DMODEL_DIR`; local assets use `KIPRJMOD`.

PCB and project stems remain matched so DRC loads the intended rules. The source is a neutral publication copy; pad, routing, zone, placement and outline geometry was checked unchanged during descriptive metadata reconciliation. See [correction report](../verification/latest/publication-corrections.json).

The current tree uses the PCBWay/working metadata variant. JLCPCB has its own exact snapshot in fabrication/jlcpcb/source/hardware. Read the [validation status](../docs/validation-status.md), including warning/ignored-rule and physical-test limitations.
