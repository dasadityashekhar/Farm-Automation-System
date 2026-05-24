# Farm Automation System 🌾

An IoT-based farm monitoring and automation system developed using ESP32 for real-time control, monitoring, and surveillance of agricultural environments.

The system enables wireless control of irrigation pumps, fly-trap lighting, and animal alert systems through a custom-built web dashboard. It also provides real-time rain monitoring and live surveillance using ESP32-CAM integration.

---

## 🚀 Features

- Remote irrigation pump control
- Real-time rain detection
- Live farm surveillance using ESP32-CAM
- Fly-trap light control system
- Animal alert buzzer system
- Responsive web-based control dashboard
- Dark/Light theme support
- Real-time device status updates
- WiFi-enabled wireless monitoring
- REST API communication using ESP32 Web Server

---

## 🛠️ Hardware Used

### Microcontroller
- ESP32

### Sensors & Modules
- Rain Sensor
- ESP32-CAM
- Relay Module
- Water Pump
- LED Light
- Buzzer

---

## 🌐 Web Dashboard

The project includes a lightweight custom HTML dashboard developed for real-time monitoring and control of farm devices using ESP32.

### Dashboard Features
- Device ON/OFF controls
- Live rain status monitoring
- Embedded surveillance stream
- Responsive interface
- Dark and light themes
- Real-time communication with ESP32

---

## 📡 REST API Endpoints

| Endpoint | Function |
|---|---|
| `/pump/on` | Turn Pump ON |
| `/pump/off` | Turn Pump OFF |
| `/led/on` | Turn LED ON |
| `/led/off` | Turn LED OFF |
| `/buzzer/on` | Turn Buzzer ON |
| `/buzzer/off` | Turn Buzzer OFF |
| `/rain` | Read Rain Sensor Status |
| `/test` | Test ESP32 Server |

---

## ⚙️ Working Principle

1. ESP32 connects to the local WiFi network.
2. ESP32 hosts a local web server.
3. The web dashboard communicates with ESP32 using HTTP requests.
4. Users can remotely control:
   - Irrigation Pump
   - Fly-Trap Light
   - Animal Alert Buzzer
5. Rain sensor status is continuously monitored and updated on the dashboard.
6. Live surveillance feed is displayed using ESP32-CAM.

---

## 📂 Project Structure

```text
Farm-Automation-System/
│
├── Hardware/
│   └── farm_automation_system.ino
│
├── Website/
│   └── index.html
│
└── README.md
```

## 💻 Technologies Used

- ESP32
- Embedded C++
- HTML
- CSS
- JavaScript
- REST API
- IoT

---


## 👨‍💻 Developed & Designed By

This project was completely designed and developed independently, including:

- ESP32 firmware development
- Hardware integration
- Sensor interfacing
- REST API implementation
- WiFi communication setup
- Irrigation and device control logic
- Responsive HTML-based control dashboard
- System testing and debugging



---

## 🌱 Future Improvements

- Soil moisture monitoring
- Automatic irrigation scheduling
- Cloud data logging
- Mobile application support
- AI-based crop monitoring
- Weather forecasting integration
- Solar-powered operation

---

## 📜 License

This project is intended for educational and research purposes.
