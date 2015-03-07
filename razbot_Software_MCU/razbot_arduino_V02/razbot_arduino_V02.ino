/* PawPi Board INDIGO

D0 RX
D1 TX

--Motor Controller 1
D2 DIR1 PD2
D3 PWM1 PD3
D5 PWM2 PD4
D4 DIR2 PD5
--Motor Controller 2
D6 PWM3 PD6
D7 DIR3 PD7
D8 DIR4 PB0
D9 PWM4 PB1

A2 STDBY PC2

--NeoPixel
A3 NP1 PC3
A1 NP2 PC1

--Servo
D10 S1  PB2
D11 S2  PB2

--ADC
(left-right)
GND  A7  A6  A5  A4  A0
*/

//Control motors
//Control Lights
//Control Servos
//Monitor Battery

#include <ros.h>
#include <std_msgs/ColorRGBA.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Int8.h>
//#include <std_msgs/Int8MultiArray.h>
#include <Adafruit_NeoPixel.h>
//#include <Servo.h> 

ros::NodeHandle  nh;
//ros::NodeHandle_<ArduinoHardware,2,2,80,105> nh;

Adafruit_NeoPixel neoLED = Adafruit_NeoPixel(1, A1, NEO_GRB + NEO_KHZ800);

long publisher_timer=0;
/*
Servo s1;
Servo s2;
int s1_limits[2] = {1,180};
int s2_limits[2] = {1,180};
*/
void c_neoLED( const std_msgs::ColorRGBA& val){
  neoLED.setPixelColor(0,val.r, val.g, val.b);
  delay(10);
  neoLED.show(); 
}


void motorControl (const std_msgs::ColorRGBA& motorVal){
  uint16_t M1 = abs(127-motorVal.r)*2; //Speeds
  uint16_t M2 = abs(127-motorVal.g)*2;
  uint16_t M3 = abs(127-motorVal.b)*2;
  uint16_t M4 = abs(127-motorVal.a)*2;
  
  boolean D1 = motorVal.r > 127; //Direction 1 is forward, 0 is reverse
  boolean D2 = motorVal.g > 127;
  boolean D3 = motorVal.b < 127;
  boolean D4 = motorVal.a < 127;
  
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
//-------------Servos----------------- DONT USE THIS CRAP SERVO LIB, does SW interrupts
/*
void servo1( const std_msgs::Int8& val){
  if (val.data == 0){
    s1.detach();
  }
  else
  {
    if (val.data >= s1_limits[0] &&  val.data <= s1_limits[1]){
      s1.attach(10);
      s1.write(val.data);
    }
  }
}

void servo2( const std_msgs::Int8& val){
  if (val.data == 0){
    s2.detach();
  }
  else
  {
    if (val.data >= s2_limits[0] &&  val.data <= s2_limits[1]){
      s2.attach(11);
      s2.write(val.data);
    }
  }
}
*/

  
ros::Subscriber<std_msgs::ColorRGBA> sub_neoLED("piBot_color", &c_neoLED );
ros::Subscriber<std_msgs::ColorRGBA> sub_motorControl("piBot_motors", &motorControl );
//ros::Subscriber<std_msgs::Int8> sub_servo1("piBot_servo1", &servo1 );
//ros::Subscriber<std_msgs::Int8> sub_servo2("piBot_servo2", &servo2 );
std_msgs::Float32 batVolt_msg;
ros::Publisher pub_batVoltage("piBot_bat", &batVolt_msg);

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
  
  //motorControl.layout.dim_length = 1;
  //motorControl.data_length = 4;
  
  nh.initNode();
  nh.subscribe(sub_neoLED);
  nh.subscribe(sub_motorControl);
  //nh.subscribe(sub_servo1);
  //nh.subscribe(sub_servo2);
  nh.advertise(pub_batVoltage);
  neoLED.begin();
  delay(10);
  neoLED.setPixelColor(0,20,5,100);
  delay(10);
  neoLED.show(); 
  
}

void loop()
{ 
  // read and publish the battery voltage every 1s
  if (millis() > publisher_timer) {
    batVolt_msg.data = analogRead(A7)*12.6/1024.0;
    pub_batVoltage.publish(&batVolt_msg);
    publisher_timer = millis() + 1000;
  }
  
  nh.spinOnce();
  delay(1);
}



