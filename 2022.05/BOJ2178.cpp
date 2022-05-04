#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
int maze[101][101] = { 0 };
bool visited[101][101];
int length[101][101] = { 0 };


int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

void bfs(int x, int y) {

	queue<pair<int, int>> q;
	q.push({ x, y });
	length[x][y]++;
	visited[x][y] = true;

	while(!q.empty()) {
		int xx = q.front().first;
		int yy = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nx = xx + dx[i];
			int ny = yy + dy[i];


			if (nx >= 0 && ny >= 0 && nx < n && ny < m && maze[nx][ny] == 1 && !visited[nx][ny]) {
				visited[nx][ny] = true;
				q.push({nx, ny});
				length[nx][ny] = length[xx][yy] + 1;
			}
		}
	}
}

int main(void) {
	
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
