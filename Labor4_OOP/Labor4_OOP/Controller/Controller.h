#pragma once

#include "../Repository/Repository.h"
#include "../Domain/Domain.h"

class FruitController {

private:
    FruitRepo *repo;

public:

    FruitController(FruitRepo &repo);

    void add(string &name, string &origin, int price, int quantity, string &expirationDate);

    void remove(string &name, string &origin);

    vector<Fruit> searchName(string &searchName);

    vector<Fruit> searchQuantity(int compareQuantity);

    vector<Fruit> showAll();

    vector<Fruit> sortByExpirationDate();

    static bool compareFruitsByName(Fruit &fruit1, Fruit &fruit2);

};