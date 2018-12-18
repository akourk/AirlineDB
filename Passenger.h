// Author       :   Alex Kourkoumelis
// Date         :   11/4/2017
// Title        :   Airline Database
// Description  :   Creates a database of 4 ordered linked lists
//                  each maintained in alphabetical order by last name.
//                  Prompts user to add, delete, search, list, quit

#ifndef ATTEMPT4_PASSENGER_H
#define ATTEMPT4_PASSENGER_H
#include <iostream>
using namespace std;

class Passenger{

private:
    string fname;
    string lname;
    string address;
    int pnum;

public:
    Passenger(){}
    Passenger(string fname, string lname, string address, int pnum){
        this->fname=fname;
        this->lname=lname;
        this->address=address;
        this->pnum=pnum;
    }

    //for passenger objects that only require names: search & delete functions
    Passenger(string fname, string lname){
        this->fname=fname;
        this->lname=lname;
    }

    const string &getFname() const {
        return fname;
    }

    void setFname(const string &fname) {
        Passenger::fname = fname;
    }

    const string &getLname() const {
        return lname;
    }

    void setLname(const string &lname) {
        Passenger::lname = lname;
    }

    const string &getAddress() const {
        return address;
    }

    void setAddress(const string &address) {
        Passenger::address = address;
    }

    int getPnum() const {
        return pnum;
    }

    void setPnum(int pnum) {
        Passenger::pnum = pnum;
    }

    //to print passenger objects
    friend ostream& operator<<(ostream& os, Passenger& p){
        os << p.getFname() << " " << p.getLname() << " " << p.getAddress() << " " << p.getPnum() << endl;
        return os;
    }

    //to compare passenger objects with "=="
    friend bool operator==(Passenger& p1, Passenger& p2){
        if(p1.getFname()==p2.getFname() && p1.getLname()==p2.getLname()){
            return true;
        }
        return false;
    }

    //to compare passenger objects with "!="
    friend bool operator!=(Passenger& p1, Passenger& p2){
        if(p1.getFname()!=p2.getFname()){
            return true;
        }
        return false;
    }

    //to compare passenger objects with "<"
    friend bool operator<(Passenger& p1, Passenger& p2){
        if(p1.getLname()<p2.getLname()){
            return true;
        }
        return false;
    }

    //to compare passenger objects with ">"
    friend bool operator>(Passenger& p1, Passenger& p2){
        if(p1.getLname()>p2.getLname()){
            return true;
        }
        return false;
    }
};


#endif //ATTEMPT4_PASSENGER_H
