# BAE305_Project_OnlineDesignFile

Colliding Planets Group

Plant Montoring System Project 

BAE 305 Spring 2026

Members:

Grace Benton, Evie Hamliton, Cami Morgan, Allison Lundy, and Ada Lasley

## Summary

## Design Decision Discussion

using I2C communication, which reduces wiring complexity by only requiring four connections: VCC, GND, SDA, and SCL.

## Materials 
- 571 $in^2$ of Walnut Wood
- 11 Torx Head Screws
- 2 SPARKFUN REDBOARDS
- 1 Breadboard
- 6 $in$ of 3/4 $in$ wide Velcro Tape
- 2  four AA Backery Pack
- 1 eight AA 12V Battery Holder
- ?? $in$ of clear 3/16 $in$ Tubing
- ?? $in$ of 1/4 $in$ Emitter Tubing
- 1 Anolog Soil Moisture Sensor
- 1 2.5L Storage Conatainer 
- 1 DC 12V Diaphram Pump
- 5 10KΩ Resistors
- 1 12VDC 1 CHANNEL RELAY Module 
- 1  RGB LED COmmon Cathode
- 1 I2C Serial Interface Adapter Module 
- 1 16x2 LCD Display Screen
- 1 10KΩ Thermistor 
- 1 Piezo Buzzer
- 3 Pushbuttons

## Project Setup and Schematics 

The plant monitoring system is designed using two separate Arduino-based control boards to independently manage temperature monitoring and soil moisture monitoring with a container to hold the water. All Compents are togeahter on base and held in place with velco tape. The system will sit next to the plant it will monitor with the emitter tubing wraping around the base of the plant and the soil moistor sensor in the pot.

### Project Base
Below is the construction process for the base of the plant monitoring system, designed to support all additional system components.

[![PDF Preview](./BAE305_Project_Base_Drawing_Image.png)](./BAE305_Project_Drawing.pdf)
*Click the image above to view the full PDF drawing.*

The main base was made from a walnut board that was first planed to a thickness of 7/8 inch. It was then cut to 13 inches in length using the chop saw. One edge was jointed to create a straight reference edge, and the board was then cut on the table saw to a final width of 8.5 inches.

The remaining walnut board was then planed to a thickness of 3/4 inch. From this material, two pieces were cut to 7.5 inches in length using the chop saw. Both pieces were jointed on one edge and then cut on the table saw, with one piece finished to 8.5 inches wide and the other finished to 5 inches wide.

Next, another board section was cut to 8.5 inches in length and then ripped into three strips, each measuring 1.5 inches wide. Two of these strips were then cut down to 6.5 inches in length.

Once all pieces were prepared, they were arranged according to the base design drawing. The assembly was secured using Torx head screws. Two screws were used per piece from the bottom for structural support, and one additional screw was used to secure the T-shaped support section together. Then, a hole was drilled with a hand drill and 1/4 $in$ bit in the corner of the lid 1 1/4 $in$ from both sides. 

### Adurino Board 1: Tempature Sensor and Screen

Board 1 is responsible for temperature monitoring and user interaction. This board includes a 10KΩ thermistor temperature sensor, a 10KΩ resistor, 16x2 LCD display, I2C Serial Interface Adapter Module, three pushbuttons, Backery Pack that holds 4 AAs and a piezo buzzer. Using the three pushbuttons the user will input the ideal tempature rang for thier plant. Pushbutton 2 is up by 0.5 degrees Farnhit, pushbutton 3 is down by 0.5 degrees farnhight, and pushbutton 1 uploads imputed temputure range to adurino board. The thermistor continuously measures ambient temperature and sends analog input data to the Arduino RedBoard. The Arduino processes this data and displays both the current temperature readings and inputed range. The piezo buzzer provides audible alerts when temperature goes outside of inputed range. This board serves as the main user interface for the plant monitoring system, allowing real-time monitoring of plant conditions while providing feedback through both visual and audible outputs.

The complete schematic, wiring diagram, and code for Board 1 provide all electrical connections and programming necessary for proper assembly, and system operation.

[![Board 1 Temperature Schematic](./BAE305_Schematic_Board1_Tempature.drawio.png)](./BAE305_Schematic_Board1_Tempature.drawio.png)
*Figure 1. Circuit schematic for Board 1 showing the temperature monitoring system with LCD display, pushbuttons, piezo buzzer, thermistor, and resistor connections.*

[![Board 1 Temperature Wiring Diagram](./Wire_Diagram_Board1_Temp.png)](./Wire_Diagram_Board1_Temp.png)
*Figure 4. Physical wiring diagram for Board 1 showing the full component layout and breadboard connections for the temperature monitoring system with LCD display, pushbuttons, piezo buzzer, and thermistor.*

*Code for Board 1*

```cpp
// Libraries
# include <Wire.h> // Required for I2C communication
# include <LiquidCrystal_I2C.h> // Download this library via Arduino IDE Library Manager
# include <math.h>

// Pin Definitions
const int thermistorPin = A0;
const int buzzerPin = 6;
const int buttonUpPin = 2;   // Example pin for 'Up' button
const int buttonDownPin = 3; // Example pin for 'Down' button
const int buttonSelectPin = 4; // Example pin for 'Select/Confirm' button

// LCD Object (adjust I2C address if needed, 0x27 is common for 16x2 LCDs)
LiquidCrystal_I2C lcd(0x27, 16, 2); // 16 columns, 2 rows

// Temperature Limits (initialized with default values)
float lowTemp = 68.0; // Default to 68 F (20 C)
float highTemp = 77.0; // Default to 77 F (25 C)

// State Management for setting limits
enum ProgramState {
  STATE_SET_LOW,
  STATE_SET_HIGH,
  STATE_MONITORING
};
ProgramState currentState = STATE_SET_LOW;

// Variables for button debouncing (simplified)
long lastButtonPressTime = 0;
long debounceDelay = 200; // milliseconds to ignore subsequent presses

// Function Prototypes
void updateLCD();
void handleButtons();
float readTemperature();

void setup() {
  Serial.begin(9600); // Keep for initial debugging, can be removed if not needed
  pinMode(buzzerPin, OUTPUT);

  // Button pins configured with internal pull-up resistors
  // Connect buttons between the pin and GND
  pinMode(buttonUpPin, INPUT_PULLUP);
  pinMode(buttonDownPin, INPUT_PULLUP);
  pinMode(buttonSelectPin, INPUT_PULLUP);

  // Initialize LCD
  lcd.init();      // Initialize the LCD
  lcd.backlight(); // Turn on backlight
  lcd.clear();     // Clear the display
  lcd.print("Initializing...");
  delay(2000);
  lcd.clear();

  updateLCD(); // Initial display update for setting low temp
}

void loop() {
  handleButtons(); // Check and process button presses

  switch (currentState) {
    case STATE_SET_LOW:
      // Values are adjusted by handleButtons, LCD updated by updateLCD()
      break;

    case STATE_SET_HIGH:
      // Values are adjusted by handleButtons, LCD updated by updateLCD()
      break;

    case STATE_MONITORING: {
      float tempF = readTemperature(); // Now reads in Fahrenheit

      // Display current temperature
      lcd.setCursor(0, 0);
      lcd.print("Temp:           "); // Clear rest of line
      lcd.setCursor(6, 0);
      lcd.print(tempF, 1); // Display temperature with 1 decimal place
      lcd.print(" F");

      // Display set limits
      lcd.setCursor(0, 1);
      lcd.print("L:");
      lcd.print(lowTemp, 1);
      lcd.print(" H:");
      lcd.print(highTemp, 1);
      lcd.print("   "); // Clear rest of line

      // Buzzer logic remains the same
      if (tempF < lowTemp || tempF > highTemp) {
        tone(buzzerPin, 1000); // Activate buzzer
      } else {
        noTone(buzzerPin); // Deactivate buzzer
      }
      delay(500); // Update temperature display every 0.5 seconds
      break;
    }
  }
}

// Function to update LCD based on current state (used for setting limits)
void updateLCD() {
  lcd.clear();
  switch (currentState) {
    case STATE_SET_LOW:
      lcd.setCursor(0, 0);
      lcd.print("Set Low Temp:");
      lcd.setCursor(0, 1);
      lcd.print(lowTemp, 1);
      lcd.print(" F (Up/Dn) Sel");
      break;
    case STATE_SET_HIGH:
      lcd.setCursor(0, 0);
      lcd.print("Set High Temp:");
      lcd.setCursor(0, 1);
      lcd.print(highTemp, 1);
      lcd.print(" F (Up/Dn) Sel");
      break;
    case STATE_MONITORING:
      // Monitoring state updates happen directly in loop()
      break;
  }
}

// Function to handle button presses
void handleButtons() {
  int buttonUpState = digitalRead(buttonUpPin);
  int buttonDownState = digitalRead(buttonDownPin);
  int buttonSelectState = digitalRead(buttonSelectPin);

  // Simple debouncing: only process button press if enough time has passed
  if ((buttonUpState == LOW || buttonDownState == LOW || buttonSelectState == LOW) && (millis() - lastButtonPressTime > debounceDelay)) {
    lastButtonPressTime = millis(); // Reset debounce timer

    if (buttonUpState == LOW) { // Up button pressed (LOW because of INPUT_PULLUP)
      if (currentState == STATE_SET_LOW) {
        lowTemp += 0.5; // Increment by 0.5
        if (lowTemp >= highTemp) lowTemp = highTemp - 0.5; // Prevent low from exceeding or equaling high
      } else if (currentState == STATE_SET_HIGH) {
        highTemp += 0.5;
      }
      updateLCD();
    }

    if (buttonDownState == LOW) { // Down button pressed
      if (currentState == STATE_SET_LOW) {
        lowTemp -= 0.5;
      } else if (currentState == STATE_SET_HIGH) {
        highTemp -= 0.5;
        if (highTemp <= lowTemp) highTemp = lowTemp + 0.5; // Prevent high from going below or equaling low
      }
      updateLCD();
    }

    if (buttonSelectState == LOW) { // Select button pressed
      if (currentState == STATE_SET_LOW) {
        currentState = STATE_SET_HIGH;
        // Ensure highTemp is appropriately set if it was less than lowTemp after adjustment
        if (highTemp <= lowTemp) highTemp = lowTemp + 5.0; // Default buffer
      } else if (currentState == STATE_SET_HIGH) {
        currentState = STATE_MONITORING;
      }
      updateLCD(); // Update LCD for the new state (e.g., switch to "Set High Temp" or start monitoring)
    }
  }
}

// Original readTemperature function, now returns Fahrenheit
float readTemperature() {
  float Vout = analogRead(thermistorPin) * 5.0 / 1023.0;
  float Rntc = 1000.0 * ((5.0 / Vout) - 1); // Assuming 1k series resistor for voltage divider

  // This formula is specific to your thermistor's characteristics.
  // If your thermistor behaves differently, you will need to adjust these coefficients (a, b, c).
  float a = 639.5, b = -0.1332, c = -162.5;
  float tempC = a * pow(Rntc, b) + c; // Calculate Celsius

  // Convert Celsius to Fahrenheit
  float tempF = (tempC * 9.0 / 5.0) + 32.0;
  return tempF; // Returns temperature in Fahrenheit
}
```

### Audurino Board 2: Mositure Sensor and Water Pump

Board 2 is responsible for monitoring soil moisture levels and controlling the automatic watering system. This board uses an anolog soil moisture sensor, RGB LED common cathode, 12V DC 1 channel relay module, DC 12V Diaphram Pump, and external eight AA 12V Battery Pack, 4 10KΩ Resistors, and Backery Pack that holds 4 AAs. For the demonstration, the soil moisture sensor checks the soil moisture every 30 seconds and sends this information to the Arduino RedBoard, although during normal operation it takes readings every 10 minutes. Based on the moisture reading, the system determines whether watering is needed and activates the proper visual indicator using the RGB LED. After watering is completed, the soil moisture sensor waits 1 minute before taking another moisture reading. For demonstration purposes, the plant is watered for 5 seconds, while under normal operation the watering cycle runs for 10 seconds. The RGB LED common cathode is used to comunicate the state of the system to the user. The LED color indicates the following: Green LED = Soil moisture is at an acceptable level and the plant is sufficiently watered, Blue LED = The system is actively watering the plant using the diaphragm pump, Red LED = The soil moisture sensor has detected dry soil for an extended period of time, indicating the water reservoir is likely empty or low. When dry soil is detected, the Arduino sends a signal to the relay module, which controls power to the 12V diaphragm pump. The relay allows the low-voltage Arduino board to safely control the higher voltage pump system. The pump then delivers water to the plant until the moisture level is restored.

The complete schematic, wiring diagram, and code for Board 2 provide the necessary electrical connections, programming, and documentation for full system assembly, and operation.

[![Board 2 Moisture Schematic](./BAE305_Schematic_Board2_Moisture.drawio.png)](./BAE305_Schematic_Board2_Moisture.drawio.png)
*Figure 2. Circuit schematic for Board 2 showing the soil moisture monitoring system with RGB LED, soil moisture sensor, relay module, diaphragm pump, and battery pack connections.*

[![Board 2 Moisture Wiring Diagram](./Wire_Diagram_Board2_Moisture.png)](./Wire_Diagram_Board2_Moisture.png)
*Figure 3. Physical wiring diagram for Board 2 showing the full component layout and breadboard connections for the soil moisture monitoring and automatic watering system.*

 *Code for Board 2*

```cpp

```

## Test Results Discussion

### Adurino Board 1: Tempature Sensor and Screen

### Audurino Board 2: Mositure Sensor and Water Pump

## Test Results 
