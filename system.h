//---------------------------------------------------------------------
// Assignment : eBuild Term Project / Phase 1
// Date : 9/18/24
// Author : Matthew Murphy and Matthew Berggren
// File Name : system.h
//---------------------------------------------------------------------
#ifndef system_h
#define system_h

// Motor Settings.
typedef enum
  {
    FAIL,
    LOST,
    DONE,
  } statsSetting;

// Events.
typedef enum
  {
    ORDER_RECEIVED,
    VALID_PAYMENT,
    INVALID_PAYMENT,
    MANUFACTURE_FAILED,
    MANUFACTURE_COMPLETED,
    SHIPMENT_ARRIVED,
    SHIPMENT_LOST
  } event;
#define INVALID_EVENT      -1

// Functions for controlling the LED Indicators.
void updateStats (statsSetting value );

void chargeClient();

void TESTER();

void paymentRejected();

void refund();

void startWarranty();

void getOrderSize();

void resetAttempts();

void incrementAttempts();

void getPymentMethod();

void dispatchFactoryLines();

void shutDownFactoryLines();

void getAddress();



#endif


