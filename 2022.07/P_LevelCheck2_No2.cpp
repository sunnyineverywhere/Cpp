#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// A, E, I, O, U로 이루어진 단어 사전을 먼저 만든다

char alphabet[5] = {'A', 'E', 'I', 'O', 'U'};
vector<string> dictionary;

void making(int maxlen, string s){
    if(maxlen == s.size()) {
        dictionary.push_back(s);
        return;
    }
    
    for(int i=0 ; i<5 ; i++) {
        making(maxlen, s+alphabet[i]);
    }
}

int solution(string word) {
    int answer = 0;
    
   for(int i=1 ; i<=5 ; i++) {
        making(i, "");
    }
    
    sort(dictionary.begin(), dictionary.end());
    answer = find(dictionary.begin(), dictionary.end(), word)-dictionary.begin()+1;
    
    
    return answer;
}
