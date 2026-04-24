int redPin= 5;    //pins in these 
int greenPin = 6;
int  bluePin = 7;

void setup() {
 
  pinMode(redPin,  OUTPUT);              
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}
void  loop() {

  setColor(0,  100, 0); // green test
  delay(1000);
  setColor(0, 0, 100); // blue test
  delay(1000);
}
void setColor(int redValue, int greenValue,  int blueValue) {  //make function to call to set the color
  analogWrite(redPin, redValue);
  analogWrite(greenPin,  greenValue);
  analogWrite(bluePin, blueValue);
}
