#include <iostream>
#include <queue>
using namespace std;

int main(void) {

	int tc;
	cin >> tc;

	while (tc--) {
		int n, m;
		int cnt = 0;
		cin >> n >> m;

		queue<pair<int, int>> q;
		priority_queue<int> pq;

		int input;
		for (int i = 0; i < n; i++) {
			cin >> input;
			q.push({i, input});
			pq.push(input);
		}

		while (!q.empty()) {
			int i = q.front().first;
			int v = q.front().second;
			q.pop();

			if (pq.top() == v) {
				pq.pop();
				cnt++;
				if (m == i) {
					cout << cnt << "\n";
					break;
				}
			}
			else {
				q.push({ i, v });
			}
		}
	}

	return 0;
}
