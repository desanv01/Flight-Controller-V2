# PCBWay fallback notes

PCBWay is a fallback only. Request a current six-layer, 1.6 mm controlled-impedance stack-up and obtain its dielectric data before ordering. Recalculate the USB 90-ohm differential geometry using PCBWay's current calculator/field-solver data; **do not reuse** the JLCPCB 0.1537 mm / 0.2032 mm dimensions without written confirmation that the stack-up is electrically equivalent.

Prepare a separate PCBWay order package if that supplier is selected. Preserve ENIG, green mask, the single-board source outline, POWER1 PTH/clip-hole requirements, filled/plated-over vias where called out, and the manufacturer-panel intent. J12 remains exact Molex 105311-1202 with gold mating parts; no unrated substitute is allowed.
