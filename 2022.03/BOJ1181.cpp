#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compare(string x, string y) {
	if (x.length() == y.length()) {
		return x < y;
	}
	else {
		return x.length() < y.length();
	}
}

int main(void) {

	int n;
	cin >> n;
	vector<string> v;

	while (n--) {
		string input;
		cin >> input;
		if (find(v.begin(), v.end(), input) == v.end()) {
			v.push_back(input);
		}
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}

	return 0;
}
