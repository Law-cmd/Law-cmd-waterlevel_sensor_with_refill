💧 Water Level Sensor Project

An Arduino‑based water level monitoring system with dual alarm modes and an automatic refill process.

🎥 Explanatory Video
📖 Overview

This project uses an Arduino Uno to measure and display water levels. It features:

    Visual alerts with LEDs

    Audible alerts with a buzzer

    Real‑time water level display on an LCD (I2C slave module)

    Automatic refill using a servo‑controlled valve

The prototype is built on a breadboard with jumper wires and programmed via Visual Studio Code.
⚙️ How It Works

    Low water level

        🚨 LED blinks red

        🔊 Buzzer sounds

        📟 LCD shows a warning message

        💦 Servo opens valve → refill starts

    Sufficient water level

        ✅ LED blinks green

        📟 LCD shows the current water level

🛠️ Components Used

    Arduino Uno

    LCD with I2C module

    LEDs (Red & Green)

    Buzzer

    Servo motor (for valve control)

    Breadboard + jumper wires

🚀 Features

    Real‑time monitoring of water levels

    Dual alarm system (visual + audible)

    Automatic refill process

    Compact breadboard prototype

    Easy to expand and customize

📷 Demo

Check out the working prototype in action: Explanatory Video
🔮 Future Improvements

    Add a mobile notification system (e.g., via WiFi module)

    Implement precise water level measurement with sensors

    Optimize power consumption for long‑term use

