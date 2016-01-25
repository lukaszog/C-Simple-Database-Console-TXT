//
// Created by Lukasz on 2016-01-14.
//

#include <fstream>
#include <sstream>
#include <stdio.h>
#include <iomanip>
#include "Model.h"
#include "Record.h"

using namespace std;

string db = "G:\\db.txt";
string db2 = "G:\\db2.txt";

void Model::notify() {

    set<Observer*>::iterator it;

    for(it = registry.begin(); it != registry.end(); it++)
    {
        (*it)->update();
    }
}

void Model::showDatabase() {

    cout << "Pokaz baze danych" << endl;
    ifstream file(db);

    string val1, val2;


    int i=1;

    cout << "\t\t Id. \t\t Numer \t\t Nazwa plyty" << endl;

    while(file >> val1 >> val2)
    {
       // file>>val1;
       // file>>val2;

        cout << "\t\t "<<i<<"\t\t"<<val1<<"\t\t"<<val2<<endl;

        i++;
    }

}
//odczyt
istream& operator >>(istream& myIn, Record& model){

    cout << "Podaj nazwe plyty: ";
    cin >> model.cdName;
    cout << "Podaj numer seryjny: ";
    cin >> model.idRecord;
}

void Model::saveToDatabase(){

    Record r;

    ofstream in(db,ios_base::app | ios_base::out);
    cout << "Dodaj rekod do bazy danych:" << endl;

    cin >> r;

    r.setCdName(r.cdName);
    r.setIdRecord(r.idRecord);

    in << r;
    in.close();
}

void Model::editRecord() {

    string recId;
    Record r;

    ifstream out(db,ios_base::app | ios_base::out);
    ofstream in(db2,ios_base::app | ios_base::out);

    cout << "Podaj numer seryjny wiersza ktory chcesz edytowac: "<<endl;
    cin >> recId;
    string val1,val2;

    cout << "Wprowac nowe dane" << endl;
    cin >> r;

    while (out >> val1 >> val2) {

       // out >> val1;
      //  out >> val2;

        if(!val1.compare(recId)) {
            in << r;
        }
        else {
            in << val1 << " " << val2 << endl;
        }
    }

    int re,rem;

    out.close(); //zamkniecie pliku db.txt
    in.close(); //zamkniecie pliku db2.txt

    re = remove(db.c_str());
    rem = rename(db2.c_str(),db.c_str());

    if(re == -1)
    {
        perror("Blad przy usuwaniu: ");
    }
    if(rem == -1)
    {
        perror("Blad przy zmianie nazwy: ");
    }

}

void Model::searchRecord() {

    string recId;

    cout << "Podaj numer seryjny: ";
    cin >> recId;

    string val1,val2;
    int i=1;

    ifstream file(db);

    cout << "\t\t Id. \t\t Numer \t\t Nazwa plyty" << endl;


    while(file >> val1 >> val2)
    {
        // file>>val1;
        // file>>val2;

        if(!val1.compare(recId)) {

            cout << "\t\t " << i<< "\t\t" << val1 << "\t\t" << val2 << endl;
            i++;
        }
    }

}