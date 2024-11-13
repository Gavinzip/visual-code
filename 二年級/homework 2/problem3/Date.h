class Date {
public:
    Date(int month, int day, int year);
    
    void setMonth(int month);
    int getMonth() const;
    
    void setDay(int day);
    int getDay() const;
    
    void setYear(int year);
    int getYear() const;
    
    void displayDate() const;

private:
    int dm;
    int dd;
    int dy;
};

