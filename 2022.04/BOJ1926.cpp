#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int canvas[501][501];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int bfs(int i, int j) {
	int sum = 1;
	queue<pair<int, int>> q;
	q.push({ i, j });
	canvas[i][j] = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int a = 0; a < 4; a++) {
			int nx = x + dx[a];
			int ny = y + dy[a];
			if (nx >= 0 && nx <= n && ny >= 0 && ny <= m && canvas[nx][ny] == 1) {
				q.push({ nx, ny });
				canvas[nx][ny] = 0;
				sum++;
			}
		}
	}

	return sum;
}


int main(void) {

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> canvas[i][j];
		}
	}
	
	int cnt = 0; int size = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (canvas[i][j] == 1) {
				int tmp = bfs(i, j);
				size = max(size, tmp);
				cnt++;
			}
		}
	}

	cout << cnt << "\n" << size;


	return 0;
}
