//
// Created by Lukasz on 2016-01-15.
//

#include "Controller.h"

class Work{

private:

    Controller*   controller;

public:

    Work(int opcja)
    {
        controller->handleEvent(opcja);
    }

};

