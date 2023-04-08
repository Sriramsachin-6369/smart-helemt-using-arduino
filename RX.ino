#include <RH_ASK.h>
#include <SPI.h>
#define motor_relay 3
RH_ASK driver;
const int led = 2;

char receive[32];
int output_state = 0;
void setup()
{
  Serial.begin(9600);
  driver.init();
  pinMode(led, OUTPUT);
  pinMode(motor_relay, OUTPUT);
}

void loop()
{
  uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
  uint8_t buflen = sizeof(buf);

  if (driver.recv(buf, &buflen))
  {
    memset(receive, 0, sizeof(receive));
    for (int i = 0; i < buflen; i++) {
      receive[i] = buf[i];
    }
    if (strcmp(receive, "Switch") == 0) {
      output_state = 1;
      digitalWrite(led, output_state);
      digitalWrite(motor_relay, output_state);
      Serial.println("helmet on");
    }
    else if (strcmp(receive, "druken") == 0) {
      output_state = 0;
      digitalWrite(led, output_state);
      digitalWrite(motor_relay, output_state);
            
      Serial.println("mq3");

    }
    else if (strcmp(receive, "put") == 0) {
      output_state = 0;
      digitalWrite(led, output_state);
      digitalWrite(motor_relay, output_state);
      Serial.println("helmet off");

      }
    else{
       Serial.println("no data recived");
    }
  }

}
