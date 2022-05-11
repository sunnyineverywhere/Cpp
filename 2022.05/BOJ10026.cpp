#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int n;
vector<vector<int>> grid(100, vector<int>(100));
bool visited[101][101] = { false };
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void bfs(int x, int y) {

	int cnt= 1;
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = 1;

	while (!q.empty()) {
		int xx = q.front().first;
		int yy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = xx + dx[i];
			int ny = yy + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (cur != grid[nx][ny]) {
					cnt++;
					bfs(nx, ny);
				}
			}
		}

	}

}

int main(void) {

	cin >> n;
	string input = "";
	for (int i = 0; i < n; i++) {
		cin >> input;
		for (int j = 0; j < n; j++) {
			switch (input[j]) {
			case 'R':
				grid[i][j] = 1; break;
			case 'G':
				grid[i][j] = 2; break;
			case 'B':
				grid[i][j] = 3; break;
			}
		}
	}

	bfs(0, 0);

	return 0;
}
