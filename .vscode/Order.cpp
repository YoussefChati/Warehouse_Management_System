#include "Order.h"
#include <iostream>

using namespace std;

int Order::nextId_ = 1; // static definition

Order::Order()
    : orderId_(nextId_++), totalAmount_(0.0)
{
    
}

Order::Order(const User& customer)
    : orderId_(nextId_++), customer_(customer), totalAmount_(0.0)
{
    
}

Order::~Order() {}

void Order::addItem(const OrderItem& item) {
    items_.push_back(item);
    calculateTotal();
}

void Order::removeItem(int index) {
    if (index >= 0 && index < (int)items_.size()) {
        items_.erase(items_.begin() + index);
        calculateTotal();
    } else {
        cout << "Invalid index." << endl;
    }
}

void Order::calculateTotal() {
    totalAmount_ = 0.0;
    for (const auto& item : items_) {
        totalAmount_ += item.getSubtotal();
    }
}

double Order::getTotalAmount() const { return totalAmount_; }

string Order::getOrderDetails() const {
    string details = "Order ID: " + to_string(orderId_) + "\n";
    details += "Customer: " + customer_.getName() + "\n";
    details += "Items:\n";
    for (const auto& item : items_) {
        details += "  - " + item.getProductName()
                + " x " + to_string(item.getQuantity())
                + " | Subtotal: $" + to_string(item.getSubtotal()) + "\n";
    }
    details += "Total: $" + to_string(totalAmount_) + "\n";
    return details;
}

int Order::getOrderId() const { return orderId_; }
User Order::getCustomer() const { return customer_; }
