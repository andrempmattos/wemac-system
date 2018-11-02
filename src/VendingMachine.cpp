#include "VendingMachine.hpp"
#include <iostream>

using namespace VMCore;

// Cancel VendingMachine external event
void VendingMachine::cancelEvent(void) {
    // given the cancel event, transition to a new state based upon 
    // the current state of the state machine
    BEGIN_TRANSITION_MAP                      // - Current State -
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)  // ST_Idle
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)  // ST_Devolution
        TRANSITION_MAP_ENTRY (ST_DEVOLUTION)  // ST_Validation
        TRANSITION_MAP_ENTRY (ST_DEVOLUTION)  // ST_Transaction
        TRANSITION_MAP_ENTRY (ST_DEVOLUTION)  // ST_Deployment
    END_TRANSITION_MAP(NULL)
}

// increment VendingMachine cash external event
void VendingMachine::cashIncrementEvent(VendingMachineData* pData) {
    BEGIN_TRANSITION_MAP                      // - Current State -
        TRANSITION_MAP_ENTRY (ST_TRANSACTION) // ST_Idle
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)  // ST_Devolution
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)  // ST_Validation
        TRANSITION_MAP_ENTRY (ST_TRANSACTION) // ST_Transaction
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)  // ST_Deployment
    END_TRANSITION_MAP(pData)
}

// set VendingMachine speed external event
void VendingMachine::productSelectionEvent(VendingMachineData* pData) {
    BEGIN_TRANSITION_MAP                      // - Current State -
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)  // ST_Idle
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)  // ST_Devolution
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)  // ST_Validation
        TRANSITION_MAP_ENTRY (ST_VALIDATION)  // ST_Transaction
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)  // ST_Deployment
    END_TRANSITION_MAP(pData)
}

// state machine sits here when VendingMachine is not running
void VendingMachine::ST_Idle(EventData* pData) {
	std::cout << "VendingMachine::ST_Idle" << std::endl;
}

// stop the VendingMachine 
void VendingMachine::ST_Devolution(EventData* pData) {
	std::cout << "VendingMachine::ST_Devolution" << std::endl;

    InternalEvent(ST_IDLE);
}

// start the VendingMachine going
void VendingMachine::ST_Validation(EventData* pData) {
	bool isPurchaseValid = false;

    std::cout << "VendingMachine::ST_Validation" << std::endl;
    
    // perform the stop VendingMachine processing here
    // transition to ST_Idle via an internal event
    
    //For debug purposes only
    //TODO: Implement the real update
    std::cin >> isPurchaseValid;

    if (isPurchaseValid) {
        InternalEvent(ST_DEPLOYMENT);
    }
    else {
        InternalEvent(ST_TRANSACTION);
    }
}

// changes the VendingMachine speed once the VendingMachine is moving
void VendingMachine::ST_Transaction(VendingMachineData* pData) {
	std::cout << "VendingMachine::ST_Transaction" << std::endl;
    // perform the change VendingMachine speed to pData->speed here
}

// changes the VendingMachine speed once the VendingMachine is moving
void VendingMachine::ST_Deployment(VendingMachineData* pData) {
    std::cout << "VendingMachine::ST_Deployment" << std::endl;
    // perform the change VendingMachine speed to pData->speed here

    InternalEvent(ST_DEVOLUTION);
}