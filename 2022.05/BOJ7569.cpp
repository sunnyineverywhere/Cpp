#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int m, n, h;
int board[103][103][103];
int isRiped[103][103][103];



int dx[6] = { 1, 0, -1, 0, 0, 0 };
int dy[6] = { 0 , 1, 0, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };


int main(void) {

	queue<tuple<int, int, int>> q;

	cin >> m >> n >> h;
	for (int k = 1; k <= h; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> board[i][j][k];
				if (board[i][j][k] == 1) {
					q.push({ i, j, k });
				}
				if (board[i][j][k] == 0) {
					isRiped[i][j][k] = -1;
				}
			}
		}
	}

	/* 입력 문제없음
	* 	for (int k = 1; k <= h; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cout << board[i][j][k];
			}
			cout << "\n";
		}
		cout << "\n";
	}
	*/

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int curX, curY, curZ;
		tie(curX, curY, curZ) = cur;
		for (int i = 0; i < 6; i++) {
			int nx = curX + dx[i];
			int ny = curY + dy[i];
			int nz = curZ + dz[i];
			if (nx < 1 || nx > n || ny < 1 || ny > m || nz < 0 || nz > h) {
				continue;
			}
			if (isRiped[nx][ny][nz] >= 0) {
				continue;
			}
			isRiped[nx][ny][nz] = isRiped[curX][curY][curZ] + 1;
			q.push({ nx, ny, nz });
		}
	}


	int ans = 0;
	for (int k = 1; k <= h; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (isRiped[i][j][k] == -1) {
					cout << -1 << "\n";
					return 0;
				}
				ans = max(ans, isRiped[i][j][k]);
			}
		}
	}

	cout << ans;

	return 0;
}
