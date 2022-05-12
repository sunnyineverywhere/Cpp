#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int n;
char grid[101][101];
bool visited[101][101] = { false };
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void bfs(int x, int y) {

	int cnt= 1;
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = 1;
	// cout << "visit " << x << " " << y << "\n";


	while (!q.empty()) {
		int xx = q.front().first;
		int yy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = xx + dx[i];
			int ny = yy + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
				continue;
			}
			if (visited[nx][ny] == 1 || grid[x][y] != grid[nx][ny]) {
				continue;
			}
			visited[nx][ny] = 1;
			q.push({ nx, ny });
		}

	}

}

int main(void) {

	cin >> n;
	// 입출력은 문제 없음
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}



	int non_cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				non_cnt++;
				bfs(i, j);
			}
		}
	}



	for (int i = 0; i < n; i++) {
		fill(visited[i], visited[i] + n, false);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == 'G') {
				grid[i][j] = 'R';
			}
		}
	}


	int rg_cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				rg_cnt++;
				bfs(i, j);
			}
		}
	}

	cout << non_cnt << " " << rg_cnt;

	return 0;
}
