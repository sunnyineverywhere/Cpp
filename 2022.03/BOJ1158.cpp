#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(void) {

	int n, k;
	cin >> n >> k;
	queue<int> q;
	vector<int> v;

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	cout << "<";

	while (!q.empty()) {
		for (int i = 0; i < k-1; i++) {
			int a = q.front();
			q.pop();
			q.push(a);
		}

		if (q.size() != 1) {
			cout << q.front() << ", ";
			q.pop();
		}
		else {
			cout << q.front();
			q.pop();
		}
	}

	cout << ">";

	return 0;
}
