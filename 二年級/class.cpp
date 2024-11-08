#include <iostream>
#include <string>
using namespace std;

class GradeBook
{
    public:
    GradeBook(string name,string id )
    {
        setCourseName(name,id);
        
    }

void setCourseName(string name,string id)
{
    courseName =name;
    studentid = id;
}

string getCourseName()
{
    return courseName;
}

string getstudentid()
{
    return studentid;
}

void displayMessage()
{
    cout << "Welcome to the grade book for\n" << getCourseName() << "!" << endl;
}

private:
    string courseName;
    string studentid;
}; 

int main()
{
    GradeBook gradeBook1("CS101 Introduction to C++ Programming","A1125525");
    GradeBook gradeBook2("CS102 Data Structures in C++","A1125525");


    cout << "gradeBook1 created for course: " << gradeBook1.getCourseName() <<"("<< gradeBook1.getstudentid()<<")" << endl;
    cout << "gradeBook2 created for course: " << gradeBook2.getCourseName() <<"("<< gradeBook2.getstudentid()<<")" << endl;

    return 0;
}