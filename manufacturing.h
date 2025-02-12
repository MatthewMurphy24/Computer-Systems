//---------------------------------------------------------------------
// Assignment : eBuild Term Project / Phase 1
// Date : 9/18/24
// Author : Matthew Murphy and Matthew Berggren
// File Name : manufacturing.h
//---------------------------------------------------------------------
#ifndef manufacturing_h
#define manufacturing_h

#include "state.h"

// Declare all of the functions performed 
// when in the manufacturing state.
static state_t*  manufacturing_failed();
static state_t*  manufacturing_completed();
static void      entry_to_manufacturing();
static void      exit_from_manufacturing();

#endif



