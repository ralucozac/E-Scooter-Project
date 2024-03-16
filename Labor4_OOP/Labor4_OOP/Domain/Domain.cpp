#include <ctime>
#include "Domain.h"
#include <string>
#include <iomanip>

using namespace std;

Fruit::Fruit(string name, string origin, int price, int quantity, string expirationDate) {
    this->name = name;
    this->origin = origin;
    this->price = price;
    this->quantity = quantity;
    this->expirationDate = Fruit::strToTime(expirationDate);

}

const string &Fruit::getName() const {
    return name;
}

void Fruit::setName(const string &name) {
    Fruit::name = name;
}

const string &Fruit::getOrigin() const {
    return origin;
}

void Fruit::setOrigin(const string &origin) {
    Fruit::origin = origin;
}

int Fruit::getPrice() const {
    return price;
}

void Fruit::setPrice(int price) {
    Fruit::price = price;
}

int Fruit::getQuantity() const {
    return quantity;
}

void Fruit::setQuantity(int quantity) {
    Fruit::quantity = quantity;
}

const time_t &Fruit::getExpirationDate() const {
    return expirationDate;
}

void Fruit::setExpirationDate(time_t expirationDate) {
    Fruit::expirationDate = expirationDate;
}

time_t Fruit::strToTime(const string &input) {
    tm time{};
    stringstream ss(input);
    ss >> get_time(&time, "%d-%m-%Y");

    return mktime(&time);
}

string Fruit::timeToStr(const time_t &input) {
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%d-%m-%Y", std::localtime(&input));
    return {buffer};
}
