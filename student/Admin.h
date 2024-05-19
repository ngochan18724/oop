#ifndef ADMIN_H
#define ADMIN_H

#include <string>

class Admin {
private:
    std::string username;
    std::string password;

public:
    // Constructor
    Admin(const std::string& adminUsername, const std::string& adminPassword);

    // Authentication method
    bool authenticate(const std::string& adminUsername, const std::string& adminPassword) const;
};

#endif
