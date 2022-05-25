#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int main(void) {

	string str;
	getline(cin, str);
	queue<char> q;

	bool isCpp = true;
	bool isJava = false;

	//cpp 판별
	for (int i = 0; i < str.size(); i++) {
		if (isupper(str[i])) {
			isCpp = false;
			break;
		}
		if (str[i] == '_' && (i == 0 || i == str.size() - 1 || str[i - 1] == '_')) {
			isCpp = false;
			break;
		}
	}

	//java 판별
	if (!isupper(str[0]) && str.find('_') == string::npos) {
		isJava = true;
	}

	if ((!isCpp && !isJava)) {
		cout << "Error!";
		return 0;
	}

	for (int i = 0; i < str.length(); i++) {
		if (isCpp) { // cpp -> java
			if (str[i] != '_') {
				q.push(str[i]);
			}
			else {
				str[i + 1] -= 32;
			}
		}
		else if (isJava) { // java -> cpp
			if (str[i] >= 65 && str[i] <= 90) {
				q.push('_');
				q.push(str[i] + 32);
			}
			else {
				q.push(str[i]);
			}
		}
	}

	while (!q.empty()) {
		cout << q.front();
		q.pop();
	}

	return 0;
}
