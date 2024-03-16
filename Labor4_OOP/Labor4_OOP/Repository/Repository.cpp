#include "Repository.h"

/**
 * constructor
 */
FruitRepo::FruitRepo() {
    Fruit apple("Apple", "romania", 25, 30, "23-03-2023");
    Fruit orange("Orange", "spain", 20, 35, "15-06-2023");
    Fruit banana("Banana", "ecuador", 15, 40, "30-09-2023");
    Fruit strawberry("Strawberry", "usa", 30, 25, "05-05-2023");
    Fruit grape("Grape", "italy", 40, 20, "10-08-2023");
    Fruit watermelon("Watermelon", "mexico", 50, 15, "20-07-2023");
    Fruit kiwi("Kiwi", "new zealand", 45, 18, "25-04-2023");
    Fruit peach("Peach", "greece", 35, 22, "02-07-2023");
    Fruit cherry("Cherry", "turkey", 50, 10, "12-06-2023");
    Fruit pineapple("Pineapple", "thailand", 60, 12, "18-09-2023");

    this->fruitList.push_back(apple);
    this->fruitList.push_back(orange);
    this->fruitList.push_back(banana);
    this->fruitList.push_back(strawberry);
    this->fruitList.push_back(grape);
    this->fruitList.push_back(watermelon);
    this->fruitList.push_back(kiwi);
    this->fruitList.push_back(peach);
    this->fruitList.push_back(cherry);
    this->fruitList.push_back(pineapple);
}
/**
 * Adds a new fruit to the repo
 * @param newFruit
 */

void FruitRepo::addNewFruit(Fruit &newFruit) {
    this->fruitList.push_back(newFruit);
}

/**
 * Increases the quantity of an already existing fruit
 * @param position
 * @param addedQuantity
 */
void FruitRepo::addExistingFruit(int position, int addedQuantity) {
    int newQuantity = this->fruitList[position].getQuantity() + addedQuantity;
    this->fruitList[position].setQuantity(newQuantity);
}

/**
 * Removes a fruit from repo
 * @param position
 */
void FruitRepo::removeFruit(int position) {
    this->fruitList.erase(fruitList.begin() + position);
}

/**
 *
 * @returns all elements from repo
 */
vector<Fruit> FruitRepo::getAll() {
    return this->fruitList;
}

/**
 *
 * @returns the size of the repo
 */
int FruitRepo::getListSize() {
    return this->fruitList.size();
}

/**
 *
 * @param position
 * @returns the fruit from a certain position
 */
Fruit FruitRepo::getFruit(int position) {
    return fruitList[position];
}


