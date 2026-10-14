# Power and interface boundaries

Controller input uses an externally regulated supply. The design basis is 5.2 V nominal and 4.9–5.5 V at the input pads under load, with 3 A continuous and 4 A/100 ms transient design targets. These are requirements, not passed physical measurements.

USB is data/debug only. External power is required before USB operation. Battery voltage must never be applied to the regulated FC input. ESC and companion loads are not powered through the FC input budget.

POWER1 is J12, Molex Nano-Fit 105311-1202: pin 1 +5 V, pin 2 GND. J6 is eight-position JST-SH: 1 NC, 2 GND, 3 NC, 4 NC, 5 M1, 6 M2, 7 M3, 8 M4. The signal harness carries no battery, current-sense or 5 V conductor. Mating housing 105307-1202, contacts 105300-2200 and TPA 105325-1002 are recorded in the vendor documents. Battery monitor is disabled pending a qualified source.

Common signal ground does not authorize back-powering. Use [actual connector nets](connector-pinouts.md), vendor harness data and the [physical checklist](bring-up.md). Hardware/shield references differ between V1 and V2.
