#include "debugConsole.hpp"

void setup() {
  // initialize debug console
  debugConsole.init(DEBUG_CONSOLE_MODE_UART_AND_SPI);
  //debugConsole.init(DEBUG_CONSOLE_MODE_UART);
  //debugConsole.init(DEBUG_CONSOLE_MODE_SPI);
}

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
  delay(5000);
}
