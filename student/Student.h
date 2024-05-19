#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    int id;
    std::string name;
    int age;
    std::string major;
    std::string password;

public:
    // Constructor
    Student(int studentId, const std::string& studentName, int studentAge, const std::string& studentMajor, const std::string& studentPassword);

    // Getter methods
    int getId() const;
    std::string getName() const;
    int getAge() const;
    std::string getMajor() const;
    std::string getPassword() const;

    // Display student details
    void display() const;
};

#endif
