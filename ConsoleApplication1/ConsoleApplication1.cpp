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

	int GtotalDay = 0;

	const string s_month[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

	const string zifu[32] = {
" 01 │", " 02 │" ," 03 │",	" 04 │", " 05 │" ," 06 │",	" 07 │", " 08 │" ," 09 │",
" 10 │", " 11 │", " 12 │" ," 13 │",	" 14 │", " 15 │" ," 16 │",	" 17 │", " 18 │" ," 19 │",
" 20 │"," 21 │", " 22 │" ," 23 │",	" 24 │", " 25 │" ," 26 │",	" 27 │", " 28 │" ," 29 │",
" 30 │"," 31 │" ,"    │" };

	// Function mine 


	//计算过了多少天 1年1月3号是3天 
	int gcaltotalDay(int y, char* m, int d) {

		int shuzu[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		int mnum = month_num(m); //月份
		int sumresult = 0;
		int dyear = (y - 1) * 365 + int((y - 1) / 4) - int((y - 1) / 100) + int((y - 1) / 400) - int((y - 1) / 4000);

		// 计算今年过了多少天 （算上当前天）
		bool leepG = check_leapyear(y);
		for (int i = 1; i < mnum; i++) {
			sumresult += shuzu[i - 1];
		}
		if (leepG && mnum > 2) {
			sumresult += 1;
		}
		sumresult += dyear;
		sumresult += d;
		return sumresult;
	}

	//由过了多少天返回年月日
	void gdayToDate(int n) {
		int y = 1;
		int remi_day = n;
		int sumday = 0;
		while (remi_day > 1000)
		{
			int tempy = 0;
			tempy = int(remi_day / 366);
			y += tempy - 1;
			sumday = gcaltotalDay(y - 1, (char*)"Dec", 31);
			remi_day = n - sumday;
		}
		if (remi_day < 0) {
			cout << "cuowu" << endl;
		}
		else
		{
			year_G = y;
			month_G = (char*)"Jan";
			day_G = 1;
			Gcal_pass_day(remi_day - 1);
		}

	}


	//用于改变天数，不调用S历的更新



	//bool Gcal_pass_day(int n) {
	//	char *month_char[] = { (char*)"Jan", (char*)"Feb", (char*)"Mar", (char*)"Apr", (char*)"May", (char*)"Jun", (char*)"Jul", (char*)"Aug", (char*)"Sep", (char*)"Oct", (char*)"Nov", (char*)"Dec" };
	//	bool leapyear = check_leapyear(this->year_G);
	//	int numOfmonth = month_num(this->month_G);
	//	int endDay = monthEndDay(year_G, numOfmonth);
	//	// 输出这个月的一共有多少天


	//			/// 保留原始数据

	//	int or_y = year_G;
	//	int or_d = day_G;
	//	int or_m = numOfmonth;
	//	/// 结束保留


	//	int y = year_G;
	//	int m = numOfmonth;
	//	int d = day_G;

	//	n += day_G;

	//	if (n > 0) {
	//		if (n <= endDay) {
	//			day_G = n;
	//		}
	//		else {
	//			while (n > endDay) {
	//				n -= endDay;
	//				m += 1;
	//				if (m > 12) {
	//					y += 1;
	//					m = 1;
	//				}
	//				endDay = monthEndDay(y, m);
	//			}
	//			year_G = y;
	//			month_G = (char*)month_char[m - 1];
	//			day_G = n;
	//		}
	//	}
	//	else {
	//		while (n < 1) {
	//			m -= 1;
	//			if (m < 1) {
	//				m = 12;
	//				y -= 1;
	//			}
	//			endDay = monthEndDay(y, m);
	//			n += endDay;
	//		}

	//		year_G = y;
	//		month_G = (char*)month_char[m - 1];
	//		day_G = n;

	//	}




	//	if (year_G <= 999999 && year_G >= 1) {

	//		return true;
	//	}
	//	else
	//	{
	//		year_G = or_y;
	//		day_G = or_d;
	//		month_G = (char*)month_char[or_m - 1];

	//		//cout << year_G << ' ' << *month_G << *(month_G + 1) << *(month_G + 2) << ' ' << day_G << ' ' << endl;

	//		return false;
	//	}




	//}

	bool  Gcal_pass_day(int num_days) {
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


				} while (n > (mon[m] + check_leapyear(y)*(m == 2)));
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
			if (int temp = n + d >= 1) {
				day_G = n + d;
			}
			else
			{
				n += d;
				while (-n >= mon[m - 1])
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

				month_G = (char*)month_char[m - 1];
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

	// 根据字符返回月份的数字
	int month_num(char* month) {
		int result = 999;

		string mm = month;
		for (int i = 0; i < 12; i++) {
			if (mm == s_month[i]) {
				result = i;
				result += 1;
				break;
			}
		}

		return result;
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
	//计算当某月的总天数 月份输入为真实int
	int monthEndDay(int y, int m) {
		int result = 0;
		int mon[13] = { 31,31,28,31,30,31,30,31,31,30,31,30,31 };
		bool leep = check_leapyear(y);
		if (leep) {
			if (m == 2) {
				result = 29;
			}
			else {
				result = mon[m];
			}
		}
		else {
			result = mon[m];
		}
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

		cout << this->year_G << ' ' << this->month_G << ' ' << this->day_G << endl;
	}

	//print the date of today in Gregorian format by "yearmonthnday"
	void print_month() {
		cout << *month_G << *(month_G + 1) << *(month_G + 2) << "                                 " << endl;
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

					GtotalDay = gcaltotalDay(year_G, month_G, day_G);
					callback();

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


				} while (n > (mon[m]+check_leapyear(y)*(m==2)));
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
			if (int temp = n + d >= 1) {
				day_G = n + d;
			}
			else
			{
				n += d;
				while (-n >= mon[m - 1])
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

				month_G = (char*)month_char[m - 1];
				year_G = y;
				day_G = n;

			}
		}


		if (year_G <= 999999 && year_G >= 1) {
			GtotalDay = gcaltotalDay(year_G, month_G, day_G);
			callback();
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
			GtotalDay = gcaltotalDay(year_G, month_G, day_G);
			callback();
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
			GtotalDay = gcaltotalDay(year_G, month_G, day_G);
			callback();
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




	virtual void callback() {

	}

};







class Shanghaitech :public Gregorian {
	//class Shanghaitech  {
private:
	int year_S;
	char* month_S;
	int day_S;
	int baocuo_day = 0;
	int baocuo_year = 0;
	int baocuo_month = 0;
public:

	int StotalDay = 0;
	/// Variable
	const string sm_stirng[9] = { "Sist","Spst","Slst","Sem","Sca","Ims","Ihuman","Siais","Ih" };
	const string run_sm_string[18] = { "Sist","Spst","Slst","Sem","Sca","Ims","Ihuman","Siais","Ih","SIST" ,"SPST",
			"SLST","SEM","SCA","IMS","IHUMAN","SIAIS","IH" };
	const string hzifu[42] = {
" 01 │", " 02 │" ," 03 │",	" 04 │", " 05 │" ," 06 │",	" 07 │", " 08 │" ," 09 │"," 0A │", " 0B │", " 0C │" ,
" 0D │" ," 0E │" ," 0F │" ," 10 │", " 11 │", " 12 │" ," 13 │",	" 14 │", " 15 │" ," 16 │",	" 17 │", " 18 │" ," 19 │"," 1A │", " 1B │", " 1C │" ,
" 1D │" ," 1E │" ," 1F │" ," 20 │"," 21 │", " 22 │" ," 23 │",	" 24 │", " 25 │" ," 26 │",	" 27 │", " 28 │" ," 29 │","    │" };
	int S_day[10004] = { 36362
,72798
,109275
,145711
,182112
,218628
,255026
,291466
,327947
,364353
,400870
,437306
,473787
,510109
,546592
,583112
,619514
,656118
,692563
,729168
,765685
,802121
,838482
,874921
,911365
,947965
,984367
,1020853
,1057297
,1093941
,1130459
,1166861
,1203346
,1239788
,1276393
,1312953
,1349478
,1386083
,1422605
,1459166
,1495682
,1532197
,1568595
,1605035
,1641437
,1678003
,1714401
,1750845
,1787328
,1823853
,1860497
,1896933
,1933338
,1969860
,2006426
,2042990
,2079431
,2115997
,2152558
,2189161
,2225680
,2262194
,2298637
,2335162
,2371647
,2408211
,2444691
,2481216
,2517819
,2554462
,2590942
,2627458
,2663983
,2700627
,2737149
,2773710
,2810228
,2846830
,2883349
,2919946
,2956462
,2993058
,3029532
,3065930
,3102370
,3138772
,3175338
,3211736
,3248180
,3284663
,3321229
,3357832
,3394268
,3430673
,3467236
,3503761
,3540364
,3576766
,3613371
,3649893
,3686496
,3723055
,3759570
,3795972
,3832576
,3868982
,3905585
,3942026
,3978592
,4015194
,4051797
,4088316
,4124793
,4161318
,4197962
,4234525
,4271045
,4307563
,4344165
,4380723
,4417320
,4453837
,4490431
,4526791
,4563276
,4599759
,4636323
,4672925
,4709410
,4745974
,4782535
,4819137
,4855654
,4892097
,4928741
,4965263
,5001865
,5038383
,5074984
,5111545
,5148141
,5184658
,5221213
,5257694
,5294260
,5330780
,5367424
,5403943
,5440542
,5477144
,5513620
,5550179
,5586734
,5623294
,5659894
,5696452
,5732971
,5769565
,5806163
,5842679
,5879274
,5915790
,5952384
,5988784
,6025258
,6061656
,6098137
,6134539
,6171064
,6207462
,6243947
,6280430
,6316996
,6353598
,6390035
,6426479
,6462962
,6499487
,6536131
,6572533
,6609177
,6645660
,6682262
,6718820
,6755375
,6791698
,6828302
,6864788
,6901391
,6937793
,6974357
,7010959
,7047562
,7084122
,7120560
,7157085
,7193688
,7230331
,7266811
,7303369
,7339971
,7376489
,7413087
,7449642
,7486236
,7522558
,7559041
,7595565
,7632131
,7668730
,7705175
,7741780
,7778341
,7814943
,7851419
,7887903
,7924508
,7961030
,7997630
,8034188
,8070790
,8107311
,8143908
,8180424
,8217019
,8253420
,8290025
,8326547
,8363150
,8399709
,8436309
,8472870
,8509427
,8545945
,8582500
,8619100
,8655700
,8692217
,8728737
,8765331
,8801928
,8838485
,8875039
,8911595
,8948150
,8984627
,9020988
,9057473
,9093956
,9130522
,9167121
,9203607
,9240210
,9276773
,9313334
,9349850
,9386335
,9422899
,9459460
,9496062
,9532579
,9569222
,9605702
,9642299
,9678854
,9715449
,9751852
,9788457
,9824979
,9861581
,9898100
,9934700
,9971300
,10007818
,10044336
,10080970
,10117530
,10154132
,10190608
,10227167
,10263722
,10300360
,10336876
,10373470
,10409986
,10446581
,10482980
,10519505
,10556108
,10592632
,10629232
,10665709
,10702312
,10738871
,10775429
,10811984
,10848539
,10885183
,10921702
,10958260
,10994776
,11031410
,11067890
,11104484
,11141000
,11177595
,11214111
,11250675
,11287195
,11323832
,11360308
,11396943
,11433461
,11469978
,11506573
,11543167
,11579683
,11616164
,11652680
,11689274
,11725869
,11762424
,11798823
,11835457
,11871894
,11908490
,11944889
,11981289
,12017725
,12054123
,12090642
,12127006
,12163648
,12199970
,12236453
,12272977
,12309543
,12346063
,12382502
,12418946
,12455470
,12491995
,12528597
,12565080
,12601685
,12638207
,12674807
,12711365
,12747801
,12784206
,12820769
,12857294
,12893897
,12930299
,12966904
,13003426
,13040029
,13076588
,13113066
,13149632
,13186193
,13222837
,13259356
,13295916
,13332516
,13369033
,13405553
,13442147
,13478741
,13515143
,13551588
,13588032
,13624676
,13661156
,13697722
,13734286
,13770849
,13807449
,13843964
,13880450
,13917053
,13953616
,13990177
,14026693
,14063296
,14099856
,14136414
,14172930
,14209524
,14245928
,14282572
,14319094
,14355696
,14392214
,14428815
,14465376
,14501972
,14538489
,14575044
,14611606
,14648206
,14684724
,14721242
,14757876
,14794395
,14830951
,14867545
,14904140
,14940656
,14977132
,15013534
,15050020
,15086464
,15123108
,15159588
,15196113
,15232716
,15269240
,15305840
,15342355
,15378880
,15415485
,15452007
,15488568
,15525084
,15561728
,15598247
,15634805
,15671321
,15707955
,15744358
,15780963
,15817526
,15854087
,15890605
,15927247
,15963767
,16000404
,16036880
,16073515
,16110038
,16146638
,16183154
,16219712
,16256267
,16292826
,16329342
,16365936
,16402531
,16439086
,16475447
,16511972
,16548575
,16585218
,16621698
,16658256
,16694858
,16731376
,16767974
,16804529
,16841047
,16877649
,16914168
,16950765
,16987281
,17023877
,17060395
,17097029
,17133545
,17170139
,17206617
,17243181
,17279739
,17316338
,17352854
,17389448
,17425928
,17462522
,17499039
,17535633
,17572149
,17608709
,17645185
,17681780
,17718374
,17754930
,17791367
,17828002
,17864400
,17900956
,17937355
,17973832
,18010234
,18046800
,18083203
,18119808
,18156288
,18192813
,18229457
,18266020
,18302540
,18339055
,18375621
,18412185
,18448748
,18485348
,18521825
,18558428
,18594947
,18631545
,18668061
,18704655
,18741140
,18777704
,18814265
,18850867
,18887384
,18924027
,18960507
,18997104
,19033659
,19070254
,19106777
,19143338
,19179934
,19216451
,19253006
,19289565
,19326081
,19362716
,19399270
,19435826
,19472188
,19508713
,19545315
,19581918
,19618476
,19654997
,19691597
,19728155
,19764674
,19801268
,19837786
,19874388
,19910907
,19947545
,19984021
,20020657
,20057174
,20093768
,20130284
,20166919
,20203317
,20239961
,20276480
,20313038
,20349554
,20386188
,20422668
,20459262
,20495778
,20532373
,20568889
,20605409
,20641964
,20678520
,20715114
,20751630
,20788107
,20824741
,20861140
,20897656
,20934055
,20970497
,21007061
,21043663
,21080266
,21116826
,21153345
,21189947
,21226464
,21263023
,21299577
,21336136
,21372738
,21409256
,21445854
,21482409
,21519005
,21555522
,21592077
,21628633
,21665228
,21701626
,21738270
,21774789
,21811347
,21847903
,21884497
,21921016
,21957571
,21994127
,22030682
,22067198
,22103718
,22140312
,22176829
,22213423
,22249939
,22286456
,22323050
,22359528
,22395965
,22432364
,22468967
,22505528
,22542085
,22578603
,22615158
,22651756
,22688272
,22724906
,22761421
,22798017
,22834496
,22871053
,22907607
,22944163
,22980718
,23017157
,23053751
,23090267
,23126784
,23163222
,23199662
,23236220
,23272775
,23309330
,23345885
,23382363
,23418958
,23455513
,23491990
,23528468
,23564908
,23601423
,23637979
,23674496
,23710934
,23747293
,23783889
,23820288
,23856767
,23893207
,23929647
,23966045
,24002560
,24038883
,24075322
,24111766
,24148325
,24184727
,24221293
,24257737
,24294342
,24330898
,24367300
,24403786
,24440230
,24476874
,24513354
,24549879
,24586482
,24623006
,24659606
,24696121
,24732522
,24768966
,24805488
,24842054
,24878694
,24915100
,24951703
,24988266
,25024866
,25061383
,25097826
,25134431
,25170994
,25207555
,25244073
,25280715
,25317235
,25353872
,25390348
,25426983
,25463459
,25499782
,25536386
,25572872
,25609475
,25645877
,25682441
,25719043
,25755646
,25792206
,25828644
,25865169
,25901772
,25938415
,25974895
,26011453
,26048055
,26084573
,26121171
,26157726
,26194241
,26230807
,26267371
,26303893
,26340493
,26376970
,26413614
,26450133
,26486691
,26523247
,26559841
,26596405
,26632963
,26669562
,26706078
,26742672
,26779152
,26815746
,26852263
,26888857
,26925373
,26961850
,26998214
,27034777
,27071302
,27107907
,27144307
,27180873
,27217434
,27254078
,27290597
,27327035
,27363601
,27400203
,27436806
,27473325
,27509885
,27546446
,27582964
,27619562
,27656117
,27692632
,27729198
,27765762
,27802325
,27838925
,27875402
,27912005
,27948524
,27985122
,28021638
,28058232
,28094835
,28131395
,28167953
,28204469
,28241063
,28277583
,28314137
,28350693
,28387248
,28423804
,28460207
,28496812
,28533334
,28569936
,28606455
,28643055
,28679655
,28716173
,28752691
,28789325
,28825885
,28862487
,28898963
,28935522
,28972077
,29008715
,29045231
,29081825
,29118341
,29154936
,29191336
,29227938
,29264457
,29301095
,29337571
,29374207
,29410724
,29447318
,29483834
,29520469
,29556908
,29593426
,29629981
,29666576
,29703131
,29739568
,29776163
,29812759
,29849236
,29885713
,29922113
,29958550
,29994955
,30031477
,30068043
,30104607
,30141048
,30177614
,30214175
,30250778
,30287297
,30323776
,30360340
,30396942
,30433545
,30470105
,30506624
,30543226
,30579743
,30616302
,30652856
,30689373
,30725898
,30762542
,30799064
,30835625
,30872143
,30908745
,30945264
,30981861
,31018377
,31054932
,31091576
,31128095
,31164653
,31201209
,31237803
,31274322
,31310877
,31347433
,31383988
,31420504
,31456948
,31493592
,31530073
,31566675
,31603194
,31639796
,31676396
,31712953
,31749470
,31786064
,31822626
,31859187
,31895744
,31932262
,31968817
,32005415
,32041931
,32078565
,32115080
,32151676
,32188118
,32224679
,32261197
,32297795
,32334350
,32370987
,32407463
,32444098
,32480574
,32517208
,32553647
,32590205
,32626760
,32663315
,32699870
,32736348
,32772943
,32809498
,32845975
,32882453
,32918893
,32955257
,32991901
,33028423
,33065025
,33101543
,33138144
,33174705
,33211301
,33247818
,33284373
,33320935
,33357535
,33394053
,33430571
,33467205
,33503724
,33540280
,33576874
,33613469
,33649985
,33686427
,33723027
,33759585
,33796104
,33832698
,33869296
,33905812
,33942407
,33978923
,34015517
,34051997
,34088514
,34125108
,34161624
,34198259
,34234696
,34271291
,34307807
,34344324
,34380762
,34417202
,34453766
,34490285
,34526882
,34563439
,34599993
,34636513
,34673068
,34709624
,34746218
,34782734
,34819253
,34855770
,34892365
,34928959
,34965475
,35001952
,35038507
,35074985
,35111501
,35147940
,35184461
,35220977
,35257571
,35294126
,35330682
,35367120
,35403675
,35440231
,35476747
,35513146
,35549586
,35586220
,35622736
,35659253
,35695651
,35732091
,35768607
,35805006
,35841445
,35877845
,35914365
,35950763
,35987207
,36023690
,36060256
,36096859
,36133302
,36169946
,36206427
,36243029
,36279548
,36316028
,36352633
,36389155
,36425758
,36462317
,36498917
,36535478
,36572035
,36608553
,36645108
,36681586
,36718152
,36754754
,36791357
,36827876
,36864436
,36900997
,36937515
,36974113
,37010668
,37047186
,37083788
,37120346
,37156943
,37193460
,37230055
,37266613
,37303168
,37339723
,37376278
,37412756
,37449241
,37485805
,37522366
,37558968
,37595485
,37632128
,37668608
,37705205
,37741760
,37778355
,37814878
,37851439
,37888035
,37924552
,37961107
,37997666
,38034182
,38070817
,38107371
,38143927
,38180409
,38217011
,38253487
,38290046
,38326601
,38363239
,38399755
,38436349
,38472865
,38509460
,38545940
,38582456
,38619051
,38655567
,38692161
,38728600
,38765194
,38801750
,38838227
,38874665
,38911144
,38947550
,38984153
,39020716
,39057316
,39093833
,39130437
,39166956
,39203553
,39240110
,39276664
,39313228
,39349748
,39386385
,39422861
,39459496
,39496014
,39532531
,39569126
,39605720
,39642236
,39678759
,39715320
,39751836
,39788355
,39824950
,39861548
,39898064
,39934658
,39971213
,40007769
,40044249
,40080804
,40117399
,40153876
,40190510
,40226909
,40263543
,40300059
,40336576
,40372974
,40409374
,40446018
,40482537
,40519095
,40555651
,40592245
,40628764
,40665319
,40701875
,40738430
,40774946
,40811466
,40848060
,40884577
,40921171
,40957687
,40994204
,41030798
,41067276
,41103713
,41140112
,41176673
,41213228
,41249822
,41286417
,41322933
,41359411
,41395966
,41432403
,41468999
,41505398
,41541837
,41578432
,41614948
,41651504
,41687863
,41724381
,41760859
,41797258
,41833697
,41870097
,41906616
,41943102
,41979705
,42016268
,42052829
,42089345
,42125948
,42162508
,42199066
,42235582
,42272176
,42308780
,42345260
,42381857
,42418412
,42455007
,42491527
,42528082
,42564598
,42601232
,42637748
,42674231
,42710831
,42747349
,42783867
,42820501
,42857020
,42893576
,42930170
,42966765
,43003281
,43039801
,43076317
,43112911
,43149427
,43186022
,43222421
,43259015
,43295531
,43332087
,43368486
,43404887
,43441490
,43478049
,43514607
,43551162
,43587758
,43624276
,43660831
,43697426
,43733981
,43770418
,43806978
,43843572
,43880088
,43916683
,43953199
,43989755
,44026310
,44062787
,44099265
,44135664
,44172223
,44208740
,44245335
,44281929
,44318445
,44354922
,44391477
,44427955
,44464471
,44500910
,44537349
,44573983
,44610420
,44647016
,44683415
,44719933
,44756371
,44792730
,44829209
,44865649
,44902091
,44938693
,44975212
,45011809
,45048325
,45084921
,45121439
,45158073
,45194589
,45231183
,45267661
,45304180
,45340735
,45377291
,45413846
,45450362
,45486918
,45523513
,45559950
,45596468
,45632827
,45669427
,45705903
,45742498
,45779092
,45815648
,45852085
,45888720
,45925118
,45961674
,45998073
,46034591
,46071146
,46107583
,46144179
,46180578
,46217096
,46253573
,46289973
,46326372
,46362892
,46399373
,46435849
,46472484
,46508960
,46545594
,46582033
,46618627
,46655143
,46691660
,46728098
,46764498
,46801093
,46837648
,46874125
,46910603
,46947043
,46983559
,47019958
,47056397
,47092797
,47129317
,47165754
,47202388
,47238826
,47275263
,47311742
,47348299
,47384697
,47421176
,47457576
,47494016
,47530533
,47567011
,47603411
,47639810
,47676250
,47712729
,47749129
,47785609
,47822089
,47858449
,47894890
,47931326
,47967724
,48004243
,48040607
,48077170
,48113571
,48150015
,48186537
,48223103
,48259664
,48296062
,48332547
,48369030
,48405596
,48442198
,48478640
,48515245
,48551808
,48588369
,48624887
,48661402
,48697807
,48734329
,48770895
,48807459
,48843900
,48880466
,48917027
,48953630
,48990149
,49026628
,49063192
,49099794
,49136397
,49172957
,49209476
,49246078
,49282595
,49319154
,49355708
,49392263
,49428744
,49465150
,49501633
,49538238
,49574757
,49611323
,49647887
,49684409
,49721009
,49757565
,49794010
,49830615
,49867176
,49903778
,49940254
,49976858
,50013416
,50050015
,50086531
,50123125
,50159529
,50196173
,50232654
,50269256
,50305775
,50342377
,50378977
,50415534
,50452051
,50488645
,50525207
,50561768
,50598325
,50634843
,50671398
,50707996
,50744512
,50781146
,50817661
,50854257
,50890733
,50927135
,50963580
,51000024
,51036668
,51073148
,51109714
,51146278
,51182841
,51219441
,51255956
,51292442
,51329045
,51365608
,51402169
,51438685
,51475288
,51511848
,51548406
,51584922
,51621516
,51657920
,51694564
,51731086
,51767688
,51804206
,51840807
,51877368
,51913964
,51950481
,51987036
,52023598
,52060198
,52096716
,52133234
,52169868
,52206387
,52242943
,52279537
,52316132
,52352648
,52389007
,52425573
,52462176
,52498778
,52535299
,52571816
,52608418
,52644937
,52681575
,52718051
,52754607
,52791210
,52827769
,52864327
,52900882
,52937478
,52973996
,53010551
,53047146
,53083701
,53120138
,53156782
,53193301
,53229898
,53266455
,53303009
,53339529
,53376084
,53412640
,53449234
,53485750
,53522269
,53558786
,53595381
,53631975
,53668491
,53704968
,53741523
,53778001
,53814517
,53850956
,53887433
,53923835
,53960360
,53996765
,54033409
,54069889
,54106414
,54143058
,54179580
,54216141
,54252656
,54289222
,54325786
,54362308
,54398908
,54435385
,54472029
,54508548
,54545106
,54581662
,54618256
,54654700
,54691305
,54727827
,54764427
,54800985
,54837587
,54874108
,54910705
,54947221
,54983816
,55020339
,55056939
,55093496
,55130013
,55166607
,55203127
,55239682
,55276276
,55312871
,55349387
,55385748
,55422314
,55458916
,55495519
,55532038
,55568598
,55605159
,55641677
,55678275
,55714830
,55751348
,55787950
,55824508
,55861105
,55897622
,55934217
,55970775
,56007330
,56043885
,56080440
,56116918
,56153521
,56190081
,56226639
,56263155
,56299749
,56336269
,56372823
,56409379
,56445934
,56482490
,56519010
,56555565
,56592081
,56628715
,56665231
,56701708
,56738303
,56774741
,56811257
,56847656
,56884098
,56920623
,56957225
,56993828
,57030386
,57066907
,57103507
,57140065
,57176584
,57213178
,57249696
,57286298
,57322817
,57359455
,57395931
,57432567
,57469084
,57505678
,57542194
,57578829
,57615227
,57651871
,57688390
,57724948
,57761464
,57798098
,57834578
,57871172
,57907688
,57944283
,57980799
,58017319
,58053874
,58090430
,58127024
,58163540
,58200017
,58236651
,58273050
,58309566
,58345965
,58382568
,58419129
,58455645
,58492164
,58528759
,58565357
,58601873
,58638467
,58675022
,58711578
,58748058
,58784613
,58821208
,58857685
,58894319
,58930718
,58967352
,59003868
,59040385
,59076783
,59113224
,59149742
,59186376
,59222892
,59259486
,59295964
,59332559
,59369075
,59405591
,59442029
,59478429
,59514985
,59551580
,59588017
,59624535
,59660894
,59697490
,59733889
,59770368
,59806808
,59843248
,59879646
,59916048
,59952652
,59989058
,60025661
,60062102
,60098668
,60135270
,60171873
,60208392
,60244869
,60281394
,60318038
,60354601
,60391121
,60427639
,60464241
,60500799
,60537396
,60573913
,60610507
,60646993
,60683596
,60720159
,60756720
,60793236
,60829839
,60866399
,60902957
,60939473
,60976067
,61012671
,61049151
,61085748
,61122303
,61158898
,61195418
,61231973
,61268489
,61305123
,61341639
,61378041
,61414607
,61451127
,61487771
,61524290
,61560889
,61597491
,61633967
,61670526
,61707081
,61743641
,61780241
,61816799
,61853318
,61889912
,61926510
,61963026
,61999621
,62036137
,62072731
,62109131
,62145734
,62182293
,62218851
,62255406
,62292002
,62328520
,62365075
,62401670
,62438225
,62474662
,62511222
,62547816
,62584332
,62620927
,62657443
,62693999
,62730554
,62767031
,62803509
,62839908
,62876350
,62912916
,62949477
,62986080
,63022599
,63059239
,63095800
,63132316
,63168835
,63205430
,63241989
,63278591
,63315108
,63351667
,63388221
,63424819
,63461374
,63497969
,63534446
,63571080
,63607481
,63644083
,63680602
,63717199
,63753715
,63790311
,63826829
,63863463
,63899979
,63936573
,63973051
,64009570
,64046125
,64082681
,64119236
,64155752
,64192308
,64228903
,64265340
,64301858
,64338217
,64374781
,64411381
,64447938
,64484455
,64521049
,64557569
,64594124
,64630718
,64667313
,64703829
,64740310
,64776826
,64813460
,64849975
,64886571
,64922969
,64959564
,64996080
,65032636
,65068995
,65105556
,65142032
,65178667
,65215143
,65251777
,65288216
,65324810
,65361326
,65397843
,65434281
,65470681
,65507276
,65543831
,65580308
,65616786
,65653226
,65689742
,65726141
,65762580
,65798980
,65835500
,65871863
,65908468
,65944990
,65981592
,66018111
,66054711
,66091311
,66127829
,66164347
,66200981
,66237541
,66274143
,66310619
,66347178
,66383733
,66420371
,66456887
,66493481
,66529997
,66566592
,66602992
,66639594
,66676113
,66712751
,66749227
,66785863
,66822380
,66858974
,66895490
,66932125
,66968564
,67005082
,67041637
,67078232
,67114787
,67151224
,67187819
,67224415
,67260892
,67297369
,67333769
,67370333
,67406853
,67443490
,67479966
,67516601
,67553119
,67589636
,67626231
,67662825
,67699341
,67735822
,67772338
,67808932
,67845527
,67882082
,67918481
,67955115
,67991552
,68028148
,68064547
,68101028
,68137583
,68174178
,68210655
,68247289
,68283688
,68320322
,68356838
,68393355
,68429753
,68466233
,68502787
,68539343
,68575820
,68612298
,68648698
,68685214
,68721613
,68758092
,68794492
,68830972
,68867535
,68904056
,68940653
,68977169
,69013764
,69050323
,69086799
,69123394
,69159988
,69196544
,69232985
,69269540
,69306134
,69342729
,69379245
,69415723
,69452278
,69488715
,69525311
,69561710
,69598230
,69634787
,69671341
,69707897
,69744452
,69780891
,69817485
,69854001
,69890518
,69926956
,69963396
,69999990
,70036506
,70073023
,70109461
,70145861
,70182377
,70218816
,70255255
,70291655
,70328135
,70364655
,70401209
,70437765
,70474320
,70510876
,70547353
,70583987
,70620425
,70656862
,70693341
,70729858
,70766453
,70802891
,70839407
,70875806
,70912363
,70948841
,70985241
,71021640
,71058080
,71094559
,71131114
,71167630
,71204186
,71240545
,71277063
,71313581
,71349940
,71386419
,71422859
,71459338
,71495775
,71532174
,71568693
,71605093
,71641573
,71677932
,71714452
,71750852
,71787372
,71823692
,71860171
,71896615
,71933098
,71969623
,72006267
,72042669
,72079313
,72115796
,72152398
,72188956
,72225436
,72262002
,72298563
,72335166
,72371685
,72408325
,72444886
,72481402
,72517921
,72554516
,72590994
,72627519
,72664122
,72700765
,72737245
,72773803
,72810405
,72846923
,72883521
,72920076
,72956594
,72993196
,73029715
,73066312
,73102828
,73139424
,73175942
,73212576
,73249092
,73285686
,73322164
,73358608
,73395213
,73431735
,73468335
,73504893
,73541495
,73578016
,73614613
,73651129
,73687724
,73724247
,73760847
,73797404
,73833921
,73870515
,73907035
,73943590
,73980184
,74016779
,74053295
,74089778
,74126378
,74162895
,74199415
,74236009
,74272606
,74309163
,74345717
,74382273
,74418828
,74455348
,74491824
,74528459
,74564935
,74601569
,74638008
,74674602
,74711118
,74747635
,74784073
,74820473
,74856958
,74893522
,74930083
,74966685
,75003202
,75039845
,75076325
,75112922
,75149477
,75186072
,75222595
,75259156
,75295752
,75332269
,75368824
,75405383
,75441899
,75478534
,75515088
,75551644
,75588126
,75624728
,75661204
,75697763
,75734318
,75770956
,75807472
,75844066
,75880582
,75917177
,75953657
,75990173
,76026768
,76063284
,76099878
,76136317
,76172911
,76209467
,76245944
,76282382
,76318782
,76355426
,76391945
,76428503
,76465019
,76501653
,76538133
,76574727
,76611243
,76647838
,76684354
,76720874
,76757429
,76793985
,76830579
,76867095
,76903572
,76940206
,76976605
,77013121
,77049520
,77086081
,77122597
,77159191
,77195786
,77232341
,77268740
,77305374
,77341811
,77378407
,77414806
,77451245
,77487800
,77524356
,77560872
,77597271
,77633750
,77670187
,77706666
,77743105
,77779505
,77816024
,77852469
,77889074
,77925635
,77962237
,77998713
,78035317
,78071875
,78108474
,78144990
,78181584
,78218147
,78254668
,78291265
,78327781
,78364376
,78400935
,78437411
,78474006
,78510600
,78547156
,78583639
,78620200
,78656757
,78693275
,78729830
,78766428
,78802944
,78839578
,78876093
,78912689
,78949168
,78985725
,79022279
,79058835
,79095390
,79131829
,79168423
,79204939
,79241456
,79277894
,79314295
,79350898
,79387417
,79424015
,79460531
,79497125
,79533644
,79570239
,79606755
,79643389
,79679826
,79716386
,79752940
,79789496
,79826051
,79862607
,79899084
,79935718
,79972156
,80008593
,80045072
,80081592
,80118108
,80154743
,80191297
,80227853
,80264291
,80300885
,80337363
,80373879
,80410278
,80446757
,80483312
,80519828
,80556384
,80592743
,80629261
,80665779
,80702138
,80738617
,80775057
,80811458
,80848061
,80884620
,80921178
,80957733
,80994329
,81030847
,81067402
,81103997
,81140552
,81176989
,81213549
,81250143
,81286659
,81323254
,81359770
,81396326
,81432881
,81469358
,81505836
,81542235
,81578794
,81615311
,81651906
,81688500
,81725016
,81761493
,81798048
,81834526
,81871042
,81907481
,81943920
,81980554
,82016991
,82053587
,82089986
,82126504
,82162942
,82199301
,82235780
,82272220
,82308740
,82345257
,82381812
,82418368
,82454963
,82491441
,82527995
,82564551
,82601028
,82637506
,82673906
,82710501
,82747017
,82783533
,82819971
,82856371
,82892927
,82929286
,82965805
,83002205
,83038725
,83075162
,83111756
,83148234
,83184671
,83221070
,83257667
,83294105
,83330545
,83366904
,83403424
,83439941
,83476379
,83512819
,83549218
,83585658
,83622097
,83658537
,83695017
,83731417
,83767857
,83804257
,83840823
,83877387
,83913950
,83950550
,83987027
,84023630
,84060149
,84096747
,84133263
,84169857
,84206460
,84243020
,84279578
,84316094
,84352688
,84389208
,84425762
,84462318
,84498873
,84535429
,84571952
,84608513
,84645109
,84681626
,84718181
,84754740
,84791256
,84827891
,84864445
,84901001
,84937442
,84973998
,85010592
,85047187
,85083703
,85120141
,85156696
,85193212
,85229768
,85266127
,85302608
,85339210
,85375729
,85412367
,85448843
,85485479
,85521996
,85558590
,85595106
,85631741
,85668180
,85704698
,85741253
,85777848
,85814403
,85850840
,85887435
,85924031
,85960508
,85996985
,86033385
,86069905
,86106460
,86143016
,86179610
,86216126
,86252603
,86289237
,86325636
,86362152
,86398551
,86435108
,86471663
,86508141
,86544657
,86581096
,86617613
,86654091
,86690531
,86726850
,86763370
,86799812
,86836414
,86872932
,86909530
,86946085
,86982681
,87019198
,87055753
,87092309
,87128904
,87165343
,87201861
,87238495
,87275011
,87311605
,87348083
,87384678
,87421194
,87457710
,87494148
,87530548
,87567068
,87603662
,87640179
,87676773
,87713289
,87749806
,87786400
,87822878
,87859315
,87895714
,87932271
,87968906
,88005304
,88041860
,88078259
,88114816
,88151254
,88187694
,88224093
,88260533
,88297053
,88333610
,88370164
,88406720
,88443275
,88479714
,88516308
,88552824
,88589341
,88625779
,88662219
,88698813
,88735329
,88771846
,88808284
,88844684
,88881200
,88917639
,88954078
,88990478
,89026958
,89063513
,89100069
,89136586
,89173024
,89209383
,89245979
,89282378
,89318857
,89355297
,89391737
,89428254
,89464652
,89501131
,89537531
,89573971
,89610370
,89646770
,89683290
,89719730
,89756210
,89792614
,89829214
,89865772
,89902291
,89938885
,89975483
,90011999
,90048594
,90085110
,90121704
,90158184
,90194701
,90231295
,90267811
,90304446
,90340883
,90377478
,90413994
,90450511
,90486949
,90523389
,90559869
,90596463
,90632979
,90669574
,90706090
,90742646
,90779201
,90815678
,90852156
,90888555
,90925072
,90961706
,90998105
,91034621
,91071020
,91107617
,91144055
,91180495
,91216854
,91253294
,91289855
,91326371
,91362965
,91399520
,91436076
,91472514
,91509069
,91545625
,91582141
,91618540
,91654980
,91691614
,91728130
,91764647
,91801045
,91837485
,91874001
,91910400
,91946839
,91983239
,92019759
,92056354
,92092870
,92129386
,92165824
,92202224
,92238780
,92275139
,92311658
,92348058
,92384578
,92421054
,92457453
,92493932
,92530372
,92566812
,92603211
,92639611
,92676051
,92712571
,92748971
,92785453
,92821969
,92858603
,92895118
,92931714
,92968112
,93004707
,93041223
,93077779
,93114138
,93150618
,93187212
,93223728
,93260245
,93296683
,93333083
,93369599
,93405998
,93442437
,93478917
,93515357
,93551952
,93588507
,93624984
,93661462
,93697902
,93734418
,93770817
,93807256
,93843656
,93880176
,93916652
,93953051
,93989530
,94025970
,94062410
,94098809
,94135209
,94171689
,94208169
,94244569
,94281048
,94317642
,94354120
,94390636
,94427035
,94463592
,94500030
,94536430
,94572829
,94609349
,94645787
,94682305
,94718664
,94755143
,94791583
,94828062
,94864502
,94900942
,94937342
,94973782
,95010183
,95046739
,95083138
,95119577
,95155977
,95192457
,95228896
,95265336
,95301736
,95338176
,95374616
,95411056
,95447576
,95483896
,95520416
,95556816
,95593257
,95629777
,95666178
,95702538
,95739020
,95775581
,95812017
,95848419
,95884817
,95921261
,95957861
,95994263
,96030788
,96067193
,96103837
,96140355
,96176836
,96213242
,96249725
,96286330
,96322849
,96359415
,96395979
,96432501
,96469101
,96505578
,96542017
,96578461
,96614985
,96651510
,96688112
,96724595
,96761200
,96797722
,96834322
,96870880
,96907323
,96943967
,96980448
,97017050
,97053569
,97090171
,97126771
,97163328
,97199845
,97236439
,97272916
,97309318
,97345922
,97382328
,97418931
,97455372
,97491938
,97528540
,97565143
,97601662
,97638139
,97674664
,97711308
,97747871
,97784391
,97820909
,97857511
,97894069
,97930666
,97967183
,98003777
,98040263
,98076866
,98113429
,98149990
,98186506
,98223109
,98259669
,98296227
,98332743
,98369337
,98405941
,98442421
,98479018
,98515573
,98552168
,98588688
,98625243
,98661759
,98698393
,98734909
,98771307
,98807709
,98844313
,98880758
,98917363
,98953804
,98990329
,99026931
,99063534
,99100092
,99136530
,99173096
,99209699
,99246301
,99282822
,99319339
,99355941
,99392460
,99429098
,99465574
,99502168
,99538693
,99575298
,99611820
,99648381
,99684897
,99721541
,99758060
,99794618
,99831134
,99867768
,99904332
,99940851
,99977448
,100014005
,100050559
,100087079
,100123634
,100160190
,100196784
,100233300
,100269702
,100306268
,100342829
,100379432
,100415951
,100452591
,100489152
,100525668
,100562187
,100598782
,100635341
,100671943
,100708460
,100745019
,100781573
,100818171
,100854726
,100891321
,100927798
,100964432
,101000833
,101037435
,101073954
,101110551
,101147067
,101183663
,101220181
,101256815
,101293331
,101329925
,101366403
,101402922
,101439477
,101476033
,101512588
,101549104
,101585660
,101622255
,101658692
,101695210
,101731569
,101768086
,101804450
,101841013
,101877538
,101914143
,101950543
,101987109
,102023670
,102060314
,102096833
,102133271
,102169837
,102206439
,102243042
,102279561
,102316121
,102352682
,102389200
,102425798
,102462353
,102498868
,102535434
,102571998
,102608561
,102645161
,102681638
,102718241
,102754760
,102791358
,102827874
,102864468
,102901071
,102937631
,102974189
,103010705
,103047299
,103083819
,103120373
,103156929
,103193484
,103230040
,103266443
,103303048
,103339570
,103376172
,103412691
,103449291
,103485891
,103522409
,103558927
,103595561
,103632121
,103668723
,103705199
,103741758
,103778313
,103814951
,103851467
,103888061
,103924577
,103961172
,103997572
,104034174
,104070693
,104107331
,104143807
,104180443
,104216960
,104253554
,104290070
,104326705
,104363144
,104399662
,104436217
,104472812
,104509367
,104545804
,104582399
,104618995
,104655472
,104691949
,104728349
,104764752
,104801396
,104837879
,104874481
,104911039
,104947641
,104984241
,105020757
,105057315
,105093870
,105130471
,105167032
,105203548
,105240067
,105276662
,105313260
,105349776
,105386370
,105422925
,105459481
,105495922
,105532524
,105569042
,105605640
,105642195
,105678791
,105715308
,105751863
,105788419
,105825014
,105861453
,105897971
,105934605
,105971121
,106007715
,106044193
,106080788
,106117304
,106153820
,106190258
,106226658
,106263261
,106299782
,106336379
,106372895
,106409490
,106446049
,106482525
,106519120
,106555714
,106592270
,106628711
,106665266
,106701860
,106738455
,106774971
,106811449
,106848004
,106884441
,106921037
,106957436
,106993956
,107030513
,107067067
,107103623
,107140178
,107176617
,107213211
,107249727
,107286244
,107322682
,107359122
,107395716
,107432232
,107468749
,107505187
,107541587
,107578103
,107614542
,107650981
,107687381
,107723861
,107760258
,107796702
,107833226
,107869751
,107906395
,107942797
,107979402
,108015924
,108052526
,108089045
,108125564
,108162130
,108198650
,108235294
,108271813
,108308412
,108345014
,108381490
,108418049
,108454604
,108491081
,108527647
,108564250
,108600852
,108637373
,108673890
,108710492
,108747011
,108783649
,108820125
,108856681
,108893284
,108929843
,108966401
,109002956
,109039552
,109076070
,109112625
,109149220
,109185775
,109222212
,109258695
,109295300
,109331863
,109368424
,109404942
,109441584
,109478104
,109514741
,109551217
,109587852
,109624375
,109660975
,109697491
,109734049
,109770604
,109807163
,109843679
,109880273
,109916868
,109953423
,109989865
,110026467
,110062984
,110099543
,110136097
,110172695
,110209250
,110245845
,110282322
,110318956
,110355435
,110391952
,110428507
,110465063
,110501658
,110538136
,110574690
,110611246
,110647723
,110684201
,110720601
,110757045
,110793650
,110830172
,110866772
,110903330
,110939932
,110976453
,111013050
,111049566
,111086161
,111122684
,111159284
,111195841
,111232358
,111268952
,111305472
,111342027
,111378621
,111415216
,111451732
,111488215
,111524815
,111561332
,111597852
,111634446
,111671043
,111707600
,111744154
,111780710
,111817265
,111853785
,111890261
,111926896
,111963372
,112000006
,112036445
,112073039
,112109555
,112146072
,112182510
,112218910
,112255513
,112292073
,112328631
,112365147
,112401741
,112438261
,112474815
,112511371
,112547926
,112584482
,112621002
,112657557
,112694073
,112730707
,112767223
,112803700
,112840295
,112876733
,112913249
,112949648
,112986169
,113022725
,113059319
,113095914
,113132430
,113168868
,113205423
,113241939
,113278495
,113314854
,113351334
,113387928
,113424444
,113461000
,113497399
,113533878
,113570315
,113606714
,113643233
,113679633
,113716152
,113752558
,113789161
,113825724
,113862324
,113898841
,113935445
,113971964
,114008561
,114045118
,114081672
,114118236
,114154756
,114191393
,114227869
,114264504
,114301022
,114337539
,114374134
,114410728
,114447244
,114483767
,114520328
,114556844
,114593363
,114629958
,114666556
,114703072
,114739666
,114776221
,114812777
,114849257
,114885812
,114922407
,114958884
,114995518
,115031917
,115068551
,115105067
,115141584
,115177982
,115214382
,115251026
,115287545
,115324103
,115360659
,115397253
,115433772
,115470327
,115506883
,115543438
,115579954
,115616474
,115653068
,115689585
,115726179
,115762695
,115799212
,115835806
,115872284
,115908721
,115945120
,115981681
,116018236
,116054830
,116091425
,116127941
,116164419
,116200974
,116237411
,116274007
,116310406
,116346845
,116383440
,116419956
,116456512
,116492871
,116529389
,116565867
,116602266
,116638705
,116675105
,116711586
,116748189
,116784708
,116821306
,116857822
,116894416
,116930935
,116967530
,117004046
,117040680
,117077117
,117113677
,117150231
,117186787
,117223342
,117259898
,117296375
,117333009
,117369447
,117405884
,117442363
,117478883
,117515399
,117552034
,117588588
,117625144
,117661582
,117698176
,117734654
,117771170
,117807569
,117844048
,117880603
,117917119
,117953675
,117990034
,118026552
,118063070
,118099429
,118135908
,118172348
,118208829
,118245346
,118281940
,118318456
,118355091
,118391528
,118428123
,118464639
,118501156
,118537594
,118574034
,118610549
,118647145
,118683622
,118720099
,118756499
,118793055
,118829414
,118865933
,118902333
,118938773
,118975250
,119011884
,119048283
,119084799
,119121198
,119157795
,119194233
,119230673
,119267032
,119303472
,119340029
,119376507
,119412947
,119449266
,119485786
,119522225
,119558625
,119595145
,119631545
,119667985
,119704464
,119740786
,119777269
,119813793
,119850359
,119886958
,119923403
,119960008
,119996569
,120033171
,120069647
,120106131
,120142736
,120179258
,120215858
,120252416
,120289018
,120325539
,120362136
,120398652
,120435247
,120471648
,120508253
,120544775
,120581378
,120617937
,120654537
,120691098
,120727655
,120764173
,120800728
,120837328
,120873928
,120910445
,120946965
,120983559
,121020156
,121056713
,121093267
,121129823
,121166378
,121202776
,121239342
,121275906
,121312469
,121349069
,121385546
,121422149
,121458668
,121495266
,121531782
,121568376
,121604979
,121641539
,121678097
,121714613
,121751207
,121787727
,121824281
,121860837
,121897392
,121933948
,121970471
,122007032
,122043628
,122080145
,122116700
,122153259
,122189775
,122226410
,122262964
,122299520
,122335961
,122372517
,122409111
,122445706
,122482222
,122518660
,122555215
,122591731
,122628287
,122664646
,122701126
,122737651
,122774254
,122810778
,122847378
,122883855
,122920458
,122957017
,122993575
,123030130
,123066685
,123103329
,123139848
,123176406
,123212922
,123249556
,123286036
,123322630
,123359146
,123395741
,123432257
,123468821
,123505341
,123541978
,123578454
,123615089
,123651607
,123688124
,123724719
,123761313
,123797829
,123834310
,123870826
,123907420
,123944015
,123980570
,124016969
,124053603
,124090040
,124126636
,124163035
,124199477
,124236079
,124272597
,124309195
,124345750
,124382346
,124418863
,124455418
,124491974
,124528569
,124565008
,124601526
,124638160
,124674676
,124711270
,124747748
,124784343
,124820859
,124857375
,124893813
,124930213
,124966733
,125003327
,125039844
,125076438
,125112954
,125149471
,125186065
,125222543
,125258980
,125295379
,125331936
,125368571
,125404969
,125441525
,125477924
,125514481
,125550919
,125587359
,125623758
,125660198
,125696598
,125733123
,125769767
,125806330
,125842850
,125879368
,125915970
,125952528
,125989125
,126025642
,126062198
,126098801
,126135320
,126171918
,126208434
,126245028
,126281547
,126318142
,126354658
,126391292
,126427729
,126464373
,126500853
,126537450
,126574005
,126610600
,126647120
,126683675
,126720191
,126756825
,126793341
,126829821
,126866337
,126902972
,126939526
,126976082
,127012520
,127049114
,127085592
,127122108
,127158507
,127194990
,127231590
,127268148
,127304667
,127341261
,127377859
,127414375
,127450970
,127487486
,127524080
,127560560
,127597077
,127633671
,127670187
,127706822
,127743259
,127779854
,127816370
,127852887
,127889325
,127925765
,127962245
,127998839
,128035355
,128071950
,128108466
,128145022
,128181577
,128218054
,128254532
,128290931
,128327448
,128364082
,128400481
,128436997
,128473396
,128509993
,128546431
,128582871
,128619230
,128655670
,128692192
,128728794
,128765311
,128801870
,128838424
,128875022
,128911577
,128948172
,128984649
,129021283
,129057762
,129094279
,129130834
,129167390
,129203985
,129240463
,129277017
,129313573
,129350050
,129386528
,129422928
,129459447
,129496002
,129532558
,129569113
,129605629
,129642185
,129678780
,129715217
,129751735
,129788094
,129824651
,129861245
,129897723
,129934160
,129970559
,130007156
,130043594
,130080034
,130116393
,130152913
,130189394
,130225910
,130262544
,130299059
,130335655
,130372053
,130408648
,130445164
,130481720
,130518079
,130554559
,130591153
,130627669
,130664186
,130700624
,130737024
,130773540
,130809939
,130846378
,130882858
,130919298
,130955893
,130992448
,131028925
,131065403
,131101843
,131138359
,131174758
,131211197
,131247597
,131284117
,131320593
,131356992
,131393471
,131429911
,131466351
,131502750
,131539150
,131575630
,131612110
,131648510
,131684913
,131721438
,131758040
,131794643
,131831201
,131867722
,131904322
,131940880
,131977399
,132013993
,132050511
,132087113
,132123632
,132160270
,132196746
,132233382
,132269899
,132306493
,132343009
,132379644
,132416042
,132452686
,132489205
,132525763
,132562279
,132598913
,132635393
,132671987
,132708503
,132745098
,132781614
,132818134
,132854689
,132891245
,132927839
,132964355
,133000832
,133037466
,133073865
,133110381
,133146780
,133183383
,133219944
,133256460
,133292979
,133329574
,133366172
,133402688
,133439282
,133475837
,133512393
,133548873
,133585428
,133622023
,133658500
,133695134
,133731533
,133768167
,133804683
,133841200
,133877598
,133914039
,133950557
,133987191
,134023707
,134060301
,134096779
,134133374
,134169890
,134206406
,134242844
,134279244
,134315800
,134352395
,134388832
,134425350
,134461709
,134498305
,134534704
,134571183
,134607623
,134644063
,134680546
,134717107
,134753664
,134790182
,134826737
,134863335
,134899851
,134936485
,134973000
,135009596
,135046075
,135082632
,135119186
,135155742
,135192297
,135228736
,135265330
,135301846
,135338363
,135374801
,135411241
,135447799
,135484354
,135520909
,135557464
,135593942
,135630537
,135667092
,135703569
,135740047
,135776487
,135813002
,135849558
,135886075
,135922513
,135958872
,135995468
,136031867
,136068346
,136104786
,136141226
,136177706
,136214222
,136250857
,136287411
,136323967
,136360405
,136396999
,136433477
,136469993
,136506392
,136542871
,136579426
,136615942
,136652498
,136688857
,136725375
,136761893
,136798252
,136834731
,136871171
,136907611
,136944205
,136980761
,137017238
,137053676
,137090076
,137126632
,137163031
,137199470
,137235870
,137272350
,137308906
,137345305
,137381744
,137418184
,137454664
,137491023
,137527543
,137563863
,137600383
,137636783
,137673348
,137709948
,137746464
,137783022
,137819577
,137856136
,137892652
,137929246
,137965841
,138002396
,138038877
,138075393
,138111987
,138148542
,138185098
,138221536
,138258091
,138294647
,138331163
,138367562
,138404082
,138440599
,138477154
,138513710
,138550305
,138586783
,138623337
,138659893
,138696370
,138732848
,138769248
,138805843
,138842359
,138878875
,138915313
,138951713
,138988269
,139024628
,139061147
,139097547
,139134067
,139170547
,139207023
,139243618
,139280212
,139316768
,139353205
,139389840
,139426238
,139462794
,139499193
,139535711
,139572266
,139608703
,139645299
,139681698
,139718216
,139754693
,139791093
,139827492
,139864012
,139900412
,139937006
,139973522
,140010039
,140046477
,140082877
,140119393
,140155792
,140192231
,140228711
,140265151
,140301667
,140338106
,140374545
,140410945
,140447425
,140483784
,140520304
,140556704
,140593144
,140629544
,140666145
,140702700
,140739216
,140775850
,140812366
,140848843
,140885438
,140921876
,140958392
,140994791
,141031309
,141067903
,141104381
,141140897
,141177296
,141213853
,141250291
,141286691
,141323090
,141359610
,141396010
,141432604
,141469120
,141505676
,141542075
,141578554
,141614991
,141651390
,141687909
,141724309
,141760749
,141797305
,141833704
,141870143
,141906543
,141943023
,141979462
,142015902
,142052302
,142088742
,142125182
,142161779
,142198334
,142234811
,142271289
,142307688
,142344245
,142380683
,142417122
,142453522
,142490042
,142526519
,142562957
,142599397
,142635756
,142672196
,142708675
,142745075
,142781555
,142818035
,142854435
,142890954
,142927392
,142963751
,143000230
,143036670
,143073149
,143109589
,143146029
,143182429
,143218949
,143255349
,143291749
,143328189
,143364669
,143401109
,143437470
,143473950
,143510430
,143546871
,143583272
,143619755
,143656193
,143692598
,143729161
,143765686
,143802289
,143838691
,143875296
,143911818
,143948421
,143984980
,144021458
,144058024
,144094585
,144131229
,144167748
,144204308
,144240908
,144277425
,144313945
,144350539
,144387016
,144423541
,144460185
,144496748
,144533268
,144569786
,144606388
,144642946
,144679543
,144716060
,144752616
,144789219
,144825738
,144862336
,144898852
,144935446
,144971965
,145008560
,145045076
,145081710
,145118147
,145154591
,145191235
,145227757
,145264359
,145300877
,145337478
,145374039
,145410635
,145447152
,145483707
,145520269
,145556869
,145593387
,145629905
,145666539
,145703058
,145739614
,145776208
,145812803
,145849319
,145885761
,145922361
,145958919
,145995438
,146032032
,146068630
,146105146
,146141741
,146178257
,146214851
,146251331
,146287848
,146324442
,146360958
,146397593
,146434030
,146470625
,146507141
,146543658
,146580096
,146616536
,146652939
,146689544
,146726107
,146762668
,146799186
,146835828
,146872348
,146908985
,146945461
,146982096
,147018619
,147055219
,147091735
,147128293
,147164848
,147201407
,147237923
,147274517
,147311112
,147347667
,147384109
,147420711
,147457228
,147493787
,147530341
,147566939
,147603494
,147640089
,147676566
,147713200
,147749679
,147786196
,147822751
,147859307
,147895902
,147932380
,147968934
,148005490
,148041967
,148078445
,148114845
,148151409
,148187967
,148224566
,148261082
,148297676
,148334156
,148370750
,148407267
,148443861
,148480377
,148516937
,148553413
,148590008
,148626602
,148663158
,148699595
,148736230
,148772628
,148809184
,148845583
,148882104
,148918620
,148955254
,148991769
,149028365
,149064763
,149101358
,149137874
,149174430
,149210789
,149247269
,149283863
,149320379
,149356896
,149393334
,149429734
,149466250
,149502649
,149539088
,149575568
,149612008
,149648493
,149685057
,149721618
,149758220
,149794737
,149831380
,149867860
,149904457
,149941012
,149977607
,150014130
,150050691
,150087287
,150123804
,150160359
,150196918
,150233434
,150270069
,150306623
,150343179
,150379661
,150416263
,150452739
,150489298
,150525853
,150562491
,150599007
,150635601
,150672117
,150708712
,150745192
,150781708
,150818303
,150854819
,150891413
,150927852
,150964446
,151001002
,151037479
,151073917
,151110317
,151146961
,151183480
,151220038
,151256554
,151293188
,151329668
,151366262
,151402778
,151439373
,151475889
,151512409
,151548964
,151585520
,151622114
,151658630
,151695107
,151731741
,151768140
,151804656
,151841055
,151877616
,151914132
,151950726
,151987321
,152023876
,152060275
,152096909
,152133346
,152169942
,152206341
,152242780
,152279335
,152315891
,152352407
,152388806
,152425285
,152461722
,152498201
,152534640
,152571040
,152607480
,152644124
,152680643
,152717201
,152753757
,152790351
,152826870
,152863425
,152899981
,152936536
,152973052
,153009572
,153046166
,153082683
,153119277
,153155793
,153192310
,153228904
,153265382
,153301819
,153338218
,153374779
,153411334
,153447928
,153484523
,153521039
,153557517
,153594072
,153630509
,153667105
,153703504
,153739943
,153776538
,153813054
,153849610
,153885969
,153922487
,153958965
,153995364
,154031803
,154068203
,154104723
,154141281
,154177836
,154214391
,154250946
,154287424
,154324019
,154360574
,154397051
,154433529
,154469969
,154506484
,154543040
,154579557
,154615995
,154652354
,154688950
,154725349
,154761828
,154798268
,154834708
,154871185
,154907780
,154944218
,154980734
,155017133
,155053690
,155090168
,155126568
,155162967
,155199407
,155235964
,155272402
,155308802
,155345201
,155381721
,155418160
,155454560
,155491080
,155527400
,155563920
,155600320
,155636845
,155673450
,155709972
,155746533
,155783049
,155819693
,155856212
,155892770
,155929286
,155965920
,156002484
,156039003
,156075600
,156112157
,156148711
,156185231
,156221786
,156258342
,156294936
,156331452
,156367976
,156404576
,156441092
,156477650
,156514205
,156550764
,156587280
,156623874
,156660469
,156697024
,156733505
,156770021
,156806615
,156843170
,156879726
,156916164
,156952719
,156989275
,157025791
,157062190
,157098632
,157135234
,157171753
,157208350
,157244866
,157281462
,157317980
,157354614
,157391130
,157427724
,157464202
,157500721
,157537276
,157573832
,157610387
,157646903
,157683459
,157720054
,157756491
,157793009
,157829368
,157865968
,157902444
,157939039
,157975633
,158012189
,158048626
,158085261
,158121659
,158158215
,158194614
,158231132
,158267687
,158304124
,158340720
,158377119
,158413637
,158450114
,158486514
,158522913
,158559433
,158595795
,158632397
,158668955
,158705552
,158742069
,158778664
,158815222
,158851777
,158888332
,158924887
,158961365
,158997884
,159034479
,159070995
,159107629
,159144066
,159180661
,159217217
,159253734
,159290172
,159326531
,159363131
,159399686
,159436202
,159472836
,159509352
,159545829
,159582424
,159618862
,159655378
,159691777
,159728295
,159764889
,159801367
,159837883
,159874282
,159910839
,159947277
,159983677
,160020076
,160056596
,160093077
,160129593
,160166188
,160202704
,160239298
,160275737
,160312331
,160348887
,160385364
,160421802
,160458241
,160494836
,160531352
,160567869
,160604307
,160640747
,160677263
,160713662
,160750101
,160786541
,160823021
,160859537
,160896092
,160932569
,160969047
,161005446
,161042003
,161078441
,161114880
,161151280
,161187800
,161224277
,161260715
,161297155
,161333514
,161369954
,161406433
,161442833
,161479313
,161515793
,161552193
,161588636
,161625238
,161661756
,161698354
,161734909
,161771505
,161808022
,161844577
,161881133
,161917728
,161954167
,161990685
,162027319
,162063835
,162100429
,162136907
,162173502
,162210018
,162246534
,162282972
,162319372
,162355892
,162392486
,162429003
,162465597
,162502113
,162538630
,162575224
,162611702
,162648139
,162684538
,162721095
,162757730
,162794128
,162830684
,162867083
,162903640
,162940078
,162976518
,163012917
,163049357
,163085877
,163122434
,163158988
,163195544
,163232099
,163268538
,163305132
,163341648
,163378165
,163414603
,163451043
,163487637
,163524153
,163560670
,163597108
,163633508
,163670024
,163706463
,163742902
,163779302
,163815782
,163852337
,163888893
,163925410
,163961848
,163998207
,164034803
,164071202
,164107681
,164144121
,164180561
,164217078
,164253476
,164289955
,164326355
,164362795
,164399194
,164435594
,164472114
,164508554
,164545034
,164581516
,164618032
,164654626
,164691142
,164727737
,164764136
,164800730
,164837246
,164873802
,164910201
,164946641
,164983235
,165019791
,165056268
,165092706
,165129106
,165165662
,165202061
,165238500
,165274900
,165311380
,165347935
,165384531
,165421008
,165457485
,165493885
,165530441
,165566800
,165603319
,165639719
,165676159
,165712676
,165749114
,165785553
,165821953
,165858473
,165894792
,165931272
,165967712
,166004232
,166040632
,166077032
,166113666
,166150103
,166186699
,166223098
,166259616
,166296054
,166332413
,166368892
,166405332
,166441811
,166478248
,166514727
,166551166
,166587566
,166624085
,166660485
,166696925
,166733405
,166769845
,166806206
,166842762
,166879161
,166915640
,166952040
,166988520
,167024879
,167061399
,167097799
,167134239
,167170639
,167207119
,167243559
,167279959
,167316439
,167352839
,167389320
,167425760
,167462161
,167498561
,167535043
,167571527
,167608093
,167644695
,167681298
,167717817
,167754377
,167790938
,167827456
,167864054
,167900609
,167937127
,167973729
,168010287
,168046884
,168083401
,168119996
,168156554
,168193109
,168229664
,168266219
,168302697
,168339300
,168375860
,168412418
,168448934
,168485528
,168522048
,168558602
,168595158
,168631713
,168668269
,168704789
,168741344
,168777860
,168814494
,168851010
,168887487
,168924082
,168960520
,168997036
,169033435
,169069997
,169106599
,169143075
,169179634
,169216189
,169252827
,169289343
,169325937
,169362453
,169399048
,169435528
,169472044
,169508639
,169545155
,169581749
,169618188
,169654782
,169691338
,169727815
,169764253
,169800694
,169837212
,169873767
,169910362
,169946917
,169983354
,170019949
,170056545
,170093022
,170129499
,170165899
,170202455
,170239010
,170275487
,170311965
,170348364
,170384921
,170421359
,170457798
,170494198
,170530718
,170567201
,170603762
,170640278
,170676797
,170713392
,170749990
,170786506
,170823100
,170859655
,170896211
,170932691
,170969246
,171005841
,171042318
,171078952
,171115351
,171151985
,171188501
,171225018
,171261416
,171297857
,171334375
,171371009
,171407525
,171444119
,171480597
,171517192
,171553708
,171590224
,171626662
,171663062
,171699618
,171736213
,171772650
,171809168
,171845527
,171882123
,171918522
,171955001
,171991441
,172027881
,172064322
,172100877
,172137471
,172174066
,172210582
,172247060
,172283615
,172320052
,172356648
,172393047
,172429486
,172466081
,172502597
,172539153
,172575512
,172612030
,172648508
,172684907
,172721346
,172757746
,172794266
,172830860
,172867376
,172903893
,172940331
,172976731
,173013247
,173049686
,173086125
,173122525
,173159005
,173195561
,173231960
,173268399
,173304799
,173341319
,173377678
,173414118
,173450518
,173486998
,173523438
,173559962
,173596562
,173633080
,173669598
,173706232
,173742751
,173779307
,173815901
,173852496
,173889012
,173925532
,173962048
,173998642
,174035158
,174071753
,174108152
,174144746
,174181262
,174217818
,174254217
,174290698
,174327215
,174363809
,174400325
,174436960
,174473397
,174509992
,174546508
,174583025
,174619463
,174655903
,174692418
,174729014
,174765491
,174801968
,174838368
,174874924
,174911283
,174947802
,174984202
,175020642
,175057161
,175093678
,175130273
,175166867
,175203383
,175239860
,175276415
,175312893
,175349409
,175385848
,175422287
,175458921
,175495358
,175531954
,175568353
,175604871
,175641309
,175677668
,175714147
,175750587
,175787027
,175823661
,175860177
,175896694
,175933092
,175969532
,176006048
,176042447
,176078886
,176115286
,176151806
,176188322
,176224721
,176261200
,176297600
,176334080
,176370439
,176406959
,176443359
,176479799
,176516199
,176552800
,176589276
,176625871
,176662465
,176699021
,176735458
,176772093
,176808491
,176845047
,176881446
,176917964
,176954519
,176990956
,177027552
,177063951
,177100469
,177136946
,177173346
,177209745
,177246265
,177282665
,177319259
,177355775
,177392292
,177428730
,177465130
,177501646
,177538045
,177574484
,177610964
,177647404
,177683920
,177720359
,177756798
,177793198
,177829678
,177866037
,177902557
,177938957
,177975397
,178011797
,178048355
,178084989
,178121427
,178157864
,178194343
,178230900
,178267298
,178303777
,178340177
,178376617
,178413134
,178449612
,178486012
,178522411
,178558851
,178595330
,178631730
,178668210
,178704690
,178741050
,178777529
,178814047
,178850406
,178886885
,178923325
,178959804
,178996244
,179032684
,179069084
,179105524
,179141965
,179178324
,179214844
,179251244
,179287764
,179324084
,179360605
,179397005
,179433526
,179469927
,179506370
,179542975
,179579495
,179616132
,179652608
,179689243
,179725761
,179762278
,179798873
,179835467
,179871983
,179908464
,179944980
,179981574
,180018169
,180054724
,180091123
,180127757
,180164194
,180200790
,180237189
,180273670
,180310225
,180346820
,180383297
,180419931
,180456330
,180492964
,180529480
,180565997
,180602395
,180638875
,180675429
,180711985
,180748462
,180784940
,180821340
,180857856
,180894255
,180930734
,180967134
,181003614
,181040094
,181076688
,181113205
,181149799
,181186315
,181222832
,181259426
,181295904
,181332341
,181368740
,181405297
,181441932
,181478330
,181514886
,181551285
,181587842
,181624280
,181660720
,181697119
,181733559
,181769998
,181806593
,181843109
,181879665
,181916024
,181952542
,181989020
,182025419
,182061858
,182098258
,182134738
,182171254
,182207653
,182244092
,182280572
,182317052
,182353411
,182389851
,182426331
,182462771
,182499171
,182535732
,182572286
,182608842
,182645397
,182681953
,182718430
,182755064
,182791502
,182827939
,182864418
,182900935
,182937530
,182973968
,183010484
,183046883
,183083440
,183119918
,183156318
,183192717
,183229157
,183265636
,183302191
,183338707
,183375263
,183411622
,183448140
,183484658
,183521017
,183557496
,183593936
,183630415
,183666852
,183703251
,183739770
,183776170
,183812650
,183849009
,183885529
,183921929
,183958449
,183994769
,184031365
,184067961
,184104438
,184140915
,184177315
,184213871
,184250230
,184286749
,184323149
,184359589
,184396106
,184432544
,184468983
,184505383
,184541903
,184578222
,184614702
,184651142
,184687662
,184724062
,184760540
,184797018
,184833458
,184869777
,184906297
,184942736
,184979136
,185015656
,185052056
,185088496
,185124936
,185161376
,185197816
,185234216
,185270736
,185307097
,185343577
,185379977
,185416418
,185452819
,185489383
,185525902
,185562457
,185599013
,185635568
,185672084
,185708640
,185745235
,185781672
,185818190
,185854549
,185891106
,185927700
,185964178
,186000615
,186037014
,186073611
,186110049
,186146489
,186182848
,186219368
,186255846
,186292401
,186328838
,186365434
,186401833
,186438351
,186474828
,186511228
,186547627
,186584147
,186620585
,186657063
,186693462
,186729901
,186766301
,186802820
,186839220
,186875740
,186912140
,186948580
,186984981
,187021576
,187058131
,187094608
,187131086
,187167526
,187204042
,187240441
,187276880
,187313280
,187349800
,187386276
,187422675
,187459154
,187495594
,187532034
,187568433
,187604833
,187641313
,187677793
,187714193
,187750711
,187787189
,187823589
,187859988
,187896428
,187932907
,187969307
,188005787
,188042267
,188078627
,188115107
,188151507
,188188027
,188224347
,188260867
,188297228
,188333708
,188370108
,188406589
,188442990
,188479553
,188516148
,188552664
,188589181
,188625619
,188662059
,188698575
,188734974
,188771413
,188807853
,188844333
,188880849
,188917208
,188953727
,188990127
,189026567
,189062966
,189099366
,189135846
,189172326
,189208726
,189245284
,189281722
,189318162
,189354521
,189390961
,189427440
,189463840
,189500320
,189536800
,189573200
,189609640
,189646040
,189682560
,189718960
,189755400
,189791761
,189828241
,189864681
,189901122
,189937523
,189974087
,190010603
,190047002
,190083441
,190119841
,190156361
,190192760
,190229200
,190265600
,190302120
,190338480
,190374920
,190411440
,190447840
,190484280
,190520680
,190557121
,190593641
,190630042
,190666442
,190702884
,190739446
,190775846
,190812286
,190848806
,190885206
,190921607
,190958127
,190994447
,191030928
,191067370
,191103853
,191140293
,191176733
,191213214
,191249615
,191286219
,191322580
,191359062
,191395545
,191432109
,191468675
,191505149
,191541547
,191577987
,191614430
,191650955
,191687353
,191723797
,191760321
,191796846
,191833449
,191869885
,191906329
,191942853
,191979378
,192016022
,192052424
,192089029
,192125551
,192162153
,192198672
,192235187
,192271589
,192308193
,192344638
,192381243
,192417684
,192454209
,192490811
,192527414
,192563972
,192600410
,192636976
,192673579
,192710181
,192746702
,192783219
,192819821
,192856340
,192892978
,192929454
,192966048
,193002449
,193038893
,193075415
,193111981
,193148621
,193185027
,193221630
,193258193
,193294793
,193331310
,193367753
,193404358
,193440921
,193477482
,193514000
,193550642
,193587162
,193623799
,193660275
,193696910
,193733311
,193769877
,193806438
,193843041
,193879560
,193916200
,193952761
,193989277
,194025796
,194062391
,194098950
,194135552
,194172069
,194208628
,194245182
,194281780
,194318335
,194354930
,194391407
,194428041
,194464518
,194500840
,194537323
,194573847
,194610413
,194647012
,194683457
,194720062
,194756623
,194793225
,194829701
,194866185
,194902790
,194939312
,194975912
,195012470
,195049072
,195085593
,195122190
,195158706
,195195301
,195231702
,195268307
,195304829
,195341432
,195377991
,195414591
,195451152
,195487709
,195524227
,195560782
,195597382
,195633982
,195670499
,195707019
,195743613
,195780210
,195816767
,195853321
,195889877
,195926432
,195962830
,195999396
,196035960
,196072523
,196109123
,196145600
,196182203
,196218722
,196255320
,196291836
,196328430
,196365033
,196401593
,196438151
,196474667
,196511261
,196547781
,196584335
,196620891
,196657446
,196694002
,196730525
,196767086
,196803682
,196840199
,196876754
,196913313
,196949829
,196986464
,197023018
,197059574
,197096015
,197132571
,197169165
,197205760
,197242276
,197278714
,197315269
,197351785
,197388341
,197424700
,197461218
,197497620
,197534105
,197570547
,197607152
,197643712
,197680237
,197716842
,197753364
,197789925
,197826520
,197862926
,197899529
,197936092
,197972692
,198009209
,198045813
,198082332
,198118929
,198155486
,198192040
,198228443
,198265087
,198301570
,198338172
,198374730
,198411332
,198447932
,198484448
,198521006
,198557561
,198594162
,198630723
,198667239
,198703758
,198740353
,198776951
,198813467
,198850061
,198886616
,198923172
,198959571
,198996096
,199032740
,199069262
,199105823
,199142341
,199178943
,199215462
,199252059
,199288575
,199325130
,199361774
,199398293
,199434851
,199471407
,199508001
,199544520
,199581075
,199617631
,199654186
,199690702
,199727305
,199763826
,199800423
,199836939
,199873534
,199910093
,199946569
,199983164
,200019758
,200056314
,200092755
,200129310
,200165904
,200202499
,200239015
,200275493
,200312048
,200348485
,200385081
,200421480
,200457880
,200494405
,200531049
,200567612
,200604132
,200640650
,200677252
,200713810
,200750407
,200786924
,200823480
,200860083
,200896602
,200933200
,200969716
,201006310
,201042829
,201079424
,201115940
,201152574
,201189011
,201225655
,201262135
,201298732
,201335287
,201371882
,201408402
,201444957
,201481473
,201518107
,201554623
,201591103
,201627619
,201664254
,201700808
,201737364
,201773802
,201810396
,201846874
,201883390
,201919789
,201956272
,201992872
,202029430
,202065949
,202102543
,202139141
,202175657
,202212252
,202248768
,202285362
,202321842
,202358359
,202394953
,202431469
,202468104
,202504541
,202541136
,202577652
,202614169
,202650607
,202687047
,202723527
,202760121
,202796637
,202833232
,202869748
,202906304
,202942859
,202979336
,203015814
,203052213
,203088730
,203125364
,203161763
,203198279
,203234678
,203271275
,203307713
,203344153
,203380512
,203416952
,203453469
,203489871
,203526396
,203562801
,203599445
,203635925
,203672450
,203709094
,203745616
,203782177
,203818692
,203855258
,203891822
,203928344
,203964944
,204001421
,204038065
,204074584
,204111142
,204147698
,204184292
,204220736
,204257341
,204293863
,204330463
,204367021
,204403623
,204440144
,204476741
,204513257
,204549852
,204586375
,204622975
,204659532
,204696049
,204732643
,204769163
,204805718
,204842312
,204878907
,204915423
,204951784
,204988350
,205024952
,205061555
,205098074
,205134634
,205171195
,205207713
,205244311
,205280866
,205317384
,205353986
,205390544
,205427141
,205463658
,205500253
,205536811
,205573366
,205609921
,205646476
,205682954
,205719557
,205756117
,205792675
,205829191
,205865785
,205902305
,205938859
,205975415
,206011970
,206048526
,206085046
,206121601
,206158117
,206194751
,206231267
,206267744
,206304339
,206340777
,206377293
,206413692
,206450134
,206486659
,206523261
,206559864
,206596422
,206632943
,206669543
,206706101
,206742620
,206779214
,206815732
,206852334
,206888853
,206925491
,206961967
,206998603
,207035120
,207071714
,207108230
,207144865
,207181263
,207217907
,207254426
,207290984
,207327500
,207364134
,207400614
,207437208
,207473724
,207510319
,207546835
,207583355
,207619910
,207656466
,207693060
,207729576
,207766053
,207802687
,207839086
,207875602
,207912001
,207948604
,207985165
,208021681
,208058200
,208094795
,208131393
,208167909
,208204503
,208241058
,208277614
,208314094
,208350649
,208387244
,208423721
,208460355
,208496754
,208533388
,208569904
,208606421
,208642819
,208679260
,208715778
,208752412
,208788928
,208825522
,208862000
,208898595
,208935111
,208971627
,209008065
,209044465
,209081021
,209117616
,209154053
,209190571
,209226930
,209263526
,209299925
,209336404
,209372844
,209409284
,209445645
,209482211
,209518772
,209555416
,209591935
,209628495
,209665095
,209701612
,209738132
,209774726
,209811286
,209847847
,209884365
,209920963
,209957518
,209994155
,210030631
,210067266
,210103742
,210140376
,210176776
,210213379
,210249898
,210286496
,210323012
,210359606
,210396125
,210432720
,210469236
,210505870
,210542307
,210578867
,210615421
,210651977
,210688532
,210725088
,210761565
,210798199
,210834637
,210871074
,210907553
,210944076
,210980676
,211017194
,211053712
,211090346
,211126865
,211163421
,211200015
,211236610
,211273126
,211309646
,211346162
,211382756
,211419272
,211455867
,211492266
,211528860
,211565376
,211601932
,211638331
,211674812
,211711329
,211747923
,211784439
,211821074
,211857511
,211894106
,211930622
,211967139
,212003577
,212040017
,212076532
,212113128
,212149605
,212186082
,212222482
,212259038
,212295397
,212331916
,212368316
,212404756
,212441280
,212477880
,212514396
,212550954
,212587509
,212624068
,212660584
,212697178
,212733773
,212770328
,212806809
,212843325
,212879919
,212916474
,212953030
,212989468
,213026023
,213062579
,213099095
,213135494
,213172014
,213208531
,213245086
,213281642
,213318237
,213354715
,213391269
,213427825
,213464302
,213500780
,213537180
,213573775
,213610291
,213646807
,213683245
,213719645
,213756201
,213792560
,213829079
,213865479
,213901999
,213938479
,213974955
,214011550
,214048144
,214084700
,214121137
,214157772
,214194170
,214230726
,214267125
,214303643
,214340198
,214376635
,214413231
,214449630
,214486148
,214522625
,214559025
,214595424
,214631944
,214668344
,214704938
,214741454
,214777971
,214814409
,214850809
,214887325
,214923724
,214960163
,214996643
,215033083
,215069599
,215106038
,215142477
,215178877
,215215357
,215251716
,215288236
,215324636
,215361076
,215397476
,215433994
,215470358
,215506921
,215543487
,215580051
,215616492
,215653058
,215689578
,215726222
,215762741
,215799220
,215835745
,215872347
,215908950
,215945508
,215982029
,216018629
,216055187
,216091706
,216128300
,216164817
,216201342
,216237945
,216274469
,216311069
,216347546
,216384149
,216420708
,216457266
,216493821
,216530376
,216567020
,216603539
,216640097
,216676613
,216713247
,216749727
,216786321
,216822837
,216859432
,216895948
,216932351
,216968995
,217005478
,217042080
,217078638
,217115240
,217151840
,217188356
,217224914
,217261469
,217298070
,217334631
,217371147
,217407666
,217444261
,217480859
,217517375
,217553969
,217590524
,217627080
,217663521
,217700123
,217736641
,217773239
,217809794
,217846390
,217882907
,217919462
,217956018
,217992613
,218029052
,218065570
,218102204
,218138720
,218175314
,218211792
,218248387
,218284903
,218321419
,218357857
,218394257
,218430701
,218467345
,218503826
,218540428
,218576947
,218613549
,218650149
,218686706
,218723223
,218759817
,218796379
,218832940
,218869497
,218906015
,218942570
,218979168
,219015684
,219052318
,219088833
,219125429
,219161871
,219198432
,219234950
,219271548
,219308103
,219344740
,219381216
,219417851
,219454327
,219490961
,219527400
,219563958
,219600513
,219637068
,219673623
,219710101
,219746696
,219783251
,219819728
,219856206
,219892646
,219929210
,219965690
,220002287
,220038842
,220075437
,220111957
,220148512
,220185028
,220221662
,220258178
,220294658
,220331174
,220367809
,220404363
,220440919
,220477357
,220513951
,220550429
,220586945
,220623344
,220659905
,220696421
,220733015
,220769531
,220806126
,220842525
,220879119
,220915635
,220952191
,220988590
,221025030
,221061624
,221098180
,221134657
,221171095
,221207495
,221244051
,221280450
,221316889
,221353289
,221389769
,221426212
,221462817
,221499380
,221535941
,221572459
,221609101
,221645621
,221682258
,221718734
,221755369
,221791892
,221828492
,221865008
,221901566
,221938121
,221974680
,222011196
,222047790
,222084385
,222120940
,222157382
,222193984
,222230501
,222267060
,222303614
,222340212
,222376767
,222413362
,222449839
,222486473
,222522952
,222559469
,222596024
,222632580
,222669175
,222705653
,222742207
,222778763
,222815240
,222851718
,222888118
,222924682
,222961240
,222997839
,223034355
,223070949
,223107429
,223144023
,223180540
,223217134
,223253650
,223290210
,223326686
,223363281
,223399875
,223436431
,223472868
,223509503
,223545901
,223582457
,223618856
,223655377
,223691893
,223728527
,223765042
,223801638
,223838036
,223874631
,223911147
,223947703
,223984062
,224020542
,224057136
,224093652
,224130169
,224166607
,224203007
,224239523
,224275922
,224312361
,224348841
,224385281
,224421884
,224458444
,224495002
,224531518
,224568112
,224604632
,224641186
,224677742
,224714297
,224750853
,224787373
,224823928
,224860444
,224897078
,224933594
,224970071
,225006666
,225043104
,225079620
,225116019
,225152540
,225189096
,225225690
,225262285
,225298801
,225335239
,225371794
,225408310
,225444866
,225481225
,225517705
,225554299
,225590815
,225627371
,225663770
,225700249
,225736686
,225773085
,225809604
,225846004
,225882485
,225919003
,225955558
,225992153
,226028708
,226065145
,226101740
,226138336
,226174813
,226211290
,226247690
,226284246
,226320801
,226357278
,226393756
,226430155
,226466712
,226503150
,226539589
,226575989
,226612509
,226648946
,226685501
,226721979
,226758495
,226794934
,226831451
,226867929
,226904369
,226940688
,226977208
,227013726
,227050164
,227086523
,227123002
,227159442
,227195921
,227232361
,227268801
,227305201
,227341721
,227378121
,227414566
,227451171
,227487732
,227524334
,227560810
,227597414
,227633972
,227670571
,227707087
,227743681
,227780244
,227816765
,227853362
,227889878
,227926473
,227963032
,227999508
,228036103
,228072697
,228109253
,228145736
,228182297
,228218854
,228255372
,228291927
,228328525
,228365041
,228401675
,228438190
,228474786
,228511265
,228547822
,228584376
,228620932
,228657487
,228693926
,228730520
,228767036
,228803553
,228839991
,228876392
,228912995
,228949514
,228986112
,229022628
,229059222
,229095741
,229132336
,229168852
,229205486
,229241923
,229278483
,229315037
,229351593
,229388148
,229424704
,229461181
,229497815
,229534253
,229570690
,229607169
,229643689
,229680205
,229716840
,229753394
,229789950
,229826388
,229862982
,229899460
,229935976
,229972375
,230008854
,230045409
,230081925
,230118481
,230154840
,230191358
,230227876
,230264235
,230300714
,230337154
,230373555
,230410158
,230446717
,230483275
,230519830
,230556426
,230592944
,230629499
,230666094
,230702649
,230739086
,230775646
,230812240
,230848756
,230885351
,230921867
,230958423
,230994978
,231031455
,231067933
,231104332
,231140891
,231177408
,231214003
,231250597
,231287113
,231323590
,231360145
,231396623
,231433139
,231469578
,231506017
,231542651
,231579088
,231615684
,231652083
,231688601
,231725039
,231761398
,231797877
,231834317
,231870837
,231907354
,231943909
,231980465
,232017060
,232053538
,232090092
,232126648
,232163125
,232199603
,232236003
,232272598
,232309114
,232345630
,232382068
,232418468
,232455024
,232491383
,232527902
,232564302
,232600822
,232637259
,232673853
,232710331
,232746768
,232783167
,232819764
,232856202
,232892642
,232929001
,232965521
,233002038
,233038476
,233074916
,233111315
,233147755
,233184194
,233220634
,233257114
,233293514
,233329954
,233366357
,233402959
,233439517
,233476114
,233512631
,233549226
,233585784
,233622339
,233658894
,233695449
,233731927
,233768446
,233805041
,233841557
,233878191
,233914628
,233951223
,233987779
,234024296
,234060734
,234097093
,234133693
,234170248
,234206764
,234243398
,234279914
,234316391
,234352986
,234389424
,234425940
,234462339
,234498857
,234535451
,234571929
,234608445
,234644844
,234681401
,234717839
,234754239
,234790638
,234827158
,234863639
,234900155
,234936750
,234973266
,235009860
,235046299
,235082893
,235119449
,235155926
,235192364
,235228803
,235265398
,235301914
,235338431
,235374869
,235411309
,235447825
,235484224
,235520663
,235557103
,235593583
,235630099
,235666654
,235703131
,235739609
,235776008
,235812565
,235849003
,235885442
,235921842
,235958362
,235994839
,236031277
,236067717
,236104076
,236140516
,236176995
,236213395
,236249875
,236286355
,236322755
,236359237
,236395792
,236432387
,236468864
,236505498
,236541897
,236578531
,236615047
,236651564
,236687962
,236724442
,236760996
,236797552
,236834029
,236870507
,236906907
,236943423
,236979822
,237016301
,237052701
,237089181
,237125697
,237162292
,237198729
,237235247
,237271606
,237308202
,237344601
,237381080
,237417520
,237453960
,237490437
,237526875
,237563315
,237599674
,237636194
,237672593
,237708993
,237745473
,237781953
,237818353
,237854793
,237891388
,237927904
,237964460
,238000819
,238037337
,238073815
,238110214
,238146653
,238183053
,238219533
,238256049
,238292448
,238328887
,238365367
,238401847
,238438206
,238474646
,238511126
,238547566
,238583966
,238620563
,238656962
,238693401
,238729801
,238766321
,238802680
,238839120
,238875520
,238912000
,238948440
,238984880
,239021280
,239057760
,239094240
,239130640
,239167121
,239203561
,239239922
,239276362
,239312804
,239349404
,239385806
,239422292
,239458736
,239495380
,239531860
,239568385
,239604988
,239641512
,239678112
,239714627
,239751152
,239787757
,239824279
,239860840
,239897356
,239934000
,239970519
,240007077
,240043593
,240080227
,240116630
,240153235
,240189798
,240226359
,240262877
,240299519
,240336039
,240372676
,240409152
,240445787
,240482310
,240518910
,240555426
,240591984
,240628539
,240665098
,240701614
,240738208
,240774803
,240811358
,240847719
,240884244
,240920847
,240957490
,240993970
,241030528
,241067130
,241103648
,241140246
,241176801
,241213319
,241249921
,241286440
,241323037
,241359553
,241396149
,241432667
,241469301
,241505817
,241542411
,241578889
,241615453
,241652011
,241688610
,241725126
,241761720
,241798200
,241834794
,241871311
,241907905
,241944421
,241980981
,242017457
,242054052
,242090646
,242127202
,242163639
,242200274
,242236672
,242273228
,242309627
,242346028
,242382594
,242419196
,242455799
,242492318
,242528878
,242565439
,242601957
,242638555
,242675110
,242711628
,242748230
,242784788
,242821385
,242857902
,242894497
,242931055
,242967610
,243004165
,243040720
,243077198
,243113801
,243150361
,243186919
,243223435
,243260029
,243296549
,243333103
,243369659
,243406214
,243442770
,243479290
,243515845
,243552361
,243588995
,243625511
,243661988
,243698583
,243735021
,243771537
,243807936
,243844498
,243881100
,243917576
,243954135
,243990690
,244027328
,244063844
,244100438
,244136954
,244173549
,244210029
,244246545
,244283140
,244319656
,244356250
,244392689
,244429283
,244465839
,244502316
,244538754
,244575195
,244611713
,244648268
,244684863
,244721418
,244757855
,244794450
,244831046
,244867523
,244904000
,244940400
,244976956
,245013511
,245049988
,245086466
,245122865
,245159422
,245195860
,245232299
,245268699
,245305219
,245341541
,245378105
,245414707
,245451310
,245487870
,245524389
,245560991
,245597508
,245634067
,245670621
,245707180
,245743782
,245780300
,245816898
,245853453
,245890049
,245926566
,245963121
,245999677
,246036272
,246072670
,246109314
,246145833
,246182391
,246218947
,246255541
,246292060
,246328615
,246365171
,246401726
,246438242
,246474762
,246511356
,246547873
,246584467
,246620983
,246657500
,246694094
,246730572
,246767009
,246803408
,246840011
,246876572
,246913129
,246949647
,246986202
,247022800
,247059316
,247095950
,247132465
,247169061
,247205540
,247242097
,247278651
,247315207
,247351762
,247388201
,247424795
,247461311
,247497828
,247534266
,247570706
,247607264
,247643819
,247680374
,247716929
,247753407
,247790002
,247826557
,247863034
,247899512
,247935952
,247972467
,248009023
,248045540
,248081978
,248118337
,248154933
,248191332
,248227811
,248264251
,248300691
,248337174
,248373774
,248410292
,248446810
,248483444
,248519963
,248556519
,248593113
,248629708
,248666224
,248702744
,248739260
,248775854
,248812370
,248848965
,248885364
,248921958
,248958474
,248995030
,249031429
,249067910
,249104427
,249141021
,249177537
,249214172
,249250609
,249287204
,249323720
,249360237
,249396675
,249433115
,249469630
,249506226
,249542703
,249579180
,249615580
,249652136
,249688495
,249725014
,249761414
,249797854
,249834373
,249870890
,249907485
,249944079
,249980595
,250017072
,250053627
,250090105
,250126621
,250163060
,250199499
,250236133
,250272570
,250309166
,250345565
,250382083
,250418521
,250454880
,250491359
,250527799
,250564239
,250600873
,250637389
,250673906
,250710304
,250746744
,250783260
,250819659
,250856098
,250892498
,250929018
,250965534
,251001933
,251038412
,251074812
,251111292
,251147651
,251184171
,251220571
,251257011
,251293411
,251329854
,251366459
,251402981
,251439584
,251476143
,251512743
,251549304
,251585861
,251622379
,251658934
,251695534
,251732134
,251768651
,251805171
,251841765
,251878362
,251914919
,251951473
,251988029
,252024584
,252060985
,252097587
,252134145
,252170742
,252207259
,252243854
,252280412
,252316967
,252353522
,252390077
,252426555
,252463074
,252499669
,252536185
,252572819
,252609256
,252645851
,252682407
,252718924
,252755362
,252791721
,252828324
,252864885
,252901481
,252937998
,252974553
,253011112
,253047628
,253084263
,253120817
,253157373
,253193814
,253230370
,253266964
,253303559
,253340075
,253376513
,253413068
,253449584
,253486140
,253522499
,253559060
,253595576
,253632171
,253668687
,253705281
,253741720
,253778314
,253814870
,253851347
,253887785
,253924224
,253960819
,253997335
,254033852
,254070290
,254106730
,254143246
,254179645
,254216084
,254252524
,254289004
,254325528
,254362048
,254398685
,254435161
,254471796
,254508314
,254544831
,254581426
,254618020
,254654536
,254691017
,254727533
,254764127
,254800722
,254837277
,254873676
,254910310
,254946747
,254983343
,255019742
,255056223
,255092778
,255129373
,255165850
,255202484
,255238883
,255275517
,255312033
,255348550
,255384948
,255421428
,255457982
,255494538
,255531015
,255567493
,255603893
,255640409
,255676808
,255713287
,255749687
,255786167
,255822647
,255859241
,255895758
,255932352
,255968868
,256005385
,256041979
,256078457
,256114894
,256151293
,256187850
,256224485
,256260883
,256297439
,256333838
,256370395
,256406833
,256443273
,256479672
,256516112
,256552551
,256589146
,256625662
,256662218
,256698577
,256735095
,256771573
,256807972
,256844411
,256880811
,256917291
,256953807
,256990206
,257026645
,257063125
,257099605
,257135964
,257172404
,257208884
,257245324
,257281724
,257318369
,257354849
,257391446
,257428001
,257464596
,257501116
,257537671
,257574187
,257610821
,257647337
,257683817
,257720333
,257756968
,257793522
,257830078
,257866516
,257903110
,257939588
,257976104
,258012503
,258049064
,258085580
,258122174
,258158690
,258195285
,258231684
,258268278
,258304794
,258341350
,258377749
,258414189
,258450783
,258487339
,258523816
,258560254
,258596654
,258633210
,258669609
,258706048
,258742448
,258778928
,258815448
,258852042
,258888558
,258925153
,258961669
,258998225
,259034780
,259071257
,259107735
,259144134
,259180651
,259217285
,259253684
,259290200
,259326599
,259363196
,259399634
,259436074
,259472433
,259508873
,259545352
,259581986
,259618423
,259655019
,259691418
,259727936
,259764374
,259800733
,259837212
,259873652
,259910131
,259946568
,259983047
,260019486
,260055886
,260092405
,260128805
,260165245
,260201725
,260238165
,260274526
,260311085
,260347640
,260384196
,260420751
,260457267
,260493823
,260530418
,260566855
,260603373
,260639732
,260676289
,260712883
,260749361
,260785798
,260822197
,260858794
,260895232
,260931672
,260968031
,261004551
,261041029
,261077584
,261114021
,261150617
,261187016
,261223534
,261260011
,261296411
,261332810
,261369330
,261405768
,261442246
,261478645
,261515084
,261551484
,261588003
,261624403
,261660923
,261697323
,261733763
,261770164
,261806759
,261843314
,261879791
,261916269
,261952709
,261989225
,262025624
,262062063
,262098463
,262134983
,262171459
,262207858
,262244337
,262280777
,262317217
,262353616
,262390016
,262426496
,262462976
,262499376
,262535894
,262572372
,262608772
,262645171
,262681611
,262718090
,262754490
,262790970
,262827450
,262863810
,262900290
,262936690
,262973210
,263009530
,263046050
,263082411
,263118891
,263155291
,263191772
,263228173
,263264776
,263301182
,263337785
,263374348
,263410948
,263447465
,263484069
,263520588
,263557185
,263593742
,263630296
,263666860
,263703380
,263740017
,263776493
,263813128
,263849646
,263886163
,263922758
,263959352
,263995868
,264032391
,264068952
,264105468
,264141987
,264178582
,264215180
,264251696
,264288290
,264324845
,264361401
,264397881
,264434436
,264471031
,264507508
,264544142
,264580541
,264617175
,264653691
,264690208
,264726606
,264763006
,264799650
,264836169
,264872727
,264909283
,264945877
,264982396
,265018951
,265055507
,265092062
,265128578
,265165098
,265201692
,265238209
,265274803
,265311319
,265347836
,265384430
,265420908
,265457345
,265493744
,265530305
,265566860
,265603454
,265640049
,265676565
,265713043
,265749598
,265786035
,265822631
,265859030
,265895469
,265932064
,265968580
,266005136
,266041495
,266078013
,266114491
,266150890
,266187329
,266223729
,266260210
,266296813
,266333332
,266369930
,266406446
,266443040
,266479559
,266516154
,266552670
,266589304
,266625741
,266662301
,266698855
,266735411
,266771966
,266808522
,266844999
,266881633
,266918071
,266954508
,266990987
,267027507
,267064023
,267100658
,267137212
,267173768
,267210206
,267246800
,267283278
,267319794
,267356193
,267392672
,267429227
,267465743
,267502299
,267538658
,267575176
,267611694
,267648053
,267684532
,267720972
,267757453
,267793970
,267830564
,267867080
,267903715
,267940152
,267976747
,268013263
,268049780
,268086218
,268122658
,268159173
,268195769
,268232246
,268268723
,268305123
,268341679
,268378038
,268414557
,268450957
,268487397
,268523874
,268560508
,268596907
,268633423
,268669822
,268706419
,268742857
,268779297
,268815656
,268852096
,268888653
,268925131
,268961571
,268997890
,269034410
,269070849
,269107249
,269143769
,269180169
,269216609
,269253012
,269289614
,269326133
,269362730
,269399246
,269435842
,269472360
,269508994
,269545510
,269582104
,269618582
,269655101
,269691656
,269728212
,269764767
,269801283
,269837839
,269874434
,269910871
,269947389
,269983748
,270020348
,270056824
,270093419
,270130013
,270166569
,270203006
,270239641
,270276039
,270312595
,270348994
,270385512
,270422067
,270458504
,270495100
,270531499
,270568017
,270604494
,270640894
,270677293
,270713813
,270750294
,270786770
,270823405
,270859881
,270896515
,270932954
,270969548
,271006064
,271042581
,271079019
,271115419
,271152014
,271188569
,271225046
,271261524
,271297964
,271334480
,271370879
,271407318
,271443718
,271480238
,271516675
,271553309
,271589747
,271626184
,271662663
,271699220
,271735618
,271772097
,271808497
,271844937
,271881454
,271917932
,271954332
,271990731
,272027171
,272063650
,272100050
,272136530
,272173010
,272209370
,272245892
,272282408
,272319003
,272355519
,272392113
,272428552
,272465146
,272501702
,272538179
,272574617
,272611056
,272647651
,272684167
,272720684
,272757122
,272793562
,272830078
,272866477
,272902916
,272939356
,272975836
,273012352
,273048907
,273085384
,273121862
,273158261
,273194818
,273231256
,273267695
,273304095
,273340615
,273377092
,273413530
,273449970
,273486329
,273522769
,273559248
,273595648
,273632128
,273668608
,273705008
,273741448
,273778003
,273814559
,273851075
,273887474
,273923953
,273960390
,273996869
,274033308
,274069708
,274106188
,274142704
,274179103
,274215542
,274251942
,274288462
,274324861
,274361301
,274397701
,274434221
,274470581
,274507178
,274543537
,274580056
,274616456
,274652976
,274689335
,274725775
,274762175
,274798655
,274835055
,274871535
,274907935
,274944375
,274980895
,275017295
,275053696
,275090216
,275126536
,275163017
,275199459
,275236025
,275272586
,275309104
,275345702
,275382257
,275418894
,275455370
,275492005
,275528481
,275565115
,275601554
,275638112
,275674667
,275711222
,275747777
,275784255
,275820850
,275857405
,275893882
,275930360
,275966800
,276003280
,276039834
,276076390
,276112945
,276149501
,276185978
,276222612
,276259050
,276295487
,276331966
,276368483
,276405078
,276441516
,276478032
,276514431
,276550988
,276587466
,276623866
,276660265
,276696705
,276733266
,276769782
,276806376
,276842892
,276879487
,276915886
,276952480
,276988996
,277025552
,277061951
,277098391
,277134985
,277171541
,277208018
,277244456
,277280856
,277317412
,277353811
,277390250
,277426650
,277463130
,277499685
,277536281
,277572758
,277609235
,277645635
,277682191
,277718550
,277755069
,277791469
,277827909
,277864426
,277900864
,277937303
,277973703
,278010223
,278046542
,278083022
,278119462
,278155982
,278192382
,278228864
,278265380
,278301974
,278338529
,278375085
,278411523
,278448078
,278484634
,278521150
,278557549
,278593989
,278630623
,278667139
,278703656
,278740054
,278776494
,278813010
,278849409
,278885848
,278922248
,278958768
,278995363
,279031879
,279068395
,279104833
,279141233
,279177789
,279214148
,279250667
,279287067
,279323587
,279360063
,279396462
,279432941
,279469381
,279505821
,279542220
,279578620
,279615060
,279651580
,279687980
,279724459
,279761014
,279797451
,279834047
,279870446
,279906964
,279943441
,279979841
,280016240
,280052760
,280089198
,280125676
,280162075
,280198514
,280234914
,280271433
,280307833
,280344353
,280380753
,280417193
,280453594
,280490110
,280526549
,280562988
,280599388
,280635868
,280672227
,280708747
,280745147
,280781587
,280817987
,280854467
,280890907
,280927307
,280963787
,281000227
,281036668
,281073188
,281109509
,281145949
,281182391
,281218995
,281255551
,281292145
,281328740
,281365256
,281401694
,281438249
,281474765
,281511321
,281547680
,281584160
,281620754
,281657270
,281693826
,281730225
,281766704
,281803141
,281839540
,281876059
,281912459
,281948938
,281985533
,282022049
,282058566
,282095004
,282131444
,282167960
,282204359
,282240798
,282277238
,282313718
,282350234
,282386593
,282423112
,282459512
,282495952
,282532351
,282568751
,282605231
,282641711
,282678111
,282714629
,282751184
,282787662
,282824178
,282860617
,282897134
,282933612
,282970052
,283006371
,283042891
,283079409
,283115847
,283152206
,283188685
,283225125
,283261604
,283298044
,283334484
,283370884
,283407404
,283443765
,283480281
,283516680
,283553119
,283589519
,283626039
,283662438
,283698878
,283735278
,283771798
,283808158
,283844598
,283881118
,283917518
,283953958
,283990358
,284026799
,284063319
,284099720
,284136120
,284172562
,284209162
,284245797
,284282195
,284318751
,284355150
,284391707
,284428145
,284464585
,284500984
,284537424
,284573942
,284610419
,284646819
,284683218
,284719738
,284756177
,284792577
,284829017
,284865417
,284901937
,284938298
,284974814
,285011213
,285047652
,285084132
,285120612
,285156971
,285193411
,285229891
,285266331
,285302731
,285339131
,285375651
,285412051
,285448491
,285484891
,285521412
,285557852
,285594333
,285630653
,285667136
,285703775
,285740173
,285776652
,285813052
,285849492
,285885891
,285922291
,285958811
,285995251
,286031731
,286068131
,286104531
,286141011
,286177491
,286213851
,286250292
,286286732
,286323132
,286359653
,286396014
,286432617
,286469057
,286505497
,286541897
,286578337
,286614738
,286651258
,286687658
,286724099
,286760500
,286797064
,286833504
,286869904
,286906425
,286942826
,286979269
,287015750
,287052151
,287088675
,287125239
,287161804
,287198322
,287234645
,287271249
,287307735
,287344338
,287380740
,287417304
,287453906
,287490509
,287527069
,287563507
,287600032
,287636635
,287673278
,287709758
,287746316
,287782918
,287819436
,287856034
,287892589
,287929104
,287965670
,288002234
,288038756
,288075356
,288111833
,288148477
,288184996
,288221554
,288258110
,288294704
,288331268
,288367826
,288404425
,288440941
,288477535
,288514015
,288550609
,288587126
,288623720
,288660236
,288696638
,288733243
,288769765
,288806368
,288842927
,288879527
,288916088
,288952645
,288989163
,289025718
,289062318
,289098918
,289135435
,289171955
,289208549
,289245146
,289281703
,289318257
,289354813
,289391368
,289427769
,289464371
,289500929
,289537526
,289574043
,289610638
,289647196
,289683751
,289720306
,289756861
,289793339
,289829858
,289866453
,289902969
,289939603
,289976040
,290012635
,290049191
,290085708
,290122146
,290158505
,290194988
,290231593
,290268115
,290304717
,290341236
,290377836
,290414436
,290450954
,290487472
,290524106
,290560666
,290597268
,290633744
,290670303
,290706858
,290743496
,290780012
,290816606
,290853122
,290889717
,290926117
,290962719
,290999238
,291035876
,291072352
,291108988
,291145505
,291182099
,291218615
,291255250
,291291689
,291328207
,291364762
,291401357
,291437912
,291474349
,291510944
,291547540
,291584017
,291620494
,291656894
,291693458
,291729978
,291766615
,291803091
,291839726
,291876244
,291912761
,291949356
,291985950
,292022466
,292058947
,292095463
,292132057
,292168652
,292205207
,292241606
,292278240
,292314677
,292351273
,292387672
,292424153
,292460708
,292497303
,292533780
,292570414
,292606813
,292643447
,292679963
,292716480
,292752878
,292789358
,292825912
,292862468
,292898945
,292935423
,292971823
,293008339
,293044738
,293081217
,293117617
,293154097
,293190501
,293227145
,293263626
,293300228
,293336747
,293373349
,293409949
,293446506
,293483023
,293519617
,293556179
,293592740
,293629297
,293665815
,293702370
,293738968
,293775484
,293812118
,293848633
,293885229
,293921671
,293958232
,293994750
,294031348
,294067903
,294104540
,294141016
,294177651
,294214127
,294250761
,294287200
,294323758
,294360313
,294396868
,294433423
,294469901
,294506496
,294543051
,294579528
,294616006
,294652446
,294689010
,294725490
,294762087
,294798642
,294835237
,294871757
,294908312
,294944828
,294981462
,295017978
,295054458
,295090974
,295127609
,295164163
,295200719
,295237157
,295273751
,295310229
,295346745
,295383144
,295419705
,295456221
,295492815
,295529331
,295565926
,295602325
,295638919
,295675435
,295711991
,295748390
,295784830
,295821424
,295857980
,295894457
,295930895
,295967295
,296003851
,296040250
,296076689
,296113089
,296149569
,296186173
,296222692
,296259289
,296295846
,296332400
,296368920
,296405475
,296442031
,296478625
,296515141
,296551660
,296588177
,296624772
,296661366
,296697882
,296734359
,296770914
,296807392
,296843908
,296880347
,296916868
,296953384
,296989978
,297026533
,297063089
,297099527
,297136082
,297172638
,297209154
,297245553
,297281993
,297318627
,297355143
,297391660
,297428058
,297464498
,297501014
,297537413
,297573852
,297610252
,297646772
,297683291
,297719846
,297756402
,297792957
,297829473
,297866029
,297902624
,297939061
,297975579
,298011938
,298048495
,298085089
,298121567
,298158004
,298194403
,298231000
,298267438
,298303878
,298340237
,298376757
,298413235
,298449790
,298486227
,298522823
,298559222
,298595740
,298632217
,298668617
,298705016
,298741536
,298777974
,298814452
,298850851
,298887290
,298923690
,298960209
,298996609
,299033129
,299069529
,299105969
,299142370
,299178855
,299215419
,299251980
,299288582
,299325099
,299361742
,299398222
,299434819
,299471374
,299507969
,299544492
,299581053
,299617649
,299654166
,299690721
,299727280
,299763796
,299800431
,299836985
,299873541
,299910023
,299946625
,299983101
,300019660
,300056215
,300092853
,300129369
,300165963
,300202479
,300239074
,300275554
,300312070
,300348665
,300385181
,300421775
,300458214
,300494808
,300531364
,300567841
,300604279
,300640679
,300677323
,300713842
,300750400
,300786916
,300823550
,300860030
,300896624
,300933140
,300969735
,301006251
,301042771
,301079326
,301115882
,301152476
,301188992
,301225469
,301262103
,301298502
,301335018
,301371417
,301407978
,301444494
,301481088
,301517683
,301554238
,301590637
,301627271
,301663708
,301700304
,301736703
,301773142
,301809697
,301846253
,301882769
,301919168
,301955647
,301992084
,302028563
,302065002
,302101402
,302137842
,302174486
,302211005
,302247563
,302284119
,302320713
,302357232
,302393787
,302430343
,302466898
,302503414
,302539934
,302576528
,302613045
,302649639
,302686155
,302722672
,302759266
,302795744
,302832181
,302868580
,302905141
,302941696
,302978290
,303014885
,303051401
,303087879
,303124434
,303160871
,303197467
,303233866
,303270305
,303306900
,303343416
,303379972
,303416331
,303452849
,303489327
,303525726
,303562165
,303598565
,303635085
,303671643
,303708198
,303744753
,303781308
,303817786
,303854381
,303890936
,303927413
,303963891
,304000331
,304036846
,304073402
,304109919
,304146357
,304182716
,304219312
,304255711
,304292190
,304328630
,304365070
,304401547
,304438142
,304474580
,304511096
,304547495
,304584052
,304620530
,304656930
,304693329
,304729769
,304766326
,304802764
,304839164
,304875563
,304912083
,304948522
,304984922
,305021442
,305057762
,305094282
,305130644
,305167247
,305203806
,305240364
,305276919
,305313515
,305350033
,305386588
,305423183
,305459738
,305496175
,305532735
,305569329
,305605845
,305642440
,305678956
,305715512
,305752067
,305788544
,305825022
,305861421
,305897980
,305934497
,305971092
,306007686
,306044202
,306080679
,306117234
,306153712
,306190228
,306226667
,306263106
,306299740
,306336177
,306372773
,306409172
,306445690
,306482128
,306518487
,306554966
,306591406
,306627926
,306664443
,306700998
,306737554
,306774149
,306810627
,306847181
,306883737
,306920214
,306956692
,306993092
,307029687
,307066203
,307102719
,307139157
,307175557
,307212113
,307248472
,307284991
,307321391
,307357911
,307394348
,307430942
,307467420
,307503857
,307540256
,307576853
,307613291
,307649731
,307686090
,307722610
,307759127
,307795565
,307832005
,307868404
,307904844
,307941283
,307977723
,308014203
,308050603
,308087043
,308123565
,308160041
,308196676
,308233152
,308269786
,308306225
,308342819
,308379335
,308415852
,308452290
,308488690
,308525285
,308561840
,308598317
,308634795
,308671235
,308707751
,308744150
,308780589
,308816989
,308853509
,308889946
,308926580
,308963018
,308999455
,309035934
,309072491
,309108889
,309145368
,309181768
,309218208
,309254725
,309291203
,309327603
,309364002
,309400442
,309436921
,309473321
,309509801
,309546281
,309582641
,309619082
,309655676
,309692192
,309728748
,309765147
,309801626
,309838063
,309874462
,309910981
,309947381
,309983821
,310020377
,310056776
,310093215
,310129615
,310166095
,310202534
,310238974
,310275374
,310311814
,310348254
,310384851
,310421210
,310457729
,310494129
,310530569
,310566968
,310603368
,310639848
,310676328
,310712728
,310749128
,310785608
,310822048
,310858568
,310894968
,310931369
,310967809
,311004209
,311040650
,311077092
,311113615
,311150140
,311186784
,311223306
,311259867
,311296385
,311332987
,311369506
,311406103
,311442619
,311479174
,311515818
,311552337
,311588895
,311625451
,311662045
,311698564
,311735119
,311771675
,311808230
,311844746
,311881349
,311917870
,311954467
,311990983
,312027578
,312064137
,312100613
,312137208
,312173802
,312210358
,312246799
,312283354
,312319948
,312356543
,312393059
,312429537
,312466092
,312502529
,312539125
,312575524
,312612007
,312648568
,312685086
,312721684
,312758239
,312794876
,312831352
,312867987
,312904463
,312941097
,312977536
,313014094
,313050649
,313087204
,313123759
,313160237
,313196832
,313233387
,313269864
,313306342
,313342782
,313379262
,313415816
,313452372
,313488927
,313525483
,313561960
,313598594
,313635032
,313671469
,313707948
,313744465
,313781060
,313817498
,313854014
,313890413
,313926970
,313963448
,313999848
,314036247
,314072687
,314109170
,314145770
,314182328
,314218847
,314255441
,314292039
,314328555
,314365150
,314401666
,314438260
,314474740
,314511257
,314547851
,314584367
,314621002
,314657439
,314694034
,314730550
,314767067
,314803505
,314839945
,314876425
,314913019
,314949535
,314986130
,315022646
,315059202
,315095757
,315132234
,315168712
,315205111
,315241628
,315278262
,315314661
,315351177
,315387576
,315424173
,315460611
,315497051
,315533410
,315569850
,315606411
,315642927
,315679521
,315716076
,315752632
,315789070
,315825625
,315862181
,315898697
,315935096
,315971536
,316008170
,316044686
,316081203
,316117601
,316154041
,316190557
,316226956
,316263395
,316299795
,316336315
,316372910
,316409426
,316445942
,316482380
,316518780
,316555336
,316591695
,316628214
,316664614
,316701134
,316737610
,316774009
,316810488
,316846928
,316883368
,316919767
,316956167
,316992607
,317029127
,317065527
,317102011
,317138611
,317175128
,317211648
,317248242
,317284839
,317321396
,317357950
,317394506
,317431061
,317467581
,317504057
,317540692
,317577168
,317613802
,317650241
,317686835
,317723351
,317759868
,317796306
,317832706
,317869225
,317905820
,317942336
,317978970
,318015407
,318052002
,318088558
,318125075
,318161513
,318197872
,318234429
,318271063
,318307501
,318343938
,318380417
,318416974
,318453372
,318489851
,318526251
,318562691
,318599172
,318635728
,318672322
,318708917
,318745433
,318781871
,318818426
,318854942
,318891498
,318927857
,318964337
,319000931
,319037447
,319074003
,319110402
,319146881
,319183318
,319219717
,319256236
,319292636
,319329115
,319365710
,319402226
,319438743
,319475181
,319511621
,319548137
,319584536
,319620975
,319657415
,319693895
,319730411
,319766770
,319803289
,319839689
,319876129
,319912528
,319948928
,319985408
,320021888
,320058288
,320094810
,320131326
,320167920
,320204515
,320241070
,320277469
,320314103
,320350540
,320387136
,320423535
,320459974
,320496529
,320533085
,320569601
,320606000
,320642479
,320678916
,320715395
,320751834
,320788234
,320824754
,320861308
,320897864
,320934341
,320970819
,321007219
,321043735
,321080134
,321116613
,321153013
,321189493
,321226009
,321262368
,321298887
,321335287
,321371807
,321408166
,321444606
,321481006
,321517486
,321553886
,321590404
,321627039
,321663437
,321699993
,321736392
,321772949
,321809387
,321845827
,321882226
,321918666
,321955184
,321991661
,322028061
,322064460
,322100980
,322137419
,322173819
,322210259
,322246659
,322283179
,322319540
,322356056
,322392455
,322428894
,322465374
,322501854
,322538213
,322574653
,322611133
,322647573
,322683973
,322720373
,322756893
,322793293
,322829733
,322866133
,322902654
,322939094
,322975575
,323011895
,323048378
,323084983
,323121583
,323158101
,323194619
,323231253
,323267772
,323304328
,323340922
,323377517
,323414033
,323450553
,323487069
,323523663
,323560179
,323596774
,323633173
,323669767
,323706283
,323742839
,323779238
,323815719
,323852236
,323888830
,323925346
,323961981
,323998418
,324035013
,324071529
,324108046
,324144484
,324180924
,324217439
,324254035
,324290512
,324326989
,324363389
,324399945
,324436304
,324472823
,324509223
,324545663
,324582182
,324618699
,324655294
,324691888
,324728404
,324764881
,324801436
,324837914
,324874430
,324910869
,324947308
,324983942
,325020379
,325056975
,325093374
,325129892
,325166330
,325202689
,325239168
,325275608
,325312048
,325348682
,325385198
,325421715
,325458113
,325494553
,325531069
,325567468
,325603907
,325640307
,325676827
,325713343
,325749742
,325786221
,325822621
,325859101
,325895460
,325931980
,325968380
,326004820
,326041220
,326077821
,326114297
,326150892
,326187486
,326224042
,326260479
,326297114
,326333512
,326370068
,326406467
,326442985
,326479540
,326515977
,326552573
,326588972
,326625490
,326661967
,326698367
,326734766
,326771286
,326807686
,326844280
,326880796
,326917313
,326953751
,326990151
,327026667
,327063066
,327099505
,327135985
,327172425
,327208941
,327245380
,327281819
,327318219
,327354699
,327391058
,327427578
,327463978
,327500418
,327536818
,327573376
,327610010
,327646448
,327682885
,327719364
,327755921
,327792319
,327828798
,327865198
,327901638
,327938155
,327974633
,328011033
,328047432
,328083872
,328120351
,328156751
,328193231
,328229711
,328266071
,328302550
,328339068
,328375427
,328411906
,328448346
,328484825
,328521265
,328557705
,328594105
,328630545
,328666986
,328703345
,328739865
,328776265
,328812785
,328849105
,328885626
,328922026
,328958547
,328994948
,329031391
,329067952
,329104507
,329141063
,329177657
,329214173
,329250650
,329287284
,329323683
,329360199
,329396598
,329433155
,329469710
,329506188
,329542704
,329579143
,329615660
,329652138
,329688578
,329724897
,329761417
,329797856
,329834411
,329870967
,329907483
,329943882
,329980361
,330016798
,330053277
,330089716
,330126116
,330162596
,330199112
,330235511
,330271950
,330308350
,330344870
,330381269
,330417709
,330454109
,330490629
,330526989
,330563586
,330600181
,330636618
,330673136
,330709495
,330746091
,330782490
,330818969
,330855409
,330891849
,330928326
,330964764
,331001204
,331037563
,331074083
,331110482
,331146882
,331183362
,331219842
,331256242
,331292761
,331329238
,331365638
,331402037
,331438557
,331474996
,331511396
,331547836
,331584236
,331620756
,331657156
,331693556
,331730076
,331766476
,331802916
,331839317
,331875837
,331912237
,331948678
,331985079
,332021603
,332058158
,332094714
,332131231
,332167669
,332204028
,332240624
,332277023
,332313502
,332349942
,332386382
,332422899
,332459297
,332495776
,332532176
,332568616
,332605015
,332641415
,332677935
,332714375
,332750855
,332787333
,332823771
,332860171
,332896570
,332933090
,332969529
,333005929
,333042449
,333078769
,333115289
,333151729
,333188169
,333224609
,333261009
,333297449
,333333850
,333370370
,333406770
,333443211
,333479612
,333516176
,333552692
,333589091
,333625530
,333661970
,333698450
,333734809
,333771329
,333807649
,333844169
,333880569
,333917009
,333953409
,333989889
,334026369
,334062769
,334099250
,334135690
,334172091
,334208491
,334244933
,334281495
,334317895
,334354375
,334390855
,334427255
,334463656
,334500096
,334536496
,334573017
,334609378
,334645902
,334682382
,334718822
,334755263
,334791664
,334828188
,334864628
,334901070
,334937593
,334974117
,335010722
,335047207
,335083812
,335120334
,335156934
,335193492
,335230094
,335266615
,335303212
,335339728
,335376323
,335412846
,335449446
,335486003
,335522520
,335559114
,335595634
,335632189
,335668783
,335705378
,335741894
,335778377
,335814977
,335851494
,335888014
,335924608
,335961205
,335997762
,336034316
,336070872
,336107427
,336143947
,336180423
,336217058
,336253534
,336290168
,336326607
,336363201
,336399717
,336436234
,336472672
,336509072
,336545675
,336582235
,336618793
,336655309
,336691903
,336728423
,336764977
,336801533
,336838088
,336874644
,336911164
,336947719
,336984235
,337020869
,337057385
,337093862
,337130457
,337166895
,337203411
,337239810
,337276331
,337312887
,337349481
,337386076
,337422592
,337459030
,337495585
,337532101
,337568657
,337605016
,337641496
,337678090
,337714606
,337751162
,337787561
,337824040
,337860477
,337896876
,337933395
,337969795
,338006235
,338042879
,338079398
,338115956
,338152472
,338189106
,338225586
,338262180
,338298696
,338335291
,338371807
,338408327
,338444882
,338481438
,338518032
,338554548
,338591025
,338627659
,338664058
,338700574
,338736973
,338773534
,338810050
,338846644
,338883239
,338919794
,338956193
,338992827
,339029264
,339065860
,339102259
,339138698
,339175253
,339211809
,339248325
,339284724
,339321203
,339357640
,339394119
,339430558
,339466958
,339503439
,339539957
,339576591
,339613107
,339649701
,339686179
,339722774
,339759290
,339795806
,339832244
,339868644
,339905200
,339941795
,339978232
,340014750
,340051109
,340087705
,340124104
,340160583
,340197023
,340233463
,340269900
,340306535
,340342933
,340379489
,340415888
,340452445
,340488883
,340525323
,340561722
,340598162
,340634680
,340671157
,340707557
,340743956
,340780476
,340816915
,340853315
,340889755
,340926155
,340962675
,340999037
,341035640
,341072159
,341108757
,341145273
,341181867
,341218386
,341254981
,341291497
,341328131
,341364568
,341401128
,341437682
,341474238
,341510793
,341547349
,341583826
,341620460
,341656898
,341693335
,341729814
,341766334
,341802850
,341839485
,341876039
,341912595
,341949033
,341985627
,342022105
,342058621
,342095020
,342131499
,342168054
,342204570
,342241126
,342277485
,342314003
,342350521
,342386880
,342423359
,342459799
,342496280
,342532797
,342569391
,342605907
,342642542
,342678979
,342715574
,342752090
,342788607
,342825045
,342861485
,342898000
,342934596
,342971073
,343007550
,343043950
,343080506
,343116865
,343153384
,343189784
,343226224
,343262701
,343299335
,343335734
,343372250
,343408649
,343445246
,343481684
,343518124
,343554483
,343590923
,343627480
,343663958
,343700398
,343736717
,343773237
,343809676
,343846076
,343882596
,343918996
,343955436
,343991917
,344028434
,344064989
,344101545
,344138140
,344174618
,344211172
,344247728
,344284205
,344320683
,344357083
,344393678
,344430194
,344466710
,344503148
,344539548
,344576104
,344612463
,344648982
,344685382
,344721902
,344758339
,344794933
,344831411
,344867848
,344904247
,344940844
,344977282
,345013722
,345050081
,345086601
,345123118
,345159556
,345195996
,345232395
,345268835
,345305274
,345341714
,345378194
,345414594
,345451034
,345487475
,345524069
,345560585
,345597102
,345633540
,345669940
,345706456
,345742855
,345779294
,345815774
,345852214
,345888730
,345925169
,345961608
,345998008
,346034488
,346070847
,346107367
,346143767
,346180207
,346216607
,346253204
,346289603
,346326082
,346362522
,346398962
,346435361
,346471761
,346508241
,346544721
,346581121
,346617521
,346653921
,346690441
,346726881
,346763361
,346799682
,346836202
,346872562
,346909043
,346945444
,346982009
,347018611
,347055130
,347091768
,347128244
,347164880
,347201397
,347237991
,347274507
,347311142
,347347581
,347384099
,347420654
,347457249
,347493804
,347530241
,347566836
,347603432
,347639909
,347676386
,347712786
,347749306
,347785861
,347822417
,347859011
,347895527
,347932004
,347968638
,348005037
,348041553
,348077952
,348114509
,348151064
,348187542
,348224058
,348260497
,348297014
,348333492
,348369932
,348406251
,348442771
,348479252
,348515807
,348552402
,348588879
,348625513
,348661912
,348698546
,348735062
,348771579
,348807977
,348844457
,348881011
,348917567
,348954044
,348990522
,349026922
,349063438
,349099837
,349136316
,349172716
,349209196
,349245712
,349282307
,349318744
,349355262
,349391621
,349428217
,349464616
,349501095
,349537535
,349573975
,349610452
,349646890
,349683330
,349719689
,349756209
,349792608
,349829008
,349865488
,349901968
,349938368
,349974889
,350011446
,350048000
,350084556
,350121111
,350157550
,350194144
,350230660
,350267177
,350303615
,350340055
,350376649
,350413165
,350449682
,350486120
,350522520
,350559036
,350595475
,350631914
,350668314
,350704794
,350741349
,350777905
,350814422
,350850860
,350887219
,350923815
,350960214
,350996693
,351033133
,351069573
,351106090
,351142488
,351178967
,351215367
,351251807
,351288206
,351324606
,351361126
,351397566
,351434046
,351470446
,351507001
,351543517
,351580073
,351616432
,351652950
,351689468
,351725827
,351762306
,351798746
,351835225
,351871662
,351908061
,351944580
,351980980
,352017460
,352053819
,352090339
,352126739
,352163259
,352199579
,352236176
,352272575
,352309014
,352345454
,352381934
,352418293
,352454813
,352491133
,352527653
,352564053
,352600493
,352636893
,352673373
,352709853
,352746253
,352782734
,352819174
,352855575
,352891975
,352928417
,352965061
,353001577
,353038171
,353074726
,353111282
,353147720
,353184275
,353220831
,353257347
,353293746
,353330186
,353366820
,353403336
,353439853
,353476251
,353512691
,353549207
,353585606
,353622045
,353658445
,353694965
,353731560
,353768076
,353804592
,353841030
,353877430
,353913986
,353950345
,353986864
,354023264
,354059784
,354096260
,354132659
,354169138
,354205578
,354242018
,354278417
,354314817
,354351257
,354387777
,354424177
,354460656
,354497211
,354533648
,354570244
,354606643
,354643161
,354679638
,354716038
,354752437
,354788957
,354825395
,354861873
,354898272
,354934711
,354971111
,355007630
,355044030
,355080550
,355116950
,355153390
,355189791
,355226307
,355262746
,355299185
,355335585
,355372065
,355408424
,355444944
,355481344
,355517784
,355554184
,355590664
,355627104
,355663504
,355699984
,355736424
,355772865
,355809385
,355845706
,355882146
,355918588
,355955189
,355991783
,356028261
,356064777
,356101176
,356137733
,356174171
,356210571
,356246970
,356283490
,356319928
,356356446
,356392805
,356429284
,356465724
,356502203
,356538643
,356575083
,356611483
,356647923
,356684324
,356720880
,356757279
,356793718
,356830118
,356866598
,356903037
,356939477
,356975877
,357012317
,357048757
,357085197
,357121717
,357158037
,357194557
,357230957
,357267398
,357303918
,357340319
,357376679
,357413161
,357449801
,357486239
,357522679
,357559038
,357595478
,357631957
,357668357
,357704837
,357741317
,357777717
,357814157
,357850557
,357887077
,357923477
,357959917
,357996278
,358032758
,358069198
,358105639
,358142040
,358178643
,358215043
,358251483
,358287963
,358324403
,358360764
,358397244
,358433724
,358470165
,358506566
,358543049
,358579570
,358615930
,358652411
,358688812
,358725294
,358761816
,358798177
,358834741
,358871265
,358907870
,358944394
,358980955
,359017512
,359054030
,359090585
,359127183
,359163699
,359200333
,359236848
,359273444
,359309923
,359346480
,359383034
,359419590
,359456145
,359492584
,359529178
,359565694
,359602211
,359638649
,359675089
,359711647
,359748202
,359784757
,359821312
,359857790
,359894385
,359930940
,359967417
,360003895
,360040335
,360076850
,360113406
,360149923
,360186361
,360222720
,360259316
,360295715
,360332194
,360368634
,360405074
,360441554
,360478070
,360514705
,360551259
,360587815
,360624253
,360660847
,360697325
,360733841
,360770240
,360806719
,360843274
,360879790
,360916346
,360952705
,360989223
,361025741
,361062100
,361098579
,361135019
,361171459
,361208053
,361244609
,361281086
,361317524
,361353924
,361390480
,361426879
,361463318
,361499718
,361536198
,361572754
,361609153
,361645592
,361682032
,361718512
,361754871
,361791391
,361827711
,361864231
,361900631
,361937191
,361973708
,362010303
,362046897
,362083413
,362119890
,362156445
,362192923
,362229439
,362265878
,362302317
,362338951
,362375388
,362411984
,362448383
,362484901
,362521339
,362557698
,362594177
,362630617
,362667057
,362703691
,362740207
,362776724
,362813122
,362849562
,362886078
,362922477
,362958916
,362995316
,363031836
,363068352
,363104751
,363141230
,363177630
,363214110
,363250469
,363286989
,363323389
,363359829
,363396229
,363432787
,363469381
,363505859
,363542296
,363578695
,363615292
,363651730
,363688170
,363724529
,363761049
,363797566
,363834004
,363870444
,363906843
,363943283
,363979722
,364016162
,364052642
,364089042
,364125482
,364161961
,364198439
,364234838
,364271277
,364307677
,364344196
,364380596
,364417116
,364453516
,364489956
,364526397
,364562756
,364599196
,364635676
,364672116
,364708516
,364745037
,364781437
,364817878
,364854359
,364890761
,364927363
,364963918
,365000434
,365037068
,365073584
,365110061
,365146656
,365183094
, 365219610, 365241885 };
	/// Function Mine

	//二分法确定在哪个区间，并且返回左值
	int SH_erfen(int day) {
		int left = 0;
		int right = 10004;
		int middle = 0;
		if (day == S_day[10004]) {
			return 10003;
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


	//不谈
	int digit_sum(int x) {
		//int a = 1;
		int count = 0;
		while (x) {
			++count;
			x = x & (x - 1);
		}
		return count;
	}


	string smonth_string(int year, int num) {
		return sm_stirng[num];
	}

	int sweekday_int(int year, char *month, int day) {

	}
	// 计算该月多少天 输入为字符的月份
	int sendDay(int year, char* month) {
		int result_endDay = 0;
		string mm = month;
		int num = 0;
		int judge = (year - digit_sum(year)) % 9 + 1;
		for (int i = 0; i < 18; i++) {
			if (mm == run_sm_string[i]) {
				num = i;
				break;
			}
		}
		if (num > 8) {
			num -= 8;
		}
		else
		{
			num++;
		}
		result_endDay = 39 + (10 * year - num) % 3;

		return result_endDay;
	}


	// 计算该月多少天 输入为int的月份
	int sint_endDay(int year, int m) { //m为真实月份
		int result_endDay = 0;
		int numOfm = m;
		result_endDay = 39 + (10 * year - numOfm) % 3;
		return result_endDay;
	}

	//计算从1年第一天到y年的最后一天一共有多少天
	int SyearDay(int y) {
		int sum = 0;
		bool leep = scheak_leepyear(y);
		if (leep) {
			int m = (y - digit_sum(y)) % 9 + 1;
			int d = 39 + (10 * y - m) % 3;
			sum = 360 + d;
		}
		else
		{
			sum = 360;
		}
		return sum;
	}


	// 计算在Shanghai日历中100年以内的天数
	int Syinei_calday(int y, char* month, int d) {
		int result = 0;
		int son_y = int(y / 100);
		int syearday = 0;
		bool leep = scheak_leepyear(y);
		string mm = month;
		// 计算从100*son_y年开始到今年过了多少天
		for (int i = son_y * 100 + 1; i < y; i++) {
			syearday = SyearDay(i);
			result += syearday;
		}
		// 计算今年过了多少天
		int judge_initial = (y - digit_sum(y)) % 9 + 1;
		int numOfm = 0;
		for (int i = 0; i < 18; i++) {
			if (mm == run_sm_string[i]) {
				numOfm = i;
				break;
			}
		}

		if (numOfm > 8) {
			for (int i = 0; i < judge_initial; i++) {
				result += 39 + (10 * y - i - 1) % 3;
			}
			result += d;
			return result;
		}
		else {
			numOfm++; // 符合真正月份

			if (leep) {
				int m = (y - digit_sum(y)) % 9 + 1;
				if (numOfm > m) {
					for (int i = 0; i < numOfm - 1; i++) {
						result += 39 + (10 * y - i - 1) % 3;
					}
					result += 39 + (10 * y - m) % 3; // 加上闰月的天数
					result += d;
					return result;
				}
				else {
					for (int i = 0; i < numOfm - 1; i++) {
						result += 39 + (10 * y - i - 1) % 3;
					}
					result += d;
					return result;
				}

			}
			else
			{
				for (int i = 0; i < numOfm - 1; i++) {
					result += 39 + (10 * y - i - 1) % 3;
				}
				result += d;
				return result;
			}
		}
	}

	// 计算在Shanghai日历中的总共天数
	int ScalTotalday(int y, char* month, int d) {
		int result = 0;
		int son_y = int(y / 100);
		int yushu_y = y % 100;
		if (son_y == 0) {
			result += Syinei_calday(y, month, d);
			return result;
		}
		else if (y == 1000361)
		{
			result += S_day[10003];
			result += Syinei_calday(y, month, d);
			return result;
		}
		else {
			result += S_day[son_y - 1];
			//int new_y = y - 100 * son_y;

			result += Syinei_calday(y, month, d);
			return result;
		}

	}


	//判断是不是闰年
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


	//将计算出的总天数n返回成Shanghai的年月日
	void DayToShangTechdate(int n) {
		int hanYearLeft = SH_erfen(n); // 返回的是 一年的最后一天，没有check过
		year_S = hanYearLeft * 100 + 1;
		Scal_pass_year(0);
		int day_remain = n - S_day[hanYearLeft - 1] - 1; //减去1是因为passday是从1开始的
		Scal_pass_day(day_remain);
	}

	bool Scal_pass_day(int n) {

		char *month_char[18] = { (char*)"Sist",(char*)"Spst",(char*)"Slst",(char*)"Sem",(char*)"Sca",(char*)"Ims",(char*)"Ihuman",(char*)"Siais",(char*)"Ih",(char*)"SIST" ,(char*)"SPST",(char*)"SLST",(char*)"SEM",(char*)"SCA",(char*)"IMS",(char*)"IHUMAN",(char*)"SIAIS",(char*)"IH" };

		//int totalDay = ScalTotalday(year_S, month_S, day_S);
		string sm = month_S;
		int y = year_S;
		bool leep = scheak_leepyear(y);

		///保存原来日期
		int or_y = year_S;
		int or_m = 0;
		for (int i = 0; i < 18; i++) {
			if (sm == run_sm_string[i]) {
				or_m = i;
				break;
			}
		}
		int or_d = day_S;
		///结束原日期

		int endDaying = 0;
		int numOfm = 0; //代表当前在第几个月,并且以下代码numofm都会表示真实月份



		if (n > 40200 || n < -40200) {// 处理超大数字
			int totalday = n + ScalTotalday(year_S, month_S, day_S);
			if (totalday >= 1 && totalday <= 365241885) {
				DayToShangTechdate(totalday);
			}
			else
			{
				baocuo_day = 1;
			}

		}
		else
		{
			if (n >= 0) {
				endDaying = sendDay(year_S, month_S);
				n += day_S;
				if (n > endDaying) {
					while (true)
					{
						Scal_pass_month(1);
						n -= endDaying;
						endDaying = sendDay(year_S, month_S);
						if (n <= endDaying) {
							break;
						}
					}
				}
				day_S = n;
			}
			else
			{
				n += day_S;
				if (n < 1) {
					while (true)
					{
						Scal_pass_month(-1);
						endDaying = sendDay(year_S, month_S);
						n += endDaying;
						if (n > 0) {
							break;
						}
					}
				}
				day_S = n;
			}


		}





		if (baocuo_month == 0 && baocuo_day == 0) {

			return true;
		}
		else
		{
			baocuo_month = 0;
			baocuo_day = 0;
			year_S = or_y;
			day_S = or_d;
			month_S = (char*)month_char[or_m];
			//cout << year_S << ' ' << *month_S << *(month_S + 1) << ' ' << day_S << endl;
			return false;
		}


	}

	bool Scal_pass_month(int n) {
		char *month_char[18] = { (char*)"Sist",(char*)"Spst",(char*)"Slst",(char*)"Sem",(char*)"Sca",
			(char*)"Ims",(char*)"Ihuman",(char*)"Siais",(char*)"Ih",(char*)"SIST" ,(char*)"SPST",
			(char*)"SLST",(char*)"SEM",(char*)"SCA",(char*)"IMS",(char*)"IHUMAN",(char*)"SIAIS",(char*)"IH" };

		string sm = month_S;
		int y = year_S;
		bool leep = scheak_leepyear(y);

		///保存原来月份
		int or_y = year_S;
		int or_m = 0;
		for (int i = 0; i < 18; i++) {
			if (sm == run_sm_string[i]) {
				or_m = i;
				break;
			}
		}
		///结束原月份

		int numOfm = 0; //代表当前在第几个月,并且以下代码numofm都会表示真实月份

		if (n >= 0) {
			if (leep) {
				int judge_initial = (y - digit_sum(y)) % 9 + 1;
				for (int i = 0; i < 18; i++) {
					if (sm == run_sm_string[i]) {
						numOfm = i;
						break;
					}
				}

				if (numOfm > 8) {
					numOfm -= 7; // 变成闰月的月份
				}
				else {
					numOfm++; // 符合真正月份
					if (numOfm > judge_initial) {
						numOfm++;
					}
				}

				numOfm += n;
				if (numOfm > 10) {
					Scal_pass_year(1);
					numOfm -= 10;
				}
				while (true)
				{
					leep = scheak_leepyear(year_S);
					if (leep) {
						if (numOfm <= 10) {
							break;
						}
						else
						{
							numOfm -= 10;
							Scal_pass_year(1);
						}
					}
					else
					{
						if (numOfm <= 9) {
							break;
						}
						else
						{
							Scal_pass_year(1);
							numOfm -= 9;
						}
					}
				}
				// 处理一年以内
				leep = scheak_leepyear(year_S);
				if (leep) {
					int judge = (year_S - digit_sum(year_S)) % 9 + 1;
					if (numOfm > judge + 1) {
						month_S = (char*)month_char[numOfm - 2];
					}
					else if (numOfm == judge + 1)
					{
						month_S = (char*)month_char[judge + 8];
					}
					else
					{
						month_S = (char*)month_char[numOfm - 1];
					}
				}
				else
				{
					month_S = (char*)month_char[numOfm - 1];
				}
			}
			else
			{
				for (int i = 0; i < 9; i++) {
					if (sm == sm_stirng[i]) {
						numOfm = i;
						break;
					}
				}
				numOfm++; // 符合真正月份
				numOfm += n;
				if (numOfm > 9) {
					Scal_pass_year(1);
					numOfm -= 9;
				}
				while (true)
				{
					leep = scheak_leepyear(year_S);
					if (leep) {
						if (numOfm <= 10) {
							break;
						}
						else
						{
							numOfm -= 10;
							Scal_pass_year(1);
						}
					}
					else
					{
						if (numOfm <= 9) {
							break;
						}
						else
						{
							Scal_pass_year(1);
							numOfm -= 9;
						}
					}
				}
				// 处理一年以内
				leep = scheak_leepyear(year_S);
				if (leep) {
					int judge = (year_S - digit_sum(year_S)) % 9 + 1;
					if (numOfm > judge + 1) {
						month_S = (char*)month_char[numOfm - 2];
					}
					else if (numOfm == judge + 1)
					{
						month_S = (char*)month_char[judge + 8];
					}
					else
					{
						month_S = (char*)month_char[numOfm - 1];
					}
				}
				else
				{
					month_S = (char*)month_char[numOfm - 1];
				}
			}
		}
		else
		{
			if (leep) {
				int judge_initial = (y - digit_sum(y)) % 9 + 1;
				for (int i = 0; i < 18; i++) {
					if (sm == run_sm_string[i]) {
						numOfm = i;
						break;
					}
				}

				if (numOfm > 8) {
					numOfm -= 7; // 变成闰月的月份
				}
				else {
					numOfm++; // 符合真正月份
					if (numOfm > judge_initial) {
						numOfm++;
					}
				}
				numOfm += n;
				if (numOfm >= 1) {
					if (numOfm > judge_initial + 1) {
						month_S = (char*)month_char[numOfm - 2];
					}
					else if (numOfm == judge_initial + 1) {
						month_S = (char*)month_char[judge_initial + 8];
					}
					else {
						month_S = (char*)month_char[numOfm - 1];
					}
				}
				else {

					while (true) {
						Scal_pass_year(-1);
						leep = scheak_leepyear(year_S);
						if (leep) {
							numOfm += 10;

						}
						else {
							numOfm += 9;
						}
						if (numOfm > 0) {
							break;
						}
					}


					// 处理一年以内
					leep = scheak_leepyear(year_S);
					if (leep) {
						int judge = (year_S - digit_sum(year_S)) % 9 + 1;
						if (numOfm > judge + 1) {
							month_S = (char*)month_char[numOfm - 2];
						}
						else if (numOfm == judge + 1)
						{
							month_S = (char*)month_char[judge + 8];
						}
						else
						{
							month_S = (char*)month_char[numOfm - 1];
						}
					}
					else
					{
						month_S = (char*)month_char[numOfm - 1];
					}

				}

			}
			else
			{

				for (int i = 0; i < 9; i++) {
					if (sm == sm_stirng[i]) {
						numOfm = i;
						break;
					}
				}
				numOfm++; // 符合真正月份
				numOfm += n;
				if (numOfm >= 1) {
					month_S = (char*)month_char[numOfm - 1];
				}
				else
				{
					while (true) {
						Scal_pass_year(-1);
						leep = scheak_leepyear(year_S);
						if (leep) {
							numOfm += 10;

						}
						else {
							numOfm += 9;
						}
						if (numOfm > 0) {
							break;
						}
					}


					// 处理一年以内
					leep = scheak_leepyear(year_S);
					if (leep) {
						int judge = (year_S - digit_sum(year_S)) % 9 + 1;
						if (numOfm > judge + 1) {
							month_S = (char*)month_char[numOfm - 2];
						}
						else if (numOfm == judge + 1)
						{
							month_S = (char*)month_char[judge + 8];
						}
						else
						{
							month_S = (char*)month_char[numOfm - 1];
						}
					}
					else
					{
						month_S = (char*)month_char[numOfm - 1];
					}


				}

			}

		}

		if (baocuo_year == 0) {
			day_S = 1;
			return true;
		}
		else
		{
			baocuo_year = 0;
			baocuo_month++;
			year_S = or_y;
			month_S = (char*)month_char[or_m];
			//cout << year_S << ' ' << *month_S << *(month_S + 1) << ' ' << day_S << endl;
			return false;
		}

	}

	bool Scal_pass_year(int n) {
		char *month_char[] = { (char*)"Sist",(char*)"Spst",(char*)"Slst",(char*)"Sem",(char*)"Sca",(char*)"Ims",(char*)"Ihuman",(char*)"Siais",(char*)"Ih" };
		int or_y = year_S;
		year_S += n;
		if (year_S <= 1000362 && year_S >= 1) {
			month_S = (char*)month_char[0];
			day_S = 1;
			return true;
		}
		else
		{
			year_S = or_y;
			baocuo_year = baocuo_year + 1;
			//cout << year_S << ' ' << *month_S << *(month_S + 1) << ' ' << day_S << endl;
			return false;
		}
	}

	// 含有参数的print_month 为了给Print_year调用
	void me_print_month(int year, char *month) {

		printf("%-36s\n", month);
		cout << "┌────┬────┬────┬────┬────┬────┬────┐" << endl;
		cout << "│ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│" << endl;
		cout << "├────┼────┼────┼────┼────┼────┼────┤" << endl;



		int week = ScalTotalday(year, month, 1) % 7;	//用int输出第一天是周几
		int endDay = sendDay(year, month); // 输出这个月的一共有多少天


		cout << "│";
		for (int j = 0; j < week; j++) {
			cout << hzifu[42 - 1];
		}

		for (int i = 0; i < 48 - week; i++) { //49代表有49个格子
			if ((i + week + 1) % 7 == 0) {
				if (i >= endDay) {
					cout << hzifu[42 - 1];
				}
				else {
					cout << hzifu[i];

				}
				cout << endl;
				cout << "├────┼────┼────┼────┼────┼────┼────┤" << endl;
				cout << "│";
			}
			else
			{
				if (i >= endDay) {
					cout << hzifu[42 - 1];
				}
				else
				{
					cout << hzifu[i];
				}

			}
		}
		cout << hzifu[41] << endl;
		cout << "└────┴────┴────┴────┴────┴────┴────┘" << endl;




	}


	/// end Mine



	/// Function HW

	Shanghaitech(int year, char *month, int day) :Gregorian(1, (char*)"Jan", 1) {
		//Shanghaitech(int year, char *month, int day){

		year_S = year;
		month_S = month;
		day_S = day;
		go_to(year, month, day);
	};
	void print_today() {

		cout << this->year_S << ' ' << this->month_S << ' ' << this->day_S << endl;

	}
	void print_month() {

		printf("%-36s\n", this->month_S);
		cout << "┌────┬────┬────┬────┬────┬────┬────┐" << endl;
		cout << "│ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│" << endl;
		cout << "├────┼────┼────┼────┼────┼────┼────┤" << endl;



		int week = ScalTotalday(year_S, month_S, 1) % 7;	//用int输出第一天是周几
		int endDay = sendDay(year_S, month_S); // 输出这个月的一共有多少天


		cout << "│";
		for (int j = 0; j < week; j++) {
			cout << hzifu[42 - 1];
		}

		for (int i = 0; i < 48 - week; i++) { //49代表有49个格子
			if ((i + week + 1) % 7 == 0) {
				if (i >= endDay) {
					cout << hzifu[42 - 1];
				}
				else {
					cout << hzifu[i];

				}
				cout << endl;
				cout << "├────┼────┼────┼────┼────┼────┼────┤" << endl;
				cout << "│";
			}
			else
			{
				if (i >= endDay) {
					cout << hzifu[42 - 1];
				}
				else
				{
					cout << hzifu[i];
				}

			}
		}
		cout << hzifu[41] << endl;
		cout << "└────┴────┴────┴────┴────┴────┴────┘" << endl;




	}

	void print_year() {
		char *month_char[18] = { (char*)"Sist",(char*)"Spst",(char*)"Slst",(char*)"Sem",(char*)"Sca",(char*)"Ims",(char*)"Ihuman",(char*)"Siais",(char*)"Ih",(char*)"SIST" ,(char*)"SPST",(char*)"SLST",(char*)"SEM",(char*)"SCA",(char*)"IMS",(char*)"IHUMAN",(char*)"SIAIS",(char*)"IH" };

		int week_month1 = ScalTotalday(year_S, month_char[0], 1) % 7;	//用int输出第一天是周几
		int endDay_month1 = sendDay(year_S, month_char[0]); // 输出这个月的一共有多少天
		int week_month2 = ScalTotalday(year_S, month_char[1], 1) % 7;
		int endDay_month2 = sendDay(year_S, month_char[1]);
		int week_month3 = ScalTotalday(year_S, month_char[2], 1) % 7;
		int endDay_month3 = sendDay(year_S, month_char[2]);


		int week_month4 = ScalTotalday(year_S, month_char[3], 1) % 7;
		int endDay_month4 = sendDay(year_S, month_char[3]);
		int week_month5 = ScalTotalday(year_S, month_char[4], 1) % 7;
		int endDay_month5 = sendDay(year_S, month_char[4]);
		int week_month6 = ScalTotalday(year_S, month_char[5], 1) % 7;
		int endDay_month6 = sendDay(year_S, month_char[5]);



		int week_month7 = ScalTotalday(year_S, month_char[6], 1) % 7;
		int endDay_month7 = sendDay(year_S, month_char[6]);

		int week_month8 = ScalTotalday(year_S, month_char[7], 1) % 7;
		int endDay_month8 = sendDay(year_S, month_char[7]);
		int week_month9 = ScalTotalday(year_S, month_char[8], 1) % 7;
		int endDay_month9 = sendDay(year_S, month_char[8]);



		// 为了给case9使用
		int endDay = sendDay(year_S, month_char[8]); // 输出这个月的一共有多少天
		//

		bool leep = scheak_leepyear(year_S);
		if (leep) {
			int run_month = (year_S - digit_sum(year_S)) % 9 + 1;
			int i_f = 0;
			int i_s = 0;
			int i_t = 0;

			int leep_weekday1 = ScalTotalday(year_S, month_char[run_month + 9], 1) % 7;

			switch (run_month)
			{

			case 1:
#pragma region 1 3 				
				cout << "Sist                                 SIST                                 Spst                                " << endl;
				cout << "┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐" << endl;
				cout << "│ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│" << endl;
				cout << "├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤" << endl;


				/// 前三个月	
				for (int i = 0; i < 147; ) {
					// 第一个月

					if (i < 21) {
						cout << "│";
						for (int j = 0; j < week_month1; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_f < 49 - week_month1) {
						if ((i_f + week_month1 + 1) % 7 == 0) {
							if (i_f >= endDay_month1) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_f];
								i++;
								cout << ' ';
							}
							i_f++;
							break;
						}
						else
						{
							if (i_f >= endDay_month1) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_f];
								i++;
							}
						}
						i_f++;
					}

					//第二个月
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < leep_weekday1; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_s < 49 - leep_weekday1) {

						if ((i_s + leep_weekday1 + 1) % 7 == 0) {
							if (i_s >= endDay_month1) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_s];
								i++;
								cout << ' ';
							}
							i_s++;
							break;
						}
						else
						{
							if (i_s >= endDay_month1) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_s];
								i++;
							}
						}
						i_s++;
					}

					//第三个月  	
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < week_month2; j++) {

							cout << hzifu[42 - 1];
							i++;
						}
					}

					while (i_t < 49 - week_month2) {

						if ((i_t + week_month2 + 1) % 7 == 0) {
							if (i_t >= endDay_month2) {
								cout << hzifu[42 - 1];
								i++;
							}
							else {
								cout << hzifu[i_t];
								i++;
							}
							cout << endl;
							if (i == 147) {
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
							if (i_t >= endDay_month2) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_t];
								i++;
							}
						}
						i_t++;
					}
				}

#pragma endregion




#pragma region 4 6
				cout << "Slst                                 Sem                                  Sca                                 " << endl;
				cout << "┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐" << endl;
				cout << "│ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│" << endl;
				cout << "├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤" << endl;

				i_f = 0;
				i_s = 0;
				i_t = 0;
				for (int i = 0; i < 147; ) {
					// 第一个月

					if (i < 21) {
						cout << "│";
						for (int j = 0; j < week_month3; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_f < 49 - week_month3) {
						if ((i_f + week_month3 + 1) % 7 == 0) {
							if (i_f >= endDay_month3) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_f];
								i++;
								cout << ' ';
							}
							i_f++;
							break;
						}
						else
						{
							if (i_f >= endDay_month3) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_f];
								i++;
							}
						}
						i_f++;
					}

					//第二个月
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < week_month4; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_s < 49 - week_month4) {

						if ((i_s + week_month4 + 1) % 7 == 0) {
							if (i_s >= endDay_month4) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_s];
								i++;
								cout << ' ';
							}
							i_s++;
							break;
						}
						else
						{
							if (i_s >= endDay_month4) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_s];
								i++;
							}
						}
						i_s++;
					}

					//第三个月  	
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < week_month5; j++) {

							cout << hzifu[42 - 1];
							i++;
						}
					}

					while (i_t < 49 - week_month5) {

						if ((i_t + week_month5 + 1) % 7 == 0) {
							if (i_t >= endDay_month5) {
								cout << hzifu[42 - 1];
								i++;
							}
							else {
								cout << hzifu[i_t];
								i++;
							}
							cout << endl;
							if (i == 147) {
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
							if (i_t >= endDay_month5) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_t];
								i++;
							}
						}
						i_t++;
					}
				}



#pragma endregion




#pragma region 7 9

				cout << "Ims                                  Ihuman                               Siais                               " << endl;
				cout << "┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐" << endl;
				cout << "│ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│" << endl;
				cout << "├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤" << endl;

				i_f = 0;
				i_s = 0;
				i_t = 0;


				for (int i = 0; i < 147; ) {
					// 第一个月

					if (i < 21) {
						cout << "│";
						for (int j = 0; j < week_month6; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_f < 49 - week_month6) {
						if ((i_f + week_month6 + 1) % 7 == 0) {
							if (i_f >= endDay_month6) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_f];
								i++;
								cout << ' ';
							}
							i_f++;
							break;
						}
						else
						{
							if (i_f >= endDay_month6) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_f];
								i++;
							}
						}
						i_f++;
					}

					//第二个月
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < week_month7; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_s < 49 - week_month7) {

						if ((i_s + week_month7 + 1) % 7 == 0) {
							if (i_s >= endDay_month7) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_s];
								i++;
								cout << ' ';
							}
							i_s++;
							break;
						}
						else
						{
							if (i_s >= endDay_month7) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_s];
								i++;
							}
						}
						i_s++;
					}

					//第三个月  	
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < week_month8; j++) {

							cout << hzifu[42 - 1];
							i++;
						}
					}

					while (i_t < 49 - week_month8) {

						if ((i_t + week_month8 + 1) % 7 == 0) {
							if (i_t >= endDay_month8) {
								cout << hzifu[42 - 1];
								i++;
							}
							else {
								cout << hzifu[i_t];
								i++;
							}
							cout << endl;
							if (i == 147) {
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
							if (i_t >= endDay_month8) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_t];
								i++;
							}
						}
						i_t++;
					}
				}

#pragma endregion

				me_print_month(year_S, month_char[8]);
				break;
			case 2:

#pragma region 1 3 				
				cout << "Sist                                 Spst                                 SPST                                " << endl;
				cout << "┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐" << endl;
				cout << "│ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│" << endl;
				cout << "├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤" << endl;


				/// 前三个月	
				for (int i = 0; i < 147; ) {
					// 第一个月

					if (i < 21) {
						cout << "│";
						for (int j = 0; j < week_month1; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_f < 49 - week_month1) {
						if ((i_f + week_month1 + 1) % 7 == 0) {
							if (i_f >= endDay_month1) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_f];
								i++;
								cout << ' ';
							}
							i_f++;
							break;
						}
						else
						{
							if (i_f >= endDay_month1) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_f];
								i++;
							}
						}
						i_f++;
					}

					//第二个月
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < week_month2; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_s < 49 - week_month2) {

						if ((i_s + week_month2 + 1) % 7 == 0) {
							if (i_s >= endDay_month2) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_s];
								i++;
								cout << ' ';
							}
							i_s++;
							break;
						}
						else
						{
							if (i_s >= endDay_month2) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_s];
								i++;
							}
						}
						i_s++;
					}

					//第三个月  	
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < leep_weekday1; j++) {

							cout << hzifu[42 - 1];
							i++;
						}
					}

					while (i_t < 49 - leep_weekday1) {

						if ((i_t + leep_weekday1 + 1) % 7 == 0) {
							if (i_t >= endDay_month2) {
								cout << hzifu[42 - 1];
								i++;
							}
							else {
								cout << hzifu[i_t];
								i++;
							}
							cout << endl;
							if (i == 147) {
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
							if (i_t >= endDay_month2) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_t];
								i++;
							}
						}
						i_t++;
					}
				}

#pragma endregion




#pragma region 4 6
				cout << "Slst                                 Sem                                  Sca                                 " << endl;
				cout << "┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐" << endl;
				cout << "│ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│" << endl;
				cout << "├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤" << endl;

				i_f = 0;
				i_s = 0;
				i_t = 0;
				for (int i = 0; i < 147; ) {
					// 第一个月

					if (i < 21) {
						cout << "│";
						for (int j = 0; j < week_month3; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_f < 49 - week_month3) {
						if ((i_f + week_month3 + 1) % 7 == 0) {
							if (i_f >= endDay_month3) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_f];
								i++;
								cout << ' ';
							}
							i_f++;
							break;
						}
						else
						{
							if (i_f >= endDay_month3) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_f];
								i++;
							}
						}
						i_f++;
					}

					//第二个月
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < week_month4; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_s < 49 - week_month4) {

						if ((i_s + week_month4 + 1) % 7 == 0) {
							if (i_s >= endDay_month4) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_s];
								i++;
								cout << ' ';
							}
							i_s++;
							break;
						}
						else
						{
							if (i_s >= endDay_month4) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_s];
								i++;
							}
						}
						i_s++;
					}

					//第三个月  	
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < week_month5; j++) {

							cout << hzifu[42 - 1];
							i++;
						}
					}

					while (i_t < 49 - week_month5) {

						if ((i_t + week_month5 + 1) % 7 == 0) {
							if (i_t >= endDay_month5) {
								cout << hzifu[42 - 1];
								i++;
							}
							else {
								cout << hzifu[i_t];
								i++;
							}
							cout << endl;
							if (i == 147) {
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
							if (i_t >= endDay_month5) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_t];
								i++;
							}
						}
						i_t++;
					}
				}



#pragma endregion




#pragma region 7 9

				cout << "Ims                                  Ihuman                               Siais                               " << endl;
				cout << "┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐" << endl;
				cout << "│ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│" << endl;
				cout << "├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤" << endl;

				i_f = 0;
				i_s = 0;
				i_t = 0;


				for (int i = 0; i < 147; ) {
					// 第一个月

					if (i < 21) {
						cout << "│";
						for (int j = 0; j < week_month6; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_f < 49 - week_month6) {
						if ((i_f + week_month6 + 1) % 7 == 0) {
							if (i_f >= endDay_month6) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_f];
								i++;
								cout << ' ';
							}
							i_f++;
							break;
						}
						else
						{
							if (i_f >= endDay_month6) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_f];
								i++;
							}
						}
						i_f++;
					}

					//第二个月
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < week_month7; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_s < 49 - week_month7) {

						if ((i_s + week_month7 + 1) % 7 == 0) {
							if (i_s >= endDay_month7) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_s];
								i++;
								cout << ' ';
							}
							i_s++;
							break;
						}
						else
						{
							if (i_s >= endDay_month7) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_s];
								i++;
							}
						}
						i_s++;
					}

					//第三个月  	
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < week_month8; j++) {

							cout << hzifu[42 - 1];
							i++;
						}
					}

					while (i_t < 49 - week_month8) {

						if ((i_t + week_month8 + 1) % 7 == 0) {
							if (i_t >= endDay_month8) {
								cout << hzifu[42 - 1];
								i++;
							}
							else {
								cout << hzifu[i_t];
								i++;
							}
							cout << endl;
							if (i == 147) {
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
							if (i_t >= endDay_month8) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_t];
								i++;
							}
						}
						i_t++;
					}
				}

#pragma endregion

				me_print_month(year_S, month_char[8]);
				break;


			case 3:

#pragma region 1 3
				cout << "Sist                                 Spst                                 Slst                                " << endl;
				cout << "┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐" << endl;
				cout << "│ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│" << endl;
				cout << "├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤" << endl;

				for (int i = 0; i < 147; ) {
					// 第一个月

					if (i < 21) {
						cout << "│";
						for (int j = 0; j < week_month1; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_f < 49 - week_month1) {
						if ((i_f + week_month1 + 1) % 7 == 0) {
							if (i_f >= endDay_month1) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_f];
								i++;
								cout << ' ';
							}
							i_f++;
							break;
						}
						else
						{
							if (i_f >= endDay_month1) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_f];
								i++;
							}
						}
						i_f++;
					}

					//第二个月
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < week_month2; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_s < 49 - week_month2) {

						if ((i_s + week_month2 + 1) % 7 == 0) {
							if (i_s >= endDay_month2) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_s];
								i++;
								cout << ' ';
							}
							i_s++;
							break;
						}
						else
						{
							if (i_s >= endDay_month2) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_s];
								i++;
							}
						}
						i_s++;
					}

					//第三个月  	
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < week_month3; j++) {

							cout << hzifu[42 - 1];
							i++;
						}
					}

					while (i_t < 49 - week_month3) {

						if ((i_t + week_month3 + 1) % 7 == 0) {
							if (i_t >= endDay_month3) {
								cout << hzifu[42 - 1];
								i++;
							}
							else {
								cout << hzifu[i_t];
								i++;
							}
							cout << endl;
							if (i == 147) {
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
							if (i_t >= endDay_month3) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_t];
								i++;
							}
						}
						i_t++;
					}
				}


#pragma endregion


#pragma region 4 6
				cout << "SLST                                 Sem                                  Sca                                 " << endl;
				cout << "┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐" << endl;
				cout << "│ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│" << endl;
				cout << "├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤" << endl;

				i_f = 0;
				i_s = 0;
				i_t = 0;
				for (int i = 0; i < 147; ) {
					// 第一个月

					if (i < 21) {
						cout << "│";
						for (int j = 0; j < leep_weekday1; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_f < 49 - leep_weekday1) {
						if ((i_f + leep_weekday1 + 1) % 7 == 0) {
							if (i_f >= endDay_month3) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_f];
								i++;
								cout << ' ';
							}
							i_f++;
							break;
						}
						else
						{
							if (i_f >= endDay_month3) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_f];
								i++;
							}
						}
						i_f++;
					}

					//第二个月
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < week_month4; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_s < 49 - week_month4) {

						if ((i_s + week_month4 + 1) % 7 == 0) {
							if (i_s >= endDay_month4) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_s];
								i++;
								cout << ' ';
							}
							i_s++;
							break;
						}
						else
						{
							if (i_s >= endDay_month4) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_s];
								i++;
							}
						}
						i_s++;
					}

					//第三个月  	
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < week_month5; j++) {

							cout << hzifu[42 - 1];
							i++;
						}
					}

					while (i_t < 49 - week_month5) {

						if ((i_t + week_month5 + 1) % 7 == 0) {
							if (i_t >= endDay_month5) {
								cout << hzifu[42 - 1];
								i++;
							}
							else {
								cout << hzifu[i_t];
								i++;
							}
							cout << endl;
							if (i == 147) {
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
							if (i_t >= endDay_month5) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_t];
								i++;
							}
						}
						i_t++;
					}
				}



#pragma endregion




#pragma region 7 9

				cout << "Ims                                  Ihuman                               Siais                               " << endl;
				cout << "┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐" << endl;
				cout << "│ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│" << endl;
				cout << "├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤" << endl;

				i_f = 0;
				i_s = 0;
				i_t = 0;


				for (int i = 0; i < 147; ) {
					// 第一个月

					if (i < 21) {
						cout << "│";
						for (int j = 0; j < week_month6; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_f < 49 - week_month6) {
						if ((i_f + week_month6 + 1) % 7 == 0) {
							if (i_f >= endDay_month6) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_f];
								i++;
								cout << ' ';
							}
							i_f++;
							break;
						}
						else
						{
							if (i_f >= endDay_month6) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_f];
								i++;
							}
						}
						i_f++;
					}

					//第二个月
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < week_month7; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_s < 49 - week_month7) {

						if ((i_s + week_month7 + 1) % 7 == 0) {
							if (i_s >= endDay_month7) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_s];
								i++;
								cout << ' ';
							}
							i_s++;
							break;
						}
						else
						{
							if (i_s >= endDay_month7) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_s];
								i++;
							}
						}
						i_s++;
					}

					//第三个月  	
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < week_month8; j++) {

							cout << hzifu[42 - 1];
							i++;
						}
					}

					while (i_t < 49 - week_month8) {

						if ((i_t + week_month8 + 1) % 7 == 0) {
							if (i_t >= endDay_month8) {
								cout << hzifu[42 - 1];
								i++;
							}
							else {
								cout << hzifu[i_t];
								i++;
							}
							cout << endl;
							if (i == 147) {
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
							if (i_t >= endDay_month8) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_t];
								i++;
							}
						}
						i_t++;
					}
				}

#pragma endregion

				me_print_month(year_S, month_char[8]);
				break;


			case 4:

#pragma region 1 3
				cout << "Sist                                 Spst                                 Slst                                " << endl;
				cout << "┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐" << endl;
				cout << "│ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│" << endl;
				cout << "├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤" << endl;

				for (int i = 0; i < 147; ) {
					// 第一个月

					if (i < 21) {
						cout << "│";
						for (int j = 0; j < week_month1; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_f < 49 - week_month1) {
						if ((i_f + week_month1 + 1) % 7 == 0) {
							if (i_f >= endDay_month1) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_f];
								i++;
								cout << ' ';
							}
							i_f++;
							break;
						}
						else
						{
							if (i_f >= endDay_month1) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_f];
								i++;
							}
						}
						i_f++;
					}

					//第二个月
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < week_month2; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_s < 49 - week_month2) {

						if ((i_s + week_month2 + 1) % 7 == 0) {
							if (i_s >= endDay_month2) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_s];
								i++;
								cout << ' ';
							}
							i_s++;
							break;
						}
						else
						{
							if (i_s >= endDay_month2) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_s];
								i++;
							}
						}
						i_s++;
					}

					//第三个月  	
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < week_month3; j++) {

							cout << hzifu[42 - 1];
							i++;
						}
					}

					while (i_t < 49 - week_month3) {

						if ((i_t + week_month3 + 1) % 7 == 0) {
							if (i_t >= endDay_month3) {
								cout << hzifu[42 - 1];
								i++;
							}
							else {
								cout << hzifu[i_t];
								i++;
							}
							cout << endl;
							if (i == 147) {
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
							if (i_t >= endDay_month3) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_t];
								i++;
							}
						}
						i_t++;
					}
				}


#pragma endregion


#pragma region 4 6
				cout << "Sem                                  SEM                                  Sca                                 " << endl;
				cout << "┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐" << endl;
				cout << "│ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│" << endl;
				cout << "├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤" << endl;

				i_f = 0;
				i_s = 0;
				i_t = 0;
				for (int i = 0; i < 147; ) {
					// 第一个月

					if (i < 21) {
						cout << "│";
						for (int j = 0; j < week_month4; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_f < 49 - week_month4) {
						if ((i_f + week_month4 + 1) % 7 == 0) {
							if (i_f >= endDay_month4) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_f];
								i++;
								cout << ' ';
							}
							i_f++;
							break;
						}
						else
						{
							if (i_f >= endDay_month4) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_f];
								i++;
							}
						}
						i_f++;
					}
					//第二个月
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < leep_weekday1; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_s < 49 - leep_weekday1) {

						if ((i_s + leep_weekday1 + 1) % 7 == 0) {
							if (i_s >= endDay_month4) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_s];
								i++;
								cout << ' ';
							}
							i_s++;
							break;
						}
						else
						{
							if (i_s >= endDay_month4) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_s];
								i++;
							}
						}
						i_s++;
					}

					//第三个月  	
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < week_month5; j++) {

							cout << hzifu[42 - 1];
							i++;
						}
					}

					while (i_t < 49 - week_month5) {

						if ((i_t + week_month5 + 1) % 7 == 0) {
							if (i_t >= endDay_month5) {
								cout << hzifu[42 - 1];
								i++;
							}
							else {
								cout << hzifu[i_t];
								i++;
							}
							cout << endl;
							if (i == 147) {
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
							if (i_t >= endDay_month5) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_t];
								i++;
							}
						}
						i_t++;
					}
				}



#pragma endregion




#pragma region 7 9

				cout << "Ims                                  Ihuman                               Siais                               " << endl;
				cout << "┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐" << endl;
				cout << "│ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│" << endl;
				cout << "├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤" << endl;

				i_f = 0;
				i_s = 0;
				i_t = 0;


				for (int i = 0; i < 147; ) {
					// 第一个月

					if (i < 21) {
						cout << "│";
						for (int j = 0; j < week_month6; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_f < 49 - week_month6) {
						if ((i_f + week_month6 + 1) % 7 == 0) {
							if (i_f >= endDay_month6) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_f];
								i++;
								cout << ' ';
							}
							i_f++;
							break;
						}
						else
						{
							if (i_f >= endDay_month6) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_f];
								i++;
							}
						}
						i_f++;
					}

					//第二个月
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < week_month7; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_s < 49 - week_month7) {

						if ((i_s + week_month7 + 1) % 7 == 0) {
							if (i_s >= endDay_month7) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_s];
								i++;
								cout << ' ';
							}
							i_s++;
							break;
						}
						else
						{
							if (i_s >= endDay_month7) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_s];
								i++;
							}
						}
						i_s++;
					}

					//第三个月  	
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < week_month8; j++) {

							cout << hzifu[42 - 1];
							i++;
						}
					}

					while (i_t < 49 - week_month8) {

						if ((i_t + week_month8 + 1) % 7 == 0) {
							if (i_t >= endDay_month8) {
								cout << hzifu[42 - 1];
								i++;
							}
							else {
								cout << hzifu[i_t];
								i++;
							}
							cout << endl;
							if (i == 147) {
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
							if (i_t >= endDay_month8) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_t];
								i++;
							}
						}
						i_t++;
					}
				}

#pragma endregion

				me_print_month(year_S, month_char[8]);
				break;





			case 5:

#pragma region 1 3
				cout << "Sist                                 Spst                                 Slst                                " << endl;
				cout << "┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐" << endl;
				cout << "│ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│" << endl;
				cout << "├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤" << endl;

				for (int i = 0; i < 147; ) {
					// 第一个月

					if (i < 21) {
						cout << "│";
						for (int j = 0; j < week_month1; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_f < 49 - week_month1) {
						if ((i_f + week_month1 + 1) % 7 == 0) {
							if (i_f >= endDay_month1) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_f];
								i++;
								cout << ' ';
							}
							i_f++;
							break;
						}
						else
						{
							if (i_f >= endDay_month1) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_f];
								i++;
							}
						}
						i_f++;
					}

					//第二个月
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < week_month2; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_s < 49 - week_month2) {

						if ((i_s + week_month2 + 1) % 7 == 0) {
							if (i_s >= endDay_month2) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_s];
								i++;
								cout << ' ';
							}
							i_s++;
							break;
						}
						else
						{
							if (i_s >= endDay_month2) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_s];
								i++;
							}
						}
						i_s++;
					}

					//第三个月  	
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < week_month3; j++) {

							cout << hzifu[42 - 1];
							i++;
						}
					}

					while (i_t < 49 - week_month3) {

						if ((i_t + week_month3 + 1) % 7 == 0) {
							if (i_t >= endDay_month3) {
								cout << hzifu[42 - 1];
								i++;
							}
							else {
								cout << hzifu[i_t];
								i++;
							}
							cout << endl;
							if (i == 147) {
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
							if (i_t >= endDay_month3) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_t];
								i++;
							}
						}
						i_t++;
					}
				}


#pragma endregion


#pragma region 4 6
				cout << "Sem                                  Sca                                  SCA                                 " << endl;
				cout << "┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐" << endl;
				cout << "│ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│" << endl;
				cout << "├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤" << endl;

				i_f = 0;
				i_s = 0;
				i_t = 0;
				for (int i = 0; i < 147; ) {
					// 第一个月

					if (i < 21) {
						cout << "│";
						for (int j = 0; j < week_month4; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_f < 49 - week_month4) {
						if ((i_f + week_month4 + 1) % 7 == 0) {
							if (i_f >= endDay_month4) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_f];
								i++;
								cout << ' ';
							}
							i_f++;
							break;
						}
						else
						{
							if (i_f >= endDay_month4) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_f];
								i++;
							}
						}
						i_f++;
					}
					//第二个月
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < week_month5; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_s < 49 - week_month5) {

						if ((i_s + week_month5 + 1) % 7 == 0) {
							if (i_s >= endDay_month5) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_s];
								i++;
								cout << ' ';
							}
							i_s++;
							break;
						}
						else
						{
							if (i_s >= endDay_month5) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_s];
								i++;
							}
						}
						i_s++;
					}


					//第三个月  	
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < leep_weekday1; j++) {

							cout << hzifu[42 - 1];
							i++;
						}
					}

					while (i_t < 49 - leep_weekday1) {

						if ((i_t + leep_weekday1 + 1) % 7 == 0) {
							if (i_t >= endDay_month5) {
								cout << hzifu[42 - 1];
								i++;
							}
							else {
								cout << hzifu[i_t];
								i++;
							}
							cout << endl;
							if (i == 147) {
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
							if (i_t >= endDay_month5) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_t];
								i++;
							}
						}
						i_t++;
					}
				}



#pragma endregion




#pragma region 7 9

				cout << "Ims                                  Ihuman                               Siais                               " << endl;
				cout << "┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐" << endl;
				cout << "│ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│" << endl;
				cout << "├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤" << endl;

				i_f = 0;
				i_s = 0;
				i_t = 0;


				for (int i = 0; i < 147; ) {
					// 第一个月

					if (i < 21) {
						cout << "│";
						for (int j = 0; j < week_month6; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_f < 49 - week_month6) {
						if ((i_f + week_month6 + 1) % 7 == 0) {
							if (i_f >= endDay_month6) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_f];
								i++;
								cout << ' ';
							}
							i_f++;
							break;
						}
						else
						{
							if (i_f >= endDay_month6) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_f];
								i++;
							}
						}
						i_f++;
					}

					//第二个月
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < week_month7; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_s < 49 - week_month7) {

						if ((i_s + week_month7 + 1) % 7 == 0) {
							if (i_s >= endDay_month7) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_s];
								i++;
								cout << ' ';
							}
							i_s++;
							break;
						}
						else
						{
							if (i_s >= endDay_month7) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_s];
								i++;
							}
						}
						i_s++;
					}

					//第三个月  	
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < week_month8; j++) {

							cout << hzifu[42 - 1];
							i++;
						}
					}

					while (i_t < 49 - week_month8) {

						if ((i_t + week_month8 + 1) % 7 == 0) {
							if (i_t >= endDay_month8) {
								cout << hzifu[42 - 1];
								i++;
							}
							else {
								cout << hzifu[i_t];
								i++;
							}
							cout << endl;
							if (i == 147) {
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
							if (i_t >= endDay_month8) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_t];
								i++;
							}
						}
						i_t++;
					}
				}

#pragma endregion

				me_print_month(year_S, month_char[8]);
				break;




			case 6:

#pragma region 1 3
				cout << "Sist                                 Spst                                 Slst                                " << endl;
				cout << "┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐" << endl;
				cout << "│ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│" << endl;
				cout << "├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤" << endl;

				for (int i = 0; i < 147; ) {
					// 第一个月

					if (i < 21) {
						cout << "│";
						for (int j = 0; j < week_month1; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_f < 49 - week_month1) {
						if ((i_f + week_month1 + 1) % 7 == 0) {
							if (i_f >= endDay_month1) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_f];
								i++;
								cout << ' ';
							}
							i_f++;
							break;
						}
						else
						{
							if (i_f >= endDay_month1) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_f];
								i++;
							}
						}
						i_f++;
					}

					//第二个月
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < week_month2; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_s < 49 - week_month2) {

						if ((i_s + week_month2 + 1) % 7 == 0) {
							if (i_s >= endDay_month2) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_s];
								i++;
								cout << ' ';
							}
							i_s++;
							break;
						}
						else
						{
							if (i_s >= endDay_month2) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_s];
								i++;
							}
						}
						i_s++;
					}

					//第三个月  	
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < week_month3; j++) {

							cout << hzifu[42 - 1];
							i++;
						}
					}

					while (i_t < 49 - week_month3) {

						if ((i_t + week_month3 + 1) % 7 == 0) {
							if (i_t >= endDay_month3) {
								cout << hzifu[42 - 1];
								i++;
							}
							else {
								cout << hzifu[i_t];
								i++;
							}
							cout << endl;
							if (i == 147) {
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
							if (i_t >= endDay_month3) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_t];
								i++;
							}
						}
						i_t++;
					}
				}


#pragma endregion

#pragma region 4 6
				cout << "Sem                                  Sca                                  Ims                                 " << endl;
				cout << "┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐" << endl;
				cout << "│ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│" << endl;
				cout << "├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤" << endl;

				i_f = 0;
				i_s = 0;
				i_t = 0;
				for (int i = 0; i < 147; ) {
					// 第一个月

					if (i < 21) {
						cout << "│";
						for (int j = 0; j < week_month4; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_f < 49 - week_month4) {
						if ((i_f + week_month4 + 1) % 7 == 0) {
							if (i_f >= endDay_month4) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_f];
								i++;
								cout << ' ';
							}
							i_f++;
							break;
						}
						else
						{
							if (i_f >= endDay_month4) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_f];
								i++;
							}
						}
						i_f++;
					}

					//第二个月
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < week_month5; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_s < 49 - week_month5) {

						if ((i_s + week_month5 + 1) % 7 == 0) {
							if (i_s >= endDay_month5) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_s];
								i++;
								cout << ' ';
							}
							i_s++;
							break;
						}
						else
						{
							if (i_s >= endDay_month5) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_s];
								i++;
							}
						}
						i_s++;
					}

					//第三个月  	
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < week_month6; j++) {

							cout << hzifu[42 - 1];
							i++;
						}
					}

					while (i_t < 49 - week_month6) {

						if ((i_t + week_month6 + 1) % 7 == 0) {
							if (i_t >= endDay_month6) {
								cout << hzifu[42 - 1];
								i++;
							}
							else {
								cout << hzifu[i_t];
								i++;
							}
							cout << endl;
							if (i == 147) {
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
							if (i_t >= endDay_month6) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_t];
								i++;
							}
						}
						i_t++;
					}
				}



#pragma endregion


#pragma region 7 9

				cout << "IMS                                  Ihuman                               Siais                               " << endl;
				cout << "┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐" << endl;
				cout << "│ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│" << endl;
				cout << "├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤" << endl;

				i_f = 0;
				i_s = 0;
				i_t = 0;


				for (int i = 0; i < 147; ) {
					// 第一个月

					if (i < 21) {
						cout << "│";
						for (int j = 0; j < leep_weekday1; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_f < 49 - leep_weekday1) {
						if ((i_f + leep_weekday1 + 1) % 7 == 0) {
							if (i_f >= endDay_month6) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_f];
								i++;
								cout << ' ';
							}
							i_f++;
							break;
						}
						else
						{
							if (i_f >= endDay_month6) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_f];
								i++;
							}
						}
						i_f++;
					}

					//第二个月
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < week_month7; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_s < 49 - week_month7) {

						if ((i_s + week_month7 + 1) % 7 == 0) {
							if (i_s >= endDay_month7) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_s];
								i++;
								cout << ' ';
							}
							i_s++;
							break;
						}
						else
						{
							if (i_s >= endDay_month7) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_s];
								i++;
							}
						}
						i_s++;
					}

					//第三个月  	
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < week_month8; j++) {

							cout << hzifu[42 - 1];
							i++;
						}
					}

					while (i_t < 49 - week_month8) {

						if ((i_t + week_month8 + 1) % 7 == 0) {
							if (i_t >= endDay_month8) {
								cout << hzifu[42 - 1];
								i++;
							}
							else {
								cout << hzifu[i_t];
								i++;
							}
							cout << endl;
							if (i == 147) {
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
							if (i_t >= endDay_month8) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_t];
								i++;
							}
						}
						i_t++;
					}
				}

#pragma endregion

				me_print_month(year_S, month_char[8]);
				break;


			case 7:

#pragma region 1 3
				cout << "Sist                                 Spst                                 Slst                                " << endl;
				cout << "┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐" << endl;
				cout << "│ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│" << endl;
				cout << "├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤" << endl;

				for (int i = 0; i < 147; ) {
					// 第一个月

					if (i < 21) {
						cout << "│";
						for (int j = 0; j < week_month1; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_f < 49 - week_month1) {
						if ((i_f + week_month1 + 1) % 7 == 0) {
							if (i_f >= endDay_month1) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_f];
								i++;
								cout << ' ';
							}
							i_f++;
							break;
						}
						else
						{
							if (i_f >= endDay_month1) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_f];
								i++;
							}
						}
						i_f++;
					}

					//第二个月
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < week_month2; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_s < 49 - week_month2) {

						if ((i_s + week_month2 + 1) % 7 == 0) {
							if (i_s >= endDay_month2) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_s];
								i++;
								cout << ' ';
							}
							i_s++;
							break;
						}
						else
						{
							if (i_s >= endDay_month2) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_s];
								i++;
							}
						}
						i_s++;
					}

					//第三个月  	
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < week_month3; j++) {

							cout << hzifu[42 - 1];
							i++;
						}
					}

					while (i_t < 49 - week_month3) {

						if ((i_t + week_month3 + 1) % 7 == 0) {
							if (i_t >= endDay_month3) {
								cout << hzifu[42 - 1];
								i++;
							}
							else {
								cout << hzifu[i_t];
								i++;
							}
							cout << endl;
							if (i == 147) {
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
							if (i_t >= endDay_month3) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_t];
								i++;
							}
						}
						i_t++;
					}
				}


#pragma endregion

#pragma region 4 6
				cout << "Sem                                  Sca                                  Ims                                 " << endl;
				cout << "┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐" << endl;
				cout << "│ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│" << endl;
				cout << "├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤" << endl;

				i_f = 0;
				i_s = 0;
				i_t = 0;
				for (int i = 0; i < 147; ) {
					// 第一个月

					if (i < 21) {
						cout << "│";
						for (int j = 0; j < week_month4; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_f < 49 - week_month4) {
						if ((i_f + week_month4 + 1) % 7 == 0) {
							if (i_f >= endDay_month4) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_f];
								i++;
								cout << ' ';
							}
							i_f++;
							break;
						}
						else
						{
							if (i_f >= endDay_month4) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_f];
								i++;
							}
						}
						i_f++;
					}

					//第二个月
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < week_month5; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_s < 49 - week_month5) {

						if ((i_s + week_month5 + 1) % 7 == 0) {
							if (i_s >= endDay_month5) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_s];
								i++;
								cout << ' ';
							}
							i_s++;
							break;
						}
						else
						{
							if (i_s >= endDay_month5) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_s];
								i++;
							}
						}
						i_s++;
					}

					//第三个月  	
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < week_month6; j++) {

							cout << hzifu[42 - 1];
							i++;
						}
					}

					while (i_t < 49 - week_month6) {

						if ((i_t + week_month6 + 1) % 7 == 0) {
							if (i_t >= endDay_month6) {
								cout << hzifu[42 - 1];
								i++;
							}
							else {
								cout << hzifu[i_t];
								i++;
							}
							cout << endl;
							if (i == 147) {
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
							if (i_t >= endDay_month6) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_t];
								i++;
							}
						}
						i_t++;
					}
				}



#pragma endregion


#pragma region 7 9

				cout << "Ihuman                               IHUMAN                               Siais                               " << endl;
				cout << "┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐" << endl;
				cout << "│ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│" << endl;
				cout << "├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤" << endl;

				i_f = 0;
				i_s = 0;
				i_t = 0;


				for (int i = 0; i < 147; ) {
					// 第一个月


					if (i < 21) {
						cout << "│";
						for (int j = 0; j < week_month7; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_f < 49 - week_month7) {
						if ((i_f + week_month7 + 1) % 7 == 0) {
							if (i_f >= endDay_month7) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_f];
								i++;
								cout << ' ';
							}
							i_f++;
							break;
						}
						else
						{
							if (i_f >= endDay_month7) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_f];
								i++;
							}
						}
						i_f++;
					}
					//第二个月
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < leep_weekday1; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_s < 49 - leep_weekday1) {

						if ((i_s + leep_weekday1 + 1) % 7 == 0) {
							if (i_s >= endDay_month7) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_s];
								i++;
								cout << ' ';
							}
							i_s++;
							break;
						}
						else
						{
							if (i_s >= endDay_month7) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_s];
								i++;
							}
						}
						i_s++;
					}

					//第三个月  	
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < week_month8; j++) {

							cout << hzifu[42 - 1];
							i++;
						}
					}

					while (i_t < 49 - week_month8) {

						if ((i_t + week_month8 + 1) % 7 == 0) {
							if (i_t >= endDay_month8) {
								cout << hzifu[42 - 1];
								i++;
							}
							else {
								cout << hzifu[i_t];
								i++;
							}
							cout << endl;
							if (i == 147) {
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
							if (i_t >= endDay_month8) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_t];
								i++;
							}
						}
						i_t++;
					}
				}

#pragma endregion

				me_print_month(year_S, month_char[8]);
				break;




			case 8:

#pragma region 1 3
				cout << "Sist                                 Spst                                 Slst                                " << endl;
				cout << "┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐" << endl;
				cout << "│ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│" << endl;
				cout << "├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤" << endl;

				for (int i = 0; i < 147; ) {
					// 第一个月

					if (i < 21) {
						cout << "│";
						for (int j = 0; j < week_month1; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_f < 49 - week_month1) {
						if ((i_f + week_month1 + 1) % 7 == 0) {
							if (i_f >= endDay_month1) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_f];
								i++;
								cout << ' ';
							}
							i_f++;
							break;
						}
						else
						{
							if (i_f >= endDay_month1) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_f];
								i++;
							}
						}
						i_f++;
					}

					//第二个月
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < week_month2; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_s < 49 - week_month2) {

						if ((i_s + week_month2 + 1) % 7 == 0) {
							if (i_s >= endDay_month2) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_s];
								i++;
								cout << ' ';
							}
							i_s++;
							break;
						}
						else
						{
							if (i_s >= endDay_month2) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_s];
								i++;
							}
						}
						i_s++;
					}

					//第三个月  	
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < week_month3; j++) {

							cout << hzifu[42 - 1];
							i++;
						}
					}

					while (i_t < 49 - week_month3) {

						if ((i_t + week_month3 + 1) % 7 == 0) {
							if (i_t >= endDay_month3) {
								cout << hzifu[42 - 1];
								i++;
							}
							else {
								cout << hzifu[i_t];
								i++;
							}
							cout << endl;
							if (i == 147) {
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
							if (i_t >= endDay_month3) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_t];
								i++;
							}
						}
						i_t++;
					}
				}


#pragma endregion

#pragma region 4 6
				cout << "Sem                                  Sca                                  Ims                                 " << endl;
				cout << "┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐" << endl;
				cout << "│ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│" << endl;
				cout << "├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤" << endl;

				i_f = 0;
				i_s = 0;
				i_t = 0;
				for (int i = 0; i < 147; ) {
					// 第一个月

					if (i < 21) {
						cout << "│";
						for (int j = 0; j < week_month4; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_f < 49 - week_month4) {
						if ((i_f + week_month4 + 1) % 7 == 0) {
							if (i_f >= endDay_month4) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_f];
								i++;
								cout << ' ';
							}
							i_f++;
							break;
						}
						else
						{
							if (i_f >= endDay_month4) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_f];
								i++;
							}
						}
						i_f++;
					}

					//第二个月
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < week_month5; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_s < 49 - week_month5) {

						if ((i_s + week_month5 + 1) % 7 == 0) {
							if (i_s >= endDay_month5) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_s];
								i++;
								cout << ' ';
							}
							i_s++;
							break;
						}
						else
						{
							if (i_s >= endDay_month5) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_s];
								i++;
							}
						}
						i_s++;
					}

					//第三个月  	
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < week_month6; j++) {

							cout << hzifu[42 - 1];
							i++;
						}
					}

					while (i_t < 49 - week_month6) {

						if ((i_t + week_month6 + 1) % 7 == 0) {
							if (i_t >= endDay_month6) {
								cout << hzifu[42 - 1];
								i++;
							}
							else {
								cout << hzifu[i_t];
								i++;
							}
							cout << endl;
							if (i == 147) {
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
							if (i_t >= endDay_month6) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_t];
								i++;
							}
						}
						i_t++;
					}
				}



#pragma endregion


#pragma region 7 9

				cout << "Ihuman                               Siais                                SIAIS                               " << endl;
				cout << "┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐" << endl;
				cout << "│ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│" << endl;
				cout << "├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤" << endl;

				i_f = 0;
				i_s = 0;
				i_t = 0;


				for (int i = 0; i < 147; ) {
					// 第一个月


					if (i < 21) {
						cout << "│";
						for (int j = 0; j < week_month7; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_f < 49 - week_month7) {
						if ((i_f + week_month7 + 1) % 7 == 0) {
							if (i_f >= endDay_month7) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_f];
								i++;
								cout << ' ';
							}
							i_f++;
							break;
						}
						else
						{
							if (i_f >= endDay_month7) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_f];
								i++;
							}
						}
						i_f++;
					}
					//第二个月
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < week_month8; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_s < 49 - week_month8) {

						if ((i_s + week_month8 + 1) % 7 == 0) {
							if (i_s >= endDay_month8) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_s];
								i++;
								cout << ' ';
							}
							i_s++;
							break;
						}
						else
						{
							if (i_s >= endDay_month8) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_s];
								i++;
							}
						}
						i_s++;
					}

					//第三个月  	
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < leep_weekday1; j++) {

							cout << hzifu[42 - 1];
							i++;
						}
					}

					while (i_t < 49 - leep_weekday1) {

						if ((i_t + leep_weekday1 + 1) % 7 == 0) {
							if (i_t >= endDay_month8) {
								cout << hzifu[42 - 1];
								i++;
							}
							else {
								cout << hzifu[i_t];
								i++;
							}
							cout << endl;
							if (i == 147) {
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
							if (i_t >= endDay_month8) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_t];
								i++;
							}
						}
						i_t++;
					}
				}

#pragma endregion

				me_print_month(year_S, month_char[8]);
				break;



			case 9:

#pragma region 1 3
				cout << "Sist                                 Spst                                 Slst                                " << endl;
				cout << "┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐" << endl;
				cout << "│ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│" << endl;
				cout << "├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤" << endl;

				for (int i = 0; i < 147; ) {
					// 第一个月

					if (i < 21) {
						cout << "│";
						for (int j = 0; j < week_month1; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_f < 49 - week_month1) {
						if ((i_f + week_month1 + 1) % 7 == 0) {
							if (i_f >= endDay_month1) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_f];
								i++;
								cout << ' ';
							}
							i_f++;
							break;
						}
						else
						{
							if (i_f >= endDay_month1) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_f];
								i++;
							}
						}
						i_f++;
					}

					//第二个月
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < week_month2; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_s < 49 - week_month2) {

						if ((i_s + week_month2 + 1) % 7 == 0) {
							if (i_s >= endDay_month2) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_s];
								i++;
								cout << ' ';
							}
							i_s++;
							break;
						}
						else
						{
							if (i_s >= endDay_month2) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_s];
								i++;
							}
						}
						i_s++;
					}

					//第三个月  	
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < week_month3; j++) {

							cout << hzifu[42 - 1];
							i++;
						}
					}

					while (i_t < 49 - week_month3) {

						if ((i_t + week_month3 + 1) % 7 == 0) {
							if (i_t >= endDay_month3) {
								cout << hzifu[42 - 1];
								i++;
							}
							else {
								cout << hzifu[i_t];
								i++;
							}
							cout << endl;
							if (i == 147) {
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
							if (i_t >= endDay_month3) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_t];
								i++;
							}
						}
						i_t++;
					}
				}


#pragma endregion

#pragma region 4 6
				cout << "Sem                                  Sca                                  Ims                                 " << endl;
				cout << "┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐" << endl;
				cout << "│ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│" << endl;
				cout << "├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤" << endl;

				i_f = 0;
				i_s = 0;
				i_t = 0;
				for (int i = 0; i < 147; ) {
					// 第一个月

					if (i < 21) {
						cout << "│";
						for (int j = 0; j < week_month4; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_f < 49 - week_month4) {
						if ((i_f + week_month4 + 1) % 7 == 0) {
							if (i_f >= endDay_month4) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_f];
								i++;
								cout << ' ';
							}
							i_f++;
							break;
						}
						else
						{
							if (i_f >= endDay_month4) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_f];
								i++;
							}
						}
						i_f++;
					}

					//第二个月
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < week_month5; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_s < 49 - week_month5) {

						if ((i_s + week_month5 + 1) % 7 == 0) {
							if (i_s >= endDay_month5) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_s];
								i++;
								cout << ' ';
							}
							i_s++;
							break;
						}
						else
						{
							if (i_s >= endDay_month5) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_s];
								i++;
							}
						}
						i_s++;
					}

					//第三个月  	
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < week_month6; j++) {

							cout << hzifu[42 - 1];
							i++;
						}
					}

					while (i_t < 49 - week_month6) {

						if ((i_t + week_month6 + 1) % 7 == 0) {
							if (i_t >= endDay_month6) {
								cout << hzifu[42 - 1];
								i++;
							}
							else {
								cout << hzifu[i_t];
								i++;
							}
							cout << endl;
							if (i == 147) {
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
							if (i_t >= endDay_month6) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_t];
								i++;
							}
						}
						i_t++;
					}
				}



#pragma endregion

#pragma region 7 9

				cout << "Ihuman                               Siais                                Ih                                  " << endl;
				cout << "┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐" << endl;
				cout << "│ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│" << endl;
				cout << "├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤" << endl;

				i_f = 0;
				i_s = 0;
				i_t = 0;


				for (int i = 0; i < 147; ) {
					// 第一个月

					if (i < 21) {
						cout << "│";
						for (int j = 0; j < week_month7; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_f < 49 - week_month7) {
						if ((i_f + week_month7 + 1) % 7 == 0) {
							if (i_f >= endDay_month7) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_f];
								i++;
								cout << ' ';
							}
							i_f++;
							break;
						}
						else
						{
							if (i_f >= endDay_month7) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_f];
								i++;
							}
						}
						i_f++;
					}

					//第二个月
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < week_month8; j++) {

							cout << hzifu[42 - 1];
							i++;

						}
					}

					while (i_s < 49 - week_month8) {

						if ((i_s + week_month8 + 1) % 7 == 0) {
							if (i_s >= endDay_month8) {
								cout << hzifu[42 - 1];
								i++;
								cout << ' ';
							}
							else {
								cout << hzifu[i_s];
								i++;
								cout << ' ';
							}
							i_s++;
							break;
						}
						else
						{
							if (i_s >= endDay_month8) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_s];
								i++;
							}
						}
						i_s++;
					}

					//第三个月  	
					cout << "│";
					if (i < 21) {

						for (int j = 0; j < week_month9; j++) {

							cout << hzifu[42 - 1];
							i++;
						}
					}

					while (i_t < 49 - week_month9) {

						if ((i_t + week_month9 + 1) % 7 == 0) {
							if (i_t >= endDay_month9) {
								cout << hzifu[42 - 1];
								i++;
							}
							else {
								cout << hzifu[i_t];
								i++;
							}
							cout << endl;
							if (i == 147) {
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
							if (i_t >= endDay_month9) {
								cout << hzifu[42 - 1];
								i++;
							}
							else
							{
								cout << hzifu[i_t];
								i++;
							}
						}
						i_t++;
					}
				}

#pragma endregion

				cout << "IH                                  " << endl;
				cout << "┌────┬────┬────┬────┬────┬────┬────┐" << endl;
				cout << "│ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│" << endl;
				cout << "├────┼────┼────┼────┼────┼────┼────┤" << endl;



				cout << "│";
				for (int j = 0; j < leep_weekday1; j++) {
					cout << hzifu[42 - 1];
				}

				for (int i = 0; i < 48 - leep_weekday1; i++) { //49代表有49个格子
					if ((i + leep_weekday1 + 1) % 7 == 0) {
						if (i >= endDay) {
							cout << hzifu[42 - 1];
						}
						else {
							cout << hzifu[i];

						}
						cout << endl;
						cout << "├────┼────┼────┼────┼────┼────┼────┤" << endl;
						cout << "│";
					}
					else
					{
						if (i >= endDay) {
							cout << hzifu[42 - 1];
						}
						else
						{
							cout << hzifu[i];
						}

					}
				}
				cout << hzifu[41] << endl;
				cout << "└────┴────┴────┴────┴────┴────┴────┘" << endl;
				break;

			default:
				break;
			}
		}
		else
		{
			int i_f = 0;
			int i_s = 0;
			int i_t = 0;
#pragma region 1 3
			cout << "Sist                                 Spst                                 Slst                                " << endl;
			cout << "┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐" << endl;
			cout << "│ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│" << endl;
			cout << "├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤" << endl;

			for (int i = 0; i < 147; ) {
				// 第一个月

				if (i < 21) {
					cout << "│";
					for (int j = 0; j < week_month1; j++) {

						cout << hzifu[42 - 1];
						i++;

					}
				}

				while (i_f < 49 - week_month1) {
					if ((i_f + week_month1 + 1) % 7 == 0) {
						if (i_f >= endDay_month1) {
							cout << hzifu[42 - 1];
							i++;
							cout << ' ';
						}
						else {
							cout << hzifu[i_f];
							i++;
							cout << ' ';
						}
						i_f++;
						break;
					}
					else
					{
						if (i_f >= endDay_month1) {
							cout << hzifu[42 - 1];
							i++;
						}
						else
						{
							cout << hzifu[i_f];
							i++;
						}
					}
					i_f++;
				}

				//第二个月
				cout << "│";
				if (i < 21) {

					for (int j = 0; j < week_month2; j++) {

						cout << hzifu[42 - 1];
						i++;

					}
				}

				while (i_s < 49 - week_month2) {

					if ((i_s + week_month2 + 1) % 7 == 0) {
						if (i_s >= endDay_month2) {
							cout << hzifu[42 - 1];
							i++;
							cout << ' ';
						}
						else {
							cout << hzifu[i_s];
							i++;
							cout << ' ';
						}
						i_s++;
						break;
					}
					else
					{
						if (i_s >= endDay_month2) {
							cout << hzifu[42 - 1];
							i++;
						}
						else
						{
							cout << hzifu[i_s];
							i++;
						}
					}
					i_s++;
				}

				//第三个月  	
				cout << "│";
				if (i < 21) {

					for (int j = 0; j < week_month3; j++) {

						cout << hzifu[42 - 1];
						i++;
					}
				}

				while (i_t < 49 - week_month3) {

					if ((i_t + week_month3 + 1) % 7 == 0) {
						if (i_t >= endDay_month3) {
							cout << hzifu[42 - 1];
							i++;
						}
						else {
							cout << hzifu[i_t];
							i++;
						}
						cout << endl;
						if (i == 147) {
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
						if (i_t >= endDay_month3) {
							cout << hzifu[42 - 1];
							i++;
						}
						else
						{
							cout << hzifu[i_t];
							i++;
						}
					}
					i_t++;
				}
			}


#pragma endregion

#pragma region 4 6
			cout << "Sem                                  Sca                                  Ims                                 " << endl;
			cout << "┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐" << endl;
			cout << "│ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│" << endl;
			cout << "├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤" << endl;

			i_f = 0;
			i_s = 0;
			i_t = 0;
			for (int i = 0; i < 147; ) {
				// 第一个月

				if (i < 21) {
					cout << "│";
					for (int j = 0; j < week_month4; j++) {

						cout << hzifu[42 - 1];
						i++;

					}
				}

				while (i_f < 49 - week_month4) {
					if ((i_f + week_month4 + 1) % 7 == 0) {
						if (i_f >= endDay_month4) {
							cout << hzifu[42 - 1];
							i++;
							cout << ' ';
						}
						else {
							cout << hzifu[i_f];
							i++;
							cout << ' ';
						}
						i_f++;
						break;
					}
					else
					{
						if (i_f >= endDay_month4) {
							cout << hzifu[42 - 1];
							i++;
						}
						else
						{
							cout << hzifu[i_f];
							i++;
						}
					}
					i_f++;
				}

				//第二个月
				cout << "│";
				if (i < 21) {

					for (int j = 0; j < week_month5; j++) {

						cout << hzifu[42 - 1];
						i++;

					}
				}

				while (i_s < 49 - week_month5) {

					if ((i_s + week_month5 + 1) % 7 == 0) {
						if (i_s >= endDay_month5) {
							cout << hzifu[42 - 1];
							i++;
							cout << ' ';
						}
						else {
							cout << hzifu[i_s];
							i++;
							cout << ' ';
						}
						i_s++;
						break;
					}
					else
					{
						if (i_s >= endDay_month5) {
							cout << hzifu[42 - 1];
							i++;
						}
						else
						{
							cout << hzifu[i_s];
							i++;
						}
					}
					i_s++;
				}

				//第三个月  	
				cout << "│";
				if (i < 21) {

					for (int j = 0; j < week_month6; j++) {

						cout << hzifu[42 - 1];
						i++;
					}
				}

				while (i_t < 49 - week_month6) {

					if ((i_t + week_month6 + 1) % 7 == 0) {
						if (i_t >= endDay_month6) {
							cout << hzifu[42 - 1];
							i++;
						}
						else {
							cout << hzifu[i_t];
							i++;
						}
						cout << endl;
						if (i == 147) {
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
						if (i_t >= endDay_month6) {
							cout << hzifu[42 - 1];
							i++;
						}
						else
						{
							cout << hzifu[i_t];
							i++;
						}
					}
					i_t++;
				}
			}



#pragma endregion

#pragma region 7 9

			cout << "Ihuman                               Siais                                Ih                                  " << endl;
			cout << "┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐ ┌────┬────┬────┬────┬────┬────┬────┐" << endl;
			cout << "│ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│ │ Sun│ Mon│Tues│ Wed│Thur│ Fri│ Sat│" << endl;
			cout << "├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤ ├────┼────┼────┼────┼────┼────┼────┤" << endl;

			i_f = 0;
			i_s = 0;
			i_t = 0;


			for (int i = 0; i < 147; ) {
				// 第一个月

				if (i < 21) {
					cout << "│";
					for (int j = 0; j < week_month7; j++) {

						cout << hzifu[42 - 1];
						i++;

					}
				}

				while (i_f < 49 - week_month7) {
					if ((i_f + week_month7 + 1) % 7 == 0) {
						if (i_f >= endDay_month7) {
							cout << hzifu[42 - 1];
							i++;
							cout << ' ';
						}
						else {
							cout << hzifu[i_f];
							i++;
							cout << ' ';
						}
						i_f++;
						break;
					}
					else
					{
						if (i_f >= endDay_month7) {
							cout << hzifu[42 - 1];
							i++;
						}
						else
						{
							cout << hzifu[i_f];
							i++;
						}
					}
					i_f++;
				}

				//第二个月
				cout << "│";
				if (i < 21) {

					for (int j = 0; j < week_month8; j++) {

						cout << hzifu[42 - 1];
						i++;

					}
				}

				while (i_s < 49 - week_month8) {

					if ((i_s + week_month8 + 1) % 7 == 0) {
						if (i_s >= endDay_month8) {
							cout << hzifu[42 - 1];
							i++;
							cout << ' ';
						}
						else {
							cout << hzifu[i_s];
							i++;
							cout << ' ';
						}
						i_s++;
						break;
					}
					else
					{
						if (i_s >= endDay_month8) {
							cout << hzifu[42 - 1];
							i++;
						}
						else
						{
							cout << hzifu[i_s];
							i++;
						}
					}
					i_s++;
				}

				//第三个月  	
				cout << "│";
				if (i < 21) {

					for (int j = 0; j < week_month9; j++) {

						cout << hzifu[42 - 1];
						i++;
					}
				}

				while (i_t < 49 - week_month9) {

					if ((i_t + week_month9 + 1) % 7 == 0) {
						if (i_t >= endDay_month9) {
							cout << hzifu[42 - 1];
							i++;
						}
						else {
							cout << hzifu[i_t];
							i++;
						}
						cout << endl;
						if (i == 147) {
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
						if (i_t >= endDay_month9) {
							cout << hzifu[42 - 1];
							i++;
						}
						else
						{
							cout << hzifu[i_t];
							i++;
						}
					}
					i_t++;
				}
			}

#pragma endregion

		}




	}

	bool go_to(int year, char* monthnew, int day) {

		string sm = monthnew;
		bool month_judge = 1;
		int mnum = 999;



		int run_m = (year - digit_sum(year)) % 9 + 1;
		for (int i = 0; i < 18; i++) {
			if (sm == run_sm_string[i]) {
				mnum = i;
				break;
			}
		}
		if (mnum == 999) {
			month_judge = 0;
		}
		bool leepy = scheak_leepyear(year);
		if (leepy) {
			if (mnum > 8) {
				mnum -= 8;
				if (mnum != run_m) {
					month_judge = 0;
				}
				else
				{
					month_judge = 1;
				}
			}
		}
		else {
			if (mnum > 8) {
				month_judge = 0;
			}
		}

		int numd = sendDay(year, monthnew);
		if (year <= 1000362 && year >= 1) {
			if (month_judge) {
				if (day >= 1 && day <= numd) {
					year_S = year;
					month_S = monthnew;
					day_S = day;
					int totalday_SforG = ScalTotalday(year, monthnew, day);
					Gregorian::gdayToDate(totalday_SforG);
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

	bool pass_day(int n) {


		char *month_char[18] = { (char*)"Sist",(char*)"Spst",(char*)"Slst",(char*)"Sem",(char*)"Sca",(char*)"Ims",(char*)"Ihuman",(char*)"Siais",(char*)"Ih",(char*)"SIST" ,(char*)"SPST",(char*)"SLST",(char*)"SEM",(char*)"SCA",(char*)"IMS",(char*)"IHUMAN",(char*)"SIAIS",(char*)"IH" };

		//int totalDay = ScalTotalday(year_S, month_S, day_S);
		string sm = month_S;
		int y = year_S;
		bool leep = scheak_leepyear(y);

		///保存原来日期
		int or_y = year_S;
		int or_m = 0;
		for (int i = 0; i < 18; i++) {
			if (sm == run_sm_string[i]) {
				or_m = i;
				break;
			}
		}
		int or_d = day_S;
		///结束原日期

		int endDaying = 0;
		int numOfm = 0; //代表当前在第几个月,并且以下代码numofm都会表示真实月份



		if (n > 40200 || n < -40200) {// 处理超大数字
			int totalday = n + ScalTotalday(year_S, month_S, day_S);
			if (totalday >= 1 && totalday <= 365241885) {
				DayToShangTechdate(totalday);
			}
			else
			{
				baocuo_day = 1;
			}

		}
		else
		{
			if (n >= 0) {
				endDaying = sendDay(year_S, month_S);
				n += day_S;
				if (n > endDaying) {
					while (true)
					{
						Scal_pass_month(1);
						//pass_month(1);
						n -= endDaying;
						endDaying = sendDay(year_S, month_S);
						if (n <= endDaying) {
							break;
						}
					}
				}
				day_S = n;
			}
			else
			{
				n += day_S;
				if (n < 1) {
					while (true)
					{
						Scal_pass_month(-1);
						//pass_month(-1);
						endDaying = sendDay(year_S, month_S);
						n += endDaying;
						if (n > 0) {
							break;
						}
					}
				}
				day_S = n;
			}


		}





		if (baocuo_month == 0 && baocuo_day == 0) {

			int totalday_SforG = ScalTotalday(year_S, month_S, day_S);
			Gregorian::gdayToDate(totalday_SforG);
			return true;
		}
		else
		{
			baocuo_month = 0;
			baocuo_day = 0;
			year_S = or_y;
			day_S = or_d;
			month_S = (char*)month_char[or_m];
			int totalday_SforG = ScalTotalday(year_S, month_S, day_S);
			Gregorian::gdayToDate(totalday_SforG);
			//cout << year_S << ' ' << *month_S << *(month_S + 1) << ' ' << day_S << endl;
			return false;
		}


	}

	bool pass_month(int n) {




		char *month_char[18] = { (char*)"Sist",(char*)"Spst",(char*)"Slst",(char*)"Sem",(char*)"Sca",
			(char*)"Ims",(char*)"Ihuman",(char*)"Siais",(char*)"Ih",(char*)"SIST" ,(char*)"SPST",
			(char*)"SLST",(char*)"SEM",(char*)"SCA",(char*)"IMS",(char*)"IHUMAN",(char*)"SIAIS",(char*)"IH" };

		string sm = month_S;
		int y = year_S;
		bool leep = scheak_leepyear(y);

		///保存原来日期
		int or_y = year_S;
		int or_m = 0;
		int or_d = day_S;
		for (int i = 0; i < 18; i++) {
			if (sm == run_sm_string[i]) {
				or_m = i;
				break;
			}
		}
		///结束保存

		int numOfm = 0; //代表当前在第几个月,并且以下代码numofm都会表示真实月份

		if (n >= 0) {
			if (leep) {
				int judge_initial = (y - digit_sum(y)) % 9 + 1;
				for (int i = 0; i < 18; i++) {
					if (sm == run_sm_string[i]) {
						numOfm = i;
						break;
					}
				}

				if (numOfm > 8) {
					numOfm -= 7; // 变成闰月的月份
				}
				else {
					numOfm++; // 符合真正月份
					if (numOfm > judge_initial) {
						numOfm++;
					}
				}

				numOfm += n;
				if (numOfm > 10) {
					Scal_pass_year(1);
					numOfm -= 10;
				}
				while (true)
				{
					leep = scheak_leepyear(year_S);
					if (leep) {
						if (numOfm <= 10) {
							break;
						}
						else
						{
							numOfm -= 10;
							Scal_pass_year(1);
						}
					}
					else
					{
						if (numOfm <= 9) {
							break;
						}
						else
						{
							Scal_pass_year(1);
							numOfm -= 9;
						}
					}
				}
				// 处理一年以内
				leep = scheak_leepyear(year_S);
				if (leep) {
					int judge = (year_S - digit_sum(year_S)) % 9 + 1;
					if (numOfm > judge + 1) {
						month_S = (char*)month_char[numOfm - 2];
					}
					else if (numOfm == judge + 1)
					{
						month_S = (char*)month_char[judge + 8];
					}
					else
					{
						month_S = (char*)month_char[numOfm - 1];
					}
				}
				else
				{
					month_S = (char*)month_char[numOfm - 1];
				}
			}
			else
			{
				for (int i = 0; i < 9; i++) {
					if (sm == sm_stirng[i]) {
						numOfm = i;
						break;
					}
				}
				numOfm++; // 符合真正月份
				numOfm += n;
				if (numOfm > 9) {
					Scal_pass_year(1);
					numOfm -= 9;
				}
				while (true)
				{
					leep = scheak_leepyear(year_S);
					if (leep) {
						if (numOfm <= 10) {
							break;
						}
						else
						{
							numOfm -= 10;
							Scal_pass_year(1);
						}
					}
					else
					{
						if (numOfm <= 9) {
							break;
						}
						else
						{
							Scal_pass_year(1);
							numOfm -= 9;
						}
					}
				}
				// 处理一年以内
				leep = scheak_leepyear(year_S);
				if (leep) {
					int judge = (year_S - digit_sum(year_S)) % 9 + 1;
					if (numOfm > judge + 1) {
						month_S = (char*)month_char[numOfm - 2];
					}
					else if (numOfm == judge + 1)
					{
						month_S = (char*)month_char[judge + 8];
					}
					else
					{
						month_S = (char*)month_char[numOfm - 1];
					}
				}
				else
				{
					month_S = (char*)month_char[numOfm - 1];
				}
			}
		}
		else
		{
			if (leep) {
				int judge_initial = (y - digit_sum(y)) % 9 + 1;
				for (int i = 0; i < 18; i++) {
					if (sm == run_sm_string[i]) {
						numOfm = i;
						break;
					}
				}

				if (numOfm > 8) {
					numOfm -= 7; // 变成闰月的月份
				}
				else {
					numOfm++; // 符合真正月份
					if (numOfm > judge_initial) {
						numOfm++;
					}
				}
				numOfm += n;
				if (numOfm >= 1) {
					if (numOfm > judge_initial + 1) {
						month_S = (char*)month_char[numOfm - 2];
					}
					else if (numOfm == judge_initial + 1) {
						month_S = (char*)month_char[judge_initial + 8];
					}
					else {
						month_S = (char*)month_char[numOfm - 1];
					}
				}
				else {

					while (true) {
						Scal_pass_year(-1);
						leep = scheak_leepyear(year_S);
						if (leep) {
							numOfm += 10;

						}
						else {
							numOfm += 9;
						}
						if (numOfm > 0) {
							break;
						}
					}


					// 处理一年以内
					leep = scheak_leepyear(year_S);
					if (leep) {
						int judge = (year_S - digit_sum(year_S)) % 9 + 1;
						if (numOfm > judge + 1) {
							month_S = (char*)month_char[numOfm - 2];
						}
						else if (numOfm == judge + 1)
						{
							month_S = (char*)month_char[judge + 8];
						}
						else
						{
							month_S = (char*)month_char[numOfm - 1];
						}
					}
					else
					{
						month_S = (char*)month_char[numOfm - 1];
					}

				}

			}
			else
			{

				for (int i = 0; i < 9; i++) {
					if (sm == sm_stirng[i]) {
						numOfm = i;
						break;
					}
				}
				numOfm++; // 符合真正月份
				numOfm += n;
				if (numOfm >= 1) {
					month_S = (char*)month_char[numOfm - 1];
				}
				else
				{
					while (true) {
						Scal_pass_year(-1);
						leep = scheak_leepyear(year_S);
						if (leep) {
							numOfm += 10;

						}
						else {
							numOfm += 9;
						}
						if (numOfm > 0) {
							break;
						}
					}


					// 处理一年以内
					leep = scheak_leepyear(year_S);
					if (leep) {
						int judge = (year_S - digit_sum(year_S)) % 9 + 1;
						if (numOfm > judge + 1) {
							month_S = (char*)month_char[numOfm - 2];
						}
						else if (numOfm == judge + 1)
						{
							month_S = (char*)month_char[judge + 8];
						}
						else
						{
							month_S = (char*)month_char[numOfm - 1];
						}
					}
					else
					{
						month_S = (char*)month_char[numOfm - 1];
					}


				}

			}

		}

		if (baocuo_year == 0) {
			day_S = 1;
			int totalday_SforG = ScalTotalday(year_S, month_S, day_S);
			Gregorian::gdayToDate(totalday_SforG);
			return true;
		}
		else
		{
			baocuo_year = 0;
			baocuo_month++;
			year_S = or_y;
			day_S = or_d;
			month_S = (char*)month_char[or_m];
			int totalday_SforG = ScalTotalday(year_S, month_S, day_S);
			Gregorian::gdayToDate(totalday_SforG);

			return false;
		}

	}

	bool pass_year(int n) {
		char *month_char[] = { (char*)"Sist",(char*)"Spst",(char*)"Slst",(char*)"Sem",(char*)"Sca",(char*)"Ims",(char*)"Ihuman",(char*)"Siais",(char*)"Ih" };


		string sm = month_S;
		///保存原来日期
		int or_y = year_S;
		int or_m = 0;
		int or_d = day_S;
		for (int i = 0; i < 18; i++) {
			if (sm == run_sm_string[i]) {
				or_m = i;
				break;
			}
		}
		///结束保存

		year_S += n;
		if (year_S <= 1000362 && year_S >= 1) {
			month_S = (char*)month_char[0];
			day_S = 1;
			int totalday_SforG = ScalTotalday(year_S, month_S, day_S);
			Gregorian::gdayToDate(totalday_SforG);
			//cout << year_S << ' ' << *month_S << *(month_S + 1) << ' '<< day_S << endl;
			return true;
		}
		else
		{
			year_S = or_y;
			day_S = or_d;
			month_S = (char*)month_char[or_m];
			baocuo_year = baocuo_year + 1;
			int totalday_SforG = ScalTotalday(year_S, month_S, day_S);
			Gregorian::gdayToDate(totalday_SforG);
			return false;
		}
	}



	virtual void callback() {
		DayToShangTechdate(GtotalDay);
	}

};

//TEMPLATE END

//APPEND BEGIN





//
//
//// //Use this main function
//int main()
//{
//	int year, day, n;
//	std::string calendar, f;
//	char month[10];
//	char newmonth[10];
//	std::cin >> f;
//	std::cin >> year >> month >> day;
//	Shanghaitech date(year, month, day);
//	Shanghaitech* S = &date;
//	Gregorian* G = &date;
//	std::cin >> calendar;
//	std::cin >> f;
//	while (!std::cin.eof()) {
//		if (f == "pass_day") {
//			std::cin >> n;
//			if (calendar == "G") G->pass_day(n); else S->pass_day(n);
//		}
//		else if (f == "pass_month") {
//			std::cin >> n;
//			if (calendar == "G") G->pass_month(n); else S->pass_month(n);
//		}
//		else if (f == "pass_year") {
//			std::cin >> n;
//			if (calendar == "G") G->pass_year(n); else S->pass_year(n);
//		}
//		else if (f == "print_today") {
//			if (calendar == "G") G->print_today(); else S->print_today();
//		}
//		else if (f == "print_month") {
//			if (calendar == "G") G->print_month(); else S->print_month();
//		}
//		else if (f == "print_year") {
//			if (calendar == "G") G->print_year(); else S->print_year();
//		}
//		else if (f == "go_to") {
//			std::cin >> year >> newmonth >> day;
//			if (calendar == "G") G->go_to(year, newmonth, day); else S->go_to(year, newmonth, day);
//		}
//		calendar = "";
//		f = "";
//		std::cin >> calendar;
//		std::cin >> f;
//	}
//	return 0;
//}
////APPEND END
//
//

int main()
{
	int year, day, n;
	std::string calendar, f;
	char month[10];
	char newmonth[10];
	std::cin >> f;
	std::cin >> year >> month >> day;
	Shanghaitech date(year, month, day);
	Shanghaitech* S = &date;
	Gregorian* G = &date;
	calendar = "S";
	while (!std::cin.eof()) {
		if (f == "pd") {
			std::cin >> n;
			if (calendar == "G") G->pass_day(n); else S->pass_day(n);
		}
		else if (f == "pm") {
			std::cin >> n;
			if (calendar == "G") G->pass_month(n); else S->pass_month(n);
		}
		else if (f == "py") {
			std::cin >> n;
			if (calendar == "G") G->pass_year(n); else S->pass_year(n);
		}
		else if (f == "ppd") {
			if (calendar == "G") G->print_today(); else S->print_today();
		}
		else if (f == "ppm") {
			if (calendar == "G") G->print_month(); else S->print_month();
		}
		else if (f == "ppy") {
			if (calendar == "G") G->print_year(); else S->print_year();
		}
		else if (f == "gt") {
			std::cin >> year >> newmonth >> day;
			if (calendar == "G") G->go_to(year, newmonth, day); else S->go_to(year, newmonth, day);
		}
		S->print_today();
		G->print_today();
		//calendar = "";
		f = "";
		//std::cin >> calendar;
		std::cin >> f;
	}
	return 0;
}
