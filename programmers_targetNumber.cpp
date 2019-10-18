//
// Created by steve park on 2019/10/18.
//

/*
 프로그래머스 / dfs.bfs / 타겟 넘버
 https://programmers.co.kr/learn/courses/30/lessons/43165
 */

#include <string>
#include <vector>

#include <iostream>

using namespace std;

void getSum(vector<int> &tree, const vector<int> numbers, int index1 = 1, int index2 = -1){
    if(index1 >= tree.size() || index2 >= (int) numbers.size()) return;

    if(index1 == 1) tree[index1] = 0;
    else{
        if(!(index1 % 2)) tree[index1] = tree[index1/2] + numbers[index2];
        else tree[index1] = tree[index1/2] - numbers[index2];
    }

    getSum(tree, numbers, index1 * 2, index2 + 1);
    getSum(tree, numbers, index1 * 2 + 1, index2 + 1);

}


int solution(vector<int> numbers, int target) {
    int answer = 0;

    int num = (int) numbers.size();

    int size = 1;

    while(num--) size <<= 1;

    vector<int> tree;
    tree.assign(size * 2 + 1, 0);

    getSum(tree, numbers);

    for(int i=size; i<tree.size();i++){
        if(tree[i] == target) answer++;
    }

    return answer;
}


int main(){

    int size = 1 << 5;

    cout << (2 & 2);

    return 0;
}
