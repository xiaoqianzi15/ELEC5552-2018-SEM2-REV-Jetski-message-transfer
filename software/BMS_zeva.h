//ELEC5552 REV-Ski peoject
//this file is used to control the BMS and motor

#include <Arduino.h>
#include <can_common.h>


//This function is used to transfer the message to website
typedef struct{
    
    uint8_t usage;
    uint8_t current;
    uint8_t charging_data;
    uint8_t cycle_count;
    uint8_t condition;
    uint8_t temp_min;
    uint8_t temp_max;
    uint8_t max_single_voltage;
    uint8_t min_single_voltage;
    uint8_t max_voltage_total;
    uint8_t min_voltage_total;
    uint8_t Total_voltage;
    uint8_t Battery_pack_number;
    uint8_t Serial;
    uint8_t Parallel;
    uint8_t Battery_type;
    
} BMS_FRAME;  //BMS_1  BMS_2  BMS_3

//This function is used to transfer the message to website
typedef struct{
    uint8_t speed;
    uint8_t current;
    uint8_t voltage;
    uint8_t Power;
    uint8_t Temp_motor;
    uint8_t Temp_controller;
    
} MOTOR;

