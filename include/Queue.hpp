#ifndef VMCORE_QUEUE_HPP
#define VMCORE_QUEUE_HPP

#include "Node.hpp"
#include "ProjectIncludes.hpp"

namespace VMCore {
    class Queue {
        private: 
            Node* m_head;
        public:
            Queue() : m_head(nullptr) {}
            ~Queue();
            void enqueue(std::string t_data); //Add(store) an item to the queue
            std::string dequeue(void);        //Remove(access) an item from the queue
            std::string peek(void);           //Gets the element at the front of the queue without removing it
            std::string peekCyclic();         //Gets the element at the front of the queue and send to the back
    };
}

#endif