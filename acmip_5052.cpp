//
// Created by steve park on 2019/10/08.
//

#include <iostream>
#include <stdio.h>

class Trie{
    Trie *next[10];
    bool expoint, nextis;

public:
    Trie(){
        memset(next, 0, sizeof(next));
        expoint = nextis = false;
    }

    ~Trie(){
        for(int i=0; i<10; i++) if(next[i]) delete(next[i]);
    }

    void update(const char *string){
        if(*string==0) expoint = true;
        else {
            int index = *string - '0';
            if (!next[index]) next[index] = new Trie;
            next[index]->update(string + 1);
            nextis = true;
        }
    }

    bool compare(){

        if(expoint && nextis) return false;

        for(int i=0; i<10; i++)
            if(next[i] && !next[i]->compare()) return false;

        return true;
    }
};

int main() {

    int t, n;
    char s[11];


    for(scanf("%d", &t); t>0; t--){
        Trie *root = new Trie;
        for(scanf("%d", &n); n>0; n--){
            scanf("%s", s);
            root->update(s);
        }
        printf("%s\n", root->compare()?"YES":"NO");
        delete root;
    }



    return 0;
}