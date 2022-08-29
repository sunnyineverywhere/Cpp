#include <iostream>
#include <vector>
#include <queue>
using namespace std;

char candy[51][51];
bool check[51][51] = { false };

int dx[2] = { 1, 0};
int dy[2] = { 0, 1 };

int ans = 0;

void input(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> candy[i][j];
		}
	}
}

void checking(int n) {
	char tmp;
	for (int i = 1; i <= n; i++) {
		int cnt = 1;
		tmp = candy[i][0];
		for (int j = 1; j <= n; j++) {
			if (candy[i][j] == tmp) {
				cnt++;
			}
			else {
				cnt = 1;
				tmp = candy[i][j];
			}

			if (ans < cnt) {
				cnt = ans;
			}
		}
	}
}

int solution(int n) {
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < n; j++) {
			swap(candy[i][j], candy[i][j + 1]);
			swap(candy[i][j], candy[i][j + 1]);
		}
	}
}

int main(void) {
	int n;
	cin >> n;
	input(n);

	// 입력 확인
	/*
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << candy[i][j];
		}
		cout << "\n";
	}
	*/

	solution(n);

	return 0;
}
