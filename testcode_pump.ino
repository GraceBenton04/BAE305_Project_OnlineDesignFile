const int pump = 2;

void setup() {
  Serial.begin(9600);           // initialize monitor
  pinMode(pump, OUTPUT);        // pump pin as output
  digitalWrite(pump, LOW);      // pump starts as off
  Serial.println("Type anything to run pump.");
}

void loop() {
  if (Serial.available() > 0) {  //start loop
      Serial.read();

    Serial.println("Pump ON - Running for 10 seconds");
    digitalWrite(pump, HIGH);   // activates relay, closing switch and turning on pump
    delay(10000);               // run for 10,000 milliseconds (10 seconds)

    digitalWrite(pump, LOW);    // turn pump OFF
    Serial.println("Pump OFF.");
    
    //clear extra characters
    while(Serial.available() > 0) Serial.read();
  }
}
