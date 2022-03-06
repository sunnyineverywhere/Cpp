#include <iostream>
#include <string>
#include <list>
using namespace std;


int main(void) {

	string s;
	cin >> s;
	int m;
	cin >> m;
	list<char> l(s.begin(), s.end());
	auto cur = l.end();

	while (m--) {
		char input;
		cin >> input;

		if (input == 'L') {
			if (cur != l.begin()) {
				cur--;
			}
		}
		else if (input == 'D') {
			if (cur != l.end()) {
				cur++;
			}
		}
		else if (input == 'B') {
			if (cur != l.begin()) {
				cur = l.erase(--cur);
			}
		}
		else if (input == 'P') {
			char c;
			cin >> c;
			l.insert(cur, c);
		}
	}

	for (auto it = l.begin(); it != l.end(); it++) {
		cout << *it;
	}

	return 0;
}
