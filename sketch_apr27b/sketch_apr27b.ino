int trig=5;
int echo=0;
int led =12;


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
  Serial.println((String)distance+"cm");
  delay(10);
 
  
/*  int br=0;
  if(distance<=20 && distance>15)
  br=1500;
  else if(distance<=15 && distance>10)
  br=1000;
  else if(distance<=10 && distance>5)
  br=500;
  else if(distance<=5)
  br=200;
  Serial.println("blink rate "+(String)br);
  digitalWrite(led,HIGH);
  delay(br);
  if(br)
  digitalWrite(led,LOW);
  delay(br);*/

}
