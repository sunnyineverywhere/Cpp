#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int cnt = 0;
vector<bool> visited(101);
vector<int> list[101];

void dfs(int x) {
	visited[x] = true;
	for (int i = 0; i < list[x].size(); i++) {
		int y = list[x][i];
		if (!visited[y]) {
			dfs(y);
			cnt++;
		}
	}
}

int main(void) {

	int n;
	cin >> n; // 노드 개수

	int k;
	cin >> k; // 엣지 개수

	while (k--) {
		int u, v;
		cin >> u >> v;
		list[u].push_back(v);
		list[v].push_back(u);
	}

	dfs(1);

	cout << cnt;

	return 0;
}
