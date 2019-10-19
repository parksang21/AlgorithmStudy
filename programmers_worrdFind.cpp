//
// Created by steve park on 2019/10/19.
// programmers dfs bfs wordfind(단어찾기)
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int total= 1e9;
vector<bool> isVisit;
bool isEnd;

class Node{
public:
    string word;
    vector<int> link;

    Node(string word){
        this->word = word;
    }

    bool canChange(const string str){
        int diff = 0, j = 0;
        for(int i=0; i<str.size(); i++){
            if(str[i] != word[j++]){
                diff++;
                if(diff > 1) return false;
            }
        }
        return true;
    }

    void linkNode(int index){
        link.push_back(index);
    }

};

void DFS(const vector<Node*> N, string target, int index=0, int depth=0){
    //이미 방문한 노드인 경우에 함수 탈출
    if(isVisit[index]) return;

    isVisit[index] = true;

    // 종단점을 만나면 함수 종료
    if(!N[index]->word.compare(target)) {
        isEnd=true;
        total = total > depth ? depth : total;
        isVisit[index]=false;
        return;
    }

    for(int i=0; i<N[index]->link.size(); i++){
        DFS(N, target, N[index]->link[i], depth+1);
    }

    isVisit[index] = false;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    vector<Node*> N(words.size());

    for(int i=0; i<words.size(); i++){
        string word = words[i];
        N[i] = new Node(word);
        for(int j=0; j<words.size(); j++){
            if(j==i) continue;
            if(N[i]->canChange(words[j]))
                N[i]->linkNode(j);
        }

    }

    isVisit.assign(N.size(), false);
    isEnd = false;

    total=1e9;
    for(int i=0; i<N.size(); i++){
        if(N[i]->canChange(begin))
            DFS(N, target, i);
    }
    answer = total < 1e9 ? total + 1 : 0;
    return answer;
}


/*
 ----------------------------------------------------------------
 */

int main(){

    string begin = "hit";
    string target = "cog";

    vector<string> words({"hot", "dot", "dog", "lot", "log", "cog"});

    cout << solution(begin, target, words);

    return 0;
}
