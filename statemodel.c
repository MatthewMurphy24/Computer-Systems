//---------------------------------------------------------------------
// Assignment : eBuild Term Project / Phase 1
// Date : 9/18/24
// Author : Matthew Murphy and Matthew Berggren
// File Name : statemodel.c
//---------------------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>

#include "statemodel.h"

extern state_t* current_state ;
//Takes in events and triggers enter events
void handle_event( event current_event )
{
    state_t* next_state;

    next_state = NULL;
    switch( current_event )
    {
        case ORDER_RECEIVED:
            next_state = current_state->order_received();
            break;
        case VALID_PAYMENT:
            next_state = current_state->valid_payment();
            break;
        case INVALID_PAYMENT:
            next_state = current_state->invalid_payment();
            break;
        case MANUFACTURE_FAILED:
            next_state = current_state->manufacture_failed();
            break;
        case MANUFACTURE_COMPLETED:
            next_state = current_state->manufacture_completed();
            break;
        case SHIPMENT_ARRIVED:
            next_state = current_state->shipment_arrived();
            break;
        case SHIPMENT_LOST:
            next_state = current_state->shipment_lost();
            break;
        
    }    

    if ( next_state != NULL ) 
    {
        current_state = next_state; // Change states
        printStateName();
        current_state->entry_to();  // enter the new state
    }
}
//prints state names
void printStateName(void)
{
    printf("\n*-*-*-*-*-*-*-*-*-*-*-*\nState: ");
    if ( current_state == &accepting )
        printf( "ACCEPTING" );
    else if ( current_state == &processing )
        printf( "PROCESSING" );
    else if ( current_state == &shipping )
            printf( "SHIPPING" );
    else if ( current_state == &manufacturing )
            printf( "MANUFACTURING" );
    printf("\n*-*-*-*-*-*-*-*-*-*-*-*\n");
}

