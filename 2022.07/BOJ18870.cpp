#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main(void) {
	
	cin >> n;

	vector<int> x(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}

	vector<int> solve(x); // 원본 벡터 복사

	// 벡터 복사되는 부분 확인
	/*
	* 	for (int i = 0; i < solve.size();  i++) {
		cout << solve[i] << ' ';
	}
	cout << '\n';	
	*/


	sort(solve.begin(), solve.end()); // 오름차순 정렬
	solve.erase(unique(solve.begin(), solve.end()), solve.end()); // 중복값 제거
	for (int i = 0; i < n; i++) {
		// 원본 벡터 x의 i번째 원소가
		// 복사본 solve에서 몇번째에 위치하는지 확인한다
		// lower_bound는 주소값을 반환한다
		auto it = lower_bound(solve.begin(), solve.end(), x[i]);

		// lower_bound의 반환값에 solve의 시작 주소값을 빼면 답이 된다
		cout << it - solve.begin() << ' ';
	}

	return 0;
}
