#include <vector>
#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;




vector<int> list[1001];
bool check[1001];
int N, M, V, a, b;

void dfs(int vertex){
    printf("%d ", vertex);
    check[vertex] = true;
    for(int i=0; i<list[vertex].size();i++)
        if(!check[list[vertex][i]]) dfs(list[vertex][i]);
}

void bfs(){
    memset(check, false, sizeof(check));
    queue<int> qu;
    int vertex;

    qu.push(V);
    check[V] = true;

    while(!qu.empty()){
        vertex = qu.front();
        qu.pop();
        printf("%d ", vertex);

        for(int i=0; i<list[vertex].size();i++){
            if(!check[list[vertex][i]]){
                qu.push(list[vertex][i]);
                check[list[vertex][i]] = true;
            }
        }

    }
}

int main(){

    memset(check, false, sizeof(check));

    scanf("%d %d %d", &N, &M, &V);

    for(int i=0; i< M; i++){
        scanf("%d %d", &a, &b);
        list[a].push_back(b);
        list[b].push_back(a);
    }

    for(int i=0; i<N; i++)
        sort(list[i].begin(), list[i].end());

    dfs(V);
    printf("\n");
    bfs();

    return 0;
}
