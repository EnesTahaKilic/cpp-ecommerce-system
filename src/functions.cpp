#include "functions.h"
#include <iostream>
#include <limits>

using namespace std;

int getPositiveInt()
{
    int value;

    while (true)
    {
        cin >> value;

        if (cin.fail() || value <= 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Please enter a positive number: ";
        }
        else
        {
            return value;
        }
    }
}

int getNonNegativeInt()
{
    int value;

    while (true)
    {
        cin >> value;

        if (cin.fail() || value < 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Please enter a non-negative number: ";
        }
        else
        {
            return value;
        }
    }
}

void addProduct(vector<Product>& products, int& nextID)
{
    string name;
    int price;
    int stock;

    cout << "Enter product name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);

    while (name.empty())
    {
        cout << "Product name cannot be empty!" << endl;
        cout << "Enter product name: ";
        getline(cin, name);
    }

    cout << "Enter product price: ";
    price = getPositiveInt();

    cout << "Enter product stock: ";
    stock = getNonNegativeInt();

    Product product(nextID, name, price, stock);
    products.push_back(product);

    cout << "Product added successfully!\n";

    nextID++;
}

void listProducts(const vector<Product>& products)
{
    if (products.empty())
    {
        cout << "No products available." << endl;
        return;
    }

    cout << "\n===== PRODUCT LIST =====" << endl;

    for (int i = 0; i < products.size(); i++)
    {
        products[i].display();
    }
}

void searchProduct(const vector<Product>& products)
{
    int id;

    cout << "Enter product ID: ";
    id = getPositiveInt();

    for (int i = 0; i < products.size(); i++)
    {
        if (products[i].getID() == id)
        {
            products[i].display();
            return;
        }
    }

    cout << "Product not found!" << endl;
}

void removeProduct(vector<Product>& products)
{
    int id;

    cout << "Enter product ID: ";
    id = getPositiveInt();

    for (int i = 0; i < products.size(); i++)
    {
        if (products[i].getID() == id)
        {
            products.erase(products.begin() + i);

            cout << "Product removed successfully!" << endl;
            return;
        }
    }

    cout << "Product not found!" << endl;
}

void showMenu()
{
    cout << "\n========================\n";
    cout << "     MINI E-COMMERCE\n";
    cout << "========================\n";
    cout << "1. Add Product\n";
    cout << "2. List Products\n";
    cout << "3. Search Product\n";
    cout << "4. Remove Product\n";
    cout << "5. Add to Cart\n";
    cout << "6. View Cart\n";
    cout << "7. Remove from Cart\n";
    cout << "8. Checkout\n";
    cout << "9. Exit\n";
    cout << "Choose: ";
}