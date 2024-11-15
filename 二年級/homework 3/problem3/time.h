class Time {
public:
    explicit Time(int = 0);
    void setTime(int);

    unsigned int getHour() const;
    unsigned int getMinute() const;
    unsigned int getSecond() const;

    void printUniversal() const;
    void printStandard() const;
private:
    unsigned int hour;
    unsigned int minute;
    unsigned int second;
    unsigned int totalsecond;
    bool flag;
};
