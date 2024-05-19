#ifndef STUDENTMANAGEMENTSYSTEM_H
#define STUDENTMANAGEMENTSYSTEM_H

#include "Student.h"
#include <vector>

class StudentManagementSystem {
private:
    std::vector<Student> students;

public:
    // Add a new student
    void addStudent(const Student& student);

    // Display all students
    void displayAllStudents() const;

    // Search for a student by ID
    void searchStudentById(int id) const;

    // Remove a student by ID
    void removeStudentById(int id);

    // Update student details
    void updateStudent(int id, const std::string& name, int age, const std::string& major, const std::string& password);

    // Authenticate student
    bool authenticateStudent(int id, const std::string& password) const;
};

#endif
