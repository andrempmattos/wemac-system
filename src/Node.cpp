/**
 * \file Node base class 
 * \brief It implements a commum base for data structures 
 * 
 * \author André Mattos <andrempmattos@gmail.com>
 * \author Daniel Baron <zdaniz22@gmail.com>
 * 
 * \date 10/28/2017
 * 
 * \defgroup VendingMachineCore
 */

#include "Node.hpp"


using namespace VMCore;

std::string Node::getNodeData() {
    return m_nodeData;
}

Node* Node::getNextNode() {
    return m_nextNode;
}

void Node::setNodeData(std::string t_nodeData) {
    m_nodeData = t_nodeData;
}

void Node::setNextNode(Node* t_nextNode) {
    m_nextNode = t_nextNode;
}
