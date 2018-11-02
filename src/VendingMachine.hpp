#ifndef VMCORE_VENDING_MACHINE_HPP
#define VMCORE_VENDING_MACHINE_HPP

#include "StateMachine.hpp"
#include <iostream>

namespace VMCore { 
    // structure to hold event data passed into state machine
    struct VendingMachineData: public EventData {
        float cashValue;
        int productSelection;
    };

    // the VendingMachine state machine class
    class VendingMachine: public StateMachine {
    public:
        VendingMachine(): StateMachine(ST_MAX_STATES) {}

        // external events taken by this state machine
        void cancelEvent();
        void cashIncrementEvent(VendingMachineData*);
        void productSelectionEvent(VendingMachineData*);
    private:
        // state machine state functions
        void ST_Idle(EventData*);
        void ST_Devolution(EventData*);
        void ST_Validation(EventData*);
        void ST_Transaction(VendingMachineData*);
        void ST_Deployment(VendingMachineData*);

        // state map to define state function order
        BEGIN_STATE_MAP
    		STATE_MAP_ENTRY(&VendingMachine::ST_Idle)
            STATE_MAP_ENTRY(&VendingMachine::ST_Devolution)
            STATE_MAP_ENTRY(&VendingMachine::ST_Validation)
            STATE_MAP_ENTRY(&VendingMachine::ST_Transaction)
            STATE_MAP_ENTRY(&VendingMachine::ST_Deployment)
        END_STATE_MAP

        // state enumeration order must match the order of state
        // method entries in the state map
        enum E_States { 
            ST_IDLE = 0,
            ST_DEVOLUTION,
            ST_VALIDATION,
            ST_TRANSACTION,
            ST_DEPLOYMENT,
            ST_MAX_STATES
        };
    };
}

#endif
