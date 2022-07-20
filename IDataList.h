//
// Created by Sarthak on 6/28/2022.
//
#ifndef C___IDATALIST_H
#define C___IDATALIST_H

class Node {
    public:
        int data;
        Node* next;
        Node* prev;
    public:
        explicit  Node(int data,Node* next = nullptr, Node* prev = nullptr){
            this->data = data;
            this->next = next;
            this->prev = prev;
            }
};

class IDataList {
    public:
        virtual ~IDataList()= default;
        virtual void deAppend(int data) = 0;
        virtual void append(int data) = 0;
        virtual void print() const = 0;
        virtual void insert(int data, int index) = 0;
        virtual void removeAt(int index) = 0;
        [[nodiscard]] virtual int getSize() const = 0;
        virtual int count() = 0;
        virtual int get(int index) = 0;
    protected:
        virtual void deleteHead() = 0;
        virtual void deleteTail() = 0;
        virtual int getFront()  = 0;
        virtual int getLast() = 0;
};

class DataList {
    protected:
        IDataList *l1 = nullptr;

    public:
        explicit DataList(IDataList *l1){
            this->l1 = l1;
        }
        void deAppend(int data) { l1->deAppend(data);}
        void append(int data) {l1->append(data);}
        void print() {l1->print();}
        void insert(int data, int index) {l1->insert(data,index);}
        void removeAt(int index) {l1->removeAt(index);}
        int getSize() {return l1->getSize();}
        int count() {return l1->count();}
        int get(int index) {return l1->get(index);}
};

class LinkedList : virtual public IDataList {
    public :
        Node *head = nullptr;
        Node* lastNode = nullptr;
        int _size = 0;

        void deAppend(int data) override;
        void append(int data) override;
        void print() const override;
        void insert(int data, int index) override;
        void removeAt(int index) override;
        [[nodiscard]] int getSize() const override ;
        int count() override;
        int get(int index) override;

    protected:
        int getFront() override;
        int getLast() override;
        void deleteHead() override;
        void deleteTail() override;
};

class CircularLinkedList : public LinkedList {
    public:
        void deAppend(int data) override;
        void append(int data) override;
        void print() const override;
        void insert(int data, int index) override;
        void removeAt(int index) override;
        [[nodiscard]] int getSize() const override;
        int count() override;
        int get(int index) override;

    protected:
        int getFront() override;
        int getLast() override;
        void deleteHead() override;
        void deleteTail() override;

};

class DoublyLinkedList : virtual public IDataList, public LinkedList{
    public:
        Node *head = nullptr;
        Node* lastNode = nullptr;
        int _size = 0;
        void deAppend(int data) override;
        void append(int data) override;
        void print() const override;
        void insert(int data, int index) override;
        void removeAt(int index) override;
        [[nodiscard]] int getSize() const override ;
        int count() override;
        int get(int index) override;

    protected:
        int getFront() override;
        int getLast() override;
        void deleteHead() override;
        void deleteTail() override;
};

class DoublyCircLinkedList : public DoublyLinkedList {

    public :
        void deAppend(int data) override;
        void append(int data) override;
        void print() const override;
        void insert(int data, int index) override;
        void removeAt(int index) override;
        [[nodiscard]] int getSize() const override ;
        int count() override;
        int get(int index) override;

    protected:
        int getFront() override;
        int getLast() override;
        void deleteHead() override;
        void deleteTail() override;
};
#endif //C___IDATALIST_H