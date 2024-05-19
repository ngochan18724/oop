#include "Student.h"
#include <iostream>

// Constructor
Student::Student(int studentId, const std::string& studentName, int studentAge, const std::string& studentMajor, const std::string& studentPassword)
    : id(studentId), name(studentName), age(studentAge), major(studentMajor), password(studentPassword) {}

// Getter methods
int Student::getId() const {
    return id;
}

std::string Student::getName() const {
    return name;
}

int Student::getAge() const {
    return age;
}

std::string Student::getMajor() const {
    return major;
}

std::string Student::getPassword() const {
    return password;
}

// Display student details
void Student::display() const {
    std::cout << "ID: " << id << "\nName: " << name << "\nAge: " << age << "\nMajor: " << major << std::endl;
}
