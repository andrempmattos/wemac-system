#ifndef VMCORE_QUEUE_HPP
#define VMCORE_QUEUE_HPP

#include "Node.hpp"
#include "../include/ProjectIncludes.hpp"

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