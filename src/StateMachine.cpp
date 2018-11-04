#include "StateMachine.hpp"
//#include <assert.h>

using namespace VMCore;
 
StateMachine::StateMachine(unsigned char t_maxStates) :
    m_maxStates(t_maxStates),
    currentState(0),
    m_eventGenerated(false),
    m_pEventData(nullptr) 
{
}    
 
// generates an external event. called once per external event 
// to start the state machine executing
void StateMachine::ExternalEvent(unsigned char newState, EventData* pData) {
    // if we are supposed to ignore this event
    if (newState == EVENT_IGNORED) {
        // just delete the event data, if any
        if (pData)  
            delete pData;
    }
    else {
        // generate the event and execute the state engine
        InternalEvent(newState, pData); 
        StateEngine();     
    }
}

// generates an internal event. called from within a state 
// function to transition to a new state
void StateMachine::InternalEvent(unsigned char newState, EventData* pData) {
	if (pData == nullptr)
		pData = new EventData();

    m_pEventData = pData;
    m_eventGenerated = true;
    currentState = newState;
}

// the state engine executes the state machine states
void StateMachine::StateEngine(void) {
    EventData* pDataTemp = nullptr;
 
    // while events are being generated keep executing states
    while (m_eventGenerated) {         
        pDataTemp = m_pEventData;  // copy of event data pointer
        m_pEventData = nullptr;    // event data used up, reset ptr
        m_eventGenerated = false;  // event used up, reset flag
 
        //TODO: Use exception instead of assert
        //assert(currentState < m_maxStates);

		// get state map
        const StateStruct* pStateMap = GetStateMap();

        // execute the state passing in event data, if any
        (this->*pStateMap[currentState].pStateFunc)(pDataTemp);

        // if event data was used, then delete it
        if (pDataTemp) {
            delete pDataTemp;
            pDataTemp = nullptr;
        }
    }
}