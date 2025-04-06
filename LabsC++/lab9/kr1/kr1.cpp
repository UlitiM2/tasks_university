#include <iostream>
using namespace std;
class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    class Error_input {
    public:
        int time;
        Error_input( int er) {
            time = er;
        }
    };
    Time() : hours(0), minutes(0), seconds(0) {}
    Time(int h, int m, int s) {
        check(h, m, s);
    }
    void check(int& h, int& m, int& s) {
        if (h < 0) {
            throw Error_input(h);
        }
        if (m < 0) {
            throw Error_input(m);
        }
        if (s < 0) {
            throw Error_input(s);
        }
        while (s >= 60) {
            s -= 60;
            ++m;
        }
        while (m >= 60) {
            m -= 60;
            ++h;
        }
        h %= 24;
        if (h < 0) {
            h += 24;
        }
        hours = h;
        minutes = m;
        seconds = s;
    }
    int getHours() const { return hours; }
    int getMinutes() const { return minutes; }
    int getSeconds() const { return seconds; }

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
    system("chcp 1251");
    try {
        Time t1(10, 30, -7);  
        Time t2(5, 20, 5); 

        Time result = t1.add(t2);
        result.print();
    }
    catch (Time::Error_input& e) {
        cerr << "Ошибка в значении: " << e.time << endl;
    }
    return 0;
}