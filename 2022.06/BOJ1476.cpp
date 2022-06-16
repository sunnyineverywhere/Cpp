#include <iostream>
#include <vector>
using namespace std;

int e, s, m;

int main(void) {
	cin >> e >> s >> m;

	int res = 1;

	// res - e = 15의 배수
	// res - s = 28의 배수
	// res - m = 19의 배수

	while (1) {
		if ((res - e) % 15 == 0 && (res - s) % 28 == 0 && (res - m) % 19 == 0) {
			break;
		}
		res++;
	}

	cout << res;

	return 0;
}
