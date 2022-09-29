#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int answer = 1;
vector<int> nodes[20];
vector<int> state;
bool visit[20][20][20];

void connect_nodes(vector<vector<int>> edges){
    for(auto n : edges){
        nodes[n[0]].push_back(n[1]);
        nodes[n[1]].push_back(n[0]);
    }
}

void dfs(int cur, int sheep, int wolf){
    // 재귀 탈출
    if(cur == 0){
        answer = max(sheep, answer);
    }
    
    for(auto next : nodes[cur]){
        if(state[next] == 0){
            if(!visit[next][sheep+1][wolf]){
                visit[next][sheep+1][wolf] = true;
                state[next] = -1;
                dfs(next, sheep+1, wolf);
                state[next] = 0;
                visit[next][sheep+1][wolf] = false;
            }
        }
        else if(state[next] == 1){
                if(!visit[next][sheep][wolf+1] && sheep > wolf+1){
                    visit[next][sheep][wolf] = true;
                    state[next] = -1;
                    dfs(next, sheep, wolf+1);
                    state[next] = 1;
                    visit[next][sheep][wolf] = false;
                }
        }
        else{
                if(!visit[next][sheep][wolf]){
                    visit[next][sheep][wolf] = true;
                    dfs(next, sheep, wolf);
                    visit[next][sheep][wolf] = false;
                }
            }
        }
}
    



int solution(vector<int> info, vector<vector<int>> edges) {
    connect_nodes(edges);
    state = info;
    state[0] = -1;
    visit[0][1][0] = false;
    
    dfs(0, 1, 0);
    
    return answer;
}
