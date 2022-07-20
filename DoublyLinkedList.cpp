//
// Created by sarth on 7/2/2022.
//

#include <iostream>
#include <string>
#include "IDataList.h"


void DoublyLinkedList::deAppend(int data) {
    if (this->head != nullptr) {
        Node* newNode = new Node(data,this->head, nullptr);
        this->head = newNode;
        this->lastNode = this->head;

    } else {

        Node* newNode = new Node(data,None,this->lastNode);
        this->lastNode->prev = newNode;
        this->lastNode = newNode;
        this->head->prev = nullptr;
        this->_size+=1;
    }
}

void DoublyLinkedList::append(int data) {
    if (this->head != nullptr) {
        this->deAppend(data);
    } else {
        Node* newNode = new Node(data,None,this->lastNode);
        this->lastNode->next = newNode;
        this->lastNode = newNode;
        this->_size+=1;
    }

}

void DoublyLinkedList::insert(int data, int index) {
    if (index < 0 || index >= this->_size){
        std::cout << "Cannot add to the list index out of range" <<std::endl;
    }else if (index == 0) {
        this->deAppend(data);
    }else if(index == this->_size -1) {
        this->append(data);
    }else {
        int c  = 0;
        Node* temp = this->head;
        while (c != index -1) {
            c+=1;
            temp = temp->next;
        }
        Node* newNode = new Node(data,temp->next,temp);
        this->_size-=1;
    }
}

void DoublyLinkedList::removeAt(int index) {
    if (index < 0 || index >= this->_size){
        std::cout << "Cannot delete index out of range" <<std::endl;
    }else if (index == 0) {
        this->deleteHead();
    }else if(index == this->_size -1) {
        this->deleteTail();
    }else {
        int c  = 0;
        Node* temp = this->head;
        while (c != index -1) {
            c+=1;
            temp = temp->next;
        }
        temp->next = temp->next->next;
        temp->next->prev = temp;
        this->_size-=1;
    }
}

void DoublyLinkedList::deleteHead() {
    if (this->head != nullptr) {
        this->head = this->head->next;
        this->head->prev = nullptr;
        this->_size-=1;
    }else {
        std::cout << "Cannot delete front of an empty list" <<std::endl;
    }
}

void DoublyLinkedList::deleteTail() {
    if (this->lastNode != nullptr){
        Node* newLastNode = this->lastNode->prev;
        this->lastNode = nullptr;
        this->lastNode = newLastNode;
        this->lastNode->next = nullptr;
    }else{
        std::cout << "Cannot delete end of an empty list" <<std::endl;
    }
}

int DoublyLinkedList::getSize() const {
    return LinkedList::getSize();
}

int DoublyLinkedList::count() {
    return LinkedList::count();
}

int DoublyLinkedList::get(int index) {
    return LinkedList::get(index);
}

int DoublyLinkedList::getFront() {
    return LinkedList::getFront();
}

int DoublyLinkedList::getLast() {
    return LinkedList::getLast();
}

void DoublyLinkedList::print() const {
    LinkedList::print();
}