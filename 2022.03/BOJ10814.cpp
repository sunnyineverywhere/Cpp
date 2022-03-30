#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

typedef struct members {
	int age;
	int order;
	string name;
};

bool compare(members& a, members& b) {
	if (a.age != b.age) {
		return a.age < b.age;
	}
	else {
		return a.order < b.order;
	}
}

int main(void) {
	int n;
	cin >> n;
	vector<members> v(n);

	for (int i = 0; i < n; i++) {
		v[i].order = i;
		cin >> v[i].age >> v[i].name;
	}

	sort(v.begin(), v.end(), compare);


	for (int i = 0; i < n; i++) {
		cout << v[i].age << " " << v[i].name << "\n";
	}

	return 0;
}
