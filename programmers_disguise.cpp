//
// Created by steve park on 2019/10/16.
//

#include <string>
#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

int mod1, mod2;

class Node{
public:
    int count;
    string name;

    Node(string n){
        count = 2;
        name = n;
    }

    bool compare(string str){

        if(!str.compare(name))
            return true;
        return false;
    }
};

Node * arr[31];

int func1(int k){ return k%mod1; }

int func2(int k, int i){ return i+k%mod2; }


void hashing(vector<vector<string>> clothes, int (*doubleHash)(int, int)){
    for(int i=0; i<31; i++) arr[i] = 0;
    mod1 = 30;
    mod2 = 30;
    for(int i=0; i<clothes.size(); i++){
        int c = 0;
        int key = 0;
        const int p = 31;
        const int m = 1e9 + 9;

        unsigned int hash_val = 0;
        int pow_p = 1;

        for(int j=0; j<clothes[i][1].length(); j++){
            hash_val = (hash_val + (clothes[i][1][j] - 'a' + 1) * pow_p) % m;
            pow_p = (p * pow_p) % m;
        }


        while(true){
            key = doubleHash(hash_val, c);
            if(!arr[key]){
                arr[key] = new Node(clothes[i][1]);
                break;
            } else {
                if (arr[key]->compare(clothes[i][1])) {
                    arr[key]->count++;
                    break;
                } else c++;
            }
        }
    }
}


int solution(vector<vector<string>> clothes){
    int answer = 0;

    hashing(clothes, func2);

    for(int i=0; i<31; i++){
        if(!arr[i]) answer *= arr[i]->count;
    }

    return answer - 1;
}


int main(){

    vector<vector<string>> test;

    vector<string> a1, a2, a3;

    a1.push_back("yellow_hat");
    a1.push_back("headgear");

    a2.push_back("blue_sunglasses");
    a2.push_back("eyewear");

    a3.push_back("green_turban");
    a3.push_back("headgear");

    test.push_back(a1);
    test.push_back(a2);
    test.push_back(a3);

    cout << solution(test) << endl;


    return 0;
}
