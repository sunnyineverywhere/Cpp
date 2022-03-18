#include <iostream>
#include <vector>
using namespace std;

int n, s;
int cnt = 0;
vector<int> v(21);

void back_tracking(int i, int tmp) {
	if (i == n) {
		return;
	}
	if (tmp + v[i] == s) {
		cnt++;
	}

	back_tracking(i + 1, tmp);
	back_tracking(i + 1, tmp + v[i]);

}

int main(void) {


	cin >> n >> s;


	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	back_tracking(0, 0);
	

	cout << cnt;
	return 0;
}
