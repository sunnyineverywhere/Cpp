#include <string>
#include <vector>

using namespace std;

vector<int> answer(1, -1);
int max_difference = 0;


bool compare(vector<int> lion){
    for(int i = 11; i>0; i--){
        if(lion[i] < answer[i]){
            return false;
        }
        else if(lion[i] > answer[i]){
            return true;
        }
    }
}


void calculation(vector<int> apeach, vector<int> lion){
    int apeach_score = 0;
    int lion_score = 0;
    
    // 각 점수 계산
    for(int i = 0; i< 11; i++){
        if(apeach[i] < lion[i]){
            lion_score += 10 - i;
        }
        else if(apeach[i] == 0 && lion[i] == 0){
            continue;
        }
        else{
            apeach_score += 10 - i;
        }
    }
    
    // 점수 차이 계산
    int tmp_difference = lion_score - apeach_score;
    
    // 어피치 우승시 리턴
    if(tmp_difference < 0){
        return;
    }
    // 점수 차이가 같을 때, 과녁
    else if(tmp_difference == max_difference){
        if(!compare(lion)){
            return;
        }
        else{
            answer = lion;
        }
    }
    else if(max_difference < tmp_difference){
        max_difference = tmp_difference;
        answer = lion;
    }
    return;
}

void dfs(int idx, int arrow, vector<int> apeach, vector<int> lion) {
    // 재귀 탈출 조건
    if(idx == 11 || arrow == 0){
        lion[10] += arrow;
        calculation(apeach, lion);
        lion[10] -= arrow;
        return;
    }
    
    // 재귀
    if(apeach[idx] < arrow){
        lion[idx] += apeach[idx] + 1;
        dfs(idx+1, arrow - lion[idx], apeach, lion);
        lion[idx] -= apeach[idx] +1; 
    }
    dfs(idx+1, arrow, apeach, lion);
}

vector<int> solution(int n, vector<int> info) {
    
    vector<int> apeach = info;
    vector<int> lion(11, 0);
    
    dfs(0, n, apeach, lion);
    
    if(answer.empty()){
        answer.push_back(-1);
    }
    
    return answer;
}
