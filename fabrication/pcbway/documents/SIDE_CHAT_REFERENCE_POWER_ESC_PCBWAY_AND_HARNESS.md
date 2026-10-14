# FCV2 FC EVT1 — Power, ESC, PCBWay, and Harness Reference

**Document purpose:** Consolidated, categorized record of the questions, decisions, and guidance discussed in the manufacturing/harness side conversation.

**Applies to:** `ENGINEERING_VALIDATION_EVT1_PCBWAY`

**Status:** Engineering validation hardware — not yet flight released

**Compiled:** 2026-09-14

---

## 1. Quick answers

- **What powers the flight controller?** The genuine Matek BEC12S-PRO supplies regulated 5.2 V to FC connector J12.
- **What is J12?** The two-pin Molex Nano-Fit regulated-power input on the FC.
- **Does USB-C power the FC?** No. In EVT1, USB-C is data/debug/firmware only; its VBUS is isolated from the FC `+5V` rail.
- **How does the ESC connect?** OpenESC J1 connects to FC J6 through a signal-only JST-SH harness carrying GND and M1–M4.
- **Does the ESC harness carry battery, 5 V, or current sense?** No.
- **Can PCBWay fabricate and assemble the board?** Yes, using the dedicated PCBWay release and after PCBWay confirms CAM/DFM, impedance, exact component sourcing, and J12 handling.
- **Must J12 be hand-soldered?** Not necessarily. PCBWay may assemble it as a through-hole part if it sources the exact part and includes THT assembly. Otherwise it may be consigned or deliberately left DNP for controlled hand soldering.
- **Can a ready-made J12 cable be used?** Yes. Genuine Molex `45130-0201` is a suitable 150 mm, 20-AWG, gold-contact cable assembly. Cut off one end and solder the free conductors to the Matek BEC.
- **Is a separate custom 22-AWG harness still required if `45130-0201` is used?** No. The 20-AWG ready-made cable is electrically acceptable and replaces the separate housing, contacts, TPA, and 22-AWG wire purchase for that harness.

---

## 2. System power topology

The intended power flow is:

```text
6S battery / PDB
├──> OpenESC battery input (high-current motor power)
└──> Matek BEC12S-PRO input
     └── regulated 5.2 V + GND
         └── POWER1 harness
             └── FC J12
                 └── FC, receiver, GPS, and approved low-power peripherals
```

The following are **not** powered from FC J12:

- OpenESC motor-power stage
- CM5/Raspberry Pi
- Camera
- LiDAR
- Analog VTX load

The Matek BEC input connects to the 6S battery/PDB, not through the flight controller. Never apply battery voltage or raw `VBAT` to J12.

---

The updated complete wiring should be:

```text
DOGCOM 6S battery / XT60
        │
        ▼
      PDB
      ├──> OpenESC high-current battery input
      └──> Matek BEC12S-PRO input
              └── regulated 5.2 V output
                    └── FC J12 POWER1
```

The Matek BEC accepts 9–55 V, defaults to 5.2 V, and supports up to 5 A continuous. It has no reverse-input protection. [Matek official specifications](https://www.mateksys.com/?portfolio=bec12s-pro) · [FPVFaster listing](https://my.fpvfaster.com/products/matek-bec12s-pro-9-55v-input-5v-8v-12v-5a-output)

## 1. Battery to PDB and OpenESC

Connect the battery XT60 to the PDB:

| Battery/PDB connection | OpenESC connection |
|---|---|
| Battery/PDB `+VBAT` | OpenESC high-current `+BATT` |
| Battery/PDB `GND` | OpenESC high-current `GND` |

Use appropriately sized high-current wiring for the OpenESC battery path.

The OpenESC motor-power connection must be completely separate from the FC POWER1 input. Do not route motor battery current through the FC.

## 2. Battery/PDB to Matek BEC input

Connect the BEC input directly to the battery/PDB:

| Matek BEC pad | Connection |
|---|---|
| `IN` / positive | PDB `+VBAT` |
| `G` / negative | PDB `GND` |

The 6S battery is approximately 22.2 V nominal and 25.2 V fully charged, which is within the BEC input range.

Double-check polarity before connecting the battery. The BEC does not provide reverse-input protection.

## 3. Configure the BEC output

Before connecting it to the FC:

1. Disconnect the battery.
2. Inspect the voltage-selection pads.
3. Leave the BEC at its factory-default **5.2 V** setting.
4. Do not bridge the 8 V or 12 V selection pads.
5. Later, measure the output with a multimeter and confirm approximately 5.2 V.

Do not connect 8 V or 12 V to the FC.

## 4. Ready-made Molex harness to the FC

The cable option is genuine Molex **45130-0201 / 0451300201**, a 150 mm Nano-Fit receptacle-to-receptacle cable with 20-AWG conductors. [element14 Malaysia](https://my.element14.com/molex/45130-0201/cable-assy-2pos-rcpt-rcpt-150mm/dp/3862447) · [DigiKey Malaysia](https://www.digikey.my/en/products/detail/molex/0451300201/6709934) · [Molex 45130 series](https://www.molex.com/en-us/products/series-chart/45130)

Adapt it as follows:

1. Keep one factory connector intact for the FC J12 end.
2. Cut the other connector off, cutting one conductor at a time to avoid shorting the two wires.
3. Keep the finished cable at or below 150 mm; approximately 100 mm is preferred if practical.
4. Use a multimeter to identify which free conductor reaches J12 pin 1.
5. Mark that conductor red using red heat-shrink or durable red sleeving.
6. Mark the other conductor black.
7. Solder the pin-1 conductor to the Matek BEC `OUT` / `5.2V` pad.
8. Solder the pin-2 conductor to the Matek BEC `G` pad.
9. Insulate both solder joints with heat-shrink.
10. Add strain relief near the BEC.
11. Label the cable:

```text
REGULATED 5.2V ONLY — NO VBAT
```

The 20-AWG cable is electrically acceptable, but it is heavier than the project’s nominal 22-AWG harness specification. Record that as a harness deviation.

## 5. FC J12 POWER1 connection

The FC board connector is Molex Nano-Fit **105311-1202**:

| FC J12 pin | Signal | Connects to |
|---|---|---|
| Pin 1 | `+5V` | Matek BEC `OUT` / 5.2 V through red-marked conductor |
| Pin 2 | `GND` | Matek BEC `G` through black-marked conductor |

Verify the connector’s pin-1 position from the FC silkscreen and confirm continuity with a meter. Do not rely only on the cable’s original wire colour because both conductors may be black.

The FC J12 connector must only receive regulated 5.2 V. Never apply battery voltage or raw `VBAT` to it.

## 6. FC to OpenESC signal harness

J6 remains an eight-position JST-SH connector, but only five conductors are populated:

| FC J6 pin | Signal | OpenESC J1 pin |
|---|---|---|
| 1 | NC | No conductor |
| 2 | Signal `GND` | Pin 2 `GND` |
| 3 | NC; no current signal | No conductor |
| 4 | NC | No conductor |
| 5 | M1 / output 1 | Pin 5 M1 |
| 6 | M2 / output 2 | Pin 6 M2 |
| 7 | M3 / output 3 | Pin 7 M3 |
| 8 | M4 / output 4 | Pin 8 M4 |

The OpenESC J1 battery and current pins must remain unused:

- J1 pin 1 `+BATT`: no conductor.
- J1 pin 2 `GND`: connect to FC J6 pin 2.
- J1 pin 3 `/CURR`: omit.
- J1 pin 4 `NC`: omit.
- J1 pins 5–8: motor signals M1–M4.

The J6 harness carries only signal ground and motor-control signals. It must not carry battery voltage, FC 5 V, or current-sense wiring.

## 7. Motor-output mapping

For the ArduPilot Quad-X configuration:

| FC output | Physical motor | Direction |
|---|---|---|
| Output 1 / J6 pin 5 | Front-right | CCW |
| Output 2 / J6 pin 6 | Rear-left | CCW |
| Output 3 / J6 pin 7 | Front-left | CW |
| Output 4 / J6 pin 8 | Rear-right | CW |

Verify all motor directions with propellers removed.

## 8. First power-up procedure

1. Remove all propellers.
2. Disconnect USB-C.
3. Check the BEC voltage-selection pads.
4. Power the BEC from a current-limited 6S source.
5. Measure the BEC output before connecting J12.
6. Confirm approximately 5.2 V.
7. Power the FC through J12.
8. Check FC current, 5 V rail, 3.3 V rail and component temperatures.
9. Only after stable POWER1 operation, connect USB-C for configuration.
10. Connect the OpenESC signal harness only after verifying its pinout.
11. Power the OpenESC from the battery/PDB branch.
12. Perform PWM, DShot300 and later bidirectional-DShot tests with propellers removed.

## Connections that must not be made

Do not connect:

- Battery `+VBAT` to FC J12.
- OpenESC battery power to J6.
- OpenESC `/CURR` to J6.
- BEC input directly to J12.
- Any BEC 8 V or 12 V output to the FC.
- USB VBUS to the FC 5 V rail.
- CM5, camera or LiDAR to the FC 5 V rail.
- Another 5 V source in parallel with the Matek BEC.
- J12 or J6 while the system is powered.

This gives the intended isolated architecture: the battery powers the OpenESC directly, the Matek BEC powers the FC through J12, and J6 carries only the OpenESC control signals and signal ground.



## 3. J12 purpose and pinout

J12 is the FC's main regulated-power input connector.

| J12 pin | Signal | Wire | Connects from |
|---|---|---|---|
| 1 | Regulated `+5V` nominally 5.2 V | Red or clearly red-marked conductor | Matek BEC12S-PRO `5V/5.2V OUT` |
| 2 | `GND` | Black | Matek BEC12S-PRO `GND` |

Board-mounted part:

- Molex Nano-Fit header `105311-1202`
- Two circuits, vertical/top-entry, through-hole with solder clips
- Exact gold-mating version required

Cable-side parts for a custom harness:

- Housing: Molex `105307-1202`
- Female contacts: Molex `105300-2200`, quantity two
- TPA retainer: Molex `105325-1002`
- Red and black 22-AWG stranded thin-wall copper wire

The housing, contacts, TPA, and wire are harness parts. They are not soldered directly to the PCB and should not be placed in the board-assembly BOM as PCB components.

Safety rules:

- Label the harness `REGULATED 5.2V ONLY — NO VBAT`.
- Never plug or unplug J12 while energized.
- Verify polarity and continuity before first power-up.
- Leave at least 12.7 mm of free, unbiased wire after the housing before the first cable tie or forced bend.
- Keep the EVT1 harness at approximately 100 mm; 150 mm is the maximum.

---

## 4. What USB-C is used for

USB-C remains on the FC for:

- Firmware loading and updates
- ArduPilot/Mission Planner connection
- Configuration and parameter changes
- Debugging, logs, and USB communication

USB-C is intentionally **not** an FC power input in EVT1. The old USB-VBUS-to-`+5V` path was removed to prevent back-powering between the computer and the external 5.2 V supply. Connecting only USB should not energize the FC `+5V` rail.

---

## 5. J12 assembly at JLCPCB or PCBWay

### 5.1 JLCPCB listing discussed

The JLCPCB parts-library listing shown in the conversation was:

- Manufacturer: Molex
- MPN: `1053111202` (same part as hyphenated `105311-1202`)
- JLCPCB part number: `C17258811`
- Assembly type shown: wave soldering

It can be used for J12 **only if the order is locked to the exact Molex MPN `105311-1202` with no substitute**. The exact part is the required gold-mating variant. Any confusing marketplace/library text such as “tin” must not be used to approve a different mating-contact finish; confirm the manufacturer part number and official drawing.

The screenshot showed very low stock. Stock is temporary and must be checked again when ordering.

### 5.2 PCBWay options for J12

Preferred sequence:

1. PCBWay sources and installs exact Molex `105311-1202` as part of mixed SMT/THT assembly.
2. If PCBWay cannot source it, buy the exact header from an authorized distributor and consign it to PCBWay.
3. If neither is possible, mark J12 DNP and hand-solder the exact header after assembly.

Mandatory instruction to the assembler:

> Populate J12 with exact Molex 105311-1202 only. Black, 0.38 µm gold version. No substitutes and no tin-contact alternative. Obtain written customer approval before any sourcing or part-number change.

The connector is through-hole, so the quotation must include THT assembly. The wire harness is a separate item and is not automatically included with PCB assembly.

---

## 6. Ready-made POWER1 harness option

### 6.1 Recommended cable

The suitable ready-made option identified in the conversation is genuine Molex `45130-0201` (also written `0451300201`):

- Two-position Nano-Fit receptacle-to-receptacle cable assembly
- 150 mm long
- 20-AWG conductors
- Gold mating contacts
- Factory-crimped housings and TPA retainers
- Both conductors are normally black

Recorded supplier links:

- [element14 Malaysia — Molex 45130-0201, order code 3862447](https://my.element14.com/molex/45130-0201/cable-assy-2pos-rcpt-rcpt-150mm/dp/3862447)
- [DigiKey Malaysia — Molex 0451300201](https://www.digikey.my/en/products/detail/molex/0451300201/6709934)
- [Molex 45130 series reference](https://www.molex.com/en-us/products/series-chart/45130)

Price and stock statements from the conversation are historical observations, not guarantees. Recheck them immediately before purchase.

### 6.2 How to adapt it

1. Keep one factory connector intact for the FC J12 end.
2. Cut off the connector at the other end, cutting close to the discarded housing so the useful cable remains as long as possible.
3. Keep the finished cable no longer than 150 mm; shorten toward 100 mm if practical.
4. Use a multimeter in continuity mode to identify which free conductor reaches J12 pin 1.
5. Mark that conductor red at both relevant locations using red heat-shrink or a durable red sleeve.
6. Solder the pin-1 conductor to Matek BEC `5V/5.2V OUT`.
7. Solder the pin-2 conductor to Matek BEC `GND`.
8. Insulate the solder joints with heat-shrink and add strain relief.
9. Before plugging into the FC, verify polarity, continuity, absence of shorts, and approximately 5.2 V at the connector.

### 6.3 Is the 20-AWG deviation acceptable?

Yes. The ready-made cable's 20-AWG wire is electrically acceptable and has more conductor cross-section than the specified 22-AWG wire. Record it as a harness deviation because the original build specification called for 22 AWG. Confirm that the assembly bends comfortably and does not place mechanical stress on J12.

If this genuine ready-made cable is used, do **not** also buy or build the exact custom 22-AWG harness unless a later mechanical test shows that the thicker cable is unsuitable.

### 6.4 Parts no longer needed when using the ready-made cable

For each harness made from `45130-0201`, separate purchases of the following are unnecessary:

- `105307-1202` housing
- Two `105300-2200` crimp contacts
- `105325-1002` TPA
- Separate red/black 22-AWG wire for that harness
- A Nano-Fit crimp tool solely for this one harness

Heat-shrink, polarity marking, solder, and strain relief are still required at the BEC end.

### 6.5 Parts to avoid

- Avoid generic “Nano-Fit compatible” marketplace cables unless the seller proves the exact genuine parts and gold contact finish.
- Avoid Molex `245130` assemblies for this interface because the discussed versions use tin mating contacts and should not be mixed with the selected gold header system.
- Shopee, AliExpress, and Taobao searches in the conversation did not produce a sufficiently verifiable exact listing. A future listing is acceptable only after exact MPN, contact finish, gauge, length, and authenticity are confirmed.

---

## 7. Custom 22-AWG harness option

Use this only if the ready-made `45130-0201` cable is unavailable or the exact red/black 22-AWG configuration is preferred.

Construction:

1. Cut approximately 100 mm each of red and black 22-AWG stranded thin-wall wire, insulation OD no greater than 1.60 mm.
2. Crimp one `105300-2200` contact onto each conductor using a correct Nano-Fit crimp tool.
3. Insert the red conductor into housing `105307-1202` cavity 1.
4. Insert the black conductor into cavity 2.
5. Confirm both contacts are fully locked.
6. Install TPA `105325-1002`.
7. Solder the free red end to Matek `5V/5.2V OUT` and the black end to Matek `GND`.
8. Apply heat-shrink and strain relief.
9. Perform continuity, isolation, polarity, and pull/visual inspections.

Potential Malaysian sources recorded in the conversation:

- RS Malaysia or element14 Malaysia for housing and contacts
- element14 Malaysia or Mouser for the TPA
- DigiKey Malaysia or a reputable local wire supplier for 22-AWG thin-wall wire
- Local custom harness companies: Markerry Manufacturing (Kedah), Smartlink Engineering Malaysia, or TeeTronics Malaysia

Suggested custom-harness RFQ text:

> One-ended Molex Nano-Fit harness, housing 105307-1202, two gold contacts 105300-2200, TPA 105325-1002, 100 mm long, 22-AWG stranded thin-wall copper wire with insulation OD no greater than 1.60 mm, red pin 1 and black pin 2, opposite ends stripped/tinned for soldering, with 100% continuity, isolation and polarity testing. No substitutions without written approval.

Ordinary pliers are not an acceptable substitute for a proper terminal crimp tool.

---

## 8. How the OpenESC connects to the FC

The proposed FC includes J6, an eight-position JST-SH physical connector for the OpenESC signal interface. Only five conductors are installed.

| FC J6 pin | OpenESC J1 pin | Function | Harness conductor |
|---|---|---|---|
| 1 | — | NC | No contact/wire |
| 2 | 2 | Signal ground | Installed |
| 3 | — | NC; `/CURR` omitted | No contact/wire |
| 4 | — | NC | No contact/wire |
| 5 | 5 | M1 | Installed |
| 6 | 6 | M2 | Installed |
| 7 | 7 | M3 | Installed |
| 8 | 8 | M4 | Installed |

Rules:

- Use an eight-position JST-SH connector shell compatible with J6/OpenESC J1, populated with only five conductors.
- Keep the EVT1 signal harness at or below 150 mm.
- The mapping is straight-through for pins 2 and 5–8.
- Do not install conductors for pins 1, 3, or 4.
- Do not carry `VBAT`, 5 V, current sense, or any other power signal through this harness.
- The OpenESC receives battery power separately from the 6S battery/PDB.
- Motors connect directly to the OpenESC three-phase outputs.
- Perform PWM and DShot motor tests with propellers removed.

Physical motor-output mapping at the FC:

| J6 pin | MCU/timer | ArduPilot output |
|---|---|---|
| 5 | PE14 / TIM1_CH4 | Output 1 / Motor 1 |
| 6 | PE13 / TIM1_CH3 | Output 2 / Motor 2 |
| 7 | PE11 / TIM1_CH2 | Output 3 / Motor 3 |
| 8 | PE9 / TIM1_CH1 | Output 4 / Motor 4 |

For ArduPilot Quad X:

- Motor 1: front-right, CCW
- Motor 2: rear-left, CCW
- Motor 3: front-left, CW
- Motor 4: rear-right, CW

---

## 9. PCBWay manufacturing and assembly

PCBWay can read and use Gerbers, drill files, BOM, centroid/pick-and-place data, assembly drawings, and supporting mechanical files. It also supports mixed SMT and through-hole assembly and can quote turnkey, consigned, or combination sourcing.

General PCBWay references discussed:

- [PCBWay assembly requirements](https://www.pcbway.com/assembly-faq.html)
- [PCBWay assembly capabilities](https://www.pcbway.com/assembly-capabilities.html)
- [PCBWay component sourcing](https://www.pcbway.com/pcb_prototype/Electronic_Components.html)

Do not upload an old overall archive or the JLCPCB release and immediately place an order. Use the dedicated PCBWay release described below.

---

## 10. Dedicated PCBWay release: exact upload map

Release root:

`FC_FAB_OUTPUT/ENGINEERING_VALIDATION_EVT1_PCBWAY`

Use the following files:

| PCBWay order field | File |
|---|---|
| PCB fabrication Gerber upload | `fabrication/FC_EVT1_PCBWAY-Gerber-Upload.zip` |
| Assembly BOM | `assembly/FC_EVT1_PCBWAY-Turnkey-BOM.csv` |
| Centroid / pick-and-place | `assembly/FC_EVT1_PCBWAY-SMT-Centroid.csv` |
| Assembly drawings | `output/pdf/FC_EVT1_PCBWAY-Assembly_Drawings.pdf` |
| THT placement support | `assembly/FC_EVT1_PCBWAY-THT-Placement.csv` |
| DNP confirmation | `assembly/FC_EVT1_PCBWAY-DNP-and-NonPurchased.csv` |
| Controlled-impedance notes | `output/pdf/FC_EVT1_PCBWAY-Controlled_Impedance.pdf` |
| IPC-356 netlist | Upload as a supporting fabrication file if requested |
| J12 sourcing/THT note | `documents/PCBWay_J12_Sourcing_and_THT_Instructions.md` |
| Harness RFQ | `harness/PCBWay_Harness_Quotation_Note.md` plus harness BOM and cut/test table |

Upload the IPC-356 file separately as a supporting fabrication file, not inside the Gerber-only ZIP, unless PCBWay engineering asks for it inside the archive.

---

## 11. PCBWay order settings

- Six-layer rigid PCB
- 1.6 mm finished thickness
- Outer copper: 1 oz
- Inner copper: 1 oz for the selected PCBWay construction
- ENIG finish
- Green solder mask
- White silkscreen
- Double-sided mixed SMT/THT assembly
- Finished single-board envelope: approximately 40.575 × 50.500 mm
- Main PCB body: 40.5 × 40.5 mm plus compact integral Nano-Fit tab
- Mounting pattern: 30.5 mm M3
- USB differential impedance: 90 Ω ±10%
- Current PCBWay USB geometry in the release: 0.1537 mm trace width / 0.2032 mm edge-to-edge gap
- Manufacturer-created 2 × 2 routed assembly panel with rails
- Single-board Gerbers remain the design source of truth
- No design, material, net, component, or MPN change without written approval

PCBWay must confirm that its chosen six-layer dielectric construction produces the required USB impedance with the supplied geometry before production. If it cannot, the PCB routing and fabrication outputs must be regenerated for the approved stack-up; PCBWay must not silently alter the design.

---

## 12. PCBWay ordering sequence

1. Open `README-FIRST.md` in the dedicated PCBWay release.
2. Upload only `fabrication/FC_EVT1_PCBWAY-Gerber-Upload.zip` to the PCB fabrication field.
3. Select the settings in Section 11.
4. Request controlled impedance and paste the 90 Ω differential requirement.
5. Request a manufacturer-created 2 × 2 routed panel with assembly rails.
6. Add PCBA and choose double-sided mixed SMT/THT assembly.
7. Upload `assembly/FC_EVT1_PCBWAY-Turnkey-BOM.csv` as the BOM.
8. Upload `assembly/FC_EVT1_PCBWAY-SMT-Centroid.csv` as centroid/pick-and-place data.
9. Attach the assembly drawing, THT-placement list, DNP list, impedance PDF, and IPC-356 netlist as supporting files.
10. Paste the exact J12 sourcing instruction. Allow no substitutes without written approval.
11. Decide operationally between PCBWay-sourced J12, customer-consigned J12, or deliberate J12 DNP/hand soldering based on its quote—not by substituting another connector.
12. If desired, request a separate cable-harness quotation using the files under `harness/`.
13. Review PCBWay's component substitutions line by line. Reject generic or unrated substitutions.
14. Obtain written confirmation of stack-up/impedance, J12 exact MPN, THT assembly, panelization, and DNP parts before authorizing production.
15. Review PCBWay's CAM/DFM output and assembly images before payment/production approval.

Suggested order note:

> Engineering Validation EVT1, not flight released. Fabricate and assemble strictly to the supplied files. Six-layer, 1.6 mm, ENIG, green mask, white silkscreen, 90-ohm differential USB ±10%, double-sided mixed SMT/THT. Populate J12 only with exact Molex 105311-1202, gold mating version; no substitute. Observe supplied DNP list. No design, material, net, component, or part-number change without written approval. Please confirm final stack-up, impedance construction, exact J12 sourcing, THT process, and 2 × 2 routed panel arrangement before production.

---

## 13. Harness sourcing decision tree

```text
Can genuine Molex 45130-0201 be obtained?
├── Yes
│   ├── Buy it
│   ├── Cut off one end
│   ├── Identify and mark pin 1 red
│   └── Solder to Matek 5.2 V OUT and GND
└── No
    ├── Order/build the exact 22-AWG custom harness
    ├── Use 105307-1202 + 2×105300-2200 + 105325-1002
    └── Perform crimp, polarity, continuity, and pull inspections
```

Do not build both options for the same aircraft unless a spare harness is intentionally required.

---

## 14. Checks before connecting power

1. Visually confirm that J12 on the FC is exact Molex `105311-1202` and correctly oriented.
2. Confirm no raw battery/VBAT wire enters J12.
3. Confirm the BEC is a genuine Matek BEC12S-PRO configured for its default 5.2 V output.
4. With the FC disconnected, energize the BEC using a current-limited setup and measure its output.
5. Confirm J12 cable pin 1 is positive and pin 2 is ground.
6. Check resistance between `+5V` and `GND` for an obvious short before connecting.
7. Confirm the ESC signal harness has no contacts/wires at J6 pins 1, 3, and 4.
8. Confirm no `VBAT`, current-sense, or 5 V continuity exists through J6.
9. Plug J12 only while the battery/BEC is de-energized.
10. Perform the EVT1 current-limited first-power-up and physical-validation worksheet before any flight use.

---

## 15. Questions resolved in the side conversation

### Will J12 be assembled by JLCPCB/PCBWay, or must it be soldered manually?

It may be assembled by either manufacturer if the quotation includes through-hole/wave soldering and the exact `105311-1202` is sourced. Manual soldering is the controlled fallback, not the default requirement.

### Is J12 in the board BOM?

Yes, the board header `105311-1202` belongs in the PCB assembly BOM. The mating housing, crimp contacts, TPA, and cable wire belong in the separate harness BOM.

### Is the JLCPCB-listed `1053111202` usable?

Yes, provided it is confirmed as exact Molex `105311-1202`, the gold-mating version, and no substitution is allowed. Recheck stock at order time.

### Can PCBWay manufacture and assemble the board from the supplied files?

Yes. Use the dedicated PCBWay release, not an older JLC or all-in-one ZIP. Final production still requires PCBWay CAM/DFM, stack-up/impedance, sourcing, and J12 confirmation.

### What does J12 connect from and to?

From Matek BEC12S-PRO regulated 5.2 V output to the FC's J12 input, using two conductors: pin 1 positive and pin 2 ground.

### What is USB-C for if it does not power the board?

Firmware loading, configuration, telemetry/debug communication, logs, and USB connection to ArduPilot tools. It is intentionally data-only with respect to the FC power rail.

### Can a ready-made J12 cable be purchased?

Yes. Genuine Molex `45130-0201` is the identified ready-made option. It is factory-crimped and 150 mm long, but both wires must be identified because they are black.

### Must the custom 22-AWG option also be made?

No. Use either the genuine ready-made 20-AWG cable or the exact custom 22-AWG harness. The ready-made cable is acceptable when adapted and polarity-marked correctly.

### Is there an ESC connector on the proposed FC?

Yes. J6 is the eight-position JST-SH connector. It receives the signal-only cable from OpenESC J1, with five populated conductors: GND and M1–M4.

---

## 16. Remaining external actions

The local release does not eliminate these real-world steps:

- Recheck distributor stock and price before purchasing.
- Obtain PCBWay's written CAM/DFM and impedance confirmation.
- Approve exact component sourcing and every proposed substitution.
- Confirm exact J12 MPN and THT process.
- Purchase/adapt the ready-made harness or obtain the custom harness.
- Fabricate and assemble EVT1.
- Complete the physical-validation worksheet on the actual hardware.
- Do not treat the board as flight released until physical validation passes.

---

## 17. Related release documents

- `README-FIRST.md`
- `PACKAGE_STATUS.md`
- `documents/PCBWay_Upload_Map.md`
- `documents/PCBWay_Fabrication_and_Order_Settings.md`
- `documents/PCBWay_Controlled_Impedance_Report.md`
- `documents/PCBWay_J12_Sourcing_and_THT_Instructions.md`
- `documents/PCBWay_Panelization_Instructions.md`
- `documents/Physical_Validation_Worksheet.md`
- `harness/POWER1_Harness_Drawing_and_Instructions.md`
- `harness/PCBWay_Harness_Quotation_Note.md`
- `harness/POWER1_Harness_BOM.csv`
- `harness/POWER1_Harness_Cut_and_Test_Table.csv`

This reference summarizes conversation guidance. The released design files, BOM, DNP list, controlled-impedance document, and manufacturer-approved CAM data take precedence if a conflict is discovered.
