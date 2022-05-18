#include <iostream>
#include "string"

using namespace std;

struct Specizalization {
    string s;
    explicit Specizalization(string new_s) {
        s = new_s;
    }
};

struct Course {
    string s;
    explicit Course(string new_s) {
        s = new_s;
    }
};

struct Week {
    string s;
    explicit Week(string new_s) {
        s = new_s;
    }
};

struct LectureTitle {
    string specialization;
    string course;
    string week;

    LectureTitle(Specizalization new_spec, Course new_course,
                 Week new_week) {
        specialization = new_spec.s;
        course = new_course.s;
        week = new_week.s;
    }
};

void PrintLecture(const LectureTitle& Lecture) {
    cout << Lecture.specialization << " " << Lecture.course << " " <<
            Lecture.week << "\n";
}

int main() {
    LectureTitle title(
            Specizalization("C++"),
            Course("White belt"),
            Week("4th")
            );
//    LectureTitle title1("C++", "White belt", "4th"); // no compile
//    LectureTitle title2(
//            string("C++"),
//            string("White belt"),
//            string("4th"));                          // no compile
//    LectureTitle title1(
//            Specizalization("C++"),
//            Week("4th"),
//            Course("White belt")                     // no compile
//    );
    PrintLecture(title);
    return 0;
}