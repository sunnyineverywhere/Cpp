#include <iostream>
using namespace std;

int n, m;



// 왼쪽 방향부터 탐색 진행: 회전 -> 전진 -> 청소
// 네 방향 모두 탐색
// 네 방향 모두 청소 -> 바라보는 방향 유지 + 한 칸 후진
// 네 구역 모두 청소 || 벽 + 뒤쪽 방향이 벽 -> 후진 불가 -> 작동 종료
// 0 북쪽, 1 동쪽, 2 남쪽, 3 서쪽
// 빈칸은 0, 기둥은 1

int board[51][51];
bool visited[51][51];
int answer = 0;
int r, c, d;

int dx[4] = { -1, 0, 1,0 };
int dy[4] = { 0, 1, 0, -1 };


/**
* x, y는 좌표
* dir은 방향
*/

int main(void) {
	cin >> n >> m;
	cin >> r >> c >> d;

	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	

	while (1) {

		if (!visited[r][c]) {
			visited[r][c] = true;
			answer++;
		}

		// cout << r << " " << c << " " << d << " " << answer << "\n";

		bool chk = false;
		for (int i = 0; i < 4; i++) {

			d = (d + 3) % 4;
			int nx = r + dx[d];
			int ny = c + dy[d];

			
			if (board[nx][ny] == 0 && !visited[nx][ny]) {
				r = nx;
				c = ny;
				chk = true;
				break;
			}
		}
		if (!chk) {
			int back_dir = d > 1 ? d - 2 : d + 2;
			if (board[r + dx[back_dir]][c + dy[back_dir]]) {
				break;
			}
			r += dx[back_dir];
			c += dy[back_dir];
		}
	}
		cout << answer;

	return 0;
}
