//PREPEND BEGIN
#include <iostream>
#include <string>
//PREPEND END
using namespace std;
//TEMPLATE BEGIN
//You just need to implement these two classes
class Gregorian {
public:
	// Variable
	int year_G;
	char* month_G;
	int day_G;
	const string zifu[32] = {
" 01 │", " 02 │" ," 03 │",	" 04 │", " 05 │" ," 06 │",	" 07 │", " 08 │" ," 09 │",
" 10 │", " 11 │", " 12 │" ," 13 │",	" 14 │", " 15 │" ," 16 │",	" 17 │", " 18 │" ," 19 │",
" 20 │"," 21 │", " 22 │" ," 23 │",	" 24 │", " 25 │" ," 26 │",	" 27 │", " 28 │" ," 29 │",
" 30 │"," 31 │" ,"    │" };

	// Function mine 

	int month_num(char* month) {


		string mm = month;
		//char decide[3];
		char switch_month_First = *month;
		char switch_month_Second = *(month + 1);
		char switch_month_Third = *(month + 2);
		//decide[0] = *month;
		//decide[1] = *(month + 1);
		//decide[2] = *(month + 2);


		switch (switch_month_First) {
		case 'J':
			switch (switch_month_Third) {
			case 'u':
				return 1;
			case 'n':
				return 6;
			case 'l':
				return 7;
			default:
				return 0;
				break;
			}
		case 'F':
			return 2;
		case 'M':
			switch (switch_month_Third) {
			case 'r':
				return 3;
			case 'y':
				return 5;
			default:
				return 0;
				break;
			}
		case 'A':
			switch (switch_month_Third) {
			case 'r':
				return 4;
			case 'y':
				return 8;
			default:
				return 0;
				break;
			}
		case 'S':
			return 9;
		case 'O':
			return 10;
		case 'N':
			return 11;
		case 'D':
			return 12;

		default:
			return 0;
			break;

		}
	}

	string weekday(int  year, char *month, int day) {
		int m = month_num(month);

		if (m < 3) {
			year -= 1;
			m += 12;
		}
		int c = int(year / 100);
		int y = year - 100 * c;
		int w = int(c / 4) - 2 * c + y + int(y / 4) + (26 * (m + 1) / 10) + day - 1;
		w = (w % 7 + 7) % 7;
		//cout << w << ' ' << y << ' ' << m << ' ' << day << ' ' << endl;
		switch (w) {
		case 0:
			return "Sun";
		case 1:
			return "Mon";
		case 2:
			return "Tues";
		case 3:
			return "Wed";
		case 4:
			return "Thur";
		case 5:
			return "Fri";
		case 6:
			return "Sat";
		default:
			return 0;
			break;
		}

	}

	bool check_leapyear(int year) {
		// 0代表不是闰年 其他代表是闰年
		int y = year;
		if (y % 4 == 0)
		{
			if (y % 4000 == 0) {
				return 0;
			}
			else {
				if (y % 100 == 0)
				{
					// // 这里如果被 400 整除是闰年
					if (y % 400 == 0)
						return 1;
					else
						return 0;
				}
				else
					return 1;
			}

		}
		else
			return 0;


	}

	// Function HW 

	Gregorian(int year, char *month, int day) {
		year_G = year;
		month_G = month;
		day_G = day;
	};
	void print_today() {
		//string p_month[3];

		cout << year_G << ' ' << *month_G << *(month_G + 1) << *(month_G + 2) << ' ' << day_G << endl;
	}

	//print the date of today in Gregorian format by "yearmonthnday"
	void print_month() {
		cout << *month_G << *(month_G + 1) << *(month_G + 2) << endl;
		cout << "┌────┬────┬────┬────┬────┬────┬────┐" << endl;
		cout << "│ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│" << endl;
		cout << "├────┼────┼────┼────┼────┼────┼────┤" << endl;

		string week_firstday = weekday(this->year_G, this->month_G, 1);
		bool leapyear = check_leapyear(this->year_G);
		int numOfmonth = month_num(this->month_G);
		int endDay = 0;
		//用int输出第一天是周几
		int m = month_num(this->month_G);
		int year = this->year_G;
		if (m < 3) {
			year -= 1;
			m += 12;
		}
		int c = int(year / 100);
		int y = year - 100 * c;
		int w = int(c / 4) - 2 * c + y + int(y / 4) + (26 * (m + 1) / 10) + 1 - 1;
		w = (w % 7 + 7) % 7;

		// 输出这个月的一共有多少天
		switch (numOfmonth) {
		case 1:
			endDay = 31;
			break;
		case 3:
			endDay = 31;
			break;
		case 5:
			endDay = 31;
			break;
		case 7:
			endDay = 31;
			break;
		case 8:
			endDay = 31;
			break;
		case 10:
			endDay = 31;
			break;
		case 12:
			endDay = 31;
			break;
		case 2:
			if (leapyear) {
				endDay = 29;
			}
			else {
				endDay = 28;
			}
			break;
		default:
			endDay = 30;
			break;
		}

		cout << "│";
		for (int j = 0; j < w; j++) {

			cout << zifu[32 - 1];

		}

		for (int i = 0; i < 41 - w; i++) { //42代表有42个格子
			if ((i + w + 1) % 7 == 0) {
				if (i >= endDay) {
					cout << zifu[32 - 1];
				}
				else {
					cout << zifu[i];

				}
				cout << endl;
				cout << "├────┼────┼────┼────┼────┼────┼────┤" << endl;
				cout << "│";

			}
			else
			{
				if (i >= endDay) {
					cout << zifu[32 - 1];
				}
				else
				{
					cout << zifu[i];
				}

			}
		}
		cout << zifu[31] << endl;
		cout << "└────┴────┴────┴────┴────┴────┴────┘" << endl;

	}





	/*		print the calendar of the current monthin
		Gregorian form at .*/
	void print_year();
	//print the calendar of the current year in
	//Gregorian format
	bool go_to(int year, char* month, int day) {
		if (year <= 999999 & year >= 1) {
			if (day <= 31 & day >= 1) {
				year = year;
				return true;
			}
			else {
				return false;
			}
		}
	}
	//go to the given day.Return true if the day in the range Jan 1, 1 toDec 31, 999999. Else false .
	bool  pass_day(int num_days);
		//pass the given number of days from todayReturn true if that day is in the rangeElse roll back to the origin day and ret
		//urn false
	bool pass_month(int num_months);
	//pass the given number of months from tod
	//ay .
	//Return true and slide to the first day of that month if that month is inthe former range .
	//Else roll back to the origin day and ret
	//urn false .
	bool pass_year(int num_years);
	//pass the given number of years from today .
	//Return true and slide to the first day of th atyear if t hat year is in
	//the former range .
	//Else roll back to the origin day and ret
	//urn false .
	//Note that the day or month or year to pass might be
	//a negative int.

};

class Shanghaitech :public Gregorian {
};

//TEMPLATE END

//APPEND BEGIN

// Use this main function
int main()
{
	int year, day, n;
	std::string calendar, f;
	char month[10];

	std::cin >> f;
	std::cin >> year >> month >> day;
	Shanghaitech date(year, month, day);
	Shanghaitech* S = &date;
	Gregorian* G = &date;
	std::cin >> calendar;
	std::cin >> f;
	while (!std::cin.eof()) {
		if (f == "pass_day") {
			std::cin >> n;
			if (calendar == "G") G->pass_day(n); else S->pass_day(n);
		}
		else if (f == "pass_month") {
			std::cin >> n;
			if (calendar == "G") G->pass_month(n); else S->pass_month(n);
		}
		else if (f == "pass_year") {
			std::cin >> n;
			if (calendar == "G") G->pass_year(n); else S->pass_year(n);
		}
		else if (f == "print_today") {
			if (calendar == "G") G->print_today(); else S->print_today();
		}
		else if (f == "print_month") {
			if (calendar == "G") G->print_month(); else S->print_month();
		}
		else if (f == "print_year") {
			if (calendar == "G") G->print_year(); else S->print_year();
		}
		else if (f == "go_to") {
			std::cin >> year >> month >> day;
			if (calendar == "G") G->go_to(year, month, day); else S->go_to(year, month, day);
		}
		calendar = "";
		f = "";
		std::cin >> calendar;
		std::cin >> f;
	}
	return 0;
}
//APPEND END