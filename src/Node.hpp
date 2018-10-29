#ifndef VMCORE_NODE_HPP
#define VMCORE_NODE_HPP

namespace VMCore {
    class Node {
        private:    
            int m_nodeData;
            Node* m_nextNode;
        public:
            Node(int t_nodeData, Node* t_nextNode) : m_nodeData(t_nodeData), m_nextNode(t_nextNode) {}
            ~Node(){}
            int getNodeData();
            Node* getNextNode();
            void setNodeData(int t_nodeData);
            void setNextNode(Node* t_nextNode);
    };  
}

#endif