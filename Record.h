//
// Created by Lukasz on 2016-01-15.
//
#include<iostream>
#include<string>
using namespace std;

class Record{

public:

    int idRecord;
    string cdName;

    void setIdRecord(const int id)
    {
        this->idRecord = id;
    }

    void setCdName(const string name)
    {
        this->cdName = name;
    }

    friend istream& operator >>(istream& myIn, Record& record);
    friend ostream& operator <<(ostream& os, const Record& record);

};

//zapis do pliku
ostream& operator <<(ostream& myIn, Record& record)
{
    myIn << record.idRecord;
    myIn << " ";
    myIn << record.cdName;
    myIn << "\n";
   // myIn << "==\n";
    return myIn;
}







