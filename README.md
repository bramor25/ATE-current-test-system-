# ATE-current-test-system-
Arduino-based ATE prototype with relay-controlled power switching, ACS712 current sensing, and Python-based data logging for automated pass/fail testing.

---

## Setup/Hardware

### Full System View(Pass Check)
- [Full Setup] <img width="1536" height="2048" alt="image" src="https://github.com/user-attachments/assets/2c48b7ba-fd0a-4421-a0eb-1ad91db6028c" />
*System showing PASS condition with green LED active.*

 ---
  
#### Close-up of Ciruit(Fail Check)
- [Close View] <img width="3000" height="4000" alt="1000008713 (1)" src="https://github.com/user-attachments/assets/cb81ebf7-97ae-49ce-a37e-6e15b9e2bad9" />
*System showing FAIL condition with red LED active.*

---


## Features
- Push-button initiated test cycle
- Relay-controlled power switching
- Current sensing using ACS712
- Pass/fail decision logic
- Red/green LED indicators
- Python serial logging to CSV

## Hardware
- Arduino Uno
- 5V Relay Module
- ACS712 Current Sensor (30A)
- Bench DC Power Supply
- Push Button
- LEDs (Red/Green)
- Breadboard + wires

## Software
- Arduino (C++)
- Python (PySerial, CSV)

## How It Works
1. Press button to start test
2. Arduino turns on relay
3. Power flows to device under test
4. Current is measured using ACS712
5. Arduino determines PASS/FAIL
6. Result is displayed with LEDs
7. Data is sent to Python and logged

## Future Improvements
- Add voltage measurement
- Use Ohm’s Law (V = IR)
- Add LCD display
- Improve enclosure/design


## Author
Brandon Moran
