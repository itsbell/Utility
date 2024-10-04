//Date.cpp

#include "Date.h"
#include <ctime>
#include <cstdio>
#pragma warning (disable:4996)


/*
�Լ���Ī: Date
��    ��: ��ü�� �����ϴ�.
��    ��: ����
��    ��: ����
*/
Date::Date() {
	this->year = 1900;
	this->month = JAN;
	this->day = 1;
	this->weekDay = MON;
}

/*
�޼�����Ī : Date
��      �� : ��ü�� �����Ѵ�.
��      �� : �⵵, ��, ��
��      �� : ����
*/
Date::Date(int year, Month month, int day) {
	struct tm date = { 0, };

	date.tm_year = year - 1900;
	date.tm_mon = month - 1;
	date.tm_mday = day;

	mktime(&date);

	this->year = date.tm_year + 1900;
	this->month = static_cast<Month>(date.tm_mon + 1);
	this->day = date.tm_mday;
	this->weekDay = static_cast<WeekDay>(date.tm_wday);
}

/*
�޼�����Ī : Date
��      �� : ��ü�� �����Ѵ�.
��      �� : ��¥
��      �� : ����
*/
Date::Date(char(*date)) {
	struct tm date_ = { 0, };

	sscanf(date, "%4d%2d%2d", &(date_.tm_year), &(date_.tm_mon), &(date_.tm_mday));

	date_.tm_year = date_.tm_year - 1900;
	date_.tm_mon = date_.tm_mon - 1;

	mktime(&date_);

	this->year = date_.tm_year + 1900;
	this->month = static_cast<Month>(date_.tm_mon + 1);
	this->day = date_.tm_mday;
	this->weekDay = static_cast<WeekDay>(date_.tm_wday);
}

/*
�޼�����Ī : Date
��      �� : ��ü�� �����Ѵ�.
��      �� : ��¥
��      �� : ����
*/
Date::Date(const Date& source) {
	this->year = source.year;
	this->month = source.month;
	this->day = source.day;
	this->weekDay = source.weekDay;
}


/*
�Լ���Ī: Today
��    ��: ���� ��¥�� ���ϴ�.
��    ��: ����
��    ��: ��¥
*/
Date Date::Today() {
	time_t timer;
	struct tm* today;
	Date today_;

	time(&timer);
	today = localtime(&timer);
	today_.year = today->tm_year + 1900;
	today_.month = static_cast<Month>(today->tm_mon + 1);
	today_.day = today->tm_mday;
	today_.weekDay = static_cast<WeekDay>(today->tm_wday);

	return today_;
}

/*
�Լ���Ī: Tomorrow
��    ��: ���� ��¥�� ���ϴ�.
��    ��: ����
��    ��: ��¥
*/
Date Date::Tomorrow() {
	struct tm tomorrow_ = { 0, };
	Date tomorrow;

	tomorrow_.tm_year = this->year - 1900;
	tomorrow_.tm_mon = this->month - 1;
	tomorrow_.tm_mday = this->day + 1;

	mktime(&tomorrow_);

	tomorrow.year = tomorrow_.tm_year + 1900;
	tomorrow.month = static_cast<Month>(tomorrow_.tm_mon + 1);
	tomorrow.day = tomorrow_.tm_mday;
	tomorrow.weekDay = static_cast<WeekDay>(tomorrow_.tm_wday);

	return tomorrow;
}

/*
�Լ���Ī: Yesterday
��    ��: ���� ��¥�� ���ϴ�.
��    ��: ����
��    ��: ��¥
*/
Date Date::Yesterday() {
	struct tm yesterday_ = { 0, };
	Date yesterday;

	yesterday_.tm_year = this->year - 1900;
	yesterday_.tm_mon = this->month - 1;
	yesterday_.tm_mday = this->day - 1;

	mktime(&yesterday_);

	yesterday.year = yesterday_.tm_year + 1900;
	yesterday.month = static_cast<Month>(yesterday_.tm_mon + 1);
	yesterday.day = yesterday_.tm_mday;
	yesterday.weekDay = static_cast<WeekDay>(yesterday_.tm_wday);

	return yesterday;
}

/*
�Լ���Ī: PreviousDate
��    ��: �Է¹��� ���� ���� ��¥�� ���ϴ�.
��    ��: ����
��    ��: ��¥
*/
Date Date::PreviousDate(int days) {
	struct tm previousDate_ = { 0, };
	Date previousDate;

	previousDate_.tm_year = this->year - 1900;
	previousDate_.tm_mon = this->month - 1;
	previousDate_.tm_mday = this->day - days;

	mktime(&previousDate_);

	previousDate.year = previousDate_.tm_year + 1900;
	previousDate.month = static_cast<Month>(previousDate_.tm_mon + 1);
	previousDate.day = previousDate_.tm_mday;
	previousDate.weekDay - static_cast<WeekDay>(previousDate_.tm_wday);

	return previousDate;
}

/*
�Լ���Ī: NextDate
��    ��: �Է¹��� ���� ���� ��¥�� ���ϴ�.
��    ��: ����
��    ��: ��¥
*/
Date Date::NextDate(int days) {
	struct tm nextDate_ = { 0, };
	Date nextDate;

	nextDate_.tm_year = this->year - 1900;
	nextDate_.tm_mon = this->month - 1;
	nextDate_.tm_mday = this->day + days;

	mktime(&nextDate_);

	nextDate.year = nextDate_.tm_year + 1900;
	nextDate.month = static_cast<Month>(nextDate_.tm_mon + 1);
	nextDate.day = nextDate_.tm_mday;
	nextDate.weekDay = static_cast<WeekDay>(nextDate_.tm_wday);

	return nextDate;
}

/*
�Լ���Ī: IsLessThan
��    ��: �� ��¥�� ���Ͽ� �� ������ Ȯ���ϴ�.
��    ��: ��¥
��    ��: Boolean
*/
bool Date::IsLessThan(const Date& other) {
	bool ret = false;

	if (this->year < other.year) {
		ret = true;
	}
	else if (this->year == other.year && this->month < other.month) {
		ret = true;
	}
	else if (this->year == other.year && this->month == other.month && this->day < other.day) {
		ret = true;
	}

	return ret;
}

/*
�Լ���Ī: IsGreaterThan
��    ��: �� ��¥�� ���Ͽ� �� ū�� Ȯ���ϴ�.
��    ��: ��¥
��    ��: Boolean
*/
bool Date::IsGreaterThan(const Date& other) {
	bool ret = false;

	if (this->year > other.year) {
		ret = true;
	}

	else if (this->year == other.year && this->month > other.month) {
		ret = true;
	}

	else if (this->year == other.year && this->month == other.month && this->day > other.day) {
		ret = true;
	}

	return ret;
}

/*
�Լ���Ī: IsEqual
��    ��: �� ��¥�� ������ Ȯ���ϴ�.
��    ��: ��¥
��    ��: Boolean
*/
bool Date::IsEqual(const Date& other) {
	bool ret = false;
	
	if (this->year == other.year && this->month == other.month && this->day == other.day) {
		ret = true;
	}

	return ret;
}

/*
�Լ���Ī: IsNotEqual
��    ��: �� ��¥�� ���� ������ Ȯ���ϴ�.
��    ��: ��¥
��    ��: Boolean
*/
bool Date::IsNotEqual(const Date& other) {
	bool ret = false;

	if (this->year != other.year || this->month != other.month || this->day != other.day) {
		ret = true;
	}

	return ret;
}

/*
�Լ���Ī: operator char*
��    ��: ����ȯ
��    ��: ����
��    ��: ����
*/
Date::operator char* () {
	static char buff[9];

	sprintf(buff, "%4d-%02d-%02d", this->year, this->month, this->day);

	return buff;
}

/*
�Լ���Ī: ~Date
��    ��: ��ü�� �Ҹ��Ű��.
��    ��: ����
��    ��: ����
*/
Date::~Date(){

}

/*
�Լ���Ī : operator--
��    �� : ��¥ �����Ϳ� ���� --(����) ������ �����ϵ��� ���ִ�.
��    �� : ����
��    �� : ����
*/
Date& Date::operator--() {
	struct tm yesterday_ = { 0, };

	yesterday_.tm_year = this->year - 1900;
	yesterday_.tm_mon = this->month - 1;
	yesterday_.tm_mday = this->day - 1;

	mktime(&yesterday_);

	this->year = yesterday_.tm_year + 1900;
	this->month = static_cast<Month>(yesterday_.tm_mon + 1);
	this->day = yesterday_.tm_mday;
	this->weekDay = static_cast<WeekDay>(yesterday_.tm_wday);

	return *this;
}

/*
�Լ���Ī : operator--
��    �� : ��¥ �����Ϳ� ���� --(����) ������ �����ϵ��� ���ִ�.
��    �� : ����
��    �� : ����
*/
Date Date::operator--(int) {
	struct tm yesterday_ = { 0, };
	Date yesterday(*this);

	yesterday_.tm_year = this->year - 1900;
	yesterday_.tm_mon = this->month - 1;
	yesterday_.tm_mday = this->day - 1;

	mktime(&yesterday_);

	this->year = yesterday_.tm_year + 1900;
	this->month = static_cast<Month>(yesterday_.tm_mon + 1);
	this->day = yesterday_.tm_mday;
	this->weekDay = static_cast<WeekDay>(yesterday_.tm_wday);

	return yesterday;
}


/*
�Լ���Ī : operator++
��    �� :  ��¥ �����Ϳ� ���� ++(����) ������ �����ϵ��� ���ִ�.
��    �� : ����
��    �� : ����
*/


Date& Date::operator++() {
	struct tm tomorrow_ = { 0, };

	tomorrow_.tm_year = this->year - 1900;
	tomorrow_.tm_mon = this->month - 1;
	tomorrow_.tm_mday = this->day + 1;

	mktime(&tomorrow_);

	this->year = tomorrow_.tm_year + 1900;
	this->month = static_cast<Month>(tomorrow_.tm_mon + 1);
	this->day = tomorrow_.tm_mday;
	this->weekDay = static_cast<WeekDay>(tomorrow_.tm_wday);

	return *this;
}


/*
�Լ���Ī : operator++
��    �� : ��¥ �����Ϳ� ���� ++(����) ������ �����ϵ��� ���ִ�.
��    �� : ����
��    �� : ����
*/
Date Date::operator++(int) {
	struct tm tomorrow_ = { 0, };
	Date tomorrow(*this);

	tomorrow_.tm_year = this->year - 1900;
	tomorrow_.tm_mon = this->month - 1;
	tomorrow_.tm_mday = this->day + 1;

	mktime(&tomorrow_);

	this->year = tomorrow_.tm_year + 1900;
	this->month = static_cast<Month>(tomorrow_.tm_mon + 1);
	this->day = tomorrow_.tm_mday;
	this->weekDay = static_cast<WeekDay>(tomorrow_.tm_wday);

	return tomorrow;
}


/*
�Լ���Ī : operator-
��    �� : ��¥ �����Ϳ� ���� - ������ �����ϵ��� ���ִ�.
��    �� : ����
��    �� : ����
*/
Date Date::operator-(int days) {
	struct tm previousDate_ = { 0, };
	Date previousDate;

	previousDate_.tm_year = this->year - 1900;
	previousDate_.tm_mon = this->month - 1;
	previousDate_.tm_mday = this->day - days;

	mktime(&previousDate_);

	previousDate.year = previousDate_.tm_year+1900;
	previousDate.month = static_cast<Month>(previousDate_.tm_mon + 1);
	previousDate.day = previousDate_.tm_mday;
	previousDate.weekDay = static_cast<WeekDay>(previousDate_.tm_wday);

	return previousDate;
}


/*
�Լ���Ī : operator+
��    �� : ��¥ �����Ϳ� ���� + ������ �����ϵ��� ���ִ�.
��    �� : ����
��    �� : ����
*/


Date Date::operator+(int days) {
	struct tm nextDate_ = { 0, };
	Date nextDate;

	nextDate_.tm_year = this->year - 1900;
	nextDate_.tm_mon = this->month - 1;
	nextDate_.tm_mday = this->day + days;

	mktime(&nextDate_);

	nextDate.year = nextDate_.tm_year + 1900;
	nextDate.month = static_cast<Month>(nextDate_.tm_mon + 1);
	nextDate.day = nextDate_.tm_mday;
	nextDate.weekDay = static_cast<WeekDay>(nextDate_.tm_wday);

	return nextDate;

}

/*
�Լ���Ī : operator<
��    �� : ��¥ �����Ϳ� ���� < ������ �����ϵ��� ���ִ�.
��    �� : ����
��    �� : ����
*/
bool Date::operator<(const Date& other) {
	bool ret = false;

	if (this->year < other.year) {
		ret = true;
	}

	else if (this->year == other.year && this->month < other.month) {
		ret = true;
	}

	else if (this->year == other.year && this->month == other.month && this->day < other.day) {
		ret = true;
	}

	return ret;
}


/*
�Լ���Ī : operator<=
��    �� : ��¥ �����Ϳ� ���� <= ������ �����ϵ��� ���ִ�.
��    �� : ����
��    �� : ����
*/
bool Date::operator<=(const Date& other) {
	bool ret = false;

	if (this->year < other.year) {
		ret = true;
	}

	else if (this->year == other.year && this->month < other.month) {
		ret = true;
	}

	else if (this->year == other.year && this->month == other.month && this->day <= other.day) {
		ret = true;
	}

	return ret;
}


/*
�Լ���Ī : operator>
��    �� : ��¥ �����Ϳ� ���� > ������ �����ϵ��� ���ִ�.
��    �� : ����
��    �� : ����
*/
bool Date::operator>(const Date& other) {
	bool ret = false;

	if (this->year > other.year) {
		ret = true;
	}

	else if (this->year == other.year && this->month > other.month) {
		ret = true;
	}

	else if (this->year == other.year && this->month == other.month && this->day > other.day) {
		ret = true;
	}
	return ret;
}




/*
�Լ���Ī : operator>=
��    �� : ��¥ �����Ϳ� ���� >= ������ �����ϵ��� ���ִ�.
��    �� : ����
��    �� : ����
*/
bool Date::operator>=(const Date& other) {
	bool ret = false;

	if (this->year > other.year) {
		ret = true;
	}

	else if (this->year == other.year && this->month > other.month) {
		ret = true;
	}

	else if (this->year == other.year && this->month == other.month && this->day >= other.day) {
		ret = true;
	}

	return ret;
}



/*
�Լ���Ī : operator ==
��    �� : ��¥ �����Ϳ� ���� == ������ �����ϵ��� ���ִ�.
��    �� : ����
��    �� : ����
*/
bool Date::operator == (const Date& other) {
	bool ret = false;

	if (this->year == other.year && this->month == other.month && this->day == other.day) {
		ret = true;
	}

	return ret;
}

/*
�Լ���Ī : operator !=
��    �� : ��¥ �����Ϳ� ���� != ������ �����ϵ��� ���ִ�.
��    �� : ����
��    �� : ����
*/
bool Date::operator != (const Date& other) {
	bool ret = false;

	if (this->year != other.year || this->month != other.month || this->day != other.day) {
		ret = true;
	}
	return ret;
}


/*
�Լ���Ī : operator =
��    �� : ��¥ �����Ϳ� ���� = ������ �����ϵ��� ���ִ�.
��    �� : ����
��    �� : ����
*/
Date& Date::operator = (const Date& source) {
	this->year = source.year;
	this->month = source.month;
	this->day = source.day;
	this->weekDay = source.weekDay;

	return *this;
}


#include <iostream> //C++ Class Libray -> Standard Template class Library (STL)
using namespace std;

int main(int argc, char* argv[]) {
	Date date;
	Date today;
	Date tomorrow;
	Date yesterday;
	Date previousDate3Days;
	Date nextDate;
	Date previousDate1Days;
	Date previousDate;
	bool ret;
	int i;

	today = Date::Today(); //function call
	cout << today.GetYear() << "-" << today.GetMonth() << "-" << today.GetDay() << endl;

	tomorrow = today.Tomorrow();
	cout << tomorrow.GetYear() << "-" << tomorrow.GetMonth() << "-" << tomorrow.GetDay() << endl;

	yesterday = today.Yesterday();
	cout << yesterday.GetYear() << "-" << yesterday.GetMonth() << "-" << yesterday.GetDay() << endl;
	
	previousDate3Days = today.PreviousDate(3);
	cout << previousDate3Days.GetYear() << "-" << previousDate3Days.GetMonth() << "-" << previousDate3Days.GetDay() << endl;

	ret = previousDate3Days.IsLessThan(today);
	if (ret == true) {
		cout << "�� �Դϴ�." << endl;
	}

	nextDate = today.NextDate(100);
	cout << nextDate.GetYear() << "-" << nextDate.GetMonth() << "-" << nextDate.GetDay() << endl;

	ret = nextDate.IsGreaterThan(yesterday);
	if (ret == true) {
		cout << "�� �Դϴ�." << endl;
	}

	ret = nextDate.IsNotEqual(yesterday);
	if (ret == true) {
		cout << "�������� �ƴմϴ�" << endl;
	}

	previousDate1Days = today.PreviousDate(1);
	cout << previousDate1Days.GetYear() << "-" << previousDate1Days.GetMonth() << "-" << previousDate1Days.GetDay() << endl;

	ret = previousDate1Days.IsEqual(yesterday);
	if (ret == true) {
		cout << "������ �Դϴ�." << endl;
	}

	Date birthday(2022, OCT, 29);
	cout << birthday.GetYear() << "-"<< birthday.GetMonth() << "-" << birthday.GetDay() << endl;

	Date another((char*)"20221029");
	cout << another.GetYear() << "-" << another.GetMonth() << "-" << another.GetDay() << endl;

	Date other(today);
	cout << static_cast<char*>(other) << endl;

	yesterday = --today;
	cout << yesterday.GetYear() << "-" << yesterday.GetMonth() << "-" << yesterday.GetDay() << endl;

	++today;
	cout << today.GetYear() << "-" << today.GetMonth() << "-" << today.GetDay() << endl;

	for (i = 1; i <= 5; i++) {
		cout << today.GetYear() << "-" << today.GetMonth() << "-" << today.GetDay() << endl;
		today--;
	}

	for (i = 1; i <= 5; i++) {
		cout << today.GetYear() << "-" << today.GetMonth() << "-" << today.GetDay() << endl;
		today++;
	}

	previousDate = today - 1;
	cout << previousDate.GetYear() << "-" << previousDate.GetMonth() << "-" << previousDate.GetDay() << endl;

	nextDate = today + 5;
	cout << nextDate.GetYear() << "-" << nextDate.GetMonth() << "-" << nextDate.GetDay() << endl;

	if (today < tomorrow) {
		cout << "�� �Դϴ�" << endl;
	}

	if (today <= today) {
		cout << "�� �Դϴ�" << endl;
	}

	if (nextDate > today) {
		cout << "�� �Դϴ�" << endl;
	}

	if (nextDate >= nextDate) {
		cout << "�� �Դϴ�" << endl;
	}

	if (yesterday == previousDate) {
		cout << "���� �� �Դϴ�" << endl;
	}

	if (today != nextDate) {
		cout << "�ٸ� �� �Դϴ�" << endl;
	}

	return 0;
}