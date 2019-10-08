//
// Created by steve park on 2019/10/01.
//

#include <iostream>
#include <vector>

using namespace std;

class SegmentTree{
public:
    vector<int> tree;
    vector<int> lazy;
//    int tree[100000*2] = {0};
//    int lazy[100000*2] = {0};
    int base = 0;

public:
    //constructor
    SegmentTree(int size){
        base = 1;
        while(base < size) base <<= 1;
        tree.resize(base * 2 + 1);
        lazy.resize(base * 2 + 1);
    }

    int quary(int targetL, int targetR, int curL, int curR, int index){
        if(curL > targetR || curR < targetL) return 0;
        propagate(curL, curR, index);
        if( targetL <= curL && curR <= targetR) return tree[index];
        int mid = (curL + curR) >> 1;

        return quary(targetL, targetR, curL, mid, index *2)
               + quary(targetL, targetR, mid + 1, curR, index * 2 + 1);
    }


    void propagate(int start, int end, int index){
        if(lazy[index]){
            if(start < end){
                lazy[index * 2] = !lazy[index*2];
                lazy[index * 2 + 1] = !lazy[index*2+1];
            }
            tree[index] = (end - start) + 1 - tree[index];
            lazy[index] = 0;
        }
    }



    void reverse(int start, int end, int curL, int curR, int index=1){
        if(start > curR || end < curL) return;
        propagate(curL, curR, index);

        if(start <= curL && curR <= end){
            tree[index] = end-start + 1 - tree[index];
            if(curL!=curR){
                lazy[index * 2] = !lazy[index*2];
                lazy[index * 2 + 1] = !lazy[index*2+1];
            }
            return;
        }

        int mid = (curL + curR) >> 1;
        reverse(start, end, curL, mid, index*2);
        reverse(start, end, mid+1, curR, index*2+1);
    }

};

int main(){

    int N, M, O, num1, num2;

    cin >> N >> M;

    SegmentTree tree(N);

    for(int i=0; i<M; i++){
        cin >> O >> num1 >> num2;
        if(O)
            cout << tree.quary(num1, num2, 1, N, 1) << endl;
        else
            tree.reverse(num1, num2, 1, N, 1);
//

    }
    return 0;
}
