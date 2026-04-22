# BAE305_Project_OnlineDesignFile
Colliding Planets Group
Plant Montoring System Group Project 
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

Board 1 is responsible for temperature monitoring and user interaction. This board includes a 10KΩ thermistor temperature sensor, a 10KΩ resistor, 16x2 LCD display, I2C Serial Interface Adapter Module, three pushbuttons, four AA Backery Pack and a piezo buzzer. Using the three pushbuttons the user will input the ideal tempature rang for thier plant. Pushbutton 2 is up by 0.5 degrees Farnhit, pushbutton 3 is down by 0.5 degrees farnhight, and pushbutton 1 uploads imputed temputure range to adurino board. The thermistor continuously measures ambient temperature and sends analog input data to the Arduino RedBoard. The Arduino processes this data and displays both the current temperature readings and inputed range. The piezo buzzer provides audible alerts when temperature goes outside of inputed range. This board serves as the main user interface for the plant monitoring system, allowing real-time monitoring of plant conditions while providing feedback through both visual and audible outputs.

The complete schematic and wiring diagram for Board 1 provide the necessary documentation for full system assembly and technician implementation.

[![Board 1 Temperature Schematic](./BAE305_Schematic_Board1_Tempature.drawio.png)](./BAE305_Schematic_Board1_Tempature.drawio.png)
*Figure 1. Circuit schematic for Board 1 showing the temperature monitoring system with LCD display, pushbuttons, piezo buzzer, thermistor, and resistor connections.*

[![Board 1 Temperature Wiring Diagram](./Wire_Diagram_Board1_Temp.png)](./Wire_Diagram_Board1_Temp.png)
*Figure 4. Physical wiring diagram for Board 1 showing the full component layout and breadboard connections for the temperature monitoring system with LCD display, pushbuttons, piezo buzzer, and thermistor.*

### Audurino Board 2: Mositure Sensor and Water Pump

demistration 30 sec betweeen rreading and normally every 10 mins and and waits 1 min after watering in done to start reading again. watering happens for 5 seconds for demontration but normally is 10 seconds.

Board 2 is responsible for monitoring soil moisture levels and controlling the automatic watering system. This board uses an Anolog Soil Moisture Sensor, RGB LED Common Cathode, 12VDC 1 CHANNEL RELAY Module, DC 12V Diaphram Pump, and external eight AA 12V Battery Pack, 4 10KΩ Resistors, and four AA Backery Pack.

The soil moisture sensor continuously reads the moisture content of the soil and sends this information to the Arduino RedBoard. Based on the moisture reading, the system determines whether watering is needed and activates the proper visual indicator using the RGB LED.

The LED color system is used as follows:

Green LED = Soil moisture is at an acceptable level and the plant is sufficiently watered
Yellow LED = The system is actively watering the plant using the diaphragm pump
Red LED = The soil moisture sensor has detected dry soil for an extended period of time, indicating the water reservoir is likely empty or low

When dry soil is detected, the Arduino sends a signal to the relay module, which controls power to the 12V diaphragm pump. The relay allows the low-voltage Arduino board to safely control the higher voltage pump system. The pump then delivers water to the plant until the desired moisture level is restored.

The full schematic and wiring diagram for Board 1 provide complete electrical connections for assembly and troubleshooting.

[![Board 2 Moisture Schematic](./BAE305_Schematic_Board2_Moisture.drawio.png)](./BAE305_Schematic_Board2_Moisture.drawio.png)
*Figure 2. Circuit schematic for Board 2 showing the soil moisture monitoring system with RGB LED, soil moisture sensor, relay module, diaphragm pump, and battery pack connections.*

[![Board 2 Moisture Wiring Diagram](./Wire_Diagram_Board2_Moisture.png)](./Wire_Diagram_Board2_Moisture.png)
*Figure 3. Physical wiring diagram for Board 2 showing the full component layout and breadboard connections for the soil moisture monitoring and automatic watering system.*

### Physical Setup 

## Test Results Discussion

### Adurino Board 1: Tempature Sensor and Screen

### Audurino Board 2: Mositure Sensor and Water Pump

## Test Results 
