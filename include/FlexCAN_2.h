


#include <Arduino.h>
#include <avr/io.h>



typedef struct CAN_message_t
{

    uint32_t      id;      // can identifier
    
    uint8_t      ext;      // identifier is extended
    uint8_t      len;      // length of data
    
    uint16_t timeout;      // milliseconds, zero will disable waiting

    uint8_t   buf[8] = {0, 0, 0, 0, 0, 0, 0, 0};

} CAN_message_t;



class FlexCAN
{

public:

                                     FlexCAN();

    void                   begin(int buadrate);

    void   loadCAN(uint32_t id, uint8_t buf[]);

    int               read(CAN_message_t &msg);

    void             write(CAN_message_t &msg);

};











