//
// Created by Nikit on 19/10/2021.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct Lecture {
    string title;
    int duration;
    string author;
};

struct LectureTitle {
    string specialization;
    string course;
    string week;
};

struct DetailedTitle {
    LectureTitle title;
    int duration;
};

void PrintLecture(const Lecture& lecture) {
    cout << "Title: " << lecture.title <<
            ", duration: " << lecture.duration <<
            ", author: " << lecture.author << "\n";
}

void PrintCourse(const vector<Lecture>& lectures) {
    for (const Lecture& lecture : lectures) {
        PrintLecture(lecture);
    }
}

int main() {
    Lecture lecture1;
    lecture1.title = "OOP";
    lecture1.duration= 5400;
    lecture1.author = "Anton";
    Lecture lecture2 = {"OOP", 3800, "Mike"};
    PrintLecture(lecture1);
    PrintLecture(lecture2);
    PrintLecture({"OOP", 300, "Alex"});

    LectureTitle title = {"C++", "White belt", "OOP"};
    DetailedTitle lecture3 = {title, 5400};
    cout << lecture3.title.specialization << "\n";
    return 0;
}