#include <iostream>
using namespace std;

int main(void) {
	int N;
	int end = 1, cnt = 6;
	int result = 1;
	cin >> N;

	while (1) {
		if (end >= N) {
			cout << result << endl;
			return 0;
		}
		end += cnt;
		cnt += 6;
		result++;
	}
}
