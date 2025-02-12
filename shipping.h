//---------------------------------------------------------------------
// Assignment : eBuild Term Project / Phase 1
// Date : 9/18/24
// Author : Matthew Murphy and Matthew Berggren
// File Name : shipping.h
//---------------------------------------------------------------------
#ifndef shipping_h
#define shipping_h

#include "state.h"

// Declare all of the functions performed 
// when in the shipping  state.
static state_t*  shipment_lost();
static state_t* shipment_arrived();
static void      entry_to_shipping();

#endif



