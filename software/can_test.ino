// Arduino Due - Displays all traffic found on either canbus port
// By Thibaut Viard/Wilfredo Molina/Collin Kidder 2013-2014

// Required libraries
#include "variant.h"
#include <due_can.h>

//Leave defined if you use native port, comment if using programming port
//This sketch could provide a lot of traffic so it might be best to use the
//native port
//#define Serial SerialUSB

void setup()
{
  Serial.begin(115200);
  
  // Initialize CAN0 and CAN1, Set the proper baud rates here
  Can0.begin(CAN_BPS_250K);
  //Can1.begin(CAN_BPS_250K);
  
  //By default there are 7 mailboxes for each device that are RX boxes
  //This sets each mailbox to have an open filter that will accept extended
  //or standard frames
  int filter;
  //extended
  for (filter = 0; filter < 3; filter++) {
  Can0.setRXFilter(filter, 0, 0, true);
  //Can1.setRXFilter(filter, 0, 0, true);
  }  
  //standard
  for (int filter = 3; filter < 7; filter++) {
  Can0.setRXFilter(filter, 0, 0, false);
  //Can1.setRXFilter(filter, 0, 0, false);
  }  
  
}

void printFrame(CAN_FRAME &frame) {
   Serial.print("ID: 0x");
   Serial.print(frame.id, HEX);
   Serial.print(" Len: ");
   Serial.print(frame.length);
   Serial.print(" Data: 0x");
   for (int count = 0; count < frame.length; count++) {
       Serial.print(frame.data.bytes[count], HEX);
       Serial.print(" ");
   }
   Serial.print("\r\n");
}

void loop()
{
  int state = 0; //if state is more than 0, transfer message use can0;
             //if state is equal to 0, transfer nothing;
             
  CAN_FRAME incoming_message;

  CAN_FRAME Speed;      //boat speed
  CAN_FRAME RPM;        //motor rpm
  CAN_FRAME Fuel_Gauge_Level;  //fuel gauge level 
  
  Serial.print("start");
  
  delay(1000);

  while(1)
  {  
    //Serial.print("start");

    if (Can0.available() > 0) 
    {
      Can0.read(incoming_message); 
      printFrame(incoming_message);   //transfer messages to USART

      if(incoming_message.id =  0x208){
        Speed = incoming_message;
        //state = 1;   //set state = 1 to send data
        };

       if(incoming_message.id =  0x210){
        Fuel_Gauge_Level = incoming_message;
        //state = 1;
        };

       if(incoming_message.id =  0x310){
        RPM = incoming_message;
        //state = 1;
        }
      
    }

    if(state == 1)
    {

      state = 0;  //exit sending 
      }

  }
}
