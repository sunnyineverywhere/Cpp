#include <string>
#include <vector>
#include <map>

using namespace std;

// map을 선언한다
map<string, int> mapset;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    // clothes 벡터의 두번째 값인 옷의 종류를 map의 key로 간주
    // 종류별 옷의 개수를 count
    for(int i = 0; i < clothes.size(); i++){
        mapset[clothes[i][1]]++;
    }
    
    // auto를 사용하여 mapset을 순회한다
    // 각 종류별 경우의 수는 (착용하지 않는 경우(1) + 옷의 개수)
    for(auto x : mapset){
        answer  *= (x.second + 1);
    }
    
    // 하나를 빼는 경우는 어떤 종류의 옷도 착용하지 않은 경우
    answer--;
    
    return answer;
}
