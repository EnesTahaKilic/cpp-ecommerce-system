#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include "Product.h"

int getPositiveInt();
int getNonNegativeInt();

void showMenu();

void addProduct(std::vector<Product>& products, int& nextID);
void listProducts(const std::vector<Product>& products);
void searchProduct(const std::vector<Product>& products);
void removeProduct(std::vector<Product>& products);

#endif
