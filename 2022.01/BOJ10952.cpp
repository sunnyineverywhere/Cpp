#include <iostream>
#include <vector>
using namespace std;

typedef struct {
	int a, b;
	int s;
}numbers;

int main(void) {
	vector<numbers> num(10000);

	int cnt = 0;
	for (int i = 0; i < 10000; i++) {
		cin >> num[i].a >> num[i].b;
		if (num[i].a == 0 && num[i].b == 0) {
			break;
		}
		num[i].s = num[i].a + num[i].b;
		cnt++;
	}

	for (int i = 0; i < cnt; i++) {
		cout << num[i].s << "\n";
	}

	return 0;
}
