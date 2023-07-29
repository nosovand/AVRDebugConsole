#include "HardwareSerial.h"
#include "debugConsole.hpp"
#include "SPI_Master.hpp"

DebugConsole debugConsole; 

DebugConsole::DebugConsole(/* args */)
{
}

DebugConsole::~DebugConsole()
{
}

void DebugConsole::init(uint8_t mode, long serialBaud)
{
    /**
     * @brief Initialize the debug console
     * @param mode: DEBUG_CONSOLE_MODE_SPI, DEBUG_CONSOLE_MODE_UART, DEBUG_CONSOLE_MODE_UART_AND_SPI
     * @param serialBaud: Baud rate for UART
     * @return None
    */
    debugConsoleMode = mode;
    if (mode == DEBUG_CONSOLE_MODE_SPI)
    {
        SPIMasterInit();
    }
    else if (mode == DEBUG_CONSOLE_MODE_UART)
    {
        Serial.begin(serialBaud);
    }
    else if (mode == DEBUG_CONSOLE_MODE_UART_AND_SPI)
    {
        Serial.begin(serialBaud);
        SPIMasterInit();
    }
}

void DebugConsole::print(char *message)
{
    /**
     * @brief Print a message to the debug console
     * @param message: Message to be printed
     * @return None
    */
    if (debugConsoleMode == DEBUG_CONSOLE_MODE_SPI)
    {
        SPITransferMessage(message);
    }
    else if (debugConsoleMode == DEBUG_CONSOLE_MODE_UART)
    {
        Serial.print(message);
    }
    else if (debugConsoleMode == DEBUG_CONSOLE_MODE_UART_AND_SPI)
    {
        SPITransferMessage(message);
        Serial.print(message);
    }
}

void DebugConsole::println(char *message)
{
    /**
     * @brief Print a message to the debug console and add a new line
     * @param message: Message to be printed
     * @return None
    */
    if (debugConsoleMode == DEBUG_CONSOLE_MODE_SPI)
    {
        SPITransferMessageln(message);
    }
    else if (debugConsoleMode == DEBUG_CONSOLE_MODE_UART)
    {
        Serial.println(message);
    }
    else if (debugConsoleMode == DEBUG_CONSOLE_MODE_UART_AND_SPI)
    {
        Serial.println(message);
        Serial.flush();
        SPITransferMessageln(message);
    }
}

void DebugConsole::print(const char *message){
    /**
     * @brief Print a message to the debug console
     * @param message: Message to be printed
     * @return None
    */
    if (debugConsoleMode == DEBUG_CONSOLE_MODE_SPI)
    {
        SPITransferMessage(message);
    }
    else if (debugConsoleMode == DEBUG_CONSOLE_MODE_UART)
    {
        Serial.print(message);
    }
    else if (debugConsoleMode == DEBUG_CONSOLE_MODE_UART_AND_SPI)
    {
        SPITransferMessage(message);
        Serial.print(message);
    }
}

void DebugConsole::println(const char *message)
{
    /**
     * @brief Print a message to the debug console and add a new line
     * @param message: Message to be printed
     * @return None
    */
    if (debugConsoleMode == DEBUG_CONSOLE_MODE_SPI)
    {
        SPITransferMessageln(message);
    }
    else if (debugConsoleMode == DEBUG_CONSOLE_MODE_UART)
    {
        Serial.println(message);
    }
    else if (debugConsoleMode == DEBUG_CONSOLE_MODE_UART_AND_SPI)
    {
        Serial.println(message);
        Serial.flush();
        SPITransferMessageln(message);
    }
}

void DebugConsole::print(String& message){
      /**
     * @brief Print a message to the debug console
     * @param message: Message to be printed
     * @return None
    */
    if (debugConsoleMode == DEBUG_CONSOLE_MODE_SPI)
    {
        SPITransferMessage(message);
    }
    else if (debugConsoleMode == DEBUG_CONSOLE_MODE_UART)
    {
        Serial.print(message);
    }
    else if (debugConsoleMode == DEBUG_CONSOLE_MODE_UART_AND_SPI)
    {
        SPITransferMessage(message);
        Serial.print(message);
    }
}

void DebugConsole::println(String& message)
{
    /**
     * @brief Print a message to the debug console and add a new line
     * @param message: Message to be printed
     * @return None
    */
    if (debugConsoleMode == DEBUG_CONSOLE_MODE_SPI)
    {
        SPITransferMessageln(message);
    }
    else if (debugConsoleMode == DEBUG_CONSOLE_MODE_UART)
    {
        Serial.println(message);
    }
    else if (debugConsoleMode == DEBUG_CONSOLE_MODE_UART_AND_SPI)
    {
        Serial.println(message);
        Serial.flush();
        SPITransferMessageln(message);
    }
}

void DebugConsole::print(double message)
{
    /**
     * @brief Print a double to the debug console
     * @param message: Double to be printed
     * @return None
    */
    if (debugConsoleMode == DEBUG_CONSOLE_MODE_SPI)
    {
        SPITransferMessage(message);
    }
    else if (debugConsoleMode == DEBUG_CONSOLE_MODE_UART)
    {
        Serial.print(message);
    }
    else if (debugConsoleMode == DEBUG_CONSOLE_MODE_UART_AND_SPI)
    {
        SPITransferMessage(message);
        Serial.print(message);
    }
}

void DebugConsole::println(double message)
{
    /**
     * @brief Print a double to the debug console and add a new line
     * @param message: Double to be printed
     * @return None
    */
    if (debugConsoleMode == DEBUG_CONSOLE_MODE_SPI)
    {
        SPITransferMessageln(message);
    }
    else if (debugConsoleMode == DEBUG_CONSOLE_MODE_UART)
    {
        Serial.println(message);
    }
    else if (debugConsoleMode == DEBUG_CONSOLE_MODE_UART_AND_SPI)
    {
        Serial.println(message);
        Serial.flush();
        SPITransferMessageln(message);
    }
}

void DebugConsole::print(const __FlashStringHelper *message)
{
    /**
     * @brief Print a message to the debug console
     * @param message: Message to be printed
     * @return None
    */
    if (debugConsoleMode == DEBUG_CONSOLE_MODE_SPI)
    {
        SPITransferMessage(message);
    }
    else if (debugConsoleMode == DEBUG_CONSOLE_MODE_UART)
    {
        Serial.print(message);
    }
    else if (debugConsoleMode == DEBUG_CONSOLE_MODE_UART_AND_SPI)
    {
        Serial.print(message);
        Serial.flush();
        SPITransferMessage(message);
    }
}

void DebugConsole::println(const __FlashStringHelper *message)
{
    /**
     * @brief Print a message to the debug console and add a new line
     * @param message: Message to be printed
     * @return None
    */
    if (debugConsoleMode == DEBUG_CONSOLE_MODE_SPI)
    {
        SPITransferMessageln(message);
    }
    else if (debugConsoleMode == DEBUG_CONSOLE_MODE_UART)
    {
        Serial.println(message);
    }
    else if (debugConsoleMode == DEBUG_CONSOLE_MODE_UART_AND_SPI)
    {
        SPITransferMessageln(message);
        Serial.println(message);
    }
}

uint8_t DebugConsole::getConsoleMode(){
    /**
     * @brief Get the current debug console mode
     * @param None
     * @return debugConsoleMode: Current debug console mode
    */
  return debugConsoleMode;
}

uint8_t DebugConsole::available(){
    /**
     * @brief Check if there is a message available in the SPI buffer
     * @param None
     * @return 1: Message available, 0: No message available
    */
  return SPIMessageAvailable();
}

char* DebugConsole::readString(){
    /**
     * @brief Read a string from the SPI buffer, dont use to check for specific input
     * @param None
     * @return rxMsg: last received string read from the SPI buffer
    */
  return SPIReceiveLastMessage();
}

uint8_t DebugConsole::receivedString(char* string){
    /**
     * @brief Check if a string has been received, use this to check for specific input
     * @param string: String to be checked
     * @return 1: String received, 0: String not received
    */
  char *result = strstr(SPIReceiveLastMessage(), string);
  SPIEraseRxMessageString();
  if (result != NULL) {
    return 1;
  }
  else{
    return 0;
  }
}

void DebugConsole::readParsedString(char& character, int& number){
    /**
     * @brief Read a command string from the SPI buffer and parse it to a character and an integer
     * @param character: Character to be parsed
     * @param number: Integer to be parsed
     * @return None
    */
  // command format: "++c1234"
  // Initialize variables to store the parsed values
  char parsedChar = '\0';
  int parsedInt = 0;
  char* input = SPIReceiveLastMessage();

  
  //check ++ at the beginning of the message (command)
  if(input[0] != '+' && input[1] != '+'){
    return;
  }
  
  // Step 1: Extract the character 
  if (input[2] != '\0') {
    parsedChar = input[2];
  }
  
  // Step 2: Extract the integer part
  // Start from the 4. character in the input string
  int index = 3;
  for(index = 3; index < SPIMaxReceiveMessageSize(); index++) {
    if(input[index] == '\0') break;
    if(input[index] < 48 || input[index] > 57) break;
    // Convert ASCII character to integer and add it to the result
    parsedInt = (parsedInt * 10) + (input[index] - '0');
  }
  
  // Assign the parsed values to the output variables
  character = parsedChar;
  number = parsedInt;
  SPIEraseRxMessageString();
}