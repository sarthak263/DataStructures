//
// Created by sarthak on 6/30/2022.
//
#include "IDataList.h"

void CircularLinkedList::deAppend(int data) {
    LinkedList::deAppend(data);
    this->lastNode->next = this->head;
}

void CircularLinkedList::append(int data) {
    LinkedList::append(data);
    this->lastNode->next = this->head;
}

//calls the super class
void CircularLinkedList::print() const {
    LinkedList::print();
}

void CircularLinkedList::insert(int data, int index) {
    LinkedList::insert(data, index);
}

void CircularLinkedList::removeAt(int index) {
    LinkedList::removeAt(index);
}

//calls the super class
int CircularLinkedList::getSize() const {
    return LinkedList::getSize();
}

//calls the super class
int CircularLinkedList::count() {
    return LinkedList::count();
}

int CircularLinkedList::get(int index) {
    return LinkedList::get(index);
}

void CircularLinkedList::deleteTail() {
    LinkedList::deleteTail();
    this->lastNode->next = this->head;
}

void CircularLinkedList::deleteHead() {
    LinkedList::deleteHead();
    this->lastNode->next = this->head;
}

int CircularLinkedList::getFront() {
    return LinkedList::getFront();
}

int CircularLinkedList::getLast() {
    return LinkedList::getLast();
}