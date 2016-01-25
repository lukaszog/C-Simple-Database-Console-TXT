//
// Created by Lukasz on 2016-01-14.
//

#ifndef CDDB_CONTROLLER_H
#define CDDB_CONTROLLER_H


#include "Observer.h"
#include "View.h"
#include "Controller.h"

class View;

class Controller : public Observer {

public:
    void handleEvent(int option);

    Controller( View *v )  : myView(v){
        myModel = myView->getModel();
        myModel->attach(this);
    }

    virtual ~Controller() { }
    virtual void update() { }

protected:
    Model   *myModel;
    View    *myView;

};


#endif //CDDB_CONTROLLER_H
