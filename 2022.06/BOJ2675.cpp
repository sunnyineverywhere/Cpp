#include <iostream>
#include <vector>
using namespace std;

int t;
int n;

int main(void) {

	cin >> t;
	while (t--) {
		cin >> n;
		string s;
		cin >> s;

		for (int i = 0; i < s.length(); i++) {
			for (int k = 0; k < n; k++) {
				cout << s[i];
			}
		}

		cout << "\n";
		
	}

	return 0;
}
