# PCBWay Upload Map

| PCBWay field | Upload / paste |
|---|---|
| PCB fabrication Gerber upload | `fabrication/FC_EVT1_PCBWAY-Gerber-Upload.zip` |
| Assembly BOM upload | `assembly/FC_EVT1_PCBWAY-Turnkey-BOM.csv` |
| Centroid / pick-and-place upload | `assembly/FC_EVT1_PCBWAY-SMT-Centroid.csv` |
| Assembly drawings / supporting documents | `output/pdf/FC_EVT1_PCBWAY-Assembly_Drawings.pdf`, `assembly/FC_EVT1_PCBWAY-THT-Placement.csv`, `assembly/FC_EVT1_PCBWAY-DNP-and-NonPurchased.csv` |
| Controlled-impedance notes | `output/pdf/FC_EVT1_PCBWAY-Controlled_Impedance.pdf` plus the fabrication/order settings |
| Component sourcing notes | Turnkey exact MPNs; no unauthorized substitutes; exact/consigned/DNP sequence for J12 |
| THT / J12 notes | Paste mandatory note from `documents/PCBWay_J12_Sourcing_and_THT_Instructions.md` |
| Harness quotation notes | `harness/PCBWay_Harness_Quotation_Note.md`, harness BOM and cut/test table |

Upload the IPC-356 file as a supporting fabrication file, not inside the Gerber-only ZIP, unless PCBWay engineering explicitly requests otherwise.
