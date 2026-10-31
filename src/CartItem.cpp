#include "CartItem.h"

CartItem::CartItem(int id, int qty)
{
    productID = id;
    quantity = qty;
}

int CartItem::getProductID() const
{
    return productID;
}

int CartItem::getQuantity() const
{
    return quantity;
}

void CartItem::setQuantity(int qty)
{
    quantity = qty;
}