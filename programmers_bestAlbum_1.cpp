/*
 프로그래머스 / 해시 / 베스트 엘범
 https://programmers.co.kr/learn/courses/30/lessons/42579
 문제에서 기본으로 제공해 주는 library를 제외한 다름 library 사용 자제한 경우.
 */


#include <string>
#include <vector>


using namespace std;

int mod = 100;

struct P{
    int index;
    int playtime;
};

struct G{
    int total_play;
    string genre;



    struct P p[2];

    int next;

    G(){
        total_play = 0;
        for(int i=0; i<3; i++){
            p[i].index = -1;
            p[i].playtime = 0;
        }
        next = 0;
        genre = "";
        next = 0;
    }

    vector<int> add(vector<int>& answer){
        for(int i=0; i<2; i++){
            if(p[i].index != -1)
                answer.push_back(p[i].index);
        }
        return answer;
    }

    void updateP(int play_time, int index){

        for(int i=0; i<2; i++){
            if(!p[i].playtime){
                p[i].index = index;
                p[i].playtime = play_time;
                break;
            }

            if(p[i].playtime < play_time){
                if(!i){
                    p[1].playtime = p[0].playtime;
                    p[1].index = p[0].index;
                }
                p[i].index = index;
                p[i].playtime = play_time;

                break;
            }
        }
    }
};


int func(int k, int i){ return (i+k)%mod;};


int stringHash(string str){
    int m = 1e9;
    int p = 31;
    int pow_p = 1;

    int hashIndex = 0;

    for(int i=0; i<str.length(); i++){
        hashIndex = (hashIndex + (str[i] - 'a')*pow_p) % m;
        pow_p *= p % m;
    }
    return hashIndex;
}

void swapG(G* &first, G* &second){
    G* temp = first;
    first = second;
    second = temp;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    G *g[200];
    for(int i=0; i<200; i++) g[i] = 0;

    int biggest = 0, index = 0;
    for(int i=0; i<genres.size(); i++){
        int c = 0;
        while(true){
            int key = func(stringHash(genres[i]), c) % 101;
            if(!g[key]){
                g[key] = new G;
                g[key]->total_play += plays[i];
                g[key]->genre = genres[i];
                g[key]->updateP(plays[i], i);
                if (biggest < g[key]->total_play) {
                    biggest = g[key]->total_play;
                    index = key;
                }
                break;
            }
            else{
                if(!g[key]->genre.compare(genres[i])){
                    g[key]->total_play += plays[i];
                    g[key]->updateP(plays[i], i);
                    if (biggest < g[key]->total_play) {
                        biggest = g[key]->total_play;
                        index = key;
                    }
                    break;
                }
                else c++;
            }
        }

    }

    swapG(g[index], g[0]);

    for(int i=0; i<200; i++){
        if(!g[i]) continue;
        for(int j=i; j<200; j++){
            if(!g[j]) continue;
            if(g[i]->total_play < g[j]->total_play){
                swapG(g[i], g[j]);
                break;
            }
        }
        g[i]->add(answer);
    }





    return answer;
}


/*
--------------------------------------------------------------
절취선
 */

int main(){

    vector<string> genre;
    vector<int> plays;

    genre.push_back("classic");
    genre.push_back("pop");
    genre.push_back("classic");
    genre.push_back("classic");
    genre.push_back("pop");

    plays.push_back(500);
    plays.push_back(600);
    plays.push_back(150);
    plays.push_back(800);
    plays.push_back(2500);

    solution(genre, plays);

    return 0;
}
