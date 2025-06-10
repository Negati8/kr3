#include "functions.h"
#include <iostream>

int main() {
    const char* filename = "test.csv";
    Student* students = nullptr;
    int32_t size{};

    try {
        size = CountLines(filename);
        students = new Student[size];
        LoadStudentsFromFile(filename, students, size);
    }
    catch (const std::exception& exc) {
        std::cerr << "Error: " << exc.what() << "\n";
        return 1;
    }

    int32_t choice;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1) Sort by surname\n";
        std::cout << "2) Find by surname\n";
        std::cout << "3) Sort by surname and group\n";
        std::cout << "4) Average grade by group\n";
        std::cout << "0) Cancel\n";
        std::cout << "Choice: "<<'\n';
        std::cin >> choice;

        try {
            switch (choice) {
            case 1:
                SortByName(students, size);
                PrintStudents(students, size);
                break;
            case 2: {
                char surname[30];
                std::cout << "Input surname: ";
                std::cin >> surname;
                int32_t index = FindBySurname(students, size, surname);
                if (index >= 0) {
                    std::cout << "Found: " << students[index].name
                        << ", group " << students[index].group
                        << ", grade " << students[index].grade << "\n";
                }
                else {
                std::cout << "Student not found.\n";
                     }
                break;
            }
            case 3:
                SortByGroupAndName(students, size);
                PrintStudents(students, size);
                break;
            case 4:
                PrintAverageByGroup(students, size);
                break;
            case 0:
                std::cout << "Cancel.\n";
                break;
            default:
                std::cout << "Incorrect choice.\n";
            }
        }
        catch (const std::exception& exc) {
            std::cerr << "Error: " << exc.what() << "\n";
        }
    } while (choice != 0); {

        delete[] students;
    }
    return 0;
}
