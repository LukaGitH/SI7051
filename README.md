# SI7051 Arduino Example (No External Library)

This Arduino sketch demonstrates how to read temperature data from the **Si7051** digital temperature sensor over I2C — without using any external libraries.

## 📦 What's Included

- `SI7051_no_lib.ino`: Example sketch to read and display temperature using raw I2C commands
- MIT License

## 🔧 Hardware Required

- Arduino board (Uno, Nano, etc.)
- Si7051 sensor (I2C interface)
- Jumper wires

## 🔌 Wiring

| Si7051 Pin | Connect to Arduino |
|------------|--------------------|
| VDD        | 3.3V or 5V         |
| GND        | GND                |
| SDA        | A4 (Uno/Nano)      |
| SCL        | A5 (Uno/Nano)      |

> ✅ The Si7051 supports both 3.3V and 5V logic, making it safe to use directly with most Arduino boards.

## 🧠 How It Works

- Sends the `0xF3` command to initiate a temperature measurement
- Waits for data, reads 2 bytes, and converts the raw result to Celsius
- Outputs the temperature over serial

### Example Serial Output

Temperature: 23.54 °C

## 🧪 Notes

- No external libraries are required — this sketch uses only `Wire.h`
- Adjust the delay (currently 200 ms) if needed for your sensor response time

## 📜 License

MIT License – see `LICENSE` for details.
