#pragma once

#include "vector"
#include "../Domain/Domain.h"

class FruitRepo {

private:
    vector<Fruit> fruitList;

public:
    FruitRepo();

    void addExistingFruit(int position, int quantity);

    void addNewFruit(Fruit &newFruit);

    void removeFruit(int position);

    vector<Fruit> getAll();

    int getListSize();

    Fruit getFruit(int position);

};