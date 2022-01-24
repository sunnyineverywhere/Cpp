#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
	int x;
	int y;
}coordinate;

bool compare(coordinate a, coordinate b) {
	if (a.x == b.x) {
		return (a.y < b.y);
	}
	else {
		return a.x < b.x;
	}
}

int main(void) {

	int n;
	cin >> n;
	vector<coordinate> coors(n);

	for (int i = 0; i < n; i++) {
		cin >> coors[i].x >> coors[i].y;
	}

	sort(coors.begin(), coors.end(), compare);

	for (int i = 0; i < n; i++) {
		cout << coors[i].x << " " << coors[i].y << endl;
	}

	return 0;
}