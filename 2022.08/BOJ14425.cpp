#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int n, m;


int main(void) {

	cin >> n >> m;

	map<string, bool> s;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		s.insert({ tmp, true });
	}

	int cnt = 0;
	while (m--) {
		string tmp;
		cin >> tmp;
		if (s[tmp] == true) {
			cnt++;
			// s[tmp] = true; // 중복되는 문자열 없음
		}
	}

	cout << cnt;

	return 0;
}
