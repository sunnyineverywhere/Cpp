#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(void) {
	
	int n;
	cin >> n;
	stack<int> s;
	vector<char> ans;
		

	int cnt = 0;

	while (n--) {
		int input;
		cin >> input;
		
		if (input >= cnt) {
			while (input > cnt) {
				s.push(++cnt);
				ans.push_back('+');
			}
			s.pop();
			ans.push_back('-');
		}
		else {
			if (!s.empty() && input == s.top()) {
				s.pop();
				ans.push_back('-');
			}
			else {
				cout << "NO" << "\n";
				return 0;
			}
		}
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}

	return 0;
}
