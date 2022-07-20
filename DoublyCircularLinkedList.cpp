//
// Created by sarth on 7/2/2022.
//

#include <iostream>
#include <string>
#include "IDataList.h"


void DoublyCircLinkedList::deAppend(int data) {
    DoublyLinkedList::deAppend(data);
    this->lastNode->next = this->head;
}

void DoublyCircLinkedList::append(int data) {
    DoublyLinkedList::append(data);
    this->lastNode->next = this->head;
    this->head->prev = this->lastNode;
}

void DoublyCircLinkedList::print() const {
    DoublyLinkedList::print();
}

void DoublyCircLinkedList::insert(int data, int index) {
    DoublyLinkedList::insert(data, index);
}

void DoublyCircLinkedList::removeAt(int index) {
    DoublyLinkedList::removeAt(index);
}

int DoublyCircLinkedList::getSize() const {
    return DoublyLinkedList::getSize();
}

int DoublyCircLinkedList::count() {
    return DoublyLinkedList::count();
}

int DoublyCircLinkedList::get(int index) {
    return DoublyLinkedList::get(index);
}

int DoublyCircLinkedList::getFront() {
    return DoublyLinkedList::getFront();
}

int DoublyCircLinkedList::getLast() {
    return DoublyLinkedList::getLast();
}

void DoublyCircLinkedList::deleteHead() {
    DoublyLinkedList::deleteHead();
    this->lastNode->next = this->head;
    this->head->prev = this->lastNode;
}

void DoublyCircLinkedList::deleteTail() {
    DoublyLinkedList::deleteTail();
    this->lastNode->next = this->head;
    this->head->prev = this->lastNode;
}
