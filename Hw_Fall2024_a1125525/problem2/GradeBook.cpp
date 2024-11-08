#include <iostream>
#include "GradeBook.h"
using namespace std;

GradeBook::GradeBook(string courseName, string instructorName)
    : courseName(courseName), instructorName(instructorName)
{
}

void GradeBook::setCourseName(string courseName) {
    courseName = courseName;
}

string GradeBook::getCourseName() const {
    return courseName;
}

void GradeBook::setInstructorName(string instructorName) {
    instructorName = instructorName;
}

string GradeBook::getInstructorName() const {
    return instructorName;
}

void GradeBook::displayMessage() const {
    cout << "Welcome to the grade book for\n" << getCourseName() << "!" << endl;
    cout << "This course is presented by: " << getInstructorName() << endl;
}
