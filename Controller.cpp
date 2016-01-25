//
// Created by Lukasz on 2016-01-14.
//
#include<iostream>
#include "Controller.h"
#include <cstdlib>
#define clrscr() system("cls");
using namespace std;

Model *model;
//View  *view;

void Controller::handleEvent(int option)
{

   // View *v1 = new View(model);
  //  v1->initialize();

    switch (option){
        case 1:
            //read file
            clrscr();
            model->showDatabase();
            break;
        case 2:
            clrscr();
            model->saveToDatabase();
            break;
        case 3:
            clrscr();
            model->editRecord();
            break;
        case 4:
            clrscr();
            model->searchRecord();
            break;
        default:

            break;
    }
}
