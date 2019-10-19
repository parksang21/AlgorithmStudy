//
// Created by steve park on 2019/10/19.
//

/*
 programmers / dfsbfs / 네트워크
 leve 2

 created by 박상욱 at 2019.10.18
 */

#include <string>
#include <vector>

#include <iostream>

using namespace std;

int total = 0;

void DFS(const vector<vector<int>> com, vector<bool> &check, int start=0){
    if(check[start]) return;

    check[start]=true;


    for(int i=0; i<com[start].size(); i++){
        if(com[start][i] && !check[i]){
            DFS(com, check, i);
        }
    }
}



int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    vector<bool> is_check(n+1, false);



    for(int i=0; i<n; i++){
        if(is_check[i]) continue;
        total++;
        DFS(computers, is_check, i);
    }
    answer = total;
    return answer;
}


/*
 ----------------------------------------------------------
 절취선
 */

int main(){


    vector<vector<int>> computers({
                                          vector<int>({1, 1, 0}),
                                          vector<int>({1, 1, 1}),
                                          vector<int>({0, 1, 1})
                                  });

    cout << solution(3, computers);

    return 0;
}
