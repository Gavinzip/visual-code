using namespace std;
#include <string>

class GradeBook {
public:
    explicit GradeBook(string courseName, string instructorName);
    void setCourseName(string courseName);
    string getCourseName() const;
    
    void setInstructorName(string instructorName);
    string getInstructorName() const;
    
    void displayMessage() const;

private:
    string courseName;
    string instructorName;
};

