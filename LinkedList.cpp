//
// Created by Sarthak on 6/28/2022.
//
#include <iostream>
#include <string>
#include "IDataList.h"

//Insert at the front of the list O(1) operation
void LinkedList::deAppend(int data){
    if (this->head== nullptr){
        Node *newNode = new Node(data, nullptr);
        this->head = newNode;
        this->lastNode = newNode;
    }else{
        Node *newNode = new Node(data, this->head);
        this->head = newNode;
    }

    this->_size+=1;
}

//Insert at the back of the list O(1) operation
void LinkedList::append(int data) {
    Node *newNode = new Node(data, nullptr);
    if (this->head == nullptr){
        this->head = newNode;
        this->lastNode = this->head;
    }else {
        Node *temp = this->lastNode;
        temp->next = new Node(data, nullptr);
        this->lastNode = temp->next;
    }
    this->_size += 1;
}

void LinkedList::print() const {
    if (this->head == nullptr) {
        std::cout << "LinkedList is empty";
    }else{
        int i =0;
        Node* temp = this->head;
        std::string llstr;
        while (i < this->getSize()){
            llstr+=std::to_string(temp->data) + " --> ";
            temp = temp->next;
            i+=1;
        }
        llstr+="NULL";
        std::cout << llstr << std::endl;
    }
}

void LinkedList::insert(int data, int index    ) {
    if (index==0){
        this->deAppend(data);
        return;
    }else if (index == this->_size){
        this->append(data);
        return;
    }else{
        int c = 0;
        Node* temp = this->head;
        while (c!= index-1){
            c+=1;
            temp = temp->next;

        }
        Node *newNode = new Node(data,temp->next);
        temp->next = newNode;
        this->_size+=1;

    }
}

void LinkedList::removeAt(int idx) {
    if (idx < 0 or idx >= this->_size) {
        std::cout << "Cannot delete at index {idx}. Out of range."
                     "Size of the list is" +std::to_string(this->getSize());
        return;
    }else if (idx == 0) {
        this->deleteHead();
        return;
    }else if (idx == this->_size-1) {
        this->deleteTail();
        return;
    }
    else{
        int c = 0;
        Node* temp = this->head;
        while (c != idx-1){
            c+=1;
            temp = temp->next;
        }
        temp->next = temp->next->next;
        this->_size-=1;
    }
}

int LinkedList::getSize() const {
    return this->_size;
}

int LinkedList::count() {
    int i = 0;
    Node* temp = this->head;
    while(temp != nullptr) {
        i+=1;
        temp = temp->next;
    }
    this->_size = i;
    return this->_size;
}

void LinkedList::deleteHead() {
    if (this->head != nullptr) {
        this->head = this->head->next;
        this->_size-=1;
        return;
    }else {
        std::cout << "Cannot delete the front of an empty list" << std::endl;
    }
}

void LinkedList::deleteTail() {
    if (this->head != nullptr) {
        Node* temp = this->head;
        while (temp->next != this->lastNode) {
            temp = temp->next;
        }
        this->lastNode = temp;
        this->lastNode->next = nullptr;
        this->_size -=1;
    }else {
        std::cout << "Cannot delete the tail of an empty list" << std::endl;
    }
}

int LinkedList::getFront() {
    return this->head->data;
}

int LinkedList::getLast() {
    return this->lastNode->data;
}

int LinkedList::get(int index) {
    if (index ==0) {
        return this->getFront();
    }else if (index == this->getSize()-1) {
        return this->getLast();
    }else if (index < 0 || index >= this->getSize()) {
        throw std::out_of_range("Index out of range cannot get a value");
    }
    int c = 0;
    Node* temp  =  this->head;
    while (c != index -1) {
        temp = temp->next;
        c+=1;
    }
    return temp->next->data;
}



