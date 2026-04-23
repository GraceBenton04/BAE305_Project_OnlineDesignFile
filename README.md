# BAE305_Project_OnlineDesignFile

Colliding Planets Group

Plant Montoring System Project 

BAE 305 Spring 2026

Members:

Grace Benton, Evie Hamliton, Cami Morgan, Allison Lundy, and Ada Lasley

## Summary

## Materials 
- 571 $in^2$ of Walnut Wood
- 11 Torx Head Screws
- 2 SPARKFUN REDBOARDS
- 1 Breadboard
- 6 $in$ of 3/4 $in$ wide Velcro Tape
- 2  four AA Backery Pack
- 1 eight AA 12V Battery Holder
- Clear 3/16 $in$ Inner Diameter Tubing
- 1/4 $in$ Emitter Tubing
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

The plant monitoring system is designed using two separate Arduino-based control boards to independently manage temperature monitoring and soil moisture monitoring with a 
container to hold the water. All Compents are togeahter on base and held in place with velco tape. The system will sit next to the plant it will monitor with the emitter 
tubing wraping around the base of the plant and the soil moistor sensor in the pot.

### Base
Below is the construction process for the base of the plant monitoring system, designed to support all additional system components.

[![PDF Preview](./BAE305_Project_Base_Drawing_Image.png)](./BAE305_Project_Drawing.pdf)
*Click the image above to view the full PDF drawing.*

The main base was made from a walnut board that was first planed to a thickness of 7/8 inch. It was then cut to 13 inches in length using the chop saw. One edge was jointed 
to create a straight reference edge, and the board was then cut on the table saw to a final width of 8.5 inches.

The remaining walnut board was then planed to a thickness of 3/4 inch. From this material, two pieces were cut to 7.5 inches in length using the chop saw. Both pieces were 
jointed on one edge and then cut on the table saw, with one piece finished to 8.5 inches wide and the other finished to 5 inches wide.

Next, another board section was cut to 8.5 inches in length and then ripped into three strips, each measuring 1.5 inches wide. Two of these strips were then cut down to 6.5 
inches in length.

Once all pieces were prepared, they were arranged according to the base design drawing. The assembly was secured using Torx head screws. Two screws were used per piece from 
the bottom for structural support, and one additional screw was used to secure the T-shaped support section together. Then, a hole was drilled with a hand drill and 1/4 $in$ 
bit in the corner of the lid 1 1/4 $in$ from both sides. 

### Adurino Board 1: Tempature Sensor and Screen

Board 1 is responsible for temperature monitoring and user interaction. This board includes a 10KΩ thermistor temperature sensor, a 10KΩ resistor, 16x2 LCD display, I2C 
Serial Interface Adapter Module, three pushbuttons, Backery Pack that holds 4 AAs and a piezo buzzer.

The complete schematic, wiring diagram, and code for Board 1 provide all electrical connections and programming necessary for proper assembly, and system operation.

[![Board 1 Temperature Schematic](./BAE305_Schematic_Board1_Tempature.drawio.png)](./BAE305_Schematic_Board1_Tempature.drawio.png)
*Figure 1. Circuit schematic for Board 1 showing the temperature monitoring system with LCD display, pushbuttons, piezo buzzer, thermistor, and resistor connections.*

[![Board 1 Temperature Wiring Diagram](./Wire_Diagram_Board1_Temp.png)](./Wire_Diagram_Board1_Temp.png)
*Figure 4. Physical wiring diagram for Board 1 showing the full component layout and breadboard connections for the temperature monitoring system with LCD display, 
pushbuttons, piezo buzzer, and thermistor.*

*Board 1 Arduino Code – Temperature Monitoring System*
[Click here to view the code file](./BAE305_Board1_Tempature_Code)


### Audurino Board 2: Mositure Sensor and Water Pump

Board 2 is responsible for monitoring soil moisture levels and controlling the automatic watering system. This board uses an anolog soil moisture sensor, RGB LED common 
cathode, 12V DC 1 channel relay module, DC 12V Diaphram Pump, and external eight AA 12V Battery Pack, 4 10KΩ Resistors, and Backery Pack that holds 4 AAs.

The complete schematic, wiring diagram, and code for Board 2 provide the necessary electrical connections, programming, and documentation for full system assembly, and 
operation.

[![Board 2 Moisture Schematic](./BAE305_Schematic_Board2_Moisture.drawio.png)](./BAE305_Schematic_Board2_Moisture.drawio.png)
*Figure 2. Circuit schematic for Board 2 showing the soil moisture monitoring system with RGB LED, soil moisture sensor, relay module, diaphragm pump, and battery pack 
connections.*

[![Board 2 Moisture Wiring Diagram](./Wire_Diagram_Board2_Moisture.png)](./Wire_Diagram_Board2_Moisture.png)
*Figure 3. Physical wiring diagram for Board 2 showing the full component layout and breadboard connections for the soil moisture monitoring and automatic watering system.*

 *Board 2 Arduino Code – Moisture Monitoring and Watering System*
[Click here to view the code file](./incertname of file here)

## Design Decision Discussion

using I2C communication, which reduces wiring complexity by only requiring four connections: VCC, GND, SDA, and SCL.

The self-watering plant monitoring system was designed to meet all required project objectives while remaining simple to assemble, reliable for long-term use, and practical 
for everyday indoor plant care.The system was divided into two separate Arduino-based control boards: one dedicated to watering and soil moisture monitoring, and the other 
dedicated to temperature monitoring and user interaction. This separation improved organization, simplified troubleshooting, and allowed each subsystem to operate 
independently without interfering with the other.

### Adurino Board 1: Tempature Sensor and Screen

Using the three pushbuttons the user will input the ideal tempature rang 
for thier plant. Pushbutton 2 is up by 0.5 degrees Farnhit, pushbutton 3 is down by 0.5 degrees farnhight, and pushbutton 1 uploads imputed temputure range to adurino board. 
The thermistor continuously measures ambient temperature and sends analog input data to the Arduino RedBoard. The Arduino processes this data and displays both the current 
temperature readings and inputed range. The piezo buzzer provides audible alerts when temperature goes outside of inputed range. This board serves as the main user interface 
for the plant monitoring system, allowing real-time monitoring of plant conditions while providing feedback through both visual and audible outputs.

### Audurino Board 2: Mositure Sensor and Water Pump


Water Delivery Method:
For the watering system, a 12V DC self-priming diaphragm pump was selected as the water delivery method. The Arduino sends commands to the pump to activate watering when the 
soil moisture sensor detects dry soil conditions. This pump was chosen because it was easily obtainable, compatible with the Arduino-controlled relay system, and capable of 
providing enough pressure to move water through the tubing system to the plant. It also provided the simplest and most reliable method for controlled water delivery.

Water Tank:
A 2.5-liter sealed storage container was selected as the water tank. The team wanted a container that could safely hold enough water for approximately one week of 
watering while minimizing the risk of water spilling near electrical components. A sealed container with a removable lid helped reduce the risk of water exposure to the 
electronics while still allowing tubing access through a drilled opening in the lid. Because the container is plastic, modifying it for tubing installation was simple. The 
tank can also be easily removed from the system for refilling without disturbing the electronics, improving both safety and user convenience.

Irrigation Tubing System:
Emitter tubing was selected to evenly distribute water throughout the plant pot. A flexible 1/4-inch emitter tube with 6-inch hole spacing allows water to be dispersed around 
the plant rather than concentrated in one location. This improves watering consistency and helps provide more accurate soil moisture sensor readings across the pot. Flexible 
tubing also allows the system to adapt to different pot sizes and plant types. Clear 3/16-inch inner diameter tubing was selected between the tank and the pump because it 
matched the required pump connection size, was flexible for routing, and allowed visual confirmation that water was flowing through the system.

Soil Moisture Sensor:
An analog soil moisture sensor module was selected because it was highly compatible with the Arduino RedBoard and operated on the same voltage range as the Arduino outputs. 
Analog readings also allowed the team to create threshold values for dry, moist, and watered soil conditions, improving system control and watering accuracy.

User Status Indicators:
An RGB common cathode LED was selected to communicate system status to the user. The team wanted the user to quickly understand whether the plant was properly watered, 
actively being watered, or if the system detected a problem such as a low water tank.

The LED color indicators were designed as follows:

Green = Soil moisture is at an acceptable level
Yellow = The system is actively watering the plant
Red = Dry soil has been detected for an extended period of time, indicating the water reservoir is likely empty or low

Using one RGB LED allowed all three colors to be displayed using a single component instead of wiring three separate LEDs, reducing wiring complexity and improving overall design simplicity.

Extra Power Supply:
A 12V battery pack was selected because the diaphragm pump required 12V power for proper operation. This allowed the pump to operate independently from the Arduino’s lower voltage system while still being controlled through the circuit.

System Operation and Control Decisions:

*Note : Add explanation for why the relay module was selected and how it protects the Arduino while controlling the 12V pump.*

### Base

## Test Results Discussion

 *This is a note get ride of it when section is complete* 
 *here is what the rubric says this section is: Could another test engineer replicate your tests? All test equipment specified (model numbers) and procedures fully described. 
 In this section can each of you say how you tested and debuged the code to get the final working code with the system. Ada for yours maybe more detail or hwo you know the 
 water pump was working?*
 
### Adurino Board 1: Tempature Sensor and Screen


### Audurino Board 2: Mositure Sensor and Water Pump


## Test Results 
