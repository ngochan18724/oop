#include "Admin.h"

// Constructor
Admin::Admin(const std::string& adminUsername, const std::string& adminPassword)
    : username(adminUsername), password(adminPassword) {}

// Authentication method
bool Admin::authenticate(const std::string& adminUsername, const std::string& adminPassword) const {
    return (username == adminUsername && password == adminPassword);
}
