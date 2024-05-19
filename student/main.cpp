#include "StudentManagementSystem.h"
#include "Admin.h"
#include <iostream>

void displayMenu() {
    std::cout << "Student Management System\n";
    std::cout << "1. Admin Login\n";
    std::cout << "2. Student Login\n";
    std::cout << "3. Exit\n";
    std::cout << "Enter your choice: ";
}

void adminMenu(StudentManagementSystem& sms) {
    int choice;
    do {
        std::cout << "Admin Menu\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Display All Students\n";
        std::cout << "3. Search Student by ID\n";
        std::cout << "4. Remove Student by ID\n";
        std::cout << "5. Update Student\n";
        std::cout << "6. Logout\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            int id, age;
            std::string name, major, password;
            std::cout << "Enter ID: ";
            std::cin >> id;
            std::cin.ignore(); // Ignore the newline character left by std::cin
            std::cout << "Enter Name: ";
            std::getline(std::cin, name);
            std::cout << "Enter Age: ";
            std::cin >> age;
            std::cin.ignore();
            std::cout << "Enter Major: ";
            std::getline(std::cin, major);
            std::cout << "Enter Password: ";
            std::getline(std::cin, password);

            Student newStudent(id, name, age, major, password);
            sms.addStudent(newStudent);
            break;
        }
        case 2:
            sms.displayAllStudents();
            break;
        case 3: {
            int id;
            std::cout << "Enter Student ID to search: ";
            std::cin >> id;
            sms.searchStudentById(id);
            break;
        }
        case 4: {
            int id;
            std::cout << "Enter Student ID to remove: ";
            std::cin >> id;
            sms.removeStudentById(id);
            break;
        }
        case 5: {
            int id, age;
            std::string name, major, password;
            std::cout << "Enter ID of the student to update: ";
            std::cin >> id;
            std::cin.ignore(); // Ignore the newline character left by std::cin
            std::cout << "Enter new Name: ";
            std::getline(std::cin, name);
            std::cout << "Enter new Age: ";
            std::cin >> age;
            std::cin.ignore();
            std::cout << "Enter new Major: ";
            std::getline(std::cin, major);
            std::cout << "Enter new Password: ";
            std::getline(std::cin, password);

            sms.updateStudent(id, name, age, major, password);
            break;
        }
        case 6:
            std::cout << "Logging out..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 6);
}

void studentMenu(const StudentManagementSystem& sms) {
    int id;
    std::string password;
    std::cout << "Enter your ID: ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "Enter your Password: ";
    std::getline(std::cin, password);

    if (sms.authenticateStudent(id, password)) {
        std::cout << "Login successful!" << std::endl;
        sms.searchStudentById(id);
    } else {
        std::cout << "Invalid ID or Password. Please try again." << std::endl;
    }
}

int main() {
    StudentManagementSystem sms;
    Admin admin("admin", "admin123");  // Default admin credentials
    int choice;

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string username, password;
            std::cout << "Enter Admin Username: ";
            std::cin >> username;
            std::cout << "Enter Admin Password: ";
            std::cin >> password;

            if (admin.authenticate(username, password)) {
                std::cout << "Admin login successful!" << std::endl;
                adminMenu(sms);
            } else {
                std::cout << "Invalid admin credentials. Please try again." << std::endl;
            }
            break;
        }
        case 2:
            studentMenu(sms);
            break;
        case 3:
            std::cout << "Exiting the system." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 3);

    return 0;
}
