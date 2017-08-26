/*
 * Simple Arduino test code to control an Icstation serial relay board
 * via the on board serial pin (NOT the Prolific USB/Serial port) with
 * an Arduino. Tested with a ICSE013A 2 relay board and an Arduino UNO.
 * Wiring is as follows:
 *  ICSE013A Serial GND - Arduino GND
 *  ICSE013A Serial 5V - Arduino 5V
 *  ICSE013A Serial TX - Arduino RX/Digital pin 0
 *  ICSE013A Serial RX - Arduino TX/Digital pin 1
 *  
 *  Should also work with the ICSE012A (4-Relays) and ICSE014A (8-Relays)
 *  and other Arduinos. For other Arduino serial port change code and wiring
 *  accordingly, always connecting RX to TX and vice-versa.
 *  
 *  (c) 2017 fabio.rossetti@gmail.com
 */

void setup() {
//setup internal serial to 9600,8,n,1
Serial.begin(9600); 
Serial.write(80); // Hex 50
delay(1000);
int a = 0;
a = Serial.read();

//board id, decimal 173 for the 2 relay ICSE013A board

// do something with the id, e.g.:
//char buf[10];
//sprintf(buf, "Model code %d", a);
//Serial.write(buf);
//delay(1000);

Serial.write(81); // make the board operative, hex 51
delay(1000);
}

void loop() {
  
//loop continuosly other the four possible states of the 2 relay board

Serial.write(1); //first relay on second off, binary 01
delay(1000);
Serial.write(2);  //first relay off second on, binary 10
delay(1000);
Serial.write(3); //both relays on, binary 11
delay(1000);
Serial.write(0); //both relays off, binary 10
delay(1000);
}
