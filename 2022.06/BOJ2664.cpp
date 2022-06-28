#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, x, y, m;
vector<bool> visited(101);
int family[101][101]; // idx에 자식, 값에 부모
int cnt = -1;
int sol = -1;

void dfs(int curr, int nxt) {
	visited[curr] = 1;
	cnt++;
	if (curr == nxt) {
		sol = cnt;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 1) {
			continue;
		}
		if (family[curr][i] == 0) {
			continue;
		}
		dfs(i, nxt);
	}
	cnt--;
}


int main(void) {

	cin >> n;
	cin >> x >> y;
	cin >> m;

	while (m--) {
		int u, v;
		cin >> u >> v; // u가 부모, v가 자식
		family[u][v] = 1;
		family[v][u] = 1;
	}

	dfs(x, y);

	cout << sol;

	return 0;
}
