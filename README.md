# ESP32 DHT11 Sensor Example

This project reads temperature and humidity data from a DHT11 sensor using the ESP32-WROOM-32D and displays it via the serial monitor.

## 🧰 Requirements
- ESP32 development board (e.g., ESP32-WROOM-32D, ESP32-C series, ESP32-S series, etc.)
- DHT11 sensor
- ESP-IDF installed and configured

## 🔧 Build and Flash

```bash
# Build the project
idf.py build

# Check the connected port (e.g., /dev/ttyUSB0)
ls /dev/ttyUSB*

# Flash the firmware to ESP32
idf.py -p /dev/ttyUSB0 flash

# Monitor serial output
idf.py monitor
