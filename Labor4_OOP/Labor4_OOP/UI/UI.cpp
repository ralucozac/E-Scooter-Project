#include "UI.h"
#include "iostream"

using namespace std;

FruitUI::FruitUI(FruitController &ctrl) {
    this->ctrl = &ctrl;
}

void FruitUI::start() {
    optionsMenu();
}

void FruitUI::optionsMenu() {

    cout << "1. Add fruit" << endl;
    cout << "2. Delete fruit" << endl;
    cout << "3. Search fruit by string" << endl;
    cout << "4. Filter fruits by quantity" << endl;
    cout << "5. Show all fruits" << endl;
    cout << "Choose an option: " << endl;

    int option;
    cin >> option;

    switch (option) {
        case 1: {
            string name, origin;
            string expirationDate;
            int price, quantity;
            cout << "Name: ";
            cin >> name;
            cout << "Origin: ";
            cin >> origin;
            cout << "Price: ";
            cin >> price;
            cout << "Quantity: ";
            cin >> quantity;
            cout << "Expiration date: ";
            cin >> expirationDate;
            ctrl->add(name, origin, price, quantity, expirationDate);
            cout << endl;
            optionsMenu();
            break;
        }

        case 2: {
            string name, origin;
            cout << "Name: ";
            cin >> name;
            cout << "Origin: ";
            cin >> origin;
            ctrl->remove(name, origin);
            cout << endl;
            optionsMenu();
            break;
        }

        case 3: {
            string searchName;
            vector<Fruit> foundFruits;
            cout << "String: ";
            cin >> searchName;
            foundFruits = ctrl->searchName(searchName);
            for (int i = 0; i < foundFruits.size(); i++) {
                cout << "Name: " << foundFruits[i].getName() << "," << "  ";
                cout << "Origin: " << foundFruits[i].getOrigin() << "," << "  ";
            }
            cout << endl;
            optionsMenu();
            break;
        }

        case 4: {
            int compareQuantity;
            vector<Fruit> foundFruits;
            cout << "Quantity: ";
            cin >> compareQuantity;
            foundFruits = ctrl->searchQuantity(compareQuantity);
            for (int i = 0; i < foundFruits.size(); i++) {
                cout << "Name: " << foundFruits[i].getName() << "," << "  ";
                cout << "Origin: " << foundFruits[i].getOrigin() << "," << "  ";
                cout << "Quantity: " << foundFruits[i].getQuantity() << "," << "  ";
                cout << endl;
            }

            cout << endl;
            optionsMenu();
            break;
        }

        case 5: {
            cout << "Fruits sorted by expiration date: " << endl;
            vector<Fruit> sortedFruits = ctrl->sortByExpirationDate();
            for (int i = 0; i < sortedFruits.size(); i++) {
                cout << "Name:" << sortedFruits[i].getName() << "," << "  ";
                cout << "Origin: " << sortedFruits[i].getOrigin() << "," << "  ";
                cout << "Price: " << sortedFruits[i].getPrice() << "," << "  ";
                cout << "Quantity: " << sortedFruits[i].getQuantity() << "," << "  ";
                cout << "Expiration date: " << Fruit::timeToStr(sortedFruits[i].getExpirationDate()) << "," << "  ";
                cout << endl;
            }

            cout << endl;
            optionsMenu();
            break;
        }

        default:
            optionsMenu();
    }
}