#include "debugConsole.hpp"
#include "SPI_Master.hpp"

void setup() {
  // initialize debug console
  debugConsole.init(DEBUG_CONSOLE_MODE_UART_AND_SPI);
  //debugConsole.init(DEBUG_CONSOLE_MODE_UART);
  //debugConsole.init(DEBUG_CONSOLE_MODE_SPI);
}

const char* testConstMessage = "test const message";
String testArduinoString = "test Arduino String";
char c;
int integer;

void loop() {
  //print test messages
  debugConsole.print(F("test "));
  debugConsole.println("messages:");
  debugConsole.println(34.35);
  debugConsole.println(-34.35);
  debugConsole.println(0.123456789);
  Serial.println(0.123456789);
  debugConsole.println(0.0012);
  debugConsole.print(-0.0012);
  debugConsole.println("");
  debugConsole.println(-0.0012);
  debugConsole.println(16777216.0625);
  debugConsole.println(23);
  debugConsole.println(123456789123456789.123456789123456789); //should trigger overflow
  debugConsole.println(testArduinoString);
  debugConsole.print(testArduinoString);
  debugConsole.println("");
  debugConsole.println(testConstMessage);
  debugConsole.print(testConstMessage);
  debugConsole.println();
  debugConsole.println(debugConsole.available()); 
  debugConsole.println(debugConsole.readString()); //does not erase input buffer, should not be used for triggering events !!
  //debugConsole.println(debugConsole.receivedString("++a")); //erases input buffer, can be used to trigger events
  debugConsole.readParsedString(c, integer);
  debugConsole.println(c);
  debugConsole.println(integer);
  delay(5000);

}
