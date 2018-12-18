// Author       :   Alex Kourkoumelis
// Date         :   11/4/2017
// Title        :   Airline Database
// Description  :   Creates a database of 4 ordered linked lists
//                  each maintained in alphabetical order by last name.
//                  Prompts user to add, delete, search, list, quit

#include <iostream>
#include "LinkedList.h"
#include "OrderedLinkedList.h"
using namespace std;

//creates 4 ordered linked lists that take passenger objects
OrderedLinkedList<Passenger> list100;
OrderedLinkedList<Passenger> list200;
OrderedLinkedList<Passenger> list300;
OrderedLinkedList<Passenger> list400;


Passenger getPassengerInfo();
int enterFlight();
string enterFname();
string enterLname();
string enterAddress();
int enterPhone();
void searchPassenger(Passenger findPassenger);
Passenger searchInfo();
void printList();
void addPassenger(int fnum, Passenger newPassenger);
void deletePassenger(int fnum, Passenger newPassenger);

int main() {
    cout << "Hello, World!" << endl;

    char decider = 'a';

    //main decision loop
    while(decider != 'Q' && decider != 'q') {
        cout << endl;
        cout << "***** WIZARD AIRLINES *****" << endl;
        cout << "Please choose an operation:" << endl;
        cout << "A(Add) | S(Search) | D(Delete) | L(List) | Q(Quit): ";
        cin >> decider;
        cout << endl;

        switch(decider) {

                //add
            case 'A':
            case 'a': {
                cout << "You chose A(Add)." << endl;
                int fnum = enterFlight();
                Passenger newPassenger = getPassengerInfo();
                addPassenger(fnum, newPassenger);
                break;
            }

                //search
            case 'S':
            case 's': {
                cout << "You chose S(Search)." << endl;
                Passenger findPassenger = searchInfo();
                cout << endl;
                searchPassenger(findPassenger);
                break;
            }

                //delete
            case 'D':
            case 'd': {
                cout << "You chose D(Delete)." << endl;
                int fnum = enterFlight();
                Passenger getPassenger = searchInfo();
                deletePassenger(fnum, getPassenger);
                break;
            }

                //list
            case 'L':
            case 'l':
                cout << "You chose L(List)." << endl;
                printList();
                break;

                //quit
            case 'Q':
            case 'q':
                cout << "You chose Q(Quit)." << endl;
        }
    }
    return 0;
}

//to print each flight list
void printList(){
    int fnum;
    fnum = enterFlight();
    switch(fnum) {
        case 100:
            cout << list100;
            break;
        case 200:
            cout << list200;
            break;
        case 300:
            cout << list300;
            break;
        case 400:
            cout << list400;
            break;
        default:
            cerr << "idk what went wrong. printing them all..." << endl;
            cout << list100 << list200 << list300 << list400;
    }

}

//to search each flight list and return results
void searchPassenger(Passenger findPassenger){
    if(list100.searchList(findPassenger)){
        cout << "Passenger is in Flight List 100" << endl;
    }else if(list200.searchList(findPassenger)){
        cout << "Passenger is in Flight List 200" << endl;
    }else if(list300.searchList(findPassenger)){
        cout << "Passenger is in Flight List 300" << endl;
    }else if(list400.searchList(findPassenger)) {
        cout << "Passenger is in Flight List 400" << endl;
    }else{
        cerr << "Didn't find the passenger in any Flight Lists." << endl;
    }
}

//to add passenger object to flight list in alphabetical order
void addPassenger(int fnum, Passenger newPassenger){
    switch(fnum){
        case 100:
            list100.insertAlphabetical(newPassenger);
            break;
        case 200:
            list200.insertAlphabetical(newPassenger);
            break;
        case 300:
            list300.insertAlphabetical(newPassenger);
            break;
        case 400:
            list400.insertAlphabetical(newPassenger);
            break;
        default:
            cout << "idk what went wrong. printing them all..." << endl;
            cout << list100 << list200 << list300 << list400;
    }
}

//to delete a passenger
void deletePassenger(int fnum, Passenger newPassenger){
    switch(fnum){
        case 100:
            list100.deleteNode(newPassenger);
            break;
        case 200:
            list200.deleteNode(newPassenger);
            break;
        case 300:
            list300.deleteNode(newPassenger);
            break;
        case 400:
            list400.deleteNode(newPassenger);
            break;
        default:
            cout << "idk what went wrong. printing them all..." << endl;
            cout << list100 << list200 << list300 << list400;
    }
}

//get info for adding
Passenger getPassengerInfo(){
    string fname;
    fname = enterFname();
    string lname;
    lname = enterLname();
    string address;
    address = enterAddress();
    int pnum;
    pnum = enterPhone();
    Passenger newPassenger(fname, lname, address, pnum);
    return newPassenger;
}

//get info for searching or deleting
Passenger searchInfo(){
    string fname;
    fname = enterFname();
    string lname;
    lname = enterLname();
    Passenger newPassenger(fname, lname);
    return newPassenger;
}

//getting flight number
int enterFlight(){
    int fnum;
    cout << "Enter Flight number: ";
    cout << "100, 200, 300, or 400.";
    cin >> fnum;
    return fnum;
}

//getting first name
string enterFname(){
    string fname;
    cout << "Enter first name: ";
    cin >> fname;
    return fname;
}

//getting last name
string enterLname(){
    string lname;
    cout << "Enter last name: ";
    cin >> lname;
    return lname;
}

//getting address
string enterAddress(){
    string address;
    cout << "Enter address: ";
    cin.ignore(INT_MAX, '\n');
    getline(cin, address);
    return address;
}

//getting phone number
int enterPhone(){
    int pnum;
    cout << "Enter phone number: ";
    cin >> pnum;
    return pnum;
}

