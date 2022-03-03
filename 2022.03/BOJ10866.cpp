#include <iostream>
#include <deque>
using namespace std;

int main(void) {

	int n;
	cin >> n;
	deque<int> dq;

	while (n--) {
		string input;
		cin >> input;
		int x;

		if (input == "push_front") {
			cin >> x;
			dq.push_front(x);
		}
		else if (input == "push_back") {
			cin >> x;
			dq.push_back(x);
		}
		else if (input == "pop_front") {
			if (!dq.empty()) {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
			else {
				cout << -1 << "\n";
			}
			
		}
		else if (input == "pop_back") {
			if (!dq.empty()) {
				cout << dq.back() << "\n";
				dq.pop_back();
			}
			else {
				cout << -1 << "\n";
			}			
		}
		else if (input == "size") {
			cout << dq.size() << "\n";
		}
		else if (input == "empty") {
			if (!dq.empty()) {
				cout << 0 << "\n";
			}
			else {
				cout << 1 << "\n";
			}
		}
		else if (input == "front") {
			if (!dq.empty()) {
				cout << dq.front() << "\n";
			}
			else {
				cout << -1 << "\n";
			}

		}
		else if (input == "back") {
			if (!dq.empty()) {
				cout << dq.back() << "\n";
			}
			else {
				cout << -1 << "\n";
			}
		}

	}


	return 0;
}
