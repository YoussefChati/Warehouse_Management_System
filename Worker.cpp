#include "Worker.h"
#include <iostream>

using namespace std;

Worker::Worker()
    : User(), position_(""), salary_(0.0), shift_(""), currentLocationId_(0)
{
    // empty
}

Worker::Worker(int id, string name, string email, string password,
               string position, double salary, string shift, int currentLocationId)
    : User(id, name, email, "worker", password),
      position_(position), salary_(salary), shift_(shift), currentLocationId_(currentLocationId)
{
    // empty
}

Worker::~Worker() {}

string Worker::getPosition() const { return position_; }
void Worker::setPosition(string position) { position_ = position; }

double Worker::getSalary() const { return salary_; }
void Worker::setSalary(double salary) { salary_ = salary; }

string Worker::getShift() const { return shift_; }
void Worker::setShift(string shift) { shift_ = shift; }

int Worker::getCurrentLocationId() const { return currentLocationId_; }
void Worker::setCurrentLocationId(int locationId) { currentLocationId_ = locationId; }

void Worker::updateShift(string newShift) {
    shift_ = newShift;
}

void Worker::increaseSalary(double percentage) {
    if (percentage > 0) salary_ += salary_ * (percentage / 100.0);
    else cout << "Invalid percentage." << endl;
}

void Worker::displayInfo() const {
    cout << "Worker ID: " << id_ << endl;
    cout << "Name: " << name_ << endl;
    cout << "Email: " << email_ << endl;
    cout << "Position: " << position_ << endl;
    cout << "Salary: " << salary_ << endl;
    cout << "Shift: " << shift_ << endl;
    cout << "Current Location ID: " << currentLocationId_ << endl;
}
