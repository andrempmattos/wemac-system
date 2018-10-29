#include "Queue.hpp"

//using namespace std;
using namespace VMCore;

Queue::~Queue() {
    Node* m_cursor = m_head;
    while(m_head != nullptr) {
        m_cursor = m_cursor->getNextNode();
        delete m_head;
        m_head = m_cursor;
    }
    m_head = nullptr; // Officially empty
}

void Queue::push(int t_data) {
    Node* p = m_head;
    Node* q = m_head;

    if (m_head == nullptr)
        m_head = new Node(t_data, m_head);
    else {
        while (q != nullptr) {
            p = q;
            q = p->getNextNode();
        }
        p->setNextNode(new Node(t_data, nullptr));
    }
}

int Queue::pop() {
    int data = 0;
    if (m_head != nullptr) {
        //cout << "Removendo: " << m_head << endl;
        //cout << "e fica:" << m_head->getVal() << endl;
        data = m_head->getNodeData();
        Node* m_oldHead = m_head;
        m_head = m_head->getNextNode();
        delete m_oldHead;
    }
    return data;
}