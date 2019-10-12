

#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>

using namespace std;

int main(){


    string A;

    cin >> A;

    int buff1 = 1, buff2 = 1;
    int prime1[4] = {0};
    int prime2[4] = {0};

    for(int i=0; i<A.size(); i++){
        int temp = A[i] - '0';

        if(i < A.size()/2){
            buff1 *= temp;
            while(temp > 1){
                if(temp % 2 == 0){
                    prime1[0]++;
                    temp /= 2;
                }else if (temp % 3 == 0){
                    prime1[1]++;
                    temp /= 3;
                }else if (temp % 5 == 0){
                    prime1[2]++;
                    temp /= 5;
                }else if (temp % 7 == 0){
                    prime1[3]++;
                    temp /= 7;
                }
            }
        }
        else{
            buff2 *= temp;
            while(temp > 1){
                if(temp % 2 == 0){
                    prime2[0]++;
                    temp /= 2;
                }else if (temp % 3 == 0){
                    prime2[1]++;
                    temp /= 3;
                }else if (temp % 5 == 0){
                    prime2[2]++;
                    temp /= 5;
                }else if (temp % 7 == 0){
                    prime2[3]++;
                    temp /= 7;
                }
            }
        }
    }

    cout << "buff1 : " << buff1 << endl;
    cout << "buff2 : " << buff2 << endl;





    return 0;
}
