#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <vector>
#include "CartItem.h"
#include "Product.h"

class ShoppingCart
{
private:
    std::vector<CartItem> items;

public:
    void addToCart(std::vector<Product>& products);
    void displayCart(std::vector<Product>& products);
    void removeFromCart();
    int calculateTotal(std::vector<Product>& products);
    void checkout(std::vector<Product>& products);
};

#endif
