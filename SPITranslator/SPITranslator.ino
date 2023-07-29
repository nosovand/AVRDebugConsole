#include<SPI.h>
#include "FIFO.h"
#define MAX_MESSAGE_SIZE 128
FIFO fifo(1024);
FIFO serial_fifo(128);
char rxMsg[MAX_MESSAGE_SIZE] = "";
volatile bool flag1 = false;
bool flag2 = false;
int i = 0;


void setup()
{
  Serial.begin(115200);
  Serial.println("Slave started");
  pinMode(SS, INPUT_PULLUP);  //SPI.h helps to get the meaning of SS
  pinMode(MISO, OUTPUT);      //should be made output to send data to Master
  SPCR |= _BV(SPE);         //SPI Port is enabled
  SPCR |= !(_BV(MSTR)); //Arduino is Slave
  SPI.attachInterrupt();    //SPI interrupt is enabled
}

void loop()
{
  if(Serial.available() > 0){
    uint8_t in = Serial.read();
    serial_fifo.push(in);
  }
  if (!fifo.isEmpty())  //SPDR has data
  {
    if (flag2 == false) //start mark of message not yet received
    {
      char q = fifo.pop();
      if (q == '<')
      {
        flag2 = true;   //start mark is detected
      }
    }
    else
    {
      char c = fifo.pop();
      if (c == '>' || c == '&')  //checking if end mark has arived
      {
        flag2 = false;
        nullifyStringAtPosition(rxMsg, i);
        i = 0;
        Serial.print(rxMsg);  //end mark has arrived; show the received message
        Serial.flush();
        if(c == '&'){
          Serial.println();     //insert newline
          Serial.flush();
        }
        cleanMessageArray();
      }
      else
      {
        rxMsg[i] = c;    //save received charcater/data byte in array
        i++;                //adjust array pointer
      }
    }
  }
}

void nullifyStringAtPosition(char *str, int position) {
    if (position >= 0 && position < strlen(str)) {
        str[position] = '\0';
    }
}

void cleanMessageArray(){
  for (int i = 0; i < MAX_MESSAGE_SIZE; i++) {
    rxMsg[i] = ' ';
  }
}

ISR (SPI_STC_vect)   //MCU comes here when there is a data byte in SPDR
{
  uint8_t rx = SPDR;
  SPDR = 0;
  uint8_t tx = serial_fifo.pop();
  SPDR = tx;
  if(!fifo.isFull() || SPDR == '&' || SPDR == '<' || SPDR == '>'){
    fifo.push(rx);
  }
  
}