#include "Product.h"
#include <iostream>

using namespace std;

Product::Product(int i, string n, int p, int s)
{
    id = i;
    name = n;
    price = p;
    stock = s;
}

int Product::getID() const
{
    return id;
}

int Product::getStock() const
{
    return stock;
}

int Product::getPrice() const
{
    return price;
}

void Product::reduceStock(int quantity)
{
    stock -= quantity;
}

void Product::display() const
{
    cout << "\n\n";
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Price: " << price << endl;
    cout << "Stock: " << stock << endl;
}