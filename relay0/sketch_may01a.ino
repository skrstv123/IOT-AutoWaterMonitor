int sd=13,led=10;
void setup() {
  // put your setup code here, to run once:
  pinMode(sd,INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}
int onf=0;
void loop() {
  // put your main code here, to run repeatedly:
  int in;
  
  in=digitalRead(sd);
  Serial.println(in);
  if(in){
    if(onf==1)
    onf=0;
    else
    onf=1;
    }
    if(onf)
    digitalWrite(led,HIGH);
    else
    digitalWrite(led,LOW);
    
}
