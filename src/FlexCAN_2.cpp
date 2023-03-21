
#include <Arduino.h>
#include <iostream>
#include "FlexCAN_2.h"


using namespace std;

CAN_message_t msgFRAME;

uint64_t frameToSend = 0;



FlexCAN::FlexCAN()
{

// ----------------------------------------------
// Initialize all msgFRAME members to 0

    msgFRAME.id         = 0;
    
    msgFRAME.ext        = 0;
    msgFRAME.len        = 8;
    
    msgFRAME.timeout    = 0;

}


void FlexCAN::begin(int buadrate)
{

// ----------------------------------------------
// Initialize the buadrate for RX1 and TX1

    Serial1.begin(buadrate);

}


void FlexCAN::loadCAN(uint32_t id, uint8_t buf[])
{

// ---------------------------------------------
// Load ID and BUFFER

    msgFRAME.id = id;

    for (uint8_t i = 0; i < msgFRAME.len; i++)
    {

        msgFRAME.buf[i] = buf[i];

    }

// ----------------------------------------------
// Combine BUFFER values into one item

    // frameToSend  |= (msgFRAME.id >> frameToSend);

    for (uint8_t i = msgFRAME.len; i > 0; i--)
    {

        frameToSend |= ((uint64_t)buf[8 - i] << ((i * msgFRAME.len) - msgFRAME.len));

    }

// ------------------------------------------------
// Send message to UART

    // Serial1.print(msgFRAME.id);
    // Serial1.print(msgFRAME.len);
    // Serial1.print(frameToSend);

    //Serial1.print(frameToSend);
    //Serial1.print(msgFRAME.len);
    //Serial1.print(msgFRAME.id);


    for (uint8_t i = msgFRAME.len; i > 0; i--)
    {

        Serial1.write(buf[i - 1]);

        if (i == 1)
        {

            Serial1.write(msgFRAME.len);

            Serial1.write(msgFRAME.id);

        }
        
    }
    
}


int FlexCAN::read(CAN_message_t &msg)
{

    return 0;

}


void FlexCAN::write(CAN_message_t &msg)
{

    Serial1.print(frameToSend);

}











