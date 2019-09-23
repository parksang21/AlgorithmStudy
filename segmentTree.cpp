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
        int index = base;
        while(index > 0){
            index >>= 1;
            tree[index] = tree[index * 2] + tree[index * 2 + 1];
        }
    }

    int quary(int targetL, int targetR, int curL, int curR, int index){
        if(curL > targetR || curR < targetL) return 0;
        if( targetL <= curL && curR <= targetR) return tree[index];
        int mid = (curL + curR) >> 1;
        return quary(targetL, targetR, curL, mid, index *2)
               + quary(targetL, targetR, mid + 1, curR, index * 2 + 1);
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