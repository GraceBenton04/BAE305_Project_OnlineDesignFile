//********************************************************************************************
const int sensorPin = A0;                             // reads sensor at A0
const int dryValue = 437;                             // reference value, what does the sensor read for air
const int wetValue = 101;                             //reference value, what does the sensor read in water
const int moistureThresh = 20;      //above percentages read as "moist", below read as "dry"
int isWet = 1;                                    //variable that changes from 1 (wet) or 0 (dry) depending on reading

const int redPin= 5;                  //red is connected to pin 5
const int greenPin = 6;               //green is connected to pin 6
const int  bluePin = 7;               //blue is connected to pin 7

const int pump = 2;                   //pump is connected to pin 2


void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);                                 // initialize serial communication

  pinMode(redPin,  OUTPUT);                           //define the pins connected to the color LED as outputs           
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  pinMode(pump, OUTPUT);        // set the pump pin as an output
  digitalWrite(pump, LOW);      // pump starts in the OFF position

}

//***********************************************************************************************

void loop() {

  
    setColor(0,  100, 0); // turn LED green
  

//measure soil moisture

 int rawValue = analogRead(sensorPin);                             // sensor measurement
  int moisturePercent = map(rawValue, dryValue, wetValue, 0, 100);  // calculate percentage of moisture relative to possible moisture of sensor
  moisturePercent = constrain(moisturePercent, 0, 100);             //make sure that it is a percent and the values don't drift out of that

//debugging lines for moisture sensor printed in serial monitor

 Serial.print("Raw: ");                                            // Print results to serial monitor
  Serial.print(rawValue);
  Serial.print(" | Moisture: ");
  Serial.print(moisturePercent);
  Serial.println("%");


//compare soil moisture to acceptable values
 
if (moisturePercent < moistureThresh)
  {
    isWet = 0;                            //evaluate soil to be DRY
  }
  else
  {
    isWet = 1;                             //evaluate soil to be WET
  }

 Serial.print(" | Status: ");
  Serial.print(isWet);

   while (isWet == 0)
   {
    //turn LED BLUE
    setColor(0, 0, 200);                    // make LED blue to signify watering happening
   
    //trigger pump for short time
    digitalWrite(pump, HIGH);   // turn pump ON
    Serial.println("Pump ON");  //debugging in serial monitor
    
    delay(10000);               // run for 10 seconds (10,000 milliseconds)
    
    digitalWrite(pump, LOW);    // turn pump OFF
    Serial.println("Pump OFF");  //debugging in serial monitor
    
    //wait 1 minute for water to seep into soil

    delay(60000UL);
    //delay(30000UL); debug line, 30 seconds
    
    //measure soil moisture

    int rawValue = analogRead(sensorPin);                             // sensor measurement
    int moisturePercent = map(rawValue, dryValue, wetValue, 0, 100);  // calculate percentage of moisture relative to possible moisture of sensor
    moisturePercent = constrain(moisturePercent, 0, 100);             //make sure that it is a percent and the values don't drift out of that
  
    //debugging lines for moisture sensor printed in serial monitor

    Serial.print("Raw: ");                                            // Print results to serial monitor
    Serial.print(rawValue);
    Serial.print(" | Moisture: ");
    Serial.print(moisturePercent);
    Serial.println("%");
   
    //compare soil moisture to acceptable values
    if (moisturePercent < moistureThresh)
    {
    isWet = 0;                            //evaluate soil to be DRY
    }
    else
    {
    isWet = 1;                             //evaluate soil to be WET
    }
  }

setColor(0,  100, 0); // turn LED green again
//wait for 10 minutes time before loop repeats
  delay(600000UL);
  //delay(30000UL); debug line for testing faster

}
//setColor function to change led color
void setColor(int redValue, int greenValue,  int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin,  greenValue);
  analogWrite(bluePin, blueValue);
}
