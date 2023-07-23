#ifndef SPI_MASTER_HPP
#define SPI_MASTER_HPP

#include <SPI.h>
#include "SPI_Master.hpp"

char txMsg[8] = "";

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
  dtostrf(message, 4, 2, txMsg);
  size_t length = strlen(txMsg);

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
  dtostrf(message, 4, 2, txMsg);
  size_t length = strlen(txMsg);

  x = SPI.transfer('<'); // start mark

  for (size_t i = 0; i < length; i++)
  {
    x = SPI.transfer(txMsg[i]);
  }

  x = SPI.transfer('&');  // end mark
}


#endif