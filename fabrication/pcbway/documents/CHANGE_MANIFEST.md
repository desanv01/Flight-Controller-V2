# PCBWay release change manifest

- Created a separate PCBWay release; JLC release untouched.
- Added exact manufacturer/MPN and production properties to all 114 populated KiCad symbols.
- Updated KiCad stack metadata to PCBWay’s published 1.6 mm six-layer regular construction with 1 oz inner copper.
- Kept USB copper geometry unchanged after 90.3-ohm masked engineering estimate.
- Generated PCBWay BOM, SMT top/bottom/combined centroids, THT J12 placement and DNP/non-purchased list.
- Added PCBWay panel, impedance, sourcing, harness, upload-map and validation documents.
- Regenerated Gerbers, drills, IPC-356, STEP, 3D/Gerber renders, ERC/DRC and assertions.
- Preserved pinned ArduPilot Copter 4.7.1 firmware outputs without rebuild.
