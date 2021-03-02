#define PIN 11

void setup() {
pinMode(PIN,OUTPUT);
Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  digitalWrite(PIN,LOW);
  delay(2000);
  Serial.println("relay is on");
  digitalWrite(PIN,HIGH);
  delay(2000);
  Serial.println("relay is off");
  // put your main code here, to run repeatedly:

}
