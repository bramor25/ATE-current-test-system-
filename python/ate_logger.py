import serial
import time
import csv

# Change COM5 if needed
arduino = serial.Serial('COM5', 9600, timeout=1)

# Let Arduino reset
time.sleep(2)

# Initialize test counter
test_count = 0

# Open CSV file
with open("test_results.csv", "w", newline="") as file:
    writer = csv.writer(file)
    writer.writerow(["Timestamp", "Current (A)", "Result"])

    while True:
        data = arduino.readline().decode('utf-8').strip()

        if data:
            try:
                current, result = data.split(",")

                timestamp = time.strftime("%Y-%m-%d %H:%M:%S")

                writer.writerow([timestamp, current, result])
                file.flush()

                test_count += 1

                print(f"Test #{test_count}")
                print(f"[ATE] Current: {current} A | Result: {result}")
                print("---------------------------")

            except ValueError:
                print("Bad data:", data)
