//
// Created by steve park on 2019/10/12.
// 아직 미완성임...
//

#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

int N, M;

vector<int> list[10001];
bool check[10001];
int COUNT = 0;
int TOTAL = 0;

void dfs(int vertex){

    COUNT++;
    check[vertex] = true;

    if(vertex == N*M){
        TOTAL = COUNT;
        return;
    }

    for(int i=list[vertex].size()-1; i>=0; i--)
        if(!check[list[vertex][i]]) dfs(list[vertex][i]);


}

int main(){

    scanf("%d %d\n", &N, &M);
    char buff[M+1], input[M+1];

    for(int i=0; i<N; i++){
        scanf("%s", input);
        for(int j=0; j<M; j++){
            if(input[j]-'0' == 1){
                if(i!=0 && buff[j]-'0' == 1){
                    list[M*(i-1) + j+1].push_back(M*(i) + j+1);
                    list[M*i + j+1].push_back(M*(i-1) + j+1);
                }
                if(input[j+1]-'0' == 1){
                    list[M*(i) + j+1].push_back(M*(i) + j+2);
                    list[M*(i) + j+2].push_back(M*(i) + j+1);
                }
            }
        }
        strcpy(buff, input);
    }

    for(int i=0; i<N*M; i++) sort(list[i].begin(), list[i].end());

    dfs(1);

    printf("%d\n", TOTAL);

    return 0;
}
