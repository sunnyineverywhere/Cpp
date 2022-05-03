#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int maze[101][101];
bool visited[101][101];
int length[101][101];
int n, m;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void bfs(int x, int y) {

	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	length[x][y] = 1;
	visited[x][y] = true;

	while(!q.empty()) {
		int x = q.front().first;
			int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];


			if (nx >= 0 && dy >= 0 && nx < n && ny < m && maze[nx][ny] == 1 && visited[nx][ny] == false) {
				length[nx][ny] = length[y][x] + 1;
				visited[nx][ny] = true;
				q.push(make_pair(nx, ny));
			}
		}
	}


}

int main(void) {
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%1d", &maze[i][j]);
		}
	}

	bfs(0, 0);

	cout << length[n-1][m-1];
	
	return 0;
}
