#ifndef ORDER_H
#define ORDER_H

#include "OrderItem.h"
#include "User.h"
#include <vector>
#include <string>
using namespace std;

class DatabaseManager; // forward decl just for friend line

class Order {
private:
    static int nextId_;        // static variable (Phase 2)
    int orderId_;
    User customer_;
    vector<OrderItem> items_;
    double totalAmount_;

public:
    Order();
    Order(const User& customer);
    ~Order();

    void addItem(const OrderItem& item);
    void removeItem(int index);
    void calculateTotal();
    double getTotalAmount() const;
    string getOrderDetails() const;

    int getOrderId() const;
    User getCustomer() const;

    // friend usage (Phase 2)
    friend class DatabaseManager;
};

#endif
