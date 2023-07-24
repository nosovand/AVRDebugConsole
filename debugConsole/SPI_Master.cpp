#include "Arduino.h"
#ifndef SPI_MASTER_HPP
#define SPI_MASTER_HPP

#define MAX_MASTER_MESSAGE_SIZE 12

#include <SPI.h>
#include "SPI_Master.hpp"

char txMsg[MAX_MASTER_MESSAGE_SIZE] = "";

void countDoubleDigits(double number, int *mainDigits, int *decimalDigits) {
    // Handling negative numbers by taking the absolute value
    number = fabs(number);
    // Counting main digits
    *mainDigits = number == 0 ? 1 : (int)log10(number) + 1;
    // Counting decimal digits
    *decimalDigits = 0;

    double decimalPart = number - floor(number);
    double precision = 1e-4; // Adjust the precision as needed

    while (decimalPart > precision) {
        decimalPart *= 10;
        decimalPart = fmod(decimalPart, 1.0);
        (*decimalDigits)++;
        if (decimalPart > (0.999))
          break;
    }
}

//SPI init
void SPIMasterInit()
{
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV128); // 16 MHz/128
}

// Specialization for const __FlashStringHelper*
void SPITransferMessage(const __FlashStringHelper* message)
{
  int x;
  const char* strPtr = reinterpret_cast<const char*>(message);
  size_t length = strlen_P(strPtr);

  x = SPI.transfer('<'); // start mark

  for (size_t i = 0; i < length; i++)
  {
   x = SPI.transfer(pgm_read_byte_near(strPtr + i)); // SPI transfer is byte-by-byte
  }

  x = SPI.transfer('>');  // end mark
}

// Specialization for const __FlashStringHelper*
void SPITransferMessageln(const __FlashStringHelper* message)
{
  int x;
  const char* strPtr = reinterpret_cast<const char*>(message);
  size_t length = strlen_P(strPtr);

  x = SPI.transfer('<'); // start mark

  for (size_t i = 0; i < length; i++)
  {
    x = SPI.transfer(pgm_read_byte_near(strPtr + i)); // SPI transfer is byte-by-byte
  }

  x = SPI.transfer('&');  // end mark
}


void SPITransferMessage(char* message)
{
  int x;
  const char* strPtr = reinterpret_cast<const char*>(message);
  size_t length = strlen(strPtr);

  x = SPI.transfer('<'); // start mark

  for (size_t i = 0; i < length; i++)
  {
    x = SPI.transfer(strPtr[i]);
  }

  x = SPI.transfer('>');  // end mark
}

void SPITransferMessageln(char* message)
{
  int x;
  const char* strPtr = reinterpret_cast<const char*>(message);
  size_t length = strlen(strPtr);

  x = SPI.transfer('<'); // start mark

  for (size_t i = 0; i < length; i++)
  {
    x = SPI.transfer(strPtr[i]);
  }

  x = SPI.transfer('&');  // end mark
}


void SPITransferMessage(double message)
{
  int x;
  int mainDigits, decimalDigits;
  countDoubleDigits(message, &mainDigits, &decimalDigits);
  if((mainDigits + decimalDigits) > (MAX_MASTER_MESSAGE_SIZE - 1)){
    decimalDigits = MAX_MASTER_MESSAGE_SIZE - mainDigits - 1;
  }
  //convert double to char array
  dtostrf(message, mainDigits, decimalDigits, txMsg);
  size_t length = MAX_MASTER_MESSAGE_SIZE;

  x = SPI.transfer('<'); // start mark

  for (size_t i = 0; i < length; i++)
  {
    x = SPI.transfer(txMsg[i]);
  }

  x = SPI.transfer('>');  // end mark
}

void SPITransferMessageln(double message)
{
  int x;
  int mainDigits, decimalDigits;
  countDoubleDigits(message, &mainDigits, &decimalDigits);
  if((mainDigits + decimalDigits) > (MAX_MASTER_MESSAGE_SIZE - 1)){
    decimalDigits = MAX_MASTER_MESSAGE_SIZE - mainDigits - 1;
  }
  //convert double to char array
  dtostrf(message, mainDigits, decimalDigits, txMsg);
  size_t length = MAX_MASTER_MESSAGE_SIZE;

  x = SPI.transfer('<'); // start mark

  for (size_t i = 0; i < length; i++)
  {
    x = SPI.transfer(txMsg[i]);
  }

  x = SPI.transfer('&');  // end mark
}


#endif