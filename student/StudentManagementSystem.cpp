#include "StudentManagementSystem.h"
#include <iostream>

// Add a new student
void StudentManagementSystem::addStudent(const Student& student) {
    students.push_back(student);
}

// Display all students
void StudentManagementSystem::displayAllStudents() const {
    for (const auto& student : students) {
        student.display();
        std::cout << "--------------------" << std::endl;
    }
}

// Search for a student by ID
void StudentManagementSystem::searchStudentById(int id) const {
    for (const auto& student : students) {
        if (student.getId() == id) {
            student.display();
            return;
        }
    }
    std::cout << "Student with ID " << id << " not found." << std::endl;
}

// Remove a student by ID
void StudentManagementSystem::removeStudentById(int id) {
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->getId() == id) {
            students.erase(it);
            std::cout << "Student with ID " << id << " removed." << std::endl;
            return;
        }
    }
    std::cout << "Student with ID " << id << " not found." << std::endl;
}

// Update student details
void StudentManagementSystem::updateStudent(int id, const std::string& name, int age, const std::string& major, const std::string& password) {
    for (auto& student : students) {
        if (student.getId() == id) {
            student = Student(id, name, age, major, password);
            std::cout << "Student with ID " << id << " updated." << std::endl;
            return;
        }
    }
    std::cout << "Student with ID " << id << " not found." << std::endl;
}

// Authenticate student
bool StudentManagementSystem::authenticateStudent(int id, const std::string& password) const {
    for (const auto& student : students) {
        if (student.getId() == id && student.getPassword() == password) {
            return true;
        }
    }
    return false;
}
