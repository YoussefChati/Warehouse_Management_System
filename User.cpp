#include "User.h"
#include <iostream>

using namespace std;

User::User()
    : id_(0), name_(""), email_(""), role_("guest"), password_("")
{
    // empty
}

User::User(int id, string name, string email, string role, string password)
    : id_(id), name_(name), email_(email), role_(role), password_(password)
{
    // empty
}

User::~User() {}

int User::getId() const { return id_; }
void User::setId(int id) { id_ = id; }

string User::getName() const { return name_; }
void User::setName(string name) { name_ = name; }

string User::getEmail() const { return email_; }
void User::setEmail(string email) { email_ = email; }

string User::getRole() const { return role_; }
void User::setRole(string role) { role_ = role; }

bool User::verifyPassword(string inputPassword) const {
    return inputPassword == password_;
}

void User::changePassword(string oldPassword, string newPassword) {
    if (oldPassword == password_) password_ = newPassword;
    else cout << "Wrong old password." << endl;
}

void User::updateEmail(string newEmail) {
    email_ = newEmail;
}

void User::displayInfo() const {
    cout << "User ID: " << id_ << endl;
    cout << "Name: " << name_ << endl;
    cout << "Email: " << email_ << endl;
    cout << "Role: " << role_ << endl;
}

string User::getUserSummary() const {
    return "User[" + to_string(id_) + "] " + name_ + " (" + role_ + ")";
}
