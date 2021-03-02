int trig=11;
int echo=12;
int led =13;

void setup() {
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  

}

void loop() {
  long distance,duration;
  digitalWrite(trig,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig,LOW);
  duration = pulseIn(echo,HIGH);
  distance = (duration/2)/29.1;
  delay(10);
  if (distance<=10)
  digitalWrite(led,HIGH);
  else
  digitalWrite(led,LOW);
  Serial.println((String)distance+"cm");

}
