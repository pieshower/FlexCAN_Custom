

#include <Arduino.h>
#include "FlexCAN_2.hpp"





uint8_t buf[] = {0x05, 0x14, 0x00, 0x64, 0x80, 0x40, 0x20, 0x10};

//uint8_t buf[] = {0, 0, 0, 10, 0, 0, 0, 10};


FlexCAN CAN1;



int main(void)
{

    pinMode(25, INPUT);
    pinMode(13, OUTPUT);

    Serial.begin(9600);

    CAN1.begin(9600);



    while(true)
    {

        if (digitalRead(25) == 1)
        {

            CAN1.loadCAN(0x0A, buf);

            delay(200);

        }

    }

}










