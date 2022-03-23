#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	long long sum;
	cin >> sum;

	long long tmp = 0, n = 1;
	int cnt = 0;

	while (1) {
		tmp += n;
		cnt++;
		if (tmp > sum) {
			cnt--;
			break;
		}
		n++;
	}

	cout << cnt;

}
