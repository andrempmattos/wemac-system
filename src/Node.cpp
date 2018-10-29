#include "Node.hpp"

using namespace VMCore;

int Node::getNodeData() {
    return m_nodeData;
}

Node* Node::getNextNode() {
    return m_nextNode;
}

void Node::setNodeData(int t_nodeData) {
    m_nodeData = t_nodeData;
}

void Node::setNextNode(Node* t_nextNode) {
    m_nextNode = t_nextNode;
}
