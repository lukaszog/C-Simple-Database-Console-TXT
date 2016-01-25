//
// Created by Lukasz on 2016-01-14.
//
#ifndef CDDB_VIEW_H
#define CDDB_VIEW_H


#include "Observer.h"
#include "Model.h"

class Controller;


class View : public Observer {


public:
    Model *myModel;
    Controller *myController;

    View(Model *m) : myModel(m), myController(0)
    {
        myModel->attach(this);
    }
    virtual ~View() {  }
    virtual void update() { }

    virtual void initialize() {
        myController = makeController();
    }
    virtual Controller *makeController() {
        //return new Controller(this);
    }

    Model *getModel() { return myModel; }
    Controller *getController() { return myController; }
};


#endif //CDDB_CONTROLLER_H
