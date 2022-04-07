#include <vector>
#include <string>
#include <iostream>
using namespace std;

int t;
string input;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--) {
		int cnt = 0;
		int n, m;
		cin >> n >> m;
		for (int i = n; i <= m; i++) {
			input = to_string(i);
			for (int j = 0; j < input.length(); j++) {
				if (input[j] == '0') {
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}

	return 0;
}
