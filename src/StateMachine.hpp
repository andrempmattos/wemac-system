#ifndef VMCORE_STATE_MACHINE_HPP
#define VMCORE_STATE_MACHINE_HPP

#include <iostream>

namespace VMCore { 
    class EventData {
    public:
        virtual ~EventData() {};  
    };

    struct StateStruct;
     
    // base class for state machines
    class StateMachine {
    public:
        StateMachine(unsigned char t_maxStates);
        virtual ~StateMachine() {}
    protected:
        enum { EVENT_IGNORED = 0xFE, CANNOT_HAPPEN };
        unsigned char currentState;
        void ExternalEvent(unsigned char newState, EventData* = NULL);
        void InternalEvent(unsigned char newState, EventData* = NULL);
        virtual const StateStruct* GetStateMap() = 0;
    private:
        const unsigned char m_maxStates;
        bool m_eventGenerated;
        EventData* m_pEventData;
        void StateEngine(void);
    };

    typedef void (StateMachine::*StateFunc)(EventData *);
    struct StateStruct {
        StateFunc pStateFunc;    
    };

    #define BEGIN_STATE_MAP \
    public:\
    const StateStruct* GetStateMap() {\
        static const StateStruct StateMap[] = { 
     
    #define STATE_MAP_ENTRY(stateFunc)\
        { reinterpret_cast<StateFunc>(stateFunc) },
     
    #define END_STATE_MAP \
        }; \
        return &StateMap[0]; }
     
    #define BEGIN_TRANSITION_MAP \
        static const unsigned char TRANSITIONS[] = {\
     
    #define TRANSITION_MAP_ENTRY(entry)\
        entry,
     
    #define END_TRANSITION_MAP(data) \
        0 };\
        ExternalEvent(TRANSITIONS[currentState], data);
} 

#endif