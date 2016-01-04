// Simulator Light Controller
// Written by:  Nik Martelaro (nikmart@stanford.edu)
// Purpose:     PWM controller for RGBW light strip with analog dimmers

// LED control pins
const int red   = 3;
const int green = 9;
const int blue  = 5;
const int white = 6;

// Analog dimmers
const int redDim   = A0;
const int greenDim = A1;
const int blueDim  = A2;
const int whiteDim = A3;

// LED brightness values
int redVal   = 0;
int blueVal  = 0;
int greenVal = 0;
int whiteVal = 0;


// Cycle through each color to check all are working
void setup() {
  // initialize LED control pins as outputs
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(white, OUTPUT);

  // reset all control pins
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
  digitalWrite(white, LOW);

  // turn each LED on for a built
  int waitTime = 250;
  digitalWrite(red, HIGH);
  delay(waitTime);
  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
  delay(waitTime);
  digitalWrite(green, LOW);
  digitalWrite(blue, HIGH);
  delay(waitTime);
  digitalWrite(blue, LOW);
  digitalWrite(white, HIGH);
  delay(waitTime);
  digitalWrite(white, LOW);

}

// read the analog pins to control brighness
void loop() {
  //red
  redVal = analogRead(redDim);
  redVal = map(redVal, 0, 1024, 0, 255);

  //green
  greenVal = analogRead(greenDim);
  greenVal = map(greenVal, 0, 1024, 0, 255);

  //blue
  blueVal = analogRead(blueDim);
  blueVal = map(blueVal, 0, 1024, 0, 255);

  //white
  whiteVal = analogRead(whiteDim);
  whiteVal = map(whiteVal, 0, 1024, 0, 255);

  // set the vaules
  analogWrite(red, redVal);
  analogWrite(green, greenVal);
  analogWrite(blue, blueVal);
  analogWrite(white, whiteVal);
}
