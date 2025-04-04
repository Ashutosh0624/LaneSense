# LaneSense
# 🚘 LaneSense – A Real-Time ADAS System in Qt & C++

**LaneSense** is an intelligent Advanced Driver Assistance System (ADAS) prototype that leverages real-time sensor simulation, modular architecture, and modern design patterns. Built using **Qt/QML**, **C++**, and **MVP architecture**, this project demonstrates an end-to-end ADAS simulation that is scalable, testable, and ready for embedded deployment.

---

## 🧠 Core Skills Demonstrated

- **Modern C++ (C++17)** – Classes, Smart Pointers, Inheritance, Polymorphism
- **Qt/QML UI Development** – Custom dashboards, property bindings, real-time updates
- **Multithreading & Signals/Slots** – For sensor simulation & data updates
- **Software Architecture** – MVP (Model-View-Presenter)
- **Design Patterns** – Strategy, Observer, Facade, Interface Segregation
- **Documentation & Diagrams** – Doxygen class diagrams, HLD & LLD markdowns

---

## 🔧 Key Features

- 🔁 **Sensor Data Simulation**: Speed, object distance, lane offset, blind spots
- 🧠 **Dynamic Safety Strategy Logic**: Plug-n-play warning strategies
- 🖥️ **QML Dashboard**: Speedometer, Live Data, Real-Time Warnings
- 🏗️ **MVP Architecture**: Clean separation of model, view, and presenter
- 📚 **Documented**: Auto-generated docs + HLD/LLD

---

## 🧠 Architecture Summary

```text
[SensorDataModel] ---> [ADASManager] ---> [ISafetyStrategy Interface]
       |                     |                     |
       |         receives & processes      applies strategy logic
       |                     ↓                     ↓
     [QML View] <------ Signals/Slots <------ [Concrete Strategies]
```

### 🔁 MVP Layer Breakdown

- **Model (SensorDataModel)** – Emits updated sensor values using `Q_PROPERTY` and `NOTIFY`
- **Presenter (ADASManager)** – Listens to model changes, applies strategies
- **View (QML Dashboard)** – Reactively shows data and alerts

---

## 🧱 Design Patterns Used

| Pattern        | Purpose                                                  |
|----------------|-----------------------------------------------------------|
| Strategy       | Runtime switching of safety logic modules                |
| Observer       | Qt signal-slot mechanism for reactive programming        |
| Facade         | Simplified interface for the UI to communicate with logic|
| Interface      | Decouples logic implementation from usage                |

---

## 📁 Folder Structure

```
LaneSense/
│
├── docs/
│   ├── HLD.md                     # High-level architecture
│   ├── LLD.md                     # Low-level design with diagrams
│   ├── ChallengesAndSolutions.md # Engineering thought process
│   ├── architecture.png           # Architecture diagram
│   └── Doxyfile                   # Doxygen config for docs
│
├── src/                          # Core application code
│   ├── main.cpp
│   ├── SensorDataModel.h/.cpp
│   ├── ADASManager.h/.cpp
│   └── strategies/
│       ├── ISafetyStrategy.h
│       ├── DistanceWarningStrategy.cpp/.h
│       └── ...
│
├── qml/                          # UI Layer
│   ├── Main.qml
│   ├── Speedometer.qml
│   ├── LiveDataDisplay.qml
│   └── WarningPanel.qml
│
├── assets/
│   └── screenshots/
│       └── dashboard.png
│
├── README.md
├── CMakeLists.txt
└── LICENSE
```

---

## 🚀 How to Run

```bash
git clone https://github.com/your-username/LaneSense.git
cd LaneSense
open with Qt Creator and run
```

### 📘 To Generate Documentation:
```bash
sudo apt install doxygen graphviz
cd LaneSense
doxygen docs/Doxyfile
```
Then open: `docs/doxygen_output/html/index.html`

---

## 📽️ Demo Video

Watch the working demo here: [▶️ LaneSense ADAS Demo: cd assets]

---

## ⚠️ Challenges Faced & Solutions

See `docs/ChallengesAndSolutions.md` for:
- Real-time data simulation design
- Multithreaded Qt signal-slot issues
- Modularizing strategies using OOP

---

## 🧠 Engineering Thought Process

- Emphasis on **SOLID principles**
- Strong separation of UI and logic
- Scalable architecture with replaceable safety modules
- Readability + maintainability = production-readiness

---

## 👨‍🏫 Why This Project Matters

- Demonstrates hands-on software architecture
- Applies theory (Design Patterns, OOP, MVP) to real systems
- Practical embedded systems design with simulation
- Complete industrial pipeline: Coding → UI → Docs → Architecture → Git → Demo

---

## 👨‍💼 Author

**Ashutosh Kumar Tiwari**  
[LinkedIn](https://www.linkedin.com/in/ashutoshktiwari/) · [Email: (ashutoshktiwari91@gmail.com)]

---

## 📜 License

MIT License

