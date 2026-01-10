#include "DatabaseManager.h"
#include <iostream>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

DatabaseManager::DatabaseManager()
    : nodeCount_(0)
{
    // empty
}

DatabaseManager::~DatabaseManager() {}

void DatabaseManager::addProduct(const Product& product) {
    products_.push_back(product);
}

void DatabaseManager::addUser(const User& user) {
    users_.push_back(user);
}

void DatabaseManager::addWorker(const Worker& worker) {
    workers_.push_back(worker);
}

void DatabaseManager::addOrder(const Order& order) {
    orders_.push_back(order);
}

void DatabaseManager::showProducts() const {
    cout << "--- Products ---" << endl;
    for (const auto& p : products_) {
        p.displayInfo();
        cout << "-----------------" << endl;
    }
}

void DatabaseManager::showUsers() const {
    cout << "--- Users ---" << endl;
    for (const auto& u : users_) {
        u.displayInfo();
        cout << "-----------------" << endl;
    }
}

void DatabaseManager::showWorkers() const {
    cout << "--- Workers ---" << endl;
    for (const auto& w : workers_) {
        w.displayInfo();
        cout << "-----------------" << endl;
    }
}

void DatabaseManager::showOrders() const {
    cout << "--- Orders ---" << endl;
    for (const auto& o : orders_) {
        cout << o.getOrderDetails();
        cout << "-----------------" << endl;
    }
}

// -------------------- Problem 2: Low stock report --------------------

vector<Product> DatabaseManager::getLowStockProducts(int threshold) const {
    vector<Product> result;
    for (const auto& p : products_) {
        if (p.getQuantity() < threshold) {
            result.push_back(p);
        }
    }
    return result;
}

void DatabaseManager::printLowStockReport(int threshold, int targetQty) const {
    cout << "=== Low Stock Report ===" << endl;
    cout << "Threshold: " << threshold << " | Target Qty: " << targetQty << endl;

    vector<Product> low = getLowStockProducts(threshold);
    if (low.empty()) {
        cout << "No products under threshold." << endl;
        return;
    }

    int totalMissing = 0;
    for (const auto& p : low) {
        int missing = max(0, targetQty - p.getQuantity());
        totalMissing += missing;

        cout << "Product: " << p.getName()
             << " | Qty: " << p.getQuantity()
             << " | Missing to target: " << missing << endl;
    }

    cout << "Total units needed to reach target for all low-stock products: "
         << totalMissing << endl;
}

// -------------------- Problem 1: Dijkstra (warehouse graph) --------------------

void DatabaseManager::setWarehouseNodeCount(int nodeCount) {
    nodeCount_ = nodeCount;
    adj_.clear();
    adj_.resize(nodeCount_);
}

void DatabaseManager::addPath(int from, int to, double cost) {
    if (from < 0 || to < 0 || from >= nodeCount_ || to >= nodeCount_) return;
    adj_[from].push_back({to, cost});
    adj_[to].push_back({from, cost}); // undirected paths (warehouse aisle both ways)
}

double DatabaseManager::shortestDistance(int start, int target) const {
    if (start < 0 || target < 0 || start >= nodeCount_ || target >= nodeCount_) {
        return numeric_limits<double>::infinity();
    }

    vector<double> dist(nodeCount_, numeric_limits<double>::infinity());
    dist[start] = 0.0;

    priority_queue<pair<double,int>, vector<pair<double,int>>, greater<pair<double,int>>> pq;
    pq.push({0.0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;
        if (u == target) return dist[u];

        for (auto [v, w] : adj_[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist[target];
}

vector<int> DatabaseManager::shortestPath(int start, int target) const {
    vector<int> empty;
    if (start < 0 || target < 0 || start >= nodeCount_ || target >= nodeCount_) return empty;

    vector<double> dist(nodeCount_, numeric_limits<double>::infinity());
    vector<int> parent(nodeCount_, -1);

    dist[start] = 0.0;

    priority_queue<pair<double,int>, vector<pair<double,int>>, greater<pair<double,int>>> pq;
    pq.push({0.0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, w] : adj_[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[target] == numeric_limits<double>::infinity()) return empty;

    vector<int> path;
    for (int cur = target; cur != -1; cur = parent[cur]) path.push_back(cur);
    reverse(path.begin(), path.end());
    return path;
}

// Estimate picking distance: worker -> each product location (simple sum of shortest paths)
double DatabaseManager::estimatePickDistance(const Worker& worker, const Order& order) const {
    if (nodeCount_ == 0) return 0.0;

    int current = worker.getCurrentLocationId();
    double total = 0.0;

    // DatabaseManager is friend of Order, so we can access order.items_ directly
    for (const auto& item : order.items_) {
        int loc = item.getProductLocation();
        double d = shortestDistance(current, loc);
        if (d == numeric_limits<double>::infinity()) {
            cout << "No path to location " << loc << endl;
            continue;
        }
        total += d;
        current = loc; // next pickup starts from last location
    }

    return total;
}

int DatabaseManager::findProductIndexById(int id) const {
    Product temp(id, "", "", 0.0, 0, 0);
    for (int i = 0; i < (int)products_.size(); i++) {
        if (products_[i] == temp) return i; // uses operator==
    }
    return -1;
}
