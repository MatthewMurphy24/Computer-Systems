//---------------------------------------------------------------------
// Assignment : eBuild Term Project / Phase 1
// Date : 9/18/24
// Author : Matthew Murphy and Matthew Berggren
// File Name : driver.h
//---------------------------------------------------------------------
#include "statemodel.h"
#include "accepting.h"
#include "system.h"
#include <stdbool.h>
#include <stdio.h>

state_t* current_state = &accepting;
extern int payAttempts;

// Converts user input into events and prints event status.
int main(){

    printStateName();
    event event1;
    bool notDone = true;
    char userInput;

    while(notDone){

        if(scanf("%c", &userInput) == EOF){
            exit(0);
        }

        event1 = INVALID_EVENT;
        
        switch (userInput) {

            case 'O':
                printf("Event: ORDER_RECEIVED\n");
                event1 = ORDER_RECEIVED;
                break;

            case 'V':
                printf("Event: VALID_PAYMENT\n");
                event1 = VALID_PAYMENT;
                break;

            case 'I':
                printf("Event: INVALID_PAYMENT\n");
                event1 = INVALID_PAYMENT;
                break;

            case 'F':
                printf("Event: MANUFACTURE_FAILED\n");
                event1 = MANUFACTURE_FAILED;
                break;

            case 'C':
                printf("Event: MANUFACTURE_COMPLETED\n");
                event1 = MANUFACTURE_COMPLETED;
                break;

            case 'R':
                printf("Event: SHIPMENT_ARRIVED\n");
                event1 = SHIPMENT_ARRIVED;
                break;

            case 'L':
                printf("Event: SHIPMENT_LOST\n");
                event1 = SHIPMENT_LOST;
                break;

            case 'X':
                printf("\n");
                exit(0);
                break;

            case '\n':
                break;

            default:
                printf("Event: INVALID_EVENT\n");
                event1 = INVALID_EVENT;
                break;
   
        }
        handle_event(event1);
    }

}