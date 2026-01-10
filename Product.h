#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;

class Product {
public:
    Product();
    Product(int id, string name, string category, double price, int quantity, int locationId);
    ~Product();

    int getId() const;
    void setId(int id);

    string getName() const;
    void setName(string name);

    string getCategory() const;
    void setCategory(string category);

    double getPrice() const;
    void setPrice(double price);

    int getQuantity() const;
    void setQuantity(int quantity);

    int getLocationId() const;
    void setLocationId(int locationId);

    void updateStock(int quantity);
    void updateStock(string action, int quantity); // overloading (already required)
    void displayInfo() const;

    // Operator overloading (Phase 2)
    bool operator==(const Product& other) const;  // compare by ID
    bool operator<(const Product& other) const;   // compare by quantity (for sorting / low stock)

private:
    int id_;
    string name_;
    string category_;
    double price_;
    int quantity_;
    int locationId_;  // for Dijkstra problem (warehouse node)
};

#endif
