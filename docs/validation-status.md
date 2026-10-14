# Validation status

Publication source checked on 14 October 2026 using KiCad 10.0.6.

| Check | Result |
|---|---|
| ERC errors / warnings | 0 / 40 |
| DRC rule errors / warnings | 0 / 0 |
| Raw unconnected entries | 0 |
| Schematic parity issues | 0 |
| Physical qualification | Pending |


The pre-publication source had 119 parity warnings. Descriptive properties/values and a library-ID mismatch were synchronized from the exact schematic netlist. No footprint was replaced and the electrical/placement/zone/outline geometry signature remained unchanged. Forty ERC warnings remain: pin-to-pin and a power-not-driven warning; runtime/electrical validation is pending.

## Evidence

- [Fresh summary](../verification/latest/summary.json)
- [Raw ERC](../verification/latest/erc.json)
- [Raw DRC and parity](../verification/latest/drc.json)
- [Metadata correction and geometry assertion](../verification/latest/publication-corrections.json)

Ignored checker categories are preserved in the raw reports and source project configuration; a clean configured result is not a clean result under every possible check. Warning and DNP dispositions are engineering exceptions, not proof of physical reliability.

## Manufacturing and firmware

V2 manufacturer snapshots remain separate. Neutral firmware rebuild result is recorded in firmware/README.md. Numeric board ID 1241 remains local and unreserved upstream.

## Physical status

Personal project activity was confirmed by Desan, but no completed measured worksheet, powered sensor qualification or flight result is provided. No flight qualification is claimed. The public engineering bundle is not a certification of a fabricated article.
