/* 백준 1408번 24 */

#include <iostream>
#include <string>

using namespace std;

typedef struct {
	int h;
	int m;
	int sec;
}Time;

Time setTime(string time) {
	return Time{
		stoi(time.substr(0,2)),
		stoi(time.substr(3,2)),
		stoi(time.substr(6,2))
	};
}

void printTime(Time time) {
	string hour = to_string(time.h);
	string minute = to_string(time.m);
	string sec = to_string(time.sec);

	hour = hour.length() == 1 ? '0' + hour : hour;
	minute = minute.length() == 1 ? '0' + minute : minute;
	sec = sec.length() == 1 ? '0' + sec : sec;

	cout << hour << ":" << minute << ":" << sec << "\n";
}

int main(void) {
	string current, start;
	cin >> current >> start;

	Time currentTime = setTime(current);
	Time startTime = setTime(start);

	Time result;

	result.sec = startTime.sec - currentTime.sec;
	if (result.sec < 0) {
		result.sec += 60;
		startTime.m--;
	}

	result.m = startTime.m - currentTime.m;
	if (result.m < 0) {
		result.m += 60;
		startTime.h--;
	}

	result.h = startTime.h - currentTime.h;
	if (result.h < 0) {
		result.h += 24;
	}

	printTime(result);
	
	return 0;
}
