const int sensorPin = A0;                                           // sensor at A0
const int dryValue = 437;                                           // what does the sensor read for air
const int wetValue = 101;                                           // what does the sensor read in water

void setup() {
  Serial.begin(9600);                                               // initialize serial communication
}

void loop() {
  int rawValue = analogRead(sensorPin);                             // sensor measurement
  int moisturePercent = map(rawValue, dryValue, wetValue, 0, 100);  // calculate percentage of moisture relative to possible moisture of sensor
  moisturePercent = constrain(moisturePercent, 0, 100);             //make sure that it is a percent and the values don't drift out of that
  
  
  Serial.print("Raw: ");                                            // Print results to serial monitor
  Serial.print(rawValue);
  Serial.print(" | Moisture: ");
  Serial.print(moisturePercent);
  Serial.println("%");
  
  delay(1000);                                                      // Wait 1 second before next reading
}
