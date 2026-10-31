#include "Product.h"
#include "CartItem.h"
#include "ShoppingCart.h"
#include "functions.h"

#include <iostream>
#include<vector>
using namespace std;

int main(){

    int choice = 0;
    vector<Product> products;
    ShoppingCart cart;
    int nextID=1;
    
    

    while (choice != 9){
    
        showMenu();
        cin >> choice;

        if(choice==1){
            addProduct(products, nextID);
        }

        else if(choice==2){
            listProducts(products);
        }

        else if(choice == 3){
            searchProduct(products);
        }
        
        else if(choice == 4){
            removeProduct(products);
        }

        else if(choice == 5){
            cart.addToCart(products);
        }

        else if(choice == 6){
            cart.displayCart(products);
        }

        else if(choice == 7){
            cart.removeFromCart();
        }

        else if(choice == 8){
            cart.checkout(products);
        }

        else if(choice == 9){
            cout << "Goodbye!" << endl;
        }


        else{
            cout << "Invalid choice!" << endl;
        }

    }


    return 0;

}

    
