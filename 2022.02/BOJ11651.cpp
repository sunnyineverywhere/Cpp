#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct coordi {
	int x;
	int y;
};

int compare(coordi a, coordi b) {
	if (a.y == b.y) {
		return a.x < b.x;
	}
	else {
		return a.y < b.y;
	}
}

int main(void) {

	int n;
	cin >> n;
	vector<coordi> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].x >> v[i].y;
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < n; i++) {
		cout << v[i].x << " " << v[i].y << "\n";
	}

	return 0;
}
