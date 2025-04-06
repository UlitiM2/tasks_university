#include <iostream>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time() : hours(0), minutes(0), seconds(0) {}
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
        if (seconds >= 60) {
            minutes += seconds / 60;
            seconds %= 60;
        }

        if (minutes >= 60) {
            hours += minutes / 60;
            minutes %= 60;
        }

        if (hours >= 24) {
            hours %= 24;
        };
    }
    void print() const {
        cout << hours << ":" << minutes << ":" << seconds << endl;
    }
    Time add(const Time& other) const {
        int totalSeconds = toTotalSeconds() + other.toTotalSeconds();
        return Time(totalSeconds / 3600, (totalSeconds % 3600) / 60, totalSeconds % 60);
    }
    int toTotalSeconds() const {
        return hours * 3600 + minutes * 60 + seconds;
    }
};

int main() {
    const Time t1(10, 30, 45);
    const Time t2(8, 67, 25);
    Time result;
    result = t1.add(t2);
    result.print();
    return 0;
}