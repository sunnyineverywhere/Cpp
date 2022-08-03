#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int n, m;

int main(void) {

	cin >> n >> m;

	map<string, bool> list; // 듣도 못한 사람
	vector<string> sol;
	while (n--) {
		string name;
		cin >> name;
		list.insert({ name, true });
	}

	// 보도 못한 사람 입력받고 찾으면서
	// 없으면 sol 리스트에 찾는다
	// 듣도 보도 못한 사람은 듣도 못한사람과 보도 못한사람의 교집합
	int cnt = 0;
	while (m--) { 
		string name;
		cin >> name;
		if (list[name]) {
			cnt++;
			sol.push_back(name);
		}
	}

	cout << cnt << "\n";

	// 사전순 출력 --> 이거 안해서 처음에 틀림
	sort(sol.begin(), sol.end());
	for (int i = 0; i < cnt; i++) {
		cout << sol[i] << "\n";
	}

	return 0;
}
