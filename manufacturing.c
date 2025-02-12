//---------------------------------------------------------------------
// Assignment : eBuild Term Project / Phase 1
// Date : 9/18/24
// Author : Matthew Murphy and Matthew Berggren
// File Name : manufacturing.c
//---------------------------------------------------------------------
#include "manufacturing.h"
#include "system.h"
#include "statemodel.h" // For the other states

// Declare the default event handler and the default action. 
// They are extern because they are used in each
// of the individual state files but defined in state.c.
extern state_t *  default_event_handler();
extern void       default_action();

// Create the object of the manufacturing state.
state_t manufacturing = {
    default_event_handler,   // order_received
    default_event_handler,   // valid_payment
    default_event_handler,   // invalid_payment
    manufacturing_failed,   // manufacture_failed
    manufacturing_completed,  //manufacture_completed
    default_event_handler,   //shipment_arrived
    default_event_handler,   //shipment_lost
    entry_to_manufacturing,         // entry_to
    exit_from_manufacturing         // exit_from
};

// Event manufacturing failed
state_t* manufacturing_failed()
{
  exit_from_manufacturing();
  updateStats(FAIL);
  return &accepting;
}
// Event manufacturing completed
state_t* manufacturing_completed()
{
  exit_from_manufacturing();
  chargeClient();
  return &shipping;
}
// Event entering manufacturing
void entry_to_manufacturing()
{
  dispatchFactoryLines();
}
// Event exiting manufacturing
void exit_from_manufacturing()
{
  shutDownFactoryLines();
}

