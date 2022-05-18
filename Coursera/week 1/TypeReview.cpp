
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

struct Person {
    string name;
    string surname;
    int age;
};

int main() {
//    std::vector<std::string> strings = {"One", "Two", "Three"};
//    std::cout << strings[2];
    vector<Person> staff;
    staff.push_back({"Ivan", "Ivanov", 32});
    staff.push_back({"Petr", "Petrov", 35});

    std::cout << staff[1].surname;
}