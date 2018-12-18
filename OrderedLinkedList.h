// Author       :   Alex Kourkoumelis
// Date         :   11/4/2017
// Title        :   Airline Database
// Description  :   Creates a database of 4 ordered linked lists
//                  each maintained in alphabetical order by last name.
//                  Prompts user to add, delete, search, list, quit

#ifndef ATTEMPT4_ORDEREDLINKEDLIST_H
#define ATTEMPT4_ORDEREDLINKEDLIST_H
#include "LinkedList.h"
#include <iostream>
using namespace std;

//inheriting LinkedList
template <class T>
class OrderedLinkedList:public LinkedList<T> {
private:
    OrderedLinkedList(const OrderedLinkedList &) = delete; //copy constructor
protected:
    int count;
    node<T> *head, *last;
public:
    OrderedLinkedList();
    bool isEmpty();
    int length();
    T front();
    T back();
    void insert(T &);
    void insertAlphabetical(T&);
    virtual void deleteNode(T&);
    virtual void destroylist();
    bool searchList(T&);
    OrderedLinkedList<T>& operator=(OrderedLinkedList<T>&);
    template <class U>
    friend ostream& operator<<(ostream& os, OrderedLinkedList<U>& list);
    virtual ~OrderedLinkedList();

};
template <class T>
OrderedLinkedList<T>::OrderedLinkedList(){
    head = last = NULL;
    count = 0;
}
template <class T>
bool OrderedLinkedList<T>::isEmpty(){
    return head==NULL;
}
template <class T>
int OrderedLinkedList<T>::length(){
    return count;
}
template <class T>
T OrderedLinkedList<T>::front(){
    return head->data;
}
template <class T>
T OrderedLinkedList<T>::back(){
    return last->data;
}

//to search and compare using friend functions in Passenger.h, returns boolean
template <class T>
bool OrderedLinkedList<T>::searchList(T& item){
    node<T>* p = head;
    while(p!= NULL && p->data < item) {
        p = p->next;
    }
    if(p!=NULL){
        if(p->data == item){
            cout << p->data;
            return true;
        }
    } else {
        return false;
    }
}

//to insertalphabetically by last name
template <class T>
void OrderedLinkedList<T>::insertAlphabetical(T &item){
    node<T> *newnode = new node<T>;                     //new node
    newnode->data = item;

    if(head==NULL) {                                    //if its the first node
        head = last = newnode;
        newnode->next = NULL;
    } else if (newnode->data < head->data){             //if it comes before the first node
        newnode->next = head;
        head = newnode;
    } else if (last->data < newnode->data){             //if its the last node
        last->next = newnode;
        last = newnode;
    } else if (newnode->data > head->data){             //if its after head
        if(head->next == NULL){                         //if there's no next node
            head->next = newnode;
            last = newnode;
        } else {                                        //if there's more than 2 nodes
            node<T> *p = head;
            while(p->next->data < newnode->data && p->next != NULL){
                p = p->next;                            //move pointer until p->next < data
            }
            if(p->next == NULL){                        //if no next node
                p->next = newnode;
                last = newnode;
            }else{                                      //if there is a next node
                newnode->next = p->next;
                p->next = newnode;
            }
        }
    }
    count++;
}

//no longer used
template <class T>
void OrderedLinkedList<T>::insert(T &item){
    node<T> *newnode = new node<T>;
    newnode->data = item;
    newnode->next = NULL;

    if(head==NULL){
        head = last = newnode;
    }else{
        last->next = newnode;
        last = newnode;
    }
    count++;
}

//to delete. compares first.
template <class T>
void OrderedLinkedList<T>::deleteNode(T& item){
    if(head == NULL)
        cerr<<"empty list";
    else{
        if(head->data == item){
            node<T>* p = head;
            head = head->next;
            delete p;
            count--;
            if(head==NULL) last = NULL;
        }else{
            node<T>* p = head;
            node<T>* q = p->next;
            while(q!=NULL && q->data != item){
                p = q;
                q = q->next;
            }
            if(q!=NULL){
                p->next = q->next;
                count--;
                if(last == q) last = p;
                delete q;
            }
        }
    }
}

template <class T>
void OrderedLinkedList<T>::destroylist(){
    node<T> *p;
    while(head != NULL){
        p = head;
        head = head->next;
        delete p;
    }
    last = NULL;
    count = 0;
}
template <class T>
OrderedLinkedList<T>& OrderedLinkedList<T>::operator=(OrderedLinkedList<T>& list){
    if(this!= &list){
        copylist(list);
    }
    return *this;
}
template <class T>
ostream& operator<<(ostream& os, OrderedLinkedList<T>& list){
    node<T> *p = list.head;
    while(p!= NULL){
        os<<p->data<<" "<<endl;
        p = p->next;
    }
    return os;
}
template <class T>
OrderedLinkedList<T>::~OrderedLinkedList(){
    destroylist();
}


#endif //ATTEMPT4_ORDEREDLINKEDLIST_H
