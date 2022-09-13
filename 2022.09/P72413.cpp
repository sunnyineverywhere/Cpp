#include <string>
#include <vector>
#include <algorithm>
#define INF 999999999 // 플로이드 워셜 알고리즘은 각 노드를 무한대와 비교하므로

using namespace std;

// s는 시작지점
// a, b는 집
// n은 노드의 개수
// fares에는 요금이 계산되어 있다
long long solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    long long answer = 0;
    
    // fares 배열에는 양방향으로 표기되어 있지 않으므로,
    // 새로운 이차원 배열 선언하여 양방향으로 표시해주자
    vector<vector<int>> arr(n+1, vector<int>(n+1, INF));
    for(int i = 0; i < fares.size(); i++){
        arr[fares[i][0]][fares[i][1]] = fares[i][2];
        arr[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    
    // s->a, s->b : 합승하지 않는 경우
    // s->a->b
    // s->b->a
    // 이 부분 코드는 참고해서 짬. 이해가 잘 안 감.
    for(int i = 1; i<=n; i++){
        for(int j = 1; j <=n; j++){
            for(int k = 1; k <=n; k++){
                if(arr[k][i] == INF || arr[i][k] == INF){
                    continue;
                }
                else{
                    arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
                }
            }
        }
    }
    
    long long case1 = arr[s][a] + arr[s][b];
    long long case2 = arr[s][a] + arr[a][b];
    long long case3 = arr[s][b] + arr[b][a];
    
    answer = min(min(case1, case2), case3);
    
    for(int i = 1; i<=n; i++){
        if(i == s || i == a || i == b){
            continue;
        }
        else{
            answer = min(answer, (long long)(arr[s][i] + arr[i][a] + arr[i][b]));
        }
    }
    
    return answer;
}
