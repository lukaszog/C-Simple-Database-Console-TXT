//
// Created by Lukasz on 2016-01-14.
//
#ifndef CDDB_MODEL_H
#define CDDB_MODEL_H

#include <iostream>
#include <cstdlib>
#include <list>
#include <set>
#include <iterator>
#include "Observer.h"

using namespace std;

class Model{


public:

    string cdName;
    int serialNumber;
    string dbfile = "C:\\Users\\Lukasz\\ClionProjects\\CDDB\\db.txt";
    string dbfile2 = "C:\\Users\\Lukasz\\ClionProjects\\CDDB\\db2.txt";


    Model(string cdName, int serialNumber)
    {
        this->cdName = cdName;
        this->serialNumber = serialNumber;
    }

    void showDatabase();
    void saveToDatabase();
    void searchRecord();
    void editRecord();

    void attach(Observer *s) { registry.insert(s); }
    void detach(Observer *s) { registry.erase(s); }
    friend istream& operator >>(istream& myIn, Model& model);

protected:
    virtual void notify();

private:
    set<Observer*> registry;
};

#endif //CDDB_CONTROLLER_H
