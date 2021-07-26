#include <VirtualWire.h>

void setup() {
  Serial.begin(9600);
   pinMode(13,INPUT);                  //startbutton
   //pinMode(52,INPUT_PULLUP);                  //startbutton
  vw_setup(2000);
}
 
void loop() {
  int valeurs[4];
//  valeurs[0] = map(analogRead(0),0,1023,-15,15);           //y軸搖桿
//  valeurs[1] = map(analogRead(1),0,1023,-15,15);          //x軸搖桿
 valeurs[0] = map(analogRead(0), 0, 1023, -15, 15);
  valeurs[1] = map(analogRead(1), 0, 1023, -15, 15);
 valeurs[2] = analogRead(2);         //fuel
 valeurs[3] = digitalRead(13);       //button
Serial.print(valeurs[0] );
  Serial.print("  " );
Serial.print(valeurs[1] );
  Serial.print("  " );
Serial.print(valeurs[2] );
  Serial.print("  " );
Serial.println(valeurs[3]  );

   
  vw_send((byte *) &valeurs, sizeof(valeurs)); 
  vw_wait_tx(); 
  
  delay(50);
}
