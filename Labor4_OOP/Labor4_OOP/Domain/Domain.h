#pragma once

#include <string>

using namespace std;

class Fruit {

private:
    string name;
    string origin;
    int price;
    int quantity;
    time_t expirationDate;

public:

    Fruit(string name, string origin, int price, int quantity, string expirationDate);

    const string &getName() const;

    void setName(const string &name);

    const string &getOrigin() const;

    void setOrigin(const string &origin);

    int getPrice() const;

    void setPrice(int price);

    int getQuantity() const;

    void setQuantity(int quantity);

    const time_t &getExpirationDate() const;

    void setExpirationDate(time_t expirationDate);

    static time_t strToTime(const string &input);

    static string timeToStr(const time_t &input);
};