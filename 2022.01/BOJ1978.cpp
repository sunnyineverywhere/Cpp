/* ���� 1978 �Ҽ� ã��*/
/* ��...? �̰� ��� �� ���� �¾���...? */


#include <iostream>
using namespace std;

int main(void) {
	int num[100] = { 0 };

	int n;
	cin >> n;
	int out = 0;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		int cnt = 0;
		for (int j = 1; j <= num[i]; j++) {
			if (num[i] % j == 0) {
				cnt++;
			}
		}
		if (cnt == 2) {
			out++;
		}
	}

	cout << out;

	return 0;
}