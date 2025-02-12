//---------------------------------------------------------------------
// Assignment : eBuild Term Project / Phase 1
// Date : 9/18/24
// Author : Matthew Murphy and Matthew Berggren
// File Name : statemodel.h
//---------------------------------------------------------------------
#ifndef statemodel_h
#define statemodel_h

#include <stdlib.h>
#include "system.h"
#include "state.h"

// Declare all of the states used in the state model.
// They are extern because they are defined (i.e., the  memory is 
// actually allocated) elsewhere (i.e., in the .c files for the 
// individual states).

extern state_t accepting;
extern state_t processing;
extern state_t shipping;
extern state_t manufacturing;


// Declare all of the functions.
void printStateName(void) ;
void handle_event( event current_event );

#endif


