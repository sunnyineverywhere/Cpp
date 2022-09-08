#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <iterator>
using namespace std;

vector<string> answer;

void solve(string input) {
    list<char> l;
    auto cur = l.begin();

    for (char c : input) {
        // 백스페이스 && 앞에 글자가 있을 때
        // 화살표 이동
        if (c == '<') {
            if (cur != l.begin()) {
                cur--;
            }
        }
        else if (c == '>') {
            if (cur != l.end()) {
                cur++;
            }
        }
        else if (c == '-') {
            if (cur != l.begin()) {
                cur--;
                cur = l.erase(cur);
            }
        }
        else {
            l.insert(cur, c);
        }
    }
    string tmp = "";
    
    for (char c : l) {
        tmp.push_back(c);
    }
    answer.push_back(tmp);
}

void solution(int l) {
    while (l--) {
        string input;
        cin >> input;
        solve(input);
    }
}

int main(void) {
    int l;
    cin >> l;
    solution(l);
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << "\n";
    }

    return 0;
}
