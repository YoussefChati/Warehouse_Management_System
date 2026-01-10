#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
public:
    User();
    User(int id, string name, string email, string role, string password);
    ~User();

    int getId() const;
    void setId(int id);

    string getName() const;
    void setName(string name);

    string getEmail() const;
    void setEmail(string email);

    string getRole() const;
    void setRole(string role);

    bool verifyPassword(string inputPassword) const;
    void changePassword(string oldPassword, string newPassword);
    void updateEmail(string newEmail);
    void displayInfo() const;
    string getUserSummary() const;

protected:
    int id_;
    string name_;
    string email_;
    string role_;
    string password_;
};

#endif
