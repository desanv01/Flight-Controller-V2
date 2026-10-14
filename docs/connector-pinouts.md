# Connector pinouts from the public netlist

Generated from the exact public schematic after neutralization. Pin numbers identify schematic/footprint pins, not cable wire colours. Check actual mating orientation against the source drawing. Mechanical/shield pads can appear as pin entries.

## J1 — USB4110GFA

| Pin | Net |
|---|---|
| A1/B12 | `GND` |
| A4/B9 | `+VBUS` |
| A5 | `/Power/A5` |
| A6 | `/Power/D+` |
| A7 | `/Power/D-` |
| A8 | `unconnected-(J1-SBU1-PadA8)` |
| B1/A12 | `GND` |
| B4/A9 | `+VBUS` |
| B5 | `/Power/B5` |
| B6 | `/Power/D+` |
| B7 | `/Power/D-` |
| B8 | `unconnected-(J1-SBU2-PadB8)` |
| S1 | `GND` |
| S2 | `GND` |
| S3 | `GND` |
| S4 | `GND` |

## J10 — CAN BUS

| Pin | Net |
|---|---|
| 1 | `+3.3V` |
| 2 | `CAN_N` |
| 3 | `CAN_P` |
| 4 | `GND` |

## J11 — MAVLINK SIGNAL-ONLY

| Pin | Net |
|---|---|
| 1 | `unconnected-(J11-Pin_1-Pad1)` |
| 2 | `EXPANSION_RX` |
| 3 | `EXPANSION_TX` |
| 4 | `GND` |

## J12 — POWER1 REGULATED 5.2V IN

| Pin | Net |
|---|---|
| 1 | `+5V` |
| 2 | `GND` |

## J2 — FPV

| Pin | Net |
|---|---|
| 1 | `GND` |
| 2 | `VIDEO_IN` |
| 3 | `unconnected-(J2-Pin_3-Pad3)` |
| 4 | `+5V` |

## J3 — ST_LINK

| Pin | Net |
|---|---|
| 1 | `+3.3V` |
| 2 | `ST_SWDIO` |
| 3 | `ST_SWCLK` |
| 4 | `GND` |

## J4 — GPS

| Pin | Net |
|---|---|
| 1 | `GND` |
| 2 | `GPS_TX` |
| 3 | `GPS_RX` |
| 4 | `GPS_SDA` |
| 5 | `GPS_SCL` |
| 6 | `+5V` |

## J5 — Airspeed sensor

| Pin | Net |
|---|---|
| 1 | `+3.3V` |
| 2 | `I2C1_SDA` |
| 3 | `I2C1_SCL` |
| 4 | `GND` |

## J6 — OpenESC SIGNAL-ONLY

| Pin | Net |
|---|---|
| 1 | `unconnected-(J6-Pin_1-Pad1)` |
| 2 | `GND` |
| 3 | `unconnected-(J6-Pin_3-Pad3)` |
| 4 | `unconnected-(J6-Pin_4-Pad4)` |
| 5 | `M1` |
| 6 | `M2` |
| 7 | `M3` |
| 8 | `M4` |

## J7 — RC Receiver

| Pin | Net |
|---|---|
| 1 | `+5V` |
| 2 | `WIFI/RC_RX` |
| 3 | `WIFI/RC_TX` |
| 4 | `GND` |

## J8 — VTX

| Pin | Net |
|---|---|
| 1 | `+pwr_out` |
| 2 | `VIDEO_OUT` |
| 3 | `VTX_TX` |
| 4 | `GND` |

## J9 — DJI

| Pin | Net |
|---|---|
| 1 | `+pwr_out` |
| 2 | `GND` |
| 3 | `DJI_TX` |
| 4 | `DJI_RX` |
| 5 | `GND` |
| 6 | `DJI_SBUS` |

## JP1 — 9V/12V

| Pin | Net |
|---|---|
| 1 | `/Power/FB_12V` |
| 2 | `/Power/FB` |
| 3 | `/Power/FB_9V` |
