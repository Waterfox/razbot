
void motorControl (int r, int g, int b, int a){
  uint16_t M1 = abs(127-r)*2; //Speeds
  uint16_t M2 = abs(127-g)*2;
  uint16_t M3 = abs(127-b)*2;
  uint16_t M4 = abs(127-a)*2;
  
  boolean D1 = r > 127; //Direction 1 is forward, 0 is reverse
  boolean D2 = g > 127;
  boolean D3 = b < 127;
  boolean D4 = a < 127;
  
  if ((M1>0) || (M2>0) || (M3>0) || (M4>0)){
    digitalWrite(A2,HIGH); // If any velocity is not zero, turn off Standby on controllers
    
    //Motor1
    digitalWrite(2,D1);
    analogWrite(3,M1);
    //Motor2
    digitalWrite(4,D2);
    analogWrite(5,M2);   
    //Motor3
    digitalWrite(7,D3);
    analogWrite(6,M3);
    //Motor3
    digitalWrite(8,D4);
    analogWrite(9,M4);
  }
  else {
    digitalWrite(A2,LOW);  //power down controllers
  }
}


void setup(){
  
  //Motor Pins
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(A2,OUTPUT);
  delay(10);
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(A2,LOW);
}

void loop()
{ 
  // read and publish the battery voltage every 1s
  motorControl(254,254,254,254);
  delay(3000);
  motorControl(127,127,127,127);
  delay(500);
  motorControl(1,1,1,1);
  delay(3000);
  motorControl(127,127,127,127);
  delay(500);

}
