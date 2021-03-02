#define PIN 2

void setup() {
  // put your setup code here, to run once:
  pinMode(PIN,OUTPUT);
  Serial.begin(9600);
  
  
}

void loop() {
  // put your main code here, to run repeatedly
  int t=0,c=1;
  while(1){
    if(t<2500&&c)
    t+=500;
    else{
    t-=500;
    c=0;
    if(t<1000)
    c=1;
    }
  int tt=1;
  while(tt>=0){ 
    Serial.println(t); 
  digitalWrite(PIN,HIGH);
  delay(t);
  digitalWrite(PIN,LOW);
  delay(t);
  tt--;
  }
  }
}
