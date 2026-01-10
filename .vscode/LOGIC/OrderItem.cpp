#include "OrderItem.h"

using namespace std;

OrderItem::OrderItem()
    : product_(), quantity_(0), subtotal_(0.0)
{
    // empty
}

OrderItem::OrderItem(const Product& product, int quantity)
    : product_(product), quantity_(quantity), subtotal_(0.0)
{
    updateSubtotal();
}

OrderItem::~OrderItem() {}

void OrderItem::setQuantity(int quantity) {
    if (quantity >= 0) {
        quantity_ = quantity;
        updateSubtotal();
    }
    else {
        cout << "Invalid quantity." << endl;
    }
}

int OrderItem::getQuantity() const { return quantity_; }

Product OrderItem::getProduct() const { return product_; }

string OrderItem::getProductName() const {
    return product_.getName();
}

int OrderItem::getProductLocation() const {
    return product_.getLocationId();
}

double OrderItem::getSubtotal() const { return subtotal_; }

void OrderItem::updateSubtotal() {
    subtotal_ = product_.getPrice() * quantity_;
}

void OrderItem::displayItemInfo() const {
    cout << product_.getName() << " x " << quantity_
         << " | Subtotal: $" << subtotal_ << endl;
}

ostream& operator<<(ostream& os, const OrderItem& item) {
    os << item.product_.getName()
       << " x " << item.quantity_
       << " | Subtotal: $" << item.subtotal_;
    return os;
}
