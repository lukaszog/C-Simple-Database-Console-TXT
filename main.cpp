#include <iostream>
#include <stdio.h>
#include "Model.h"
#include "Work.h"


using namespace std;

int main() {

    int opcja=0;
    bool check = true;

        while(check) {
            cout << "1) Pokaz baze danych" << endl;
            cout << "2) Dodaj rekord do bazy danych" << endl;
            cout << "3) Edytuj rekord" << endl;
            cout << "4) Wyszukaj rekord" << endl;

            cin >> opcja;

            try {
                Work work = Work(opcja);
            }
            catch (const char *wyjatek) {
                cout << "Error: " << wyjatek << endl;
                cin >> opcja;
            }
            if (opcja == 0) {
                check = false;
            }
        }

    getchar();

    return 0;

}