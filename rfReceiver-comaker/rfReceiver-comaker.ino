#include <VirtualWire.h>

void setup() {
  vw_set_ptt_inverted(true); // Required for DR3100
  vw_set_rx_pin(12);
  vw_setup(4000); // Bits per sec
  pinMode(3, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(2, OUTPUT);
  vw_rx_start(); // Start the receiver PLL running
}

void loop() {
  digitalWrite(2,1);
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  if (vw_get_message(buf, &buflen)) {// Non-blocking
    if(buf[0]=='1'){
      digitalWrite(3,1); 
      digitalWrite(13,1);       
    } 
  if(buf[0]=='0'){
    digitalWrite(3,0);
    digitalWrite(13,0);
    }
  }
}
