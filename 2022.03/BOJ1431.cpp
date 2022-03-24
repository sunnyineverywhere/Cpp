#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool compare(string a, string b) {



	int as = 0; int bs = 0;
	if (a.length() != b.length()) {
		return a.length() < b.length();
	}
	
	for (int i = 0; i < a.length(); i++) {
		if (a[i] <= '9') {
			as += a[i] - '0';
		}
		if (b[i] <= '9') {
			bs += b[i] - '0';
		}
	}	
	if (as != bs) {

		return as < bs;
		
	}
	else {
		return a < b;
	}
}

int main(void) {
	int n;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < n; i++) {
		cout << v[i] << "\n";
	}

	return 0;
}
