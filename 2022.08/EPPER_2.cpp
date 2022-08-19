#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct student
{
	string name;
	int kor;
	int eng;
	int math;
};

bool compare(student a, student b) {
	if (a.kor == b.kor) {
		if (a.eng == b.eng) {
			if (a.math == b.math) {
				return a.name < b.name; // 모든 점수가 같으면 이름이 사전순 증가 순서
			}
			return a.math > b.math; // 국, 영 점수 같으면 수학 점수가 감소하는 순서
		}
		return a.eng < b.eng; // 국어 점수가 같으면 영어 점수가 증가하는 순서
	}
	else {
		return a.kor > b.kor; // 국어 점수가 감소하는 순서
	}
}

vector<string> solve(vector<student> list) {
	sort(list.begin(), list.end(), compare);
	vector<string> solution;
	for (int i = 0; i < list.size(); i++) {
		solution.push_back(list[i].name);
	}
	return solution;
}

int main(void) {
	int n;
	cin >> n;
	vector<student> list(n);
	for (int i = 0; i < n; i++) {
		cin >> list[i].name >> list[i].kor >> list[i].eng >> list[i].math;
	}

	vector<string> solution(n); 
	solution = solve(list);

	for (int i = 0; i < solution.size(); i++) {
		cout << solution[i] << "\n";
	}

}
