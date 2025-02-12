//---------------------------------------------------------------------
// Assignment : eBuild Term Project / Phase 1
// Date : 9/18/24
// Author : Matthew Murphy and Matthew Berggren
// File Name : processing.c
//---------------------------------------------------------------------
#include "processing.h"
#include "system.h"
#include "statemodel.h" // For the other states

// Declare the default event handler and the default action. 
// They are extern because they are used in each
// of the individual state files but defined in state.c.
extern state_t *  default_event_handler();
extern void       default_action();
extern int payAttempts;


// Create the object of the processing state.
state_t processing = {
    default_event_handler,          // order_received
    valid_payment,                 // valid_payment
    invalid_payment,              // invalid_payment
    default_event_handler,       // manufacture_failed
    default_event_handler,      // manufacture_completed
    default_event_handler,     // shipment_arrived
    default_event_handler,    // shipment_lost
    entry_to_processing,     // entry_to
    default_action          // exit_from
};

// Event valid payment
state_t* valid_payment()
{
  return &manufacturing;
}
// Event invalid payment
state_t* invalid_payment()
{
  incrementAttempts();
  if(payAttempts < 3){
    return &processing;
  }
  else{
    paymentRejected();
    return &accepting;
  }
}
// Event entry to processing
void entry_to_processing()
{
  getPymentMethod();
}

