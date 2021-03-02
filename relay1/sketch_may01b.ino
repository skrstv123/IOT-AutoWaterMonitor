#define sm A1
#define LED 10

void setup() {
  // put your setup code here, to run once:
  pinMode(sm,INPUT);
  pinMode(LED,OUTPUT);
  Serial.begin(9600);

}
int in;
void loop() {
  float sc;
  // put your main code here, to run repeatedly:
sc=analogRead(sm);
Serial.println(sc);

digitalWrite(LED,HIGH);
delay(5000);
}
