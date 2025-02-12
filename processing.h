//---------------------------------------------------------------------
// Assignment : eBuild Term Project / Phase 1
// Date : 9/18/24
// Author : Matthew Murphy and Matthew Berggren
// File Name : processing.h
//---------------------------------------------------------------------

#ifndef processing_h
#define processing_h

#include "state.h"

// Declare all of the functions performed 
// when in the processing state.
static state_t*  valid_payment();
static state_t* invalid_payment();
static void     entry_to_processing();

#endif



