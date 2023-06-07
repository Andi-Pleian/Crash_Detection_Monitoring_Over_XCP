const int xpin = A1;       // x-axis of the accelerometer
const int ypin = A2;       // y-axis
const int zpin = A3;       // z-axis (only on 3-axis models)

void setup() {
  // initialize the serial communications:
  Serial.begin(9600);
}

void loop() {
  // print the sensor values:
  int xvalue = analogRead(xpin);
  int x = map(xvalue, 267, 400, -100, 100);
  Serial.print(analogRead(xpin));
  // print a tab between values:
  Serial.print("\t");
  Serial.print(analogRead(ypin));
  // print a tab between values:
  Serial.print("\t");
  Serial.print(analogRead(zpin));
  Serial.println();
  // delay before next reading:
  delay(100);
}
