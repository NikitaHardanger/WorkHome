#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct Student {
    string FirstName, LastName;
    int day = 0;
    int month = 0;
    int year = 0;
};

int main() {
    int n;
    cin >> n;
    string first_name, last_name;
    int day = 0;
    int month = 0;
    int year = 0;
    vector<Student> students;

    for (int i = 0; i < n; ++i) {
        cin >> first_name >> last_name >> day >> month >> year;

        students.push_back(Student{
            first_name,
            last_name,
            day,
            month,
            year
        });
    }

    int m;
    cin >> m;
    string query;
    int student_number;

    for (int i = 0; i < m; ++i) {
        cin >> query >> student_number;
        --student_number;

        if (query == "name" && student_number >= 0 && student_number < n) {
            cout << students[student_number].FirstName << " "
                 << students[student_number].LastName << endl;
        } else if (query == "date" && student_number >= 0 && student_number < n) {
            cout << students[student_number].day << "."
                 << students[student_number].month << "."
                 << students[student_number].year << endl;
        } else {
            cout << "bad request" << endl;
        }
    }
    return 0;
}