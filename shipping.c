//---------------------------------------------------------------------
// Assignment : eBuild Term Project / Phase 1
// Date : 9/18/24
// Author : Matthew Murphy and Matthew Berggren
// File Name : shipping.c
//---------------------------------------------------------------------
#include "shipping.h"
#include "system.h"
#include "statemodel.h" // For the other states

// Declare the default event handler and the default action. 
// They are extern because they are used in each
// of the individual state files but defined in state.c.
extern state_t *  default_event_handler();
extern void       default_action();

// Create the object of the shipping state.
state_t shipping = {
    default_event_handler,   // order_received
    default_event_handler,   // valid_payment
    default_event_handler,   // invalid_payment
    default_event_handler,   // manufacture_failed
    default_event_handler,  //manufacture_completed
    shipment_arrived,   //shipment_arrived
    shipment_lost,   //shipment_lost
    entry_to_shipping,         // entry_to
    default_action         // exit_from
};

//Event shipment arrived
state_t* shipment_arrived()
{
  startWarranty();
  updateStats(DONE);
  return &accepting;
}
//Event shipment lost
state_t* shipment_lost()
{
  refund();
  updateStats(LOST);
  return &accepting;
}

//Event entry to shipping
void entry_to_shipping()
{
  getAddress();
}


