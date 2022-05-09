#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int t;
int m, n, k;
int field[51][51] = { 0 };
bool chk[51][51] = { false };

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
queue <pair<int, int>> q;


void bfs(int x, int y) {
	chk[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if (field[nx][ny] == 1) {
				if (!chk[nx][ny]) {
					bfs(nx, ny);
				}
			}
		}
		else {
			continue;
		}
	}
}

int main(void) {

	cin >> t;
	while (t--) {
		cin >> m >> n >> k;
		int cnt = 0;
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			field[y][x] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (field[i][j] == 1) {
					if (!chk[i][j]) {
						cnt++;
						bfs(i, j);
					}
				
				}
			}
		}

		cout << cnt << "\n";
		memset(chk, false, sizeof(chk));
		memset(field, 0, sizeof(field));
	}

	return 0;
}
