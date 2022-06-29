#include <iostream>
using namespace std;

int main(void) {

	int hour, sec;
	cin >> hour >> sec;
	int add;
	cin >> add;

	sec += add;

	while (hour >= 24 || sec >= 60) {
		if (sec >= 60) {
			sec -= 60;
			hour++;
		}
		if (hour >= 24) {
			hour -= 24;
		}
	}

	cout << hour << " " << sec;

	return 0;
}
