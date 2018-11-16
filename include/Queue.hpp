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
            std::string pop();          // Normal Pop
            std::string cPop();         // Circular Pop
            void dPop();        // Pop and delete
            void push(std::string t_data);
            std::string getdataHead();		
    };
}

#endif