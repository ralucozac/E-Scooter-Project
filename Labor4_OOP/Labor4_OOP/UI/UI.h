#pragma once

#include "../Controller/Controller.h"

class FruitUI {

private:
    FruitController *ctrl;

public:

    FruitUI(FruitController &ctrl);

    void start();

    void optionsMenu();

};