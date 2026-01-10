#ifndef ORDERITEM_H
#define ORDERITEM_H

#include "Product.h"
#include <string>
#include <iostream>
using namespace std;

class OrderItem {
public:
    OrderItem();
    OrderItem(const Product& product, int quantity);
    ~OrderItem();

    void setQuantity(int quantity);
    int getQuantity() const;

    Product getProduct() const;
    string getProductName() const;
    int getProductLocation() const;

    double getSubtotal() const;
    void updateSubtotal();
    void displayItemInfo() const;

    // Operator overloading (Phase 2)
    friend ostream& operator<<(ostream& os, const OrderItem& item);

private:
    Product product_;
    int quantity_;
    double subtotal_;
};

#endif
