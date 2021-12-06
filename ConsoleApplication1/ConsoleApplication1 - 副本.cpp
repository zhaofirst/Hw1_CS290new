//PREPEND BEGIN
#include <iostream>
#include<time.h>
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
	int weekday_int(int  year, char *month, int day) {
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
		return w;
	}

	int weekday_int_foryear(int  year, int month, int day) {
		int m = month;
		if (m < 3) {
			year -= 1;
			m += 12;
		}
		int c = int(year / 100);
		int y = year - 100 * c;
		int w = int(c / 4) - 2 * c + y + int(y / 4) + (26 * (m + 1) / 10) + day - 1;
		w = (w % 7 + 7) % 7;
		//cout << w << ' ' << y << ' ' << m << ' ' << day << ' ' << endl;
		return w;
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

		//string week_firstday = weekday(this->year_G, this->month_G, 1);
		bool leapyear = check_leapyear(this->year_G);
		int numOfmonth = month_num(this->month_G);
		int endDay = 0;
		//用int输出第一天是周几
		int w = weekday_int(this->year_G, this->month_G, 1);

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

	void print_year() {




#pragma region _1到3月


		cout << "Jan                                  Feb                                  Mar                                 " << endl;
		cout << "┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐" << endl;
		cout << "│ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│" << endl;
		cout << "├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤" << endl;
		int endDay_1 = 31;  //endday_1 代表1月几天
		int endDay_2 = 0;
		if (check_leapyear(this->year_G)) {
			endDay_2 = 29;
		}
		else {
			endDay_2 = 28;
		}
		int endDay_3 = 31;

		int i_f = 0;
		int i_s = 0;
		int i_t = 0;
		for (int i = 0; i < 126;) {

			/*char* mm[12][10] = { "Jau", };*/

			int w_f = weekday_int_foryear(this->year_G, 1, 1);
			int w_s = weekday_int_foryear(this->year_G, 2, 1);
			int w_t = weekday_int_foryear(this->year_G, 3, 1);

			// 第一个月

			if (i < 21) {
				cout << "│";
				for (int j = 0; j < w_f; j++) {

					cout << zifu[32 - 1];
					i++;

				}
			}

			while (i_f < 42 - w_f) {
				if ((i_f + w_f + 1) % 7 == 0) {
					if (i_f >= endDay_1) {
						cout << zifu[32 - 1];
						i++;
						cout << ' ';
					}
					else {
						cout << zifu[i_f];
						i++;
						cout << ' ';
					}
					i_f++;
					break;
				}
				else
				{
					if (i_f >= endDay_1) {
						cout << zifu[32 - 1];
						i++;
					}
					else
					{
						cout << zifu[i_f];
						i++;
					}
				}
				i_f++;
			}

			//第二个月
			cout << "│";
			if (i < 21) {

				for (int j = 0; j < w_s; j++) {

					cout << zifu[32 - 1];
					i++;

				}
			}

			while (i_s < 42 - w_s) {

				if ((i_s + w_s + 1) % 7 == 0) {
					if (i_s >= endDay_2) {
						cout << zifu[32 - 1];
						i++;
						cout << ' ';
					}
					else {
						cout << zifu[i_s];
						i++;
						cout << ' ';
					}
					i_s++;
					break;
				}
				else
				{
					if (i_s >= endDay_2) {
						cout << zifu[32 - 1];
						i++;
					}
					else
					{
						cout << zifu[i_s];
						i++;
					}
				}
				i_s++;
			}

			//第三个月  	
			cout << "│";
			if (i < 21) {

				for (int j = 0; j < w_t; j++) {

					cout << zifu[32 - 1];
					i++;
				}
			}

			while (i_t < 42 - w_t) {

				if ((i_t + w_t + 1) % 7 == 0) {
					if (i_t >= endDay_3) {
						cout << zifu[32 - 1];
						i++;
					}
					else {
						cout << zifu[i_t];
						i++;
					}
					cout << endl;
					if (i == 126) {
						cout << "└────┴────┴────┴────┴────┴────┴────┘ └────┴────┴────┴────┴────┴────┴────┘ └────┴────┴────┴────┴────┴────┴────┘" << endl;
						break;
					}

					cout << "├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤" << endl;
					cout << "│";
					i_t++;
					break;
				}
				else
				{
					if (i_t >= endDay_3) {
						cout << zifu[32 - 1];
						i++;
					}
					else
					{
						cout << zifu[i_t];
						i++;
					}
				}
				i_t++;
			}







		}



#pragma endregion





#pragma region 4到6月



		cout << "Apr                                  May                                  Jun                                 " << endl;
		cout << "┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐" << endl;
		cout << "│ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│" << endl;
		cout << "├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤" << endl;
		int endDay_4 = 30;  //endday_1 代表1月几天
		int endDay_5 = 31;
		int endDay_6 = 30;


		i_f = 0;
		i_s = 0;
		i_t = 0;
		for (int i = 0; i < 126;) {

			/*char* mm[12][10] = { "Jau", };*/

			int w_f = weekday_int_foryear(this->year_G, 4, 1);
			int w_s = weekday_int_foryear(this->year_G, 5, 1);
			int w_t = weekday_int_foryear(this->year_G, 6, 1);

			// 第一个月

			if (i < 21) {
				cout << "│";
				for (int j = 0; j < w_f; j++) {

					cout << zifu[32 - 1];
					i++;

				}
			}

			while (i_f < 42 - w_f) {
				if ((i_f + w_f + 1) % 7 == 0) {
					if (i_f >= endDay_4) {
						cout << zifu[32 - 1];
						i++;
						cout << ' ';
					}
					else {
						cout << zifu[i_f];
						i++;
						cout << ' ';
					}
					i_f++;
					break;
				}
				else
				{
					if (i_f >= endDay_4) {
						cout << zifu[32 - 1];
						i++;
					}
					else
					{
						cout << zifu[i_f];
						i++;
					}
				}
				i_f++;
			}

			//第二个月
			cout << "│";
			if (i < 21) {

				for (int j = 0; j < w_s; j++) {

					cout << zifu[32 - 1];
					i++;

				}
			}

			while (i_s < 42 - w_s) {

				if ((i_s + w_s + 1) % 7 == 0) {
					if (i_s >= endDay_5) {
						cout << zifu[32 - 1];
						i++;
						cout << ' ';
					}
					else {
						cout << zifu[i_s];
						i++;
						cout << ' ';
					}
					i_s++;
					break;
				}
				else
				{
					if (i_s >= endDay_5) {
						cout << zifu[32 - 1];
						i++;
					}
					else
					{
						cout << zifu[i_s];
						i++;
					}
				}
				i_s++;
			}

			//第三个月  	
			cout << "│";
			if (i < 21) {

				for (int j = 0; j < w_t; j++) {

					cout << zifu[32 - 1];
					i++;
				}
			}

			while (i_t < 42 - w_t) {

				if ((i_t + w_t + 1) % 7 == 0) {
					if (i_t >= endDay_6) {
						cout << zifu[32 - 1];
						i++;
					}
					else {
						cout << zifu[i_t];
						i++;
					}
					cout << endl;
					if (i == 126) {
						cout << "└────┴────┴────┴────┴────┴────┴────┘ └────┴────┴────┴────┴────┴────┴────┘ └────┴────┴────┴────┴────┴────┴────┘" << endl;
						break;
					}

					cout << "├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤" << endl;
					cout << "│";
					i_t++;
					break;
				}
				else
				{
					if (i_t >= endDay_6) {
						cout << zifu[32 - 1];
						i++;
					}
					else
					{
						cout << zifu[i_t];
						i++;
					}
				}
				i_t++;
			}







		}



#pragma endregion





#pragma region 7到9月
		cout << "Jul                                  Aug                                  Sep                                 " << endl;
		cout << "┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐" << endl;
		cout << "│ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│" << endl;
		cout << "├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤" << endl;
		endDay_4 = 31;  //endday_1 代表1月几天
		endDay_5 = 31;
		endDay_6 = 30;


		i_f = 0;
		i_s = 0;
		i_t = 0;
		for (int i = 0; i < 126;) {

			/*char* mm[12][10] = { "Jau", };*/

			int w_f = weekday_int_foryear(this->year_G, 7, 1);
			int w_s = weekday_int_foryear(this->year_G, 8, 1);
			int w_t = weekday_int_foryear(this->year_G, 9, 1);

			// 第一个月

			if (i < 21) {
				cout << "│";
				for (int j = 0; j < w_f; j++) {

					cout << zifu[32 - 1];
					i++;

				}
			}

			while (i_f < 42 - w_f) {
				if ((i_f + w_f + 1) % 7 == 0) {
					if (i_f >= endDay_4) {
						cout << zifu[32 - 1];
						i++;
						cout << ' ';
					}
					else {
						cout << zifu[i_f];
						i++;
						cout << ' ';
					}
					i_f++;
					break;
				}
				else
				{
					if (i_f >= endDay_4) {
						cout << zifu[32 - 1];
						i++;
					}
					else
					{
						cout << zifu[i_f];
						i++;
					}
				}
				i_f++;
			}

			//第二个月
			cout << "│";
			if (i < 21) {

				for (int j = 0; j < w_s; j++) {

					cout << zifu[32 - 1];
					i++;

				}
			}

			while (i_s < 42 - w_s) {

				if ((i_s + w_s + 1) % 7 == 0) {
					if (i_s >= endDay_5) {
						cout << zifu[32 - 1];
						i++;
						cout << ' ';
					}
					else {
						cout << zifu[i_s];
						i++;
						cout << ' ';
					}
					i_s++;
					break;
				}
				else
				{
					if (i_s >= endDay_5) {
						cout << zifu[32 - 1];
						i++;
					}
					else
					{
						cout << zifu[i_s];
						i++;
					}
				}
				i_s++;
			}

			//第三个月  	
			cout << "│";
			if (i < 21) {

				for (int j = 0; j < w_t; j++) {

					cout << zifu[32 - 1];
					i++;
				}
			}

			while (i_t < 42 - w_t) {

				if ((i_t + w_t + 1) % 7 == 0) {
					if (i_t >= endDay_6) {
						cout << zifu[32 - 1];
						i++;
					}
					else {
						cout << zifu[i_t];
						i++;
					}
					cout << endl;
					if (i == 126) {
						cout << "└────┴────┴────┴────┴────┴────┴────┘ └────┴────┴────┴────┴────┴────┴────┘ └────┴────┴────┴────┴────┴────┴────┘" << endl;
						break;
					}

					cout << "├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤" << endl;
					cout << "│";
					i_t++;
					break;
				}
				else
				{
					if (i_t >= endDay_6) {
						cout << zifu[32 - 1];
						i++;
					}
					else
					{
						cout << zifu[i_t];
						i++;
					}
				}
				i_t++;
			}







		}
#pragma endregion


#pragma region 10到12月
		cout << "Oct                                  Nov                                  Dec                                 " << endl;
		cout << "┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐" << endl;
		cout << "│ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│" << endl;
		cout << "├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤" << endl;
		endDay_4 = 31;  //endday_1 代表1月几天
		endDay_5 = 30;
		endDay_6 = 31;


		i_f = 0;
		i_s = 0;
		i_t = 0;
		for (int i = 0; i < 126;) {

			/*char* mm[12][10] = { "Jau", };*/

			int w_f = weekday_int_foryear(this->year_G, 10, 1);
			int w_s = weekday_int_foryear(this->year_G, 11, 1);
			int w_t = weekday_int_foryear(this->year_G, 12, 1);

			// 第一个月

			if (i < 21) {
				cout << "│";
				for (int j = 0; j < w_f; j++) {

					cout << zifu[32 - 1];
					i++;

				}
			}

			while (i_f < 42 - w_f) {
				if ((i_f + w_f + 1) % 7 == 0) {
					if (i_f >= endDay_4) {
						cout << zifu[32 - 1];
						i++;
						cout << ' ';
					}
					else {
						cout << zifu[i_f];
						i++;
						cout << ' ';
					}
					i_f++;
					break;
				}
				else
				{
					if (i_f >= endDay_4) {
						cout << zifu[32 - 1];
						i++;
					}
					else
					{
						cout << zifu[i_f];
						i++;
					}
				}
				i_f++;
			}

			//第二个月
			cout << "│";
			if (i < 21) {

				for (int j = 0; j < w_s; j++) {

					cout << zifu[32 - 1];
					i++;

				}
			}

			while (i_s < 42 - w_s) {

				if ((i_s + w_s + 1) % 7 == 0) {
					if (i_s >= endDay_5) {
						cout << zifu[32 - 1];
						i++;
						cout << ' ';
					}
					else {
						cout << zifu[i_s];
						i++;
						cout << ' ';
					}
					i_s++;
					break;
				}
				else
				{
					if (i_s >= endDay_5) {
						cout << zifu[32 - 1];
						i++;
					}
					else
					{
						cout << zifu[i_s];
						i++;
					}
				}
				i_s++;
			}

			//第三个月  	
			cout << "│";
			if (i < 21) {

				for (int j = 0; j < w_t; j++) {

					cout << zifu[32 - 1];
					i++;
				}
			}

			while (i_t < 42 - w_t) {

				if ((i_t + w_t + 1) % 7 == 0) {
					if (i_t >= endDay_6) {
						cout << zifu[32 - 1];
						i++;
					}
					else {
						cout << zifu[i_t];
						i++;
					}
					cout << endl;
					if (i == 126) {
						cout << "└────┴────┴────┴────┴────┴────┴────┘ └────┴────┴────┴────┴────┴────┴────┘ └────┴────┴────┴────┴────┴────┴────┘" << endl;
						break;
					}

					cout << "├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤" << endl;
					cout << "│";
					i_t++;
					break;
				}
				else
				{
					if (i_t >= endDay_6) {
						cout << zifu[32 - 1];
						i++;
					}
					else
					{
						cout << zifu[i_t];
						i++;
					}
				}
				i_t++;
			}







		}
#pragma endregion








	}







	
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
	//Shanghaitech date(year, month, day);
	//Shanghaitech* S = &date;
	Gregorian gb(year, month, day);
	Gregorian *G = &gb;
	//Gregorian* G = &date;
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