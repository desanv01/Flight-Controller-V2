# Flight Controller V2 — JLCPCB engineering package

Status: engineering data available; physical qualification pending. Supplier construction/impedance, actual part sourcing, rotations and fabricated-article tests remain external.

## Source and fabrication

Exact source: `source/hardware/`. [Source manifest](source/source-manifest.json). [Fresh source checks](verification/summary.json). Regenerated neutral Gerbers/drills are in `fabrication/`; upload the Gerber/drill-only ZIP rather than a documentation archive. Technical source and electrical/placement geometry are preserved; visible naming and descriptive metadata were updated for publication.

## Assembly files

- [FC_EVT1-BOM.csv](assembly/reference/FC_EVT1-BOM.csv)
- [FC_EVT1-CPL-JLCPCB.csv](assembly/reference/FC_EVT1-CPL-JLCPCB.csv)
- [FC_EVT1-CPL-KiCad.csv](assembly/reference/FC_EVT1-CPL-KiCad.csv)
- [FC_EVT1-JLCPCB-BOM-FINAL.csv](assembly/FC_EVT1-JLCPCB-BOM-FINAL.csv)
- [FC_EVT1-JLCPCB-CPL-FINAL.csv](assembly/FC_EVT1-JLCPCB-CPL-FINAL.csv)
- [J12-HAND-INSTALL-BOM.csv](assembly/J12-HAND-INSTALL-BOM.csv)

For V2 JLCPCB, files ending BOM-FINAL and CPL-FINAL are the final reconciled SMT pair; J12 is separately hand-installed. Earlier raw/engineering files are preserved only for traceability.

Use this vendor's exact BOM and centroid. Confirm rotation and sourcing with the manufacturer. J12 in V1 is microSD; J12 in V2 is POWER1, so designators must not be transferred between versions. [Current connector nets](../../docs/connector-pinouts.md).

## Documentation

Readable neutral exports are in `exports/`. Historical manufacturer notes in `documents/` retain original technical intent but some file references predate publication restructuring; use this README and exact source manifest as the upload map. [Physical checklist](../../docs/bring-up.md).

## Definitive upload map

| Supplier field | Public file |
|---|---|
| PCB fabrication | [Gerber/drill-only ZIP](fabrication/Gerber-Drill-Upload.zip) |
| Assembly BOM | [FC_EVT1-JLCPCB-BOM-FINAL.csv](assembly/FC_EVT1-JLCPCB-BOM-FINAL.csv) |
| SMT placement | [FC_EVT1-JLCPCB-CPL-FINAL.csv](assembly/FC_EVT1-JLCPCB-CPL-FINAL.csv) |
| Assembly drawing | [Assembly PDF](exports/assembly.pdf) |
| Fabrication drawing | [Fabrication PDF](exports/fabrication.pdf) |
| Schematic | [Schematic PDF](exports/schematic.pdf) |

Fresh reconciliation: 51 BOM rows, 113 BOM references and 113 placement references. Placement-only references: zero. BOM-only references: `none`; these require the separate THT/manual instructions. [Pair report](verification/final-upload-pair.json).

Raw export files under `assembly/reference/` are retained for traceability and are not the supplier upload pair. Part sourcing/rotation/vendor CAM and physical qualification are still required.
