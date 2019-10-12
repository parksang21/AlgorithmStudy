
/*
 acmipc_17365 번 별다줄...
 Created by Sang Uk Park on 2019 10 08
 */

#include <stdio.h>
#include <string.h>


class Trie{
    // 알파벳 개수는 26개
    Trie *ch[26];
    bool EOH;

public:
    Trie(){
        memset(ch, 0, sizeof(ch));
        EOH = false;
    }
    ~Trie(){
        for(int i=0; i<26; i++) if(ch[i]) delete ch[i];
    }

    void update(const char *S){
        if(S==0) EOH = true;
        else{
            int index = *S - 'a';
            if(!ch[index]) ch[index] = new Trie;
            ch[index]->update(S+1);
        }
    }



};


int main(){

    printf("acmipc 17365번\n");


    return 0;
}
