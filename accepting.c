//---------------------------------------------------------------------
// Assignment : eBuild Term Project / Phase 1
// Date : 9/18/24
// Author : Matthew Murphy and Matthew Berggren
// File Name : accepting.h
//---------------------------------------------------------------------
#include "accepting.h"
#include "system.h"
#include "statemodel.h" // For the other states

// Declare the default event handler and the default action. 
// They are extern because they are used in each
// of the individual state files but defined in state.c.
extern state_t *  default_event_handler();
extern void       default_action();

// Create the object of the accepting state.
state_t accepting = {
    order_received,   // order_received
    default_event_handler,   // valid_payment
    default_event_handler,   // invalid_payment
    default_event_handler,   // manufacture_failed
    default_event_handler,  //manufacture_completed
    default_event_handler,   //shipment_arrived
    default_event_handler,   //shipment_lost
    default_action,         // entry_to
    default_action         // exit_from
};

// Event order recieved
state_t* order_received()
{
  getOrderSize();
  resetAttempts();
  return &processing;
}


