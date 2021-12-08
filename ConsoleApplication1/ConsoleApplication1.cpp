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
			switch (switch_month_Second)
			{
			case 'a':
				return 1;
			case 'u':
				switch (switch_month_Third) {

				case 'n':
					return 6;
				case 'l':
					return 7;
				default:
					return 0;
					break;
				}
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
			case 'g':
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
	string month_string(int num) {
		string mm[12] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
		return mm[num];
	}
	int weekday_int(int  year, char *month, int day) {
		int m = month_num(month);
		if (m < 3) {
			year -= 1;
			m += 12;
		}
		int result;
		//int w;
		int c = int(year / 100);
		int y = year - 100 * c;
		if (year > 4000) {
			result = int(c / 4) - 2 * c + y + int(y / 4) + (26 * (m + 1) / 10) - int(year / 4000) + day - 1;
			result = (result % 7 + 7) % 7;
		}
		else {
			result = int(c / 4) - 2 * c + y + int(y / 4) + (26 * (m + 1) / 10) + day - 1;
			result = (result % 7 + 7) % 7;
		}
		//cout << w << ' ' << y << ' ' << m << ' ' << day << ' ' << endl;
		return result;
	}

	int weekday_int_foryear(int  year, int month, int day) {
		int m = month;
		if (m < 3) {
			year -= 1;
			m += 12;
		}
		int result;
		//int w;
		int c = int(year / 100);
		int y = year - 100 * c;
		if (year > 4000) {
			result = int(c / 4) - 2 * c + y + int(y / 4) + (26 * (m + 1) / 10) - int(year / 4000) + day - 1;
			result = (result % 7 + 7) % 7;
		}
		else {
			result = int(c / 4) - 2 * c + y + int(y / 4) + (26 * (m + 1) / 10) + day - 1;
			result = (result % 7 + 7) % 7;
		}
		//cout << w << ' ' << y << ' ' << m << ' ' << day << ' ' << endl;
		return result;
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

		//cout << year_G << ' ' << *month_G << *(month_G + 1) << *(month_G + 2) << ' ' << day_G << endl;
		cout << this->year_G << ' ' << this->month_G  << ' ' << this->day_G << endl;
	}

	//print the date of today in Gregorian format by "yearmonthnday"
	void print_month() {
		cout << *month_G << *(month_G + 1) << *(month_G + 2) <<"                                 "<< endl;
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





#pragma region 1到3月
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


	bool go_to(int year, char* month, int day) {

		if (year_G <= 999999 && year_G >= 1) {
			if (day_G <= 31 && day_G >= 1) {
				if (month_num(month_G) <= 12 && month_num(month_G) >= 1) {
					year_G = year;
					month_G = month;
					day_G = day;
					return true;
				}
				else {
					return false;
				}

			}
			else {
				return false;
			}
		}
		else
		{
			return false;
		}
	}

	bool  pass_day(int num_days) {
		char *month_char[] = { (char*)"Jan", (char*)"Feb", (char*)"Mar", (char*)"Apr", (char*)"May", (char*)"Jun", (char*)"Jul", (char*)"Aug", (char*)"Sep", (char*)"Oct", (char*)"Nov", (char*)"Dec" };
		bool leapyear = check_leapyear(this->year_G);
		int numOfmonth = month_num(this->month_G);
		int endDay = 0;
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
		int n = num_days;

		/// 保留原始数据

		int or_y = year_G;
		int or_d = day_G;
		int or_m = numOfmonth;
		/// 结束保留


		int y, m, d;
		int mon[13] = { 31,31,28,31,30,31,30,31,31,30,31,30,31 };
		y = year_G;
		m = numOfmonth;
		d = day_G;


		if (n > 0) {
			n += d;
			if (n <= endDay) {
				day_G = n;
			}
			else {
				do
				{
					bool leepyear = check_leapyear(y);
					if (m == 2 && leepyear) {
						n -= 29;
					}
					else {
						n -= mon[m];


					}
					if (++m > 12) {
						m = 1; y++;
					}


				} while (n > mon[m]);
				year_G = y;
				month_G = (char*)month_char[m - 1];
				day_G = n;
			}
		}
		else if (n == 0) {
			//cout << year_G << ' ' << *month_G << *(month_G + 1) << *(month_G + 2) << ' ' << day_G << ' ' << endl;
			return true;
		}
		else {
			if( int temp = n + d >= 1) {
				day_G = n + d;
			}
			else
			{
				n += d;
				while( -n >=mon[m-1])
				{
					if (--m == 0) {
						m = 12;
						--y;
					}
					bool leepyear = check_leapyear(y);
					if (m == 2 && leepyear) {
						n += 29;
					}
					else
					{
						n += mon[m];
					}

				}
				if (--m == 0) {
					m = 12;
					--y;
				}
				bool leepyear = check_leapyear(y);
				if (m == 2 && leepyear) {
					n += 29;
				}
				else {
					n += mon[m];
				}

				month_G = (char*)month_char[m-1];
				year_G = y;
				day_G = n;

			}
		}


		if (year_G <= 999999 && year_G >= 1) {
			return true;
		}
		else
		{
			year_G = or_y;
			day_G = or_d;
			month_G = (char*)month_char[or_m - 1];

			//cout << year_G << ' ' << *month_G << *(month_G + 1) << *(month_G + 2) << ' ' << day_G << ' ' << endl;

			return false;
		}




	}


	bool pass_month(int num_months) {
		char *month_char[] = { (char*)"Jan", (char*)"Feb", (char*)"Mar", (char*)"Apr", (char*)"May", (char*)"Jun", (char*)"Jul", (char*)"Aug", (char*)"Sep", (char*)"Oct", (char*)"Nov", (char*)"Dec" };
		int numOfmonth = month_num(this->month_G);
		int n = num_months;

		/// 保留原始数据
		int or_y = year_G;
		int or_d = day_G;
		int or_m = numOfmonth;
		/// 结束保留

		int m = numOfmonth;
		m += n;
		if (m > 0) {

			int plus_year = int(m / 12);
			if (m % 12 == 0) {
				year_G -= 1;
			}
			year_G += plus_year;

			m -= plus_year * 12;




			if (m == 0) {
				m = 12;
			}



			month_G = (char*)month_char[m - 1];

			day_G = 1;

		}

		else
		{
			year_G -= 1;
			int dec_year = int(m / 12);
			year_G += dec_year;
			m -= dec_year * 12;
			m += 12;
			month_G = (char*)month_char[m - 1];
			day_G = 1;

		}



		if (year_G <= 999999 && year_G >= 1) {
			return true;
		}
		else
		{
			year_G = or_y;
			day_G = or_d;
			month_G = (char*)month_char[or_m - 1];

			//cout << year_G << ' ' << *month_G << *(month_G + 1) << *(month_G + 2) << ' ' << day_G << ' ' << endl;

			return false;
		}






	}
	//pass the given number of months from tod
	//ay .
	//Return true and slide to the first day of that month if that month is inthe former range .
	//Else roll back to the origin day and ret
	//urn false .
	bool pass_year(int num_years) {
		char *month_char[] = { (char*)"Jan", (char*)"Feb", (char*)"Mar", (char*)"Apr", (char*)"May", (char*)"Jun", (char*)"Jul", (char*)"Aug", (char*)"Sep", (char*)"Oct", (char*)"Nov", (char*)"Dec" };
		int numOfmonth = month_num(this->month_G);
		int n = num_years;

		/// 保留原始数据
		int or_y = year_G;
		int or_d = day_G;
		int or_m = numOfmonth;
		/// 结束保留


		year_G += n;
		numOfmonth = 1;

		month_G = (char*)month_char[numOfmonth - 1];
		day_G = 1;


		if (year_G <= 999999 && year_G >= 1) {
			return true;
		}
		else
		{
			year_G = or_y;
			day_G = or_d;
			month_G = (char*)month_char[or_m - 1];

			//cout << year_G << ' ' << *month_G << *(month_G + 1) << *(month_G + 2) << ' ' << day_G << ' ' << endl;

			return false;
		}




	}
	//pass the given number of years from today .
	//Return true and slide to the first day of th atyear if t hat year is in
	//the former range .
	//Else roll back to the origin day and ret
	//urn false .
	//Note that the day or month or year to pass might be
	//a negative int.

};







class Shanghaitech :public Gregorian {

private:
	int year_S;
	char* month_S;
	int day_S;
public:

	/// Variable
	const string sm_stirng[9] = { "Sist","Spst","Slst","Sem","Sca","Ims","Ihuman","Siais","Ih" };
	const string hzifu[42] = {
" 01 │", " 02 │" ," 03 │",	" 04 │", " 05 │" ," 06 │",	" 07 │", " 08 │" ," 09 │"," 0A │", " 0B │", " 0C │" ,
" 0D │" ," 0E │" ," 0F │" ," 10 │", " 11 │", " 12 │" ," 13 │",	" 14 │", " 15 │" ," 16 │",	" 17 │", " 18 │" ," 19 │"," 1A │", " 1B │", " 1C │" ,
" 1D │" ," 1E │" ," 1F │" ," 20 │"," 21 │", " 22 │" ," 23 │",	" 24 │", " 25 │" ," 26 │",	" 27 │", " 28 │" ," 29 │","    │" };
	int S_day[1001] = { 364353
,729168
,1093941
,1459166
,1823853
,2189161
,2554462
,2919946
,3284663
,3649893
,4015194
,4380723
,4745974
,5111545
,5477144
,5842679
,6207462
,6572533
,6937793
,7303369
,7668730
,8034188
,8399709
,8765331
,9130522
,9496062
,9861581
,10227167
,10592632
,10958260
,11323832
,11689274
,12054123
,12418946
,12784206
,13149632
,13515143
,13880450
,14245928
,14611606
,14977132
,15342355
,15707955
,16073515
,16439086
,16804529
,17170139
,17535633
,17900956
,18266020
,18631545
,18997104
,19362716
,19728155
,20093768
,20459262
,20824741
,21189947
,21555522
,21921016
,22286456
,22651756
,23017157
,23382363
,23747293
,24111766
,24476874
,24842054
,25207555
,25572872
,25938415
,26303893
,26669562
,27034777
,27400203
,27765762
,28131395
,28496812
,28862487
,29227938
,29593426
,29958550
,30323776
,30689373
,31054932
,31420504
,31786064
,32151676
,32517208
,32882453
,33247818
,33613469
,33978923
,34344324
,34709624
,35074985
,35440231
,35805006
,36169946
,36535478
,36900997
,37266613
,37632128
,37997666
,38363239
,38728600
,39093833
,39459496
,39824950
,40190510
,40555651
,40921171
,41286417
,41651504
,42016268
,42381857
,42747349
,43112911
,43478049
,43843572
,44208740
,44573983
,44938693
,45304180
,45669427
,46034591
,46399373
,46764498
,47129317
,47494016
,47858449
,48223103
,48588369
,48953630
,49319154
,49684409
,50050015
,50415534
,50781146
,51146278
,51511848
,51877368
,52242943
,52608418
,52973996
,53339529
,53704968
,54069889
,54435385
,54800985
,55166607
,55532038
,55897622
,56263155
,56628715
,56993828
,57359455
,57724948
,58090430
,58455645
,58821208
,59186376
,59551580
,59916048
,60281394
,60646993
,61012671
,61378041
,61743641
,62109131
,62474662
,62839908
,63205430
,63571080
,63936573
,64301858
,64667313
,65032636
,65397843
,65762580
,66127829
,66493481
,66858974
,67224415
,67589636
,67955115
,68320322
,68685214
,69050323
,69415723
,69780891
,70145861
,70510876
,70875806
,71240545
,71605093
,71969623
,72335166
,72700765
,73066312
,73431735
,73797404
,74162895
,74528459
,74893522
,75259156
,75624728
,75990173
,76355426
,76720874
,77086081
,77451245
,77816024
,78181584
,78547156
,78912689
,79277894
,79643389
,80008593
,80373879
,80738617
,81103997
,81469358
,81834526
,82199301
,82564551
,82929286
,83294105
,83658537
,84023630
,84389208
,84754740
,85120141
,85485479
,85850840
,86216126
,86581096
,86946085
,87311605
,87676773
,88041860
,88406720
,88771846
,89136586
,89501131
,89865772
,90231295
,90596463
,90961706
,91326371
,91691614
,92056354
,92421054
,92785453
,93150618
,93515357
,93880176
,94244569
,94609349
,94973782
,95338176
,95702538
,96067193
,96432501
,96797722
,97163328
,97528540
,97894069
,98259669
,98625243
,98990329
,99355941
,99721541
,100087079
,100452591
,100818171
,101183663
,101549104
,101914143
,102279561
,102645161
,103010705
,103376172
,103741758
,104107331
,104472812
,104837879
,105203548
,105569042
,105934605
,106299782
,106665266
,107030513
,107395716
,107760258
,108125564
,108491081
,108856681
,109222212
,109587852
,109953423
,110318956
,110684201
,111049566
,111415216
,111780710
,112146072
,112511371
,112876733
,113241939
,113606714
,113971964
,114337539
,114703072
,115068551
,115433772
,115799212
,116164419
,116529389
,116894416
,117259898
,117625144
,117990034
,118355091
,118720099
,119084799
,119449266
,119813793
,120179258
,120544775
,120910445
,121275906
,121641539
,122007032
,122372517
,122737651
,123103329
,123468821
,123834310
,124199477
,124565008
,124930213
,125295379
,125660198
,126025642
,126391292
,126756825
,127122108
,127487486
,127852887
,128218054
,128582871
,128948172
,129313573
,129678780
,130043594
,130408648
,130773540
,131138359
,131502750
,131867722
,132233382
,132598913
,132964355
,133329574
,133695134
,134060301
,134425350
,134790182
,135155742
,135520909
,135886075
,136250857
,136615942
,136980761
,137345305
,137709948
,138075393
,138440599
,138805843
,139170547
,139535711
,139900412
,140265151
,140629544
,140994791
,141359610
,141724309
,142088742
,142453522
,142818035
,143182429
,143546871
,143911818
,144277425
,144642946
,145008560
,145374039
,145739614
,146105146
,146470625
,146835828
,147201407
,147566939
,147932380
,148297676
,148663158
,149028365
,149393334
,149758220
,150123804
,150489298
,150854819
,151220038
,151585520
,151950726
,152315891
,152680643
,153046166
,153411334
,153776538
,154141281
,154506484
,154871185
,155235964
,155600320
,155965920
,156331452
,156697024
,157062190
,157427724
,157793009
,158158215
,158522913
,158888332
,159253734
,159618862
,159983677
,160348887
,160713662
,161078441
,161442833
,161808022
,162173502
,162538630
,162903640
,163268538
,163633508
,163998207
,164362795
,164727737
,165092706
,165457485
,165821953
,166186699
,166551166
,166915640
,167279959
,167644695
,168010287
,168375860
,168741344
,169106599
,169472044
,169837212
,170202455
,170567201
,170932691
,171297857
,171663062
,172027881
,172393047
,172757746
,173122525
,173486998
,173852496
,174217818
,174583025
,174947802
,175312893
,175677668
,176042447
,176406959
,176772093
,177136946
,177501646
,177866037
,178230900
,178595330
,178959804
,179324084
,179689243
,180054724
,180419931
,180784940
,181149799
,181514886
,181879665
,182244092
,182608842
,182973968
,183338707
,183703251
,184067961
,184432544
,184797018
,185161376
,185525902
,185891106
,186255846
,186620585
,186984981
,187349800
,187714193
,188078627
,188442990
,188807853
,189172326
,189536800
,189901122
,190265600
,190630042
,190994447
,191359062
,191723797
,192089029
,192454209
,192819821
,193185027
,193550642
,193916200
,194281780
,194647012
,195012470
,195377991
,195743613
,196109123
,196474667
,196840199
,197205760
,197570547
,197936092
,198301570
,198667239
,199032740
,199398293
,199763826
,200129310
,200494405
,200860083
,201225655
,201591103
,201956272
,202321842
,202687047
,203052213
,203416952
,203782177
,204147698
,204513257
,204878907
,205244311
,205609921
,205975415
,206340777
,206706101
,207071714
,207437208
,207802687
,208167909
,208533388
,208898595
,209263526
,209628495
,209994155
,210359606
,210725088
,211090346
,211455867
,211821074
,212186082
,212550954
,212916474
,213281642
,213646807
,214011550
,214376635
,214741454
,215106038
,215470358
,215835745
,216201342
,216567020
,216932351
,217298070
,217663521
,218029052
,218394257
,218759817
,219125429
,219490961
,219856206
,220221662
,220586945
,220952191
,221316889
,221682258
,222047790
,222413362
,222778763
,223144023
,223509503
,223874631
,224239523
,224604632
,224970071
,225335239
,225700249
,226065145
,226430155
,226794934
,227159442
,227524334
,227889878
,228255372
,228620932
,228986112
,229351593
,229716840
,230081925
,230446717
,230812240
,231177408
,231542651
,231907354
,232272598
,232637259
,233002038
,233366357
,233731927
,234097093
,234462339
,234827158
,235192364
,235557103
,235921842
,236286355
,236651564
,237016301
,237381080
,237745473
,238110214
,238474646
,238839120
,239203561
,239568385
,239934000
,240299519
,240665098
,241030528
,241396149
,241761720
,242127202
,242492318
,242857902
,243223435
,243588995
,243954135
,244319656
,244684863
,245049988
,245414707
,245780300
,246145833
,246511356
,246876572
,247242097
,247607264
,247972467
,248337174
,248702744
,249067910
,249433115
,249797854
,250163060
,250527799
,250892498
,251257011
,251622379
,251988029
,252353522
,252718924
,253084263
,253449584
,253814870
,254179645
,254544831
,254910310
,255275517
,255640409
,256005385
,256370395
,256735095
,257099605
,257464596
,257830078
,258195285
,258560254
,258925153
,259290200
,259655019
,260019486
,260384196
,260749361
,261114021
,261478645
,261843314
,262207858
,262572372
,262936690
,263301182
,263666860
,264032391
,264397881
,264763006
,265128578
,265493744
,265859030
,266223729
,266589304
,266954508
,267319794
,267684532
,268049780
,268414557
,268779297
,269143769
,269508994
,269874434
,270239641
,270604494
,270969548
,271334480
,271699220
,272063650
,272428552
,272793562
,273158261
,273522769
,273887474
,274251942
,274616456
,274980895
,275345702
,275711222
,276076390
,276441516
,276806376
,277171541
,277536281
,277900864
,278265380
,278630623
,278995363
,279360063
,279724459
,280089198
,280453594
,280817987
,281182391
,281547680
,281912459
,282277238
,282641711
,283006371
,283370884
,283735278
,284099720
,284464585
,284829017
,285193411
,285557852
,285922291
,286286732
,286651258
,287015750
,287380740
,287746316
,288111833
,288477535
,288842927
,289208549
,289574043
,289939603
,290304717
,290670303
,291035876
,291401357
,291766615
,292132057
,292497303
,292862468
,293227145
,293592740
,293958232
,294323758
,294689010
,295054458
,295419705
,295784830
,296149569
,296515141
,296880347
,297245553
,297610252
,297975579
,298340237
,298705016
,299069529
,299434819
,299800431
,300165963
,300531364
,300896624
,301262103
,301627271
,301992084
,302357232
,302722672
,303087879
,303452849
,303817786
,304182716
,304547495
,304912083
,305276919
,305642440
,306007686
,306372773
,306737554
,307102719
,307467420
,307832005
,308196676
,308561840
,308926580
,309291203
,309655676
,310020377
,310384851
,310749128
,311113615
,311479174
,311844746
,312210358
,312575524
,312941097
,313306342
,313671469
,314036247
,314401666
,314767067
,315132234
,315497051
,315862181
,316226956
,316591695
,316956167
,317321396
,317686835
,318052002
,318416974
,318781871
,319146881
,319511621
,319876129
,320241070
,320606000
,320970819
,321335287
,321699993
,322064460
,322428894
,322793293
,323158101
,323523663
,323888830
,324254035
,324618699
,324983942
,325348682
,325713343
,326077821
,326442985
,326807686
,327172425
,327536818
,327901638
,328266071
,328630545
,328994948
,329360199
,329724897
,330089716
,330454109
,330818969
,331183362
,331547836
,331912237
,332277023
,332641415
,333005929
,333370370
,333734809
,334099250
,334463656
,334828188
,335193492
,335559114
,335924608
,336290168
,336655309
,337020869
,337386076
,337751162
,338115956
,338481438
,338846644
,339211809
,339576591
,339941795
,340306535
,340671157
,341035640
,341401128
,341766334
,342131499
,342496280
,342861485
,343226224
,343590923
,343955436
,344320683
,344685382
,345050081
,345414594
,345779294
,346143767
,346508241
,346872562
,347237991
,347603432
,347968638
,348333492
,348698546
,349063438
,349428217
,349792608
,350157550
,350522520
,350887219
,351251807
,351616432
,351980980
,352345454
,352709853
,353074726
,353439853
,353804592
,354169138
,354533648
,354898272
,355262746
,355627104
,355991783
,356356446
,356720880
,357085197
,357449801
,357814157
,358178643
,358543049
,358907870
,359273444
,359638649
,360003895
,360368634
,360733841
,361098579
,361463318
,361827711
,362192923
,362557698
,362922477
,363286989
,363651730
,364016162
,364380596
,364745037
, 365110061, 365241885 };


	/// Function Mine

	int SH_erfen(int day) {
		int left = 0;
		int right = 1001;
		int middle = 0;
		if (day == S_day[1000]) {
			return 1001;
		}
		while (right - left > 1) {
			middle = left + int((right - left) / 2);
			if (day < S_day[middle - 1]) {
				right = middle;
			}
			else if (day > S_day[middle - 1]) {
				left = middle;
			}
			else
			{
				return middle;
			}
		}

		return left;
	}



	int digit_sum(int x) {
		int result = 0;
		int base = 2;
		int d = 0;
		int k = int(log(x) / log(base)) + 1;
		for (int i = 0; i < k; i++) {
			d = (x % (int)pow(base, i + 1) - x % (int)pow(base, i)) / (int)pow(base, i);
			result += d;
		}
		return result;
	}


	string smonth_string(int year,int num) {
		return sm_stirng[num];
	}

	int sweekday_int(int year, char *month, int day) {

	}
	// 计算该月多少天
	int sendDay(int year, char* month) {
		int result_endDay = 0;


		string mm = month;
		int numOfm = 0;
		if (mm == "SIST") {
			int leep_m = 0;
			int sy = digit_sum(year);
			int temp = year - sy;
			leep_m = temp % 9 + 1;
			numOfm = leep_m + 1;
			result_endDay = 39 + (10 * year - numOfm) % 3;
		}
		else {
			for (int i = 0; i < 9; i++) {
				if (mm == sm_stirng[i]) {
					numOfm = i;
					break;
				}
			}
			numOfm++; // 符合真正月份

			bool leep = scheak_leepyear(year);
			if (leep) {
				int leep_m = 0;
				int sy = digit_sum(year);
				int temp = year - sy;
				leep_m = temp % 9 + 1;
				if (numOfm > leep_m) {
					numOfm++;
				}
				result_endDay = 39 + (10 * year - numOfm) % 3;

			}
			else
			{
				result_endDay = 39 + (10 * year - numOfm) % 3;
			}

		}


		return result_endDay;


	}
	//计算该年多少天
	int SyearDay(int y) {
		bool leep = scheak_leepyear(y);

	}
	// 计算在Shanghai日历中1000年以内的天数
	int Syinei_calday(int y, char* month, int d) {
		int result = 0;
		int son_y = int(y / 1000);

	}

	// 计算在Shanghai日历中的总共天数
	int Scalday(int y, char* month, int d) {
		int result = 0;
		int son_y = int(y / 1000);
		if (son_y == 0) {
			//result = 
		}
		else if (son_y > 1000) 
		{
			result += S_day[1000];

		}
		else {
			result += S_day[son_y - 1];
		}
		
	}

	bool scheak_leepyear(int year) {
		int sy = digit_sum(year);
		int temp = year + sy;
		if (temp % 8 == 0) {
			return true;
		}
		else
		{
			return false;
		}
	}




	/// end Mine



	/// Function HW

	Shanghaitech(int year, char *month, int day):Gregorian(year, month,  day) {
		year_S = year;
		month_S = month;
		day_S = day;
	};
	void print_today() {

		cout << this->year_S << ' ' << this->month_S << ' ' << this->day_S << endl;
	}
	void print_month() {
		cout << *month_S << *(month_S + 1) << *(month_S + 2) << "                                 " << endl;
		cout << "┌────┬────┬────┬────┬────┬────┬────┐" << endl;
		cout << "│ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│" << endl;
		cout << "├────┼────┼────┼────┼────┼────┼────┤" << endl;

		//string week_firstday = weekday(this->year_S, this->month_S, 1);
		bool leapyear = check_leapyear(this->year_S);
		int numOfmonth = month_num(this->month_S);
		int endDay = 0;
		//用int输出第一天是周几
		int w = weekday_int(this->year_S, this->month_S, 1);

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
	bool pass_day(int n) {
		char *month_char[] = { (char*)"Sist",(char*)"Spst",(char*)"Slst",(char*)"Sem",(char*)"Sca",(char*)"Ims",(char*)"Ihuman",(char*)"Siais",(char*)"Ih" };
		bool leapyear = scheak_leepyear(this->year_S);
		int numOfmonth = month_num(this->month_S);
		int endDay = 0;




		/// 保留原始数据
		int or_y = year_S;
		int or_d = day_S;
		int or_m = numOfmonth;
		/// 结束保留








	}

	bool pass_year(int n) {
		char *month_char[] = { (char*)"Sist",(char*)"Spst",(char*)"Slst",(char*)"Sem",(char*)"Sca",(char*)"Ims",(char*)"Ihuman",(char*)"Siais",(char*)"Ih" };
		

		int or_y = year_S;
		year_S += n;
		if (year_S <= 999999 && year_S >= 1) {
			month_S = (char*)month_char[0];
			day_S = 1;
			return true;
		}
		else
		{
			year_S = or_y;
			//cout << year_S << ' ' << *month_S << *(month_S + 1) << *(month_S + 2) << ' ' << day_S << ' ' << endl;
			return false;
		}
	}




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
			if (calendar == "G") {
				G->pass_day(n); S->pass_day(n);
			}
			else { S->pass_day(n); G->pass_day(n);
			}
		}
		else if (f == "pass_month") {
			std::cin >> n;
			if (calendar == "G") { G->pass_month(n);  }
			else {
				S->pass_month(n); 
			}
		}
		else if (f == "pass_year") {
			std::cin >> n;
			if (calendar == "G") G->pass_year(n);
			else { S->pass_year(n); 
			}
		}
		else if (f == "print_today") {
			if (calendar == "G") { G->print_today(); 
			}
			else S->print_today(); 
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
