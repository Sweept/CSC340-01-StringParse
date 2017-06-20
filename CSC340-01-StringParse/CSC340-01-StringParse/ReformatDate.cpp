// ReformatDate.cpp : Defines the entry point for the console application.
//

#include "string"
#include "iostream"

using namespace std;

void decodeFormatOne(string& dateFormat1, int& date, int& month, int& year) {

	//three parts sperated by space, first contians date, second contains month, third year
	//first one, date, contains ordinal indicators, which we don't need
	date = dateFormat1[0] - '0';
	int monthStart = 4;
	int yearStart = 8;

	if (dateFormat1[1] <= '9') {
		date = date * 10 + (dateFormat1[1] - '0');
		monthStart = 5;
		yearStart = 9;
	}
	if (dateFormat1[monthStart] == 'J') {
		if (dateFormat1[monthStart + 1] == 'a') {
			month = 1;
		}
		else if (dateFormat1[monthStart + 1] == 'u') {
			if (dateFormat1[monthStart + 2] == 'n') {
				month = 6;
			}
			else if (dateFormat1[monthStart + 2] == 'l') {
				month = 7;
			}
		}
	}
	else if (dateFormat1[monthStart] == 'F') {
		month = 2;
	}
	else if (dateFormat1[monthStart] == 'M') {
		if (dateFormat1[monthStart + 1] == 'a') {
			if (dateFormat1[monthStart + 2] == 'r') {
				month = 3;
			}
			else if (dateFormat1[monthStart + 2] == 'y') {
				month = 5;
			}
		}
	}
	else if (dateFormat1[monthStart] == 'A') {
		if (dateFormat1[monthStart + 1] == 'p') {
			month = 4;
		}
		else if (dateFormat1[monthStart + 1] == 'U') {
			month = 8;
		}
	}
	else if (dateFormat1[monthStart] == 'S') {
		month = 9;
	}
	else if (dateFormat1[monthStart] == 'O') {
		month = 10;
	}
	else if (dateFormat1[monthStart] == 'N') {
		month = 1;
	}
	else if (dateFormat1[monthStart] == 'D') {
		month = 12;
	}
	year = (dateFormat1[yearStart] - '0') * 1000 + (dateFormat1[yearStart + 1] - '0') * 100 + (dateFormat1[yearStart + 2] - '0') * 10 + (dateFormat1[yearStart + 3] - '0');

}





string Date2UniFormat(int date, int month, int year) {
	string dateUniStr;
	dateUniStr += year / 1000 + '0';
	year -= (year / 1000) * 1000;
	dateUniStr += year / 100 + '0';
	year -= (year / 100) * 100;
	dateUniStr += year / 10 + '0';
	year -= (year / 10) * 10;
	dateUniStr += year + '0';
	dateUniStr += '-';

	if (month > 9) {
		dateUniStr += '1';
		month -= 10;
	}
	else
	{
		dateUniStr += '0';
	}
	dateUniStr += month + '0';
	dateUniStr += '-';
	if (date > 9) {
		dateUniStr += '1';
		date -= 10;
	}
	else
	{
		dateUniStr += '0';
	}
	dateUniStr += date + '0';

	return dateUniStr;
}

string USAFormat2Uni(string dateIn) {
	int date;
	int month;
	int year;
	decodeFormatOne(dateIn, date, month, year);
	return Date2UniFormat(date, month, year);
}
int main()
{
	string USAFormat1("1st Mar 1984");
	string UniFormat1 = USAFormat2Uni(USAFormat1);
	cout << UniFormat1 << endl;

	string USAFormat2("2nd Feb 2013");
	string UniFormat2 = USAFormat2Uni(USAFormat2);
	cout << UniFormat2 << endl;

	string USAFormat3("15th Apr 1840");
	string UniFormat3 = USAFormat2Uni(USAFormat3);
	cout << UniFormat3 << endl;

	return 0;
}



