#include <VirtualWire.h>

char *controller;

int comaker_pin = 11;
int comaker = 0;

void setup() {
  pinMode(comaker_pin,INPUT);
  pinMode(13,OUTPUT);
  vw_set_ptt_inverted(true); //
  vw_set_tx_pin(12);
  vw_setup(4000);// speed of data transfer Kbps
}

void loop(){
  comaker = digitalRead(comaker_pin);
  
  if(comaker == 1){
    controller="1" ;
    vw_send((uint8_t *)controller, strlen(controller));
    vw_wait_tx(); // Wait until the whole message is gone
    digitalWrite(13,1);
  }

  if(comaker == 0){
    controller="0" ;
    vw_send((uint8_t *)controller, strlen(controller));
    vw_wait_tx(); // Wait until the whole message is gone
    digitalWrite(13,0);
  }
}

