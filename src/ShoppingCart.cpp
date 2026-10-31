#include "ShoppingCart.h"
#include "functions.h"
#include <iostream>
#include <cstddef>

using namespace std;

void ShoppingCart::addToCart(vector<Product>& products)
{
    int id;
    int quantity;

    cout << "Enter product ID: ";
    id = getPositiveInt();

    cout << "Enter quantity: ";
    quantity = getPositiveInt();

    for (std::size_t i = 0; i < products.size(); i++)
    {
        if (products[i].getID() == id)
        {
            if (quantity > products[i].getStock())
            {
                cout << "Not enough stock!" << endl;
                return;
            }

            for (std::size_t j = 0; j < items.size(); j++)
            {
                if (items[j].getProductID() == id)
                {
                    int newQuantity =
                        items[j].getQuantity() + quantity;

                    if (newQuantity > products[i].getStock())
                    {
                        cout << "Not enough stock!" << endl;
                        return;
                    }

                    items[j].setQuantity(newQuantity);

                    cout << "Product quantity updated in cart." << endl;
                    return;
                }
            }

            items.push_back(CartItem(id, quantity));

            cout << "Product added to cart." << endl;
            return;
        }
    }

    cout << "Product not found!" << endl;
}

void ShoppingCart::displayCart(vector<Product>& products)
{
    if (items.empty())
    {
        cout << "Shopping cart is empty!" << endl;
        return;
    }

    cout << "\n===== SHOPPING CART =====" << endl;

    for (std::size_t i = 0; i < items.size(); i++)
    {
        int productID = items[i].getProductID();
        int quantity = items[i].getQuantity();

        for (std::size_t j = 0; j < products.size(); j++)
        {
            if (products[j].getID() == productID)
            {
                cout << "Product: ";
                products[j].display();

                cout << "Quantity: " << quantity << endl;

                break;
            }
        }
    }
}

void ShoppingCart::removeFromCart()
{
    int id;
    int quantity;

    cout << "Enter product ID: ";
    id = getPositiveInt();

    cout << "Enter quantity to remove: ";
    quantity = getPositiveInt();

    for (std::size_t i = 0; i < items.size(); i++)
    {
        if (items[i].getProductID() == id)
        {
            if (quantity > items[i].getQuantity())
            {
                cout << "You cannot remove more than the quantity in the cart!" << endl;
                return;
            }

            if (quantity == items[i].getQuantity())
            {
                items.erase(items.begin() + i);

                cout << "Product removed from cart." << endl;
                return;
            }

            items[i].setQuantity(items[i].getQuantity() - quantity);

            cout << "Product quantity updated in cart." << endl;
            return;
        }
    }

    cout << "Product not found in cart!" << endl;
}

int ShoppingCart::calculateTotal(vector<Product>& products)
{
    int total = 0;

    for (std::size_t i = 0; i < items.size(); i++)
    {
        int productID = items[i].getProductID();
        int quantity = items[i].getQuantity();

        for (std::size_t j = 0; j < products.size(); j++)
        {
            if (products[j].getID() == productID)
            {
                total += products[j].getPrice() * quantity;
                break;
            }
        }
    }

    return total;
}

void ShoppingCart::checkout(vector<Product>& products)
{
    if (items.empty())
    {
        cout << "Shopping cart is empty!" << endl;
        return;
    }

    int total = calculateTotal(products);

    cout << "\n===== CHECKOUT =====" << endl;

    displayCart(products);

    cout << "\nTotal: " << total << endl;

    char confirm;

    cout << "Confirm purchase? (y/n): ";
    cin >> confirm;

    if (confirm == 'y' || confirm == 'Y')
    {
        for (std::size_t i = 0; i < items.size(); i++)
        {
            int productID = items[i].getProductID();
            int quantity = items[i].getQuantity();

            for (std::size_t j = 0; j < products.size(); j++)
            {
                if (products[j].getID() == productID)
                {
                    if (quantity > products[j].getStock())
                    {
                        cout << "Not enough stock for product ID: "
                             << productID << endl;
                        return;
                    }

                    break;
                }
            }
        }

        for (std::size_t i = 0; i < items.size(); i++)
        {
            int productID = items[i].getProductID();
            int quantity = items[i].getQuantity();

            for (std::size_t j = 0; j < products.size(); j++)
            {
                if (products[j].getID() == productID)
                {
                    products[j].reduceStock(quantity);
                    break;
                }
            }
        }

        items.clear();

        cout << "Purchase successful!" << endl;
    }
    else
    {
        cout << "Purchase cancelled." << endl;
    }
}