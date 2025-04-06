#include <iostream>
using namespace std;
struct Time
{
	int hours;
	int minutes;
	int seconds;
	void Show()
	{
		cout << "\n часы: " << hours << "\n минуты: " << minutes << "\n секунды: " << seconds << endl;
	}
};

void Show_seconds(Time& t)
{
	cout << "\n Итог: " << t.seconds << " секунд \n";
}

Time Change(Time& t1)
{
	Time t;
	t.seconds = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
	return t;
}

Time Sum(Time& t1, Time& t2)
{
	Time t;
	t.hours = t1.hours + t2.hours;
	t.minutes = t1.minutes + t2.minutes;
	t.seconds = t1.seconds + t2.seconds;
	t.minutes += t.seconds / 60;
	t.seconds %= 60;
	t.hours += t.minutes / 60;
	t.minutes %= 60;
	return t;
}

Time Minus(Time& t1, Time& t2)
{
	Time t;
	t.hours = t1.hours - t2.hours;
	t.minutes = t1.minutes - t2.minutes;
	t.seconds = t1.seconds - t2.seconds;
	if (t.seconds < 0)
	{
		t.seconds += 60;
		t.minutes--;
	}
	if (t.minutes < 0)
	{
		t.minutes += 60;
		t.hours--;
	}
	if (t.hours < 0)
	{
		t.hours = 0;
		t.minutes = 0;
		t.seconds = 0;
	}
	return t;

}


Time Input()
{
	Time t;
	bool validInput = false;
	do
	{
		cout << "Введите часы: ";
		cin >> t.hours;
		cout << "Введите минуты: ";
		cin >> t.minutes;
		cout << "Введите секунды: ";
		cin >> t.seconds;
		if ((t.hours >= 0) && ((t.minutes >= 0) && (t.minutes < 60)) && ((t.seconds >= 0) && (t.seconds < 60)))
			break;
		cout << "Неверное значение! Попробуйте снова.\n";
	} while (true);

	return t;
}

int main()
{
	system ("chcp 1251");
	Time t1 = Input();
	Time t2 = { 1, 15, 25 };
	Time t3 = { 1, 45, 0 };
	t1.Show();
	Time t_new = Change(t1);
	Show_seconds(t_new);
	Time t_add = Sum(t1, t2);
	t_add.Show();
	Time t_minus = Minus(t1, t3);
	t_minus.Show();
	return 0;
}
