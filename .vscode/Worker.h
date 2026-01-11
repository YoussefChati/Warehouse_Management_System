#ifndef WORKER_H
#define WORKER_H

#include "User.h"
#include <string>
using namespace std;

class Worker : public User {
public:
    Worker();
    Worker(int id, string name, string email, string password,
           string position, double salary, string shift, int currentLocationId);
    ~Worker();

    string getPosition() const;
    void setPosition(string position);

    double getSalary() const;
    void setSalary(double salary);

    string getShift() const;
    void setShift(string shift);

    int getCurrentLocationId() const;
    void setCurrentLocationId(int locationId);

    void updateShift(string newShift);
    void increaseSalary(double percentage = 5.0); // default argument (Phase 2)
    void displayInfo() const;

private:
    string position_;
    double salary_;
    string shift_;
    int currentLocationId_; // warehouse node for Dijkstra
};

#endif
