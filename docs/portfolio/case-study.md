# Flight Controller V2 — engineering case study

## Objective and role

STM32H743VIT6 controller adapted from an open-hardware reference design for externally regulated power, a signal-only OpenESC interface, exact Nano-Fit integration and a pinned ArduPilot target. The repository preserves the hardware adaptation, firmware work and vendor engineering packages.

Desan Vasu confirmed performing the project engineering activities except fabrication. 26 August–6 October 2026 is the documented evidence period. No employment title or tenure is inferred.

## Decisions and implementation

- Reference-derived STM32H743VIT6 hardware with two dissimilar IMUs
- ICM42688P on SPI6, BMI270 on SPI3 and BMP388 on I2C2
- External regulated POWER1 supply; USB remains data/debug only
- Onboard AP63205 supply path removed; four signal-only OpenESC outputs
- Exact Molex Nano-Fit 105311-1202 on an integral connector tab
- Analog OSD hardware retained, disabled by initial firmware defaults
- Pinned ArduPilot Copter 4.7.1 source and neutral FCV2 target
- Separate JLCPCB and PCBWay source/manufacturing snapshots

## Engineering result

The adaptation isolates the external FC power boundary, constrains the ESC harness, integrates an exact Nano-Fit connector and prepares pinned firmware and separate manufacturing packages. Source contains 162 footprints, 1,390 segments and 371 vias; saved assembly reconciliation is 113 SMT placements plus one THT connector.

| Check | Result |
|---|---|
| ERC errors / warnings | 0 / 40 |
| DRC rule errors / warnings | 0 / 0 |
| Raw unconnected entries | 0 |
| Schematic parity issues | 0 |
| Physical qualification | Pending |


## Lessons

Preserve exact source/vendor pairing, report checker settings and exceptions, distinguish compilation from runtime qualification, and recover historical artifacts without inventing missing source states. Inherited board resources and firmware claims require revalidation after electrical/mechanical adaptation.

## Evidence and remaining work

[Source](../../hardware/README.md) · [Timeline](../development/timeline.md) · [Manufacturing](../../fabrication/README.md) · [Verification](../validation-status.md). Physical qualification remains pending. Fabrication was external. Upstream designs/tests remain attributed to their authors.
