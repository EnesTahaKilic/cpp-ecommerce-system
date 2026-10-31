#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product
{
private:
    int id;
    std::string name;
    int price;
    int stock;

public:
    Product(int i, std::string n, int p, int s);

    int getID() const;
    int getStock() const;
    int getPrice() const;

    void reduceStock(int quantity);
    void display() const;
};

#endif
