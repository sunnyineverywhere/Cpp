#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 연결 요소란
// 연결 되어 있는 한 덩어리

const int MAX = 1002;
int n, m;
int map[MAX][MAX] = { 0 };
bool visited[MAX] = { 0 };
queue<int> q;

void bfs(int v) {
	q.push(v);
	visited[v] = true;

	while (!q.empty()) {
		v = q.front();
		q.pop();

		for (int i = 1; i <= n; i++) {
			if (map[v][i] == 1 && visited[i] == 0) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
}

int main(void) {

	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		map[u][v] = 1;
		map[v][u] = 1;
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			bfs(i);
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}
