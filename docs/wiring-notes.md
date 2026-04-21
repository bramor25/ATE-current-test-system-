# Wiring Notes

## Arduino Connections
- D8 → Relay IN
- A0 → ACS712 output
- A1 → Voltage measurement (after relay)
- D11 → Red LED
- D12 → Green LED
- D4 → Push button

## Power
- DC+ → Relay COM
- Relay NO → Load (LED + resistor)
- GND shared across system

## Notes
- Common ground required between Arduino and power supply
- Current sensor placed inline with load
