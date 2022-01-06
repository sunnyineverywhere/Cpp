/* 백준 11098번 첼시를 도와줘! */

#include <iostream>
#include <string>
using namespace std;

struct player {
	int sal;
	string name;
};

int main(void) {

	int n;
	cin >> n;

	int p;


	player players[101];

	for (int i = 0; i < n; i++) {
		cin >> p;
		int index;
		int max = 0;
		for (int j = 0; j < p; j++) {
			cin >> players[j].sal >> players[j].name;
			if (players[j].sal > max) {
				max = players[j].sal;
				index = j;
			}
		}
		cout << players[index].name << '\n';
	}


	return 0;
}