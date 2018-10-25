void setup() {
 Serial.begin(9600);
}

void loop() {
  Serial.print("J1= ");
  Serial.print(sensorRead(J1));
  Serial.print("          J2= ");
  Serial.print(sensorRead(J2));
  Serial.print("          US= ");
  Serial.println(ultrasoundRead(J3));
  delay(200);

}
