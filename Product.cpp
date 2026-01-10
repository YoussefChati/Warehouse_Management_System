#include "Product.h"
#include <iostream>

using namespace std;

Product::Product()
    : id_(0), name_(""), category_(""), price_(0.0), quantity_(0), locationId_(0)
{
    // empty
}

Product::Product(int id, string name, string category, double price, int quantity, int locationId)
    : id_(id), name_(name), category_(category), price_(price), quantity_(quantity), locationId_(locationId)
{
    // empty
}

Product::~Product() {}

int Product::getId() const { return id_; }
void Product::setId(int id) { id_ = id; }

string Product::getName() const { return name_; }
void Product::setName(string name) { name_ = name; }

string Product::getCategory() const { return category_; }
void Product::setCategory(string category) { category_ = category; }

double Product::getPrice() const { return price_; }
void Product::setPrice(double price) { price_ = price; }

int Product::getQuantity() const { return quantity_; }
void Product::setQuantity(int quantity) { quantity_ = quantity; }

int Product::getLocationId() const { return locationId_; }
void Product::setLocationId(int locationId) { locationId_ = locationId; }

void Product::updateStock(int quantity) {
    quantity_ += quantity;
}

void Product::updateStock(string action, int quantity) {
    if (action == "add") {
        quantity_ += quantity;
    }
    else if (action == "remove") {
        if (quantity_ >= quantity) quantity_ -= quantity;
        else cout << "Not enough stock to remove." << endl;
    }
    else {
        cout << "Invalid action. Use 'add' or 'remove'." << endl;
    }
}

void Product::displayInfo() const {
    cout << "Product ID: " << id_ << endl;
    cout << "Name: " << name_ << endl;
    cout << "Category: " << category_ << endl;
    cout << "Price: $" << price_ << endl;
    cout << "Quantity: " << quantity_ << endl;
    cout << "Location ID: " << locationId_ << endl;
}

bool Product::operator==(const Product& other) const {
    return id_ == other.id_;
}

bool Product::operator<(const Product& other) const {
    return quantity_ < other.quantity_;
}
