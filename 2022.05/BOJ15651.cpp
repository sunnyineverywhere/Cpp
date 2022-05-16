#include <iostream>
#include <vector>
using namespace std;

int n, m;
int num[8] = { 0, };
bool visited[8] = { 0 };

void bt(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << num[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		visited[i] = true;
		num[cnt] = i;
		bt(cnt + 1);
		visited[i] = false;
	}
}

int main(void) {
	cin >> n >> m;

	bt(0);

	return 0;
}
