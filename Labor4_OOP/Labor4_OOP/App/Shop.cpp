#include "../Repository/Repository.h"
#include "../UI/UI.h"
#include "cassert"

using namespace std;

void testAdd() {
    FruitRepo repo;
    FruitController ctrl(repo);
    string name = "Banana";
    string origin = "Romania";
    int price = 25;
    int quantity = 50;
    string expirationDate = "23-03-2023";
    ctrl.add(name, origin, price, quantity, expirationDate);
    assert(repo.getFruit(11).getName() == name);
    assert(repo.getFruit(11).getOrigin() == origin);
    assert(repo.getFruit(11).getPrice() == price);
    assert(repo.getFruit(11).getQuantity() == quantity);
//    assert(repo.getFruit(11).getExpirationDate() == Fruit::timeToStr(repo.getFruit(11).getExpirationDate()));
}

void testRemove() {
    FruitRepo repo;
    FruitController ctrl(repo);
    string name = "Banana";
    string origin = "Romania";
    int price = 25;
    int quantity = 50;
    string expirationDate = "23-03-2023";
    ctrl.add(name, origin, price, quantity, expirationDate);
    assert(repo.getListSize() == 0);
}

void testSearch() {
    FruitRepo repo;
    FruitController ctrl(repo);
    string name = "Banana";
    string origin = "Romania";
    string substring = "na";
    int price = 25;
    int quantity = 50;
    string expirationDate = "23-03-2023";
    vector<Fruit> fruitList;
    Fruit fruit(name, origin, price, quantity, expirationDate);
    fruitList.push_back(fruit);
    ctrl.add(name, origin, price, quantity, expirationDate);
//    assert(ctrl.searchName(substring) == fruitList);

}


void testQuantity() {
    FruitRepo repo;
    FruitController ctrl(repo);
    string name = "Banana";
    string origin = "Romania";
    string substring = "na";
    int price = 25;
    int quantity = 50;
    string expirationDate = "23-03-2023";
    vector<Fruit> fruitList;
    Fruit fruit(name, origin, price, quantity, expirationDate);
    fruitList.push_back(fruit);
    ctrl.add(name, origin, price, quantity, expirationDate);
//    assert(ctrl.searchQuantity(70) == fruitList);

}



void testAll() {
    testAdd();
    testRemove();
    testSearch();
    testQuantity();
}




int main() {

//    testAll();
    FruitRepo repo{};
    FruitController controller(repo);
    FruitUI ui(controller);
    ui.start();

}
