#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string input;
vector<string> dic(1001);

int main(void) {

	cin >> input;
	int len = input.length();

	// 접미사 넣기
	for (int i = 0; i < input.length(); i++) {
		string tmp;
		for (int j = i; j < len; j++) {
			tmp += input[j];
		}
		dic[i] = tmp;
	}

	// 확인(완)
	/*
	for (int i = 0; i < len; i++) {
		cout << dic[i] << "\n";
	}
	*/

	// 정렬

	sort(dic.begin(), dic.begin() + len);

	for (int i = 0; i < len; i++) {
		cout << dic[i] << "\n";
	}

	return 0;
}
