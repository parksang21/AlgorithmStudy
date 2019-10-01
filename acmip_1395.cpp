//
// Created by steve park on 2019/10/01.
//

#include <iostream>
#include <vector>

using namespace std;

class SegmentTree{
public:
    vector<int> tree;
    int base = 0;

public:
    //constructor
    SegmentTree(int size){
        base = 1;
        while(base < size) base <<= 1;
        tree.assign(base * 2 + 1, 0);
    }

    //각 노드들의 합을 구해주는 함수
    void sum(){
        int index = base - 1;
        while(index >= 1){
            tree[index] = tree[index * 2] + tree[index * 2 + 1];
            index--;
        }
    }

    long long quary(int targetL, int targetR, int curL, int curR, int index){
        if(curL > targetR || curR < targetL) return 0;
        if( targetL <= curL && curR <= targetR) return tree[index];
        int mid = (curL + curR) >> 1;

        return quary(targetL, targetR, curL, mid, index *2)
               + quary(targetL, targetR, mid + 1, curR, index * 2 + 1);
    }

    void update(int start, int end){

        start += base - 1;
        for(int i=start; i<end+1; i++){
            tree[i] = tree[i] == 1 ? 0 : 1;
            i >>= 1;
            while(i >= 1){
                tree[i] = tree[i * 2] + tree[i * 2 + 1];
                i >>= 1;
            }
        }
    }

    // 출력해주는 함수
    void print(){
        cout << "Segment Tree" << endl;
        for(int i=1; i<base; i++){
            printf("parent[%d]-%d\t", i, tree[i]);
        }
        cout << endl;
        for(int i=base; i<tree.size(); i++){
            printf("data[%d]-%d\t", i, tree[i]);
        }
        cout << endl;
    }

};

int main(){

    int N, M, O, num1, num2;

    cin >> N >> M;

    SegmentTree tree(N);

    for(int i=0; i<M; i++){
        cin >> O >> num1 >> num2;
        switch(O){
            case 0:
                tree.update(num1, num2);
                tree.print();
                break;
            case 1:
                cout << tree.quary(num1, num2, 1, N, 1) << endl;
                break;
        }

    }
    return 0;
}