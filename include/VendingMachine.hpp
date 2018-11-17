#ifndef VMCORE_VENDING_MACHINE_HPP
#define VMCORE_VENDING_MACHINE_HPP

#include "ProjectIncludes.hpp"
#include "StateMachine.hpp"
#include "Advertising.hpp"
#include "Interface.hpp"
#include "Product.hpp"
#include "Log.hpp"

namespace VMCore { 
    //Structure to hold event data passed into state machine
    struct VendingMachineData: public EventData {
        float cashValue;
        int productSelection;
    };

    //The VendingMachine state machine class
    class VendingMachine: public StateMachine {
        public:
            VendingMachine(Interface* t_interfaceOverride);
            VendingMachine();
            ~VendingMachine();

            //External events taken by this state machine
            void timerEvent();
            void cancelEvent();
            void confirmationEvent(int t_productSelection);
            void cashIncrementEvent(float t_inputCash);
            void productSelectionEvent(int t_productSelection);
        private:
            Log* logVendingMachine = new Log("[VMCORE]");
            
            float m_totalMachineCash = 0;
            float m_transactionCash = 0;
            Interface* m_interface = nullptr;
            Product* productDatabase = nullptr;
            Advertising* advertisingMessage = new Advertising();

            //State machine state functions
            void ST_Idle(EventData*);
            void ST_Devolution(EventData*);
            void ST_Validation(VendingMachineData*);
            void ST_Transaction(VendingMachineData*);
            void ST_Deployment(VendingMachineData*);
            void ST_Advertising(void);
            void ST_Confirmation(VendingMachineData*); 
            //State map to define state function order
            BEGIN_STATE_MAP
        		STATE_MAP_ENTRY(&VendingMachine::ST_Idle)
                STATE_MAP_ENTRY(&VendingMachine::ST_Devolution)
                STATE_MAP_ENTRY(&VendingMachine::ST_Validation)
                STATE_MAP_ENTRY(&VendingMachine::ST_Transaction)
                STATE_MAP_ENTRY(&VendingMachine::ST_Deployment)
                STATE_MAP_ENTRY(&VendingMachine::ST_Advertising)
                STATE_MAP_ENTRY(&VendingMachine::ST_Confirmation)
            END_STATE_MAP

            //State enumeration order must match the order of state
            //Method entries in the state map
            enum E_States { 
                ST_IDLE = 0,
                ST_DEVOLUTION,
                ST_VALIDATION,
                ST_TRANSACTION,
                ST_DEPLOYMENT,
                ST_ADVERTISING,
                ST_CONFIRMATION,
                ST_MAX_STATES
            };
    };
}

#endif
