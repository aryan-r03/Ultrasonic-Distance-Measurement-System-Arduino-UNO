# Ultrasonic Distance Measurement System (Arduino UNO)

![Arduino](https://img.shields.io/badge/Arduino-UNO-blue)
![Language](https://img.shields.io/badge/Language-C%2B%2B-brightgreen)
![Python](https://img.shields.io/badge/Python-3.8+-yellow)
![Domain](https://img.shields.io/badge/Domain-Embedded%20Systems-orange)
![Status](https://img.shields.io/badge/Status-Stable-success)
![License](https://img.shields.io/badge/License-MIT-lightgrey)

## Project Overview

> **Portfolio-grade embedded systems project demonstrating ultrasonic sensing, real-time signal processing, hardware–software integration, and multi-platform interfacing using Arduino UNO.**

This project implements a **comprehensive distance measurement system** using an **HC-SR04 ultrasonic sensor** and **Arduino UNO**, featuring:
- Real-time distance calculation with visual LED feedback
- **Dual Python interface support** (GUI + Audio Alert System)
- Threshold-based object detection and triggering
- Serial communication protocol for cross-platform integration

This project is intentionally modular, deterministic, and production-ready — optimized for **academics, portfolio demonstrations, and embedded systems fundamentals**.

---

## 🎯 Key Features

- ✅ **Hardware-Software Integration**: Seamless Arduino-Python communication
- ✅ **Multiple Output Modes**: Compatible with GUI and audio alert systems simultaneously
- ✅ **Real-time Processing**: 10 Hz sampling rate with distance calculation
- ✅ **Visual Feedback**: LED indicator for proximity alerts
- ✅ **Modular Design**: Easy to extend and customize
- ✅ **Professional Code**: Clean, well-documented, interview-ready

---

## 📦 Hardware Requirements

### Components
| Component | Quantity | Purpose |
|-----------|----------|---------|
| Arduino UNO | 1 | Microcontroller |
| HC-SR04 Ultrasonic Sensor | 1 | Distance measurement |
| LED (any color) | 1 | Visual indicator |
| 220Ω Resistor | 1 | LED current limiting |
| Jumper Wires | 6+ | Connections |
| USB Type-B Cable | 1 | Programming & power |

---

## 🔌 Circuit Connections

### HC-SR04 → Arduino UNO
| HC-SR04 Pin | Arduino Pin | Description |
|-------------|-------------|-------------|
| VCC         | 5V          | Power supply |
| GND         | GND         | Ground |
| TRIG        | D9          | Trigger pin |
| ECHO        | D10         | Echo pin |

### LED Circuit
- **Anode (+)** → D3 (via 220Ω resistor)
- **Cathode (–)** → GND

### Circuit Diagram
📌 See `circuit_diagram.png` for visual reference

```
        Arduino UNO
    ┌─────────────────┐
    │                 │
    │  D9  ────────── │ TRIG
    │  D10 ────────── │ ECHO     HC-SR04
    │  5V  ────────── │ VCC
    │  GND ────────── │ GND
    │                 │
    │  D3  ──[220Ω]── │ LED+ ──┐
    │  GND ────────── │ LED- ──┘
    │                 │
    └─────────────────┘
```

---

## 🧠 Working Principle

### Distance Measurement Algorithm

1. **Trigger Phase**: Arduino sends a 10µs HIGH pulse to TRIG pin
2. **Ultrasonic Emission**: HC-SR04 emits 8 pulses of 40 kHz ultrasonic waves
3. **Echo Detection**: Waves reflect from object and return to sensor
4. **Time Measurement**: ECHO pin stays HIGH for duration proportional to distance
5. **Distance Calculation**:
   ```cpp
   Distance (cm) = (Echo Duration × Speed of Sound) / 2
   Distance (cm) = (Duration × 0.0343) / 2
   ```
6. **Threshold Detection**: LED activates when distance is within defined range (10-40 cm)
7. **Serial Output**: Distance values and trigger signals transmitted via UART

### Speed of Sound Breakdown
- Speed of sound in air: **343 m/s** = **0.0343 cm/µs**
- Division by 2: Accounts for round-trip travel time

---

## 💻 Software Requirements

### Arduino Development
- **Arduino IDE** (1.8.x or 2.x)
- **Board**: Arduino UNO
- **Baud Rate**: 9600
- **No external libraries required** (uses standard Arduino functions)

### Python Interface (Optional)
- **Python 3.8+**
- **Libraries**:
  ```bash
  pip install pyserial pygame
  ```

---

## 📂 Project Structure

```
ultrasonic-distance-arduino/
│
├── arduino_sketch_simple.ino          # Main Arduino sketch (RECOMMENDED)
├── arduino_sketch_compatible.ino      # Advanced mode-selectable version
├── Distance_GUI.py                    # Real-time GUI display interface
├── Distance_custom_audio.py           # Audio alert system
├── circuit_diagram.png                # Wiring diagram
├── README.md                          # This file
└── audio_files/                       # Audio alerts (user-provided)
    ├── audio_1.mp3
    ├── audio_2.mp3
    └── audio_3.mp3
```

---

## 🚀 How to Run

### Step 1: Upload Arduino Code

```bash
# Clone the repository
git clone https://github.com/your-username/ultrasonic-distance-arduino.git
cd ultrasonic-distance-arduino
```

1. Open `arduino_sketch_simple.ino` in Arduino IDE
2. Connect Arduino UNO via USB
3. Select:
   - **Board** → Arduino UNO
   - **Port** → Correct COM/USB port (e.g., COM3, /dev/ttyUSB0)
4. Click **Upload** (→)
5. Open **Serial Monitor** (9600 baud) to verify output

**Expected Serial Output:**
```
25.3
23.7
21.4
PLAY_AUDIO
20.1
18.9
```

### Step 2: Test with Serial Monitor

Move an object in front of the sensor and observe:
- Distance values printing continuously
- LED turning ON when object is 10-40 cm away
- "PLAY_AUDIO" trigger appearing in range

### Step 3: Run Python Interfaces (Optional)

#### Option A: GUI Display
```bash
python Distance_GUI.py
```
**Features:**
- Real-time distance display with color coding
- Green (>50cm) → Yellow (20-50cm) → Red (<20cm)
- Text-to-speech distance announcements

#### Option B: Audio Alert System
```bash
python Distance_custom_audio.py
```
**Features:**
- Listens for "PLAY_AUDIO" trigger
- Plays sequential audio warnings
- 5-second cooldown between alerts

**Note:** Update the serial port in Python files:
```python
SERIAL_PORT = "/dev/cu.usbmodem101"  # macOS
# PORT = "/dev/ttyUSB0"              # Linux
# PORT = "COM3"                      # Windows
```

---

## 🔧 Customization

### Adjust Detection Range
Edit in `.ino` file:
```cpp
#define MIN_DISTANCE 10  // Minimum trigger distance (cm)
#define MAX_DISTANCE 40  // Maximum trigger distance (cm)
```

### Change Sampling Rate
```cpp
delay(100);  // Current: 10 Hz (100ms interval)
delay(50);   // Example: 20 Hz (50ms interval)
```

### Modify Debounce Period
```cpp
#define DEBOUNCE_DELAY 1500  // Milliseconds between triggers
```

---

## 🎓 Learning Outcomes

This project demonstrates proficiency in:

### Embedded Systems
- ✅ Time-of-flight distance measurement
- ✅ GPIO and digital signal handling
- ✅ Pulse width modulation concepts
- ✅ Real-time sensor data processing

### Software Engineering
- ✅ Serial communication protocols (UART)
- ✅ Hardware-software integration
- ✅ Multi-platform compatibility design
- ✅ State machine implementation

### Professional Skills
- ✅ Clean, maintainable C++ code
- ✅ Comprehensive documentation
- ✅ Modular system architecture
- ✅ Cross-platform development

---

## 🌟 Use Cases

### Academic & Learning
- Embedded systems laboratory practicals
- Microcontroller programming fundamentals
- Sensor integration demonstrations

### Practical Applications
- **Obstacle Detection**: Robotics navigation systems
- **Parking Assistance**: Vehicle proximity alerts
- **Smart Automation**: Automated door systems
- **Industrial**: Object presence detection
- **IoT Prototyping**: Distance-based triggers

### Portfolio Enhancement
- Demonstrates hardware-software integration
- Shows multi-language proficiency (C++, Python)
- Exhibits professional documentation skills

---

## 🐛 Troubleshooting

### Common Issues

#### No Serial Output
- ✅ Check USB connection
- ✅ Verify correct COM port selected
- ✅ Confirm baud rate is 9600
- ✅ Check Arduino board selection

#### Incorrect Distance Readings
- ✅ Verify HC-SR04 wiring (TRIG → D9, ECHO → D10)
- ✅ Ensure sensor has clear line of sight
- ✅ Check 5V power supply is stable
- ✅ Avoid angled or absorptive surfaces

#### LED Not Working
- ✅ Check LED polarity (long leg = anode)
- ✅ Verify 220Ω resistor is in series
- ✅ Confirm LED is not burnt out
- ✅ Test with multimeter

#### Python Script Connection Errors
- ✅ Close Arduino Serial Monitor before running Python
- ✅ Update `SERIAL_PORT` variable with correct port
- ✅ Check port permissions (Linux/macOS: `sudo chmod 666 /dev/ttyUSB0`)
- ✅ Install required libraries: `pip install pyserial pygame`

---

## 📊 Technical Specifications

| Parameter | Value |
|-----------|-------|
| Operating Voltage | 5V DC |
| Current Consumption | ~15mA (Arduino) + 15mA (HC-SR04) |
| Measurement Range | 2 cm - 400 cm |
| Accuracy | ±3 mm |
| Measurement Angle | 15° cone |
| Ultrasonic Frequency | 40 kHz |
| Sampling Rate | 10 Hz |
| Serial Baud Rate | 9600 |

---

## 🔄 Version History

### v2.0 (Current)
- ✅ Added dual Python interface support
- ✅ Implemented mode-selectable operation
- ✅ Enhanced serial protocol
- ✅ Improved documentation

### v1.0
- ✅ Basic distance measurement
- ✅ LED indicator
- ✅ Serial output

---

## 🤝 Contributing

Contributions are welcome! Please:
1. Fork the repository
2. Create a feature branch (`git checkout -b feature/enhancement`)
3. Commit changes (`git commit -m 'Add enhancement'`)
4. Push to branch (`git push origin feature/enhancement`)
5. Open a Pull Request

---

## 📄 License

This project is licensed under the **MIT License** - see [LICENSE](LICENSE) file for details.

---

## 👨‍💻 Author

**Aryan Ranjan**
- GitHub: [[@aryan-r03](https://github.com/aryan-r03)]
- LinkedIn: [aryan-ranjan03](https://linkedin.com/in/aryan-ranjan03)

  
---

## 🙏 Acknowledgments

- Arduino Community for comprehensive documentation
- HC-SR04 sensor datasheet authors
- Contributors to pyserial and pygame libraries

---

## 📞 Support

For questions or issues:
- Open an issue on GitHub
- Email: your.email@example.com
- Documentation: See `README.md` and inline code comments

---

<div align="center">

**⭐ Star this repository if you found it helpful!**



</div>
