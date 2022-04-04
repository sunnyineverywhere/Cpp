#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int n, m;
int map[1001][1001] = { 0 };
bool visited[1001] = { 0 };

void bfs(int v) {
	queue<int> q;
	q.push(v);
	visited[v] = 1;

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
