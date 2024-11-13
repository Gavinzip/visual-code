using namespace std;
#include <string>

class GradeBook {
public:
    explicit GradeBook(string name);
    void setCourseName(string name);
    string getCourseName() const;
    void displayMessage() const;
private:
    string courseName;
};

