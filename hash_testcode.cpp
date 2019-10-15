//
// Created by steve park on 2019/10/15.
//

#include <cstdio>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <random>
#include <stdio.h>


using namespace std;

vector<int> v,h;

int n, k, m1, m2;

int myrandom(int i){ return std::rand()%i; };

void randGenerator(vector<int>& v, int n, int k){
    srand(time(NULL));
    random_device rd;
    mt19937 g(rd());

    for(int i=0; i<=2*n; i++){
        v.push_back(i);
    }

    shuffle(v.begin(), v.end(), g);
}

int hashFunc1(int k){
    return k%m1;
}

int hashFunc2(int k){
    return 1+k%m2;
}

int doubleFunc(int k, int i){
    return (hashFunc1(k) + hashFunc2(k))%m1;
}

void hashing(vector<int>& v, vector<int>& h, int (*hashFunc)(int, int)){
    int first = -1, count = 0;
    double rate = 0.0;

    for(int i=0; i<k; i++){
        int c = 0;
        while(true){
            int key = hashFunc(v[i], c);
            if(h[key] == -1){
                h[key] = v[i];
                break;
            } else {
                if(first == -1){
                    first = v[i];
                    rate = (double) i / n*100;
                }
                count++;
                c++;
            }
        }
        printf("첫 충돌 값 : %d\n", first);
        printf("총 충돌 수 : %d\n", count);
        printf("첫 충돌 시 적재율 : %lf%%\n", rate);
    }
}


int main(){
    printf("키 값 범위의 크기 : ");
    scanf("%d", &k);
    printf("해시 테이블 크기 (1~n) : ");
    scanf("%d", &n);
    printf("m1 m2 입력 :  ");
    scanf("%d %d\n", &m1, &m2);

    printf("\n\n");
    randGenerator(v, n, k);

    for(int i=0; i<n; i++)
        h.push_back(-1);

    printf("\n");
    hashing(v, h, doubleFunc);
    printf("\n");
}
