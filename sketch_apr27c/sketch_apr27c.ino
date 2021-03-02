int smog = 13;

void setup() {
  // put your setup code here, to run once:
pinMode(smog,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);
 float s = analogRead(smog,HIGH);
 Serial.println("smoke "+(String)s);
 
}
