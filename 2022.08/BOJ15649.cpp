#include <iostream>
#include <vector>

using namespace std;

int n, m;
int arr[9];
bool check[9];


/* 
* 백트래킹을 사용하여 푸는 문제
* 조건이 채워지기 전까지 재귀를 사용하여
* 모든 경우의 수를 탐색한다
*/
void back_tracking(int idx) {

	if (idx == m) { // 현재 정답의 개수까지 다 채웠으면
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n"; // 출력하고
		return; // 현재 함수를 종료한다
	}

	for (int i = 1; i <= n; i++) {
		if (!check[i]) { // i가 현재 배열에 없을 경우
			arr[idx] = i; // 현재 idx에 i 넣고
			check[i] = true; // check를 바꾼다
			back_tracking(idx + 1); // 백트래킹 사용하여 배열의 개수가 m개가 될 때까지 돌고
			check[i] = false; // 다 채워지면 하나씩 재귀로 되돌아가면서 i를 false로 만듬
		}
	}
}

int main(void) {

	cin >> n >> m;

	// idx는 현재 arr에 들어간 숫자의 개수를 의미
	int idx = 0;
	back_tracking(idx);

}
