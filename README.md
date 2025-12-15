# Overview

I have made a water level sensor with two ways of alarming and a refill process.

Sensor funktion:[Explanatory video](https://www.youtube.com/shorts/WR1qh0_Rwd8)


The data is displayed on an LCD diplay uisng an I2C SLAVE modul.

I am using a Arduino Uno and for the programming Visual Studio Code.
I have build this project using jumper wires and a simple Breadborad.

# Explanation:
If the water level is too low the LED will BLink RED, the buzzer will buzz, the LCD will show a message and the reill process will start (servo opens a valve).
If there is enough water then the LED will blink GREEN and The LCD will show the waterlevel.
# Setup
lcd.init();
lcd.clear();         
lcd.backlight();   

pinMode(A1, OUTPUT);//sensor

pinMode(11, OUTPUT);//piezo

servo.attach(8);
servo.write(angle);

digitalWrite(sensorPower, LOW);
pinMode(redPin, OUTPUT); pinMode(greenPin, OUTPUT); pinMode(bluePin, OUTPUT);
