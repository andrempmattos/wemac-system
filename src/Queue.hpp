#ifndef VMCORE_QUEUE_HPP
#define VMCORE_QUEUE_HPP

//#include <iostream>
#include "Node.hpp"

namespace VMCore {
    class Queue {
        private: 
            Node* m_head;
        public:
            Queue() : m_head(nullptr) {}
            ~Queue();
            int pop();
            void push(int t_data);
    };
}

#endif