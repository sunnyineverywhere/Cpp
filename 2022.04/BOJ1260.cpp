#include <iostream>
#include <queue>
using namespace std;

int n, m, v;
int matrix[1001][1001];
int visited[1001];

void dfs(int v) {
	cout << v << " ";
	visited[v] = 1;
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 1 || matrix[v][i] == 0) {
			continue;
		}
		dfs(i);
	}
}

void bfs(int v) {
	queue<int> q;
	q.push(v);
	visited[v] = 0;
	while (!q.empty()) {
		v = q.front();
		cout << q.front() << ' ';
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (visited[i] == 0 || matrix[v][i] == 0) {
				continue;
			}
			q.push(i);
			visited[i] = 0;
		}
	}
}

int main(void) {
	int x, y;
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		matrix[x][y] = 1;
		matrix[y][x] = 1;
	}

	dfs(v);
	cout << "\n";
	bfs(v);
}
