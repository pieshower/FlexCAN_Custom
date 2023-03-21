 
 
 /*
    Gave up trying to merge it into one 
    64 bit item. Got close and it worked in
    visual studio but for some reason not here.
    Anyways, Im pretty sure it sends like 15 
    24-bit frames. This below sends each "item" as 
    an independent UART message kinda similar. 
    Would like to check this on an acutal CAN chip.
*/

//  Also mathew said the CAN chip should interperate
//  whatever you send it... So, bad chip? mmm fritos



#include <Arduino.h>
#include "FlexCAN_2.h"



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

















