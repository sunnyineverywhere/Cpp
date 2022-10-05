#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

bool compare(pair<string, int>& a, pair<string, int>& b){
    return a.second > b.second;
}

bool compare_songs(pair<int, int>& a, pair<int, int>& b){
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    // 장르 개수 저장
    map<string, int> cnt;
    
    // 장르 별 플레이 회수 저장
    map<string, map<int, int>> songs;
    
    for(int i = 0; i < genres.size(); i++){
        cnt[genres[i]]++;
        songs[genres[i]][i] = plays[i];
    }
    
    vector<pair<string, int>> v(cnt.begin(), cnt.end());
    sort(v.begin(), v.end(), compare);
    /*
    for(int i = 0; i < v.size(); i++){
        cout << v[i].first << " ";
    }
    */
    
    for(int i = 0; i < v.size(); i++){
        for(auto x : songs[v[i]]){
            cout << x.second << " ";
        }
    }
    
    return answer;
}
