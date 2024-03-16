#include "Controller.h"
#include "algorithm"

/**
 * constructor
 * @param repo
 */
FruitController::FruitController(FruitRepo &repo) {
    this->repo = &repo;
}

/**
 * Adds a new fruit to the list or increases the quantity of an existing fruit
 * @param name
 * @param origin
 * @param price
 * @param quantity
 * @param expirationDate
 */
void FruitController::add(string &name, string &origin, int price, int quantity, string &expirationDate) {
    for (int i = 0; i < repo->getListSize(); i++) {
        if (name == repo->getFruit(i).getName() && origin == repo->getFruit(i).getOrigin()) {
            repo->addExistingFruit(i, quantity);
            return;
        }
    }

    Fruit newFruit = Fruit(name, origin, price, quantity, expirationDate);
    repo->addNewFruit(newFruit);
}

/**
 * Removes a fruit from the list
 * @param name
 * @param origin
 */
void FruitController::remove(string &name, string &origin) {
    for (int i = 0; i < repo->getListSize(); i++) {
        if (name == repo->getFruit(i).getName() && origin == repo->getFruit(i).getOrigin()) {
            repo->removeFruit(i);
            return;
        }
    }
}

/**
 * Searches all matches of a string given by the user
 * @param searchName
 * @returns all matches of the substring
 */
vector<Fruit> FruitController::searchName(string &searchName) {
    vector<Fruit> foundFruits;

    if (searchName.size() == 0) {
        vector<Fruit> sortedFruits = repo->getAll();
        return sortedFruits;
    } else {
        for (int i = 0; i < repo->getListSize(); i++) {
            size_t found = repo->getFruit(i).getName().find(searchName);
            if (found != string::npos) {
                foundFruits.push_back(repo->getFruit(i));
            }
        }
        return foundFruits;
    }
}

/**
 * Finds all fruits with a quantity lower than a value given by the user
 * @param compareQuantity
 * @returns a vector of fruits
 */
vector<Fruit> FruitController::searchQuantity(int compareQuantity) {
    vector<Fruit> foundFruits;
    for (int i = 0; i < repo->getListSize(); i++) {
        if (repo->getFruit(i).getQuantity() < compareQuantity) {
            foundFruits.push_back(repo->getFruit(i));
        }
    }

    return foundFruits;
}

/**
 * Prints all fruits sorted by expiration date
 * @returns all fruits of the list
 */
vector<Fruit> FruitController::showAll() {
    vector<Fruit> sortedFruits = repo->getAll();


}
/**
 * Sorts all fruits by expiration date
 * @returns a list of fruits sorted by expiration date
 */
vector<Fruit> FruitController::sortByExpirationDate() {
    vector<Fruit> list = repo->getAll();

    sort(list.begin(), list.end(), [](const Fruit &fruit1, const Fruit &fruit2) {
        return fruit1.getExpirationDate() < fruit2.getExpirationDate();
    });

    return list;
}