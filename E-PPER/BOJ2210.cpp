#include <iostream>
#include <vector>
using namespace std;

int ans = 0;
bool visited[1000000];

int b[5][5] = { 0 };
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void dfs(int x, int y, int sum, int cnt) {
	if (cnt == 5) {
		if (visited[sum] == false) {
			visited[sum] = true;
			ans++;
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < 5 && ny < 5) {
			dfs(nx, ny, sum * 10 + b[nx][ny], cnt + 1);
		}
	}
}

int main(void) {

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> b[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			dfs(i, j, b[i][j], 0);
		}
	}

	cout << ans;

	return 0;
}
