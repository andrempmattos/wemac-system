/**
 * \file Advertising queue class 
 * \brief It implements a string based queue
 * 
 * \author André Mattos <andrempmattos@gmail.com>
 * \author Daniel Baron <zdaniz22@gmail.com>
 * 
 * \date 10/27/2017
 * 
 * \defgroup VendingMachineCore
 */

#include "Queue.hpp"

using namespace VMCore;

Queue::~Queue() {
    Node* m_cursor = m_head;
    while(m_head != nullptr) {
        m_cursor = m_cursor->getNextNode();
        delete m_head;
        m_head = m_cursor;
    }
    m_head = nullptr; //Officially empty
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
        data = m_head->getNodeData();
        Node* m_oldHead = m_head;
        m_head = m_head->getNextNode();
        delete m_oldHead;
    }
    return data;
}

int Queue::cPop() {
    int data = 0;
    if(m_head != nullptr) {
        data = m_head->getNodeData();
        Node* m_oldHead = m_head;
        m_head = m_head->getNextNode();
        this->push(data);
        delete m_oldHead;
    }
    return data;
}