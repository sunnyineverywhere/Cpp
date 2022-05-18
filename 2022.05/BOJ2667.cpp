#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n;
int square[26][26];
bool vis[26][26] = { false };
int cnt = 0;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

vector<int> sol;
queue<pair<int, int>> q;

void bfs() {
	int resident_cnt = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		resident_cnt++;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			// 숫자 넘어가면 통과
			if (nx < 0 || nx > n || ny < 0 || ny > n) {
				continue;
			}
			// 방문했으면 통과
			if (vis[nx][ny] == true) {
				continue;
			}
			vis[nx][ny] = true;
			if (square[nx][ny] == 1) {
				q.push({ nx, ny });
			}
		}
	}
	sol.push_back(resident_cnt);
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf_s("%1d", &square[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (square[i][j] == 1 && vis[i][j] == false) {
				cnt++;
				q.push({ i, j });
				vis[i][j] = true;
				bfs();
			}
		}
	}

	cout << cnt << "\n";
	sort(sol.begin(), sol.end());

	for (int i = 0; i < sol.size(); i++) {
		cout << sol[i] << "\n";
	}

	return 0;
}
