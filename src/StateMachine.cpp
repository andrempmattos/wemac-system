/**
 * \file State machine base class 
 * \brief It implements a moore vending machine
 * 
 * \author André Mattos <andrempmattos@gmail.com>
 * \author Daniel Baron <zdaniz22@gmail.com>
 * 
 * \date 11/02/2017
 * 
 * \defgroup VendingMachineCore
 */

#include "../include/StateMachine.hpp"
//#include <assert.h>

using namespace VMCore;
 
StateMachine::StateMachine(unsigned char t_maxStates) :
    m_maxStates(t_maxStates),
    currentState(0),
    m_eventGenerated(false),
    m_pEventData(nullptr) 
{
}    
 
//Generates an external event. Called once per external event 
//to start the state machine executing
void StateMachine::ExternalEvent(unsigned char newState, EventData* pData) {
    //If we are supposed to ignore this event
    if (newState == EVENT_IGNORED) {
        //Just delete the event data, if any
        if (pData)  
            delete pData;
    }
    else {
        //Generate the event and execute the state engine
        InternalEvent(newState, pData); 
        StateEngine();     
    }
}

//Generates an internal event. Called from within a state 
//function to transition to a new state
void StateMachine::InternalEvent(unsigned char newState, EventData* pData) {
	if (pData == nullptr)
		pData = new EventData();

    m_pEventData = pData;
    m_eventGenerated = true;
    currentState = newState;
}

//The state engine executes the state machine states
void StateMachine::StateEngine(void) {
    EventData* pDataTemp = nullptr;
 
    //While events are being generated keep executing states
    while (m_eventGenerated) {         
        pDataTemp = m_pEventData;  //Copy of event data pointer
        m_pEventData = nullptr;    //Event data used up, reset ptr
        m_eventGenerated = false;  //Event used up, reset flag
 
        //TODO: Use exception instead of assert
        //assert(currentState < m_maxStates);

		//Get state map
        const StateStruct* pStateMap = GetStateMap();

        //Execute the state passing in event data, if any
        (this->*pStateMap[currentState].pStateFunc)(pDataTemp);

        //If event data was used, then delete it
        if (pDataTemp) {
            delete pDataTemp;
            pDataTemp = nullptr;
        }
    }
}