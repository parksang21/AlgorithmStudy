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

    //각 노드들의 최대값을 구하는 함수
    void calculate(){
        int index = base - 1;
        while(index >= 1){
            tree[index] = max(tree[index * 2], tree[index * 2 + 1]);
            index--;
        }
    }

    int query(int targetL, int targetR, int curL, int curR, int index, int target){
        if(curL > targetR || curR < targetL || index >= tree.size()-1) return 0;

        //범위 내에 있는 경우
        if(targetL <= curL && curR <= targetR){
            if(target > tree[index]) return curR - curL + 1;
        }

        int mid = (curL + curR) >> 1;

        return query(targetL, targetR, curL, mid, index * 2, target)
               + query(targetL, targetR, mid+1, curR, index * 2 + 1, target);
    }

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

//    cout << "백준 2517번 달리기 문제" << endl;

    int N, buff;

    cin >> N;
    SegmentTree array(N);

    for(int i=0; i<N; i++){
        cin >> buff;
        array.tree[i+array.base] = buff;
    }

    array.calculate();
//    cout << N << endl;

//    array.print();

    int b = array.base + 1;

    cout << 1 << endl;
    for(int i=2; i <= N; i++){
        cout << i - array.query(1,i,1, N, 1, array.tree[b++]) << endl;
    }

    return 0;
}
