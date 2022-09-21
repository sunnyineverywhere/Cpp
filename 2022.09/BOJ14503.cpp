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

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };


/**
* x, y는 좌표
* dir은 방향
*/
void solution() {

	cout << r << " " << c << " " << d << "\n";
	
	for (int i = 0; i < 4; i++) {
		int nd = (d + 3 - i) % 4;
		int nx = r + dx[nd];
		int ny = c + dx[nd];

		// 왼쪽 방향에 청소 공간 X -> 회전
		if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == 1) {
			continue;
		}

		if (board[nx][ny] == 0 && !visited[nx][ny]) {
			visited[nx][ny] = 1;
			r = nx;
			c = ny;
			d = nd;
			answer++;
			solution();
		}
	}

	int back_dir = d > 1 ? d - 2 : d + 2;
	int back_x = r + dx[back_dir];
	int back_y = c + dy[back_dir];
	// 네방향 청소 완 + 벽
	if(back_x >= 0 || back_x <= n || back_y >= 0 || back_y <= m){
		if (board[back_x][back_y] == 0) {
			r = back_x;
			c = back_y;
			solution();
		}
		else {
			cout << answer;
			exit(0);
		}
	}

}

int main(void) {
	cin >> n >> m;
	cin >> r >> c >> d;

	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	visited[r][c] = 1;
	answer++;

	solution();

	return 0;
}
