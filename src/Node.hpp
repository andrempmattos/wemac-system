#ifndef VMCORE_NODE_HPP
#define VMCORE_NODE_HPP

#include "../include/ProjectIncludes.hpp"
#include "Log.hpp"

namespace VMCore {
    class Node {
        private:    
            std::string m_nodeData;
            Node* m_nextNode; 
        public:
            Node(std::string t_nodeData, Node* t_nextNode) : m_nodeData(t_nodeData), m_nextNode(t_nextNode) {}
            ~Node(){}
            std::string getNodeData();
            Node* getNextNode();
            void setNodeData(std::string t_nodeData);
            void setNextNode(Node* t_nextNode);
    };  
}

#endif