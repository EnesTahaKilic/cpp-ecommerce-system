#ifndef CARTITEM_H
#define CARTITEM_H

class CartItem
{
private:
    int productID;
    int quantity;

public:
    CartItem(int id, int qty);

    int getProductID() const;
    int getQuantity() const;

    void setQuantity(int qty);
};

#endif