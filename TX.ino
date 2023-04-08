#include <RH_ASK.h>
#include <SPI.h>
#define sensorDigital 5
#define  led 4

const int switch_in = 2;
//int state = 0;
char *msg;
RH_ASK driver;

void setup()
{
  Serial.begin(9600);
  driver.init();
 
  pinMode(switch_in, INPUT);
  pinMode(sensorDigital,INPUT);
  pinMode(led,OUTPUT);
 
 


}

void loop()
{
    digitalWrite(switch_in ,HIGH);
  bool digital = digitalRead(sensorDigital);
  if (digitalRead(switch_in) == LOW && digital == 1 ) {
    digitalWrite(led,HIGH);
    msg = "Switch";
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(200);
    //state = 0;
    Serial.println("helemet on");
  }
  else if (digitalRead(switch_in) == LOW && digital ==0){
    digitalWrite(led,HIGH);
    msg = "druken";
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(200);

    //state = 1;
    Serial.println("mq3");
  }
  else if(digitalRead(switch_in) == HIGH && digital == 1 ){
    digitalWrite(led,LOW);
    msg = "put";
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(200);

    //state = 1;
    Serial.println("no data");
  }
  else {
     digitalWrite(led,LOW);
   Serial.println("zero"); 
  }
  delay(300);

}
