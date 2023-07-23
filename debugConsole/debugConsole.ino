#include "debugConsole.hpp"

void setup() {
  // put your setup code here, to run once:
  debugConsole.init(DEBUG_CONSOLE_MODE_SPI);
}

void loop() {
  // put your main code here, to run repeatedly:
  debugConsole.print(F("test "));
  debugConsole.println("1");
  debugConsole.println(34.35);
  debugConsole.print(23);
}
