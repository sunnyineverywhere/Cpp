#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

typedef struct student {
	string name;
	int d;
	int m;
	int y;
};

bool compare(const struct student& a, const struct student& b) {
	if (a.y < b.y) {
		return true;
	}
	else if (a.y == b.y) {
		if (a.m < b.m) {
			return true;
		}
		else if (a.m == b.m) {
			if (a.d < b.d) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

int main(void) {
	int n;
	cin >> n;
	vector<student> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].name >> v[i].d >> v[i].m >> v[i].y;
	}

	sort(v.begin(), v.end(), compare);

	cout << v[n - 1].name << "\n" << v[0].name;

	return 0;
}
