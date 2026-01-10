#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include "Product.h"
#include "User.h"
#include "Worker.h"
#include "Order.h"
#include <vector>
#include <string>
using namespace std;

class DatabaseManager {
public:
    DatabaseManager();
    ~DatabaseManager();

    // basic storage
    void addProduct(const Product& product);
    void addUser(const User& user);
    void addWorker(const Worker& worker);
    void addOrder(const Order& order);

    void showProducts() const;
    void showUsers() const;
    void showWorkers() const;
    void showOrders() const;

    // Problem 2 (report)
    vector<Product> getLowStockProducts(int threshold) const;
    void printLowStockReport(int threshold, int targetQty) const;

    // Problem 1 (Dijkstra)
    void setWarehouseNodeCount(int nodeCount);
    void addPath(int from, int to, double cost);
    double shortestDistance(int start, int target) const;
    vector<int> shortestPath(int start, int target) const;

    // route for picking an order
    double estimatePickDistance(const Worker& worker, const Order& order) const;

private:
    vector<Product> products_;
    vector<User> users_;
    vector<Worker> workers_;
    vector<Order> orders_;

    // Graph (warehouse map)
    int nodeCount_;
    vector<vector<pair<int,double>>> adj_;

    // helper: find product by id (uses operator==)
    int findProductIndexById(int id) const;
};

#endif
