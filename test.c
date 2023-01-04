#include <stdio.h>
#include "mylib/mylib.h"

int main(void){

    int i[3] = {0,0,1}; // input bits
    int s[3] = {0,1,1}; // current state
    int S[3]; // next state

    int test_input[6][3] = {
        {0,0,0},{0,1,1},{1,1,1},
        {1,0,0},{1,0,1},{1,1,0}
        };

    for(int j=0; j<6; j++){

        i[0] = test_input[j][0];
        i[1] = test_input[j][1];
        i[2] = test_input[j][2];

        // printf("%d %d %d\n",test_input[i][0],test_input[i][1],test_input[i][2]);

        combinational(
            i[0], i[1], i[2], 
            s[0], s[1], s[2],
            S);

        if(S[0]==0 && S[1]==0 && S[2]==0){
            printf("Next state: IDLE\n"); 
        } else if(S[0]==0 && S[1]==0 && S[2]==1){
            printf("Next state: 1 HOUR\n"); 
        } else if(S[0]==0 && S[1]==1 && S[2]==0){
            printf("Next state: 2 HOURS\n"); 
        } else if(S[0]==0 && S[1]==1 && S[2]==1){
            printf("Next state: 3 HOURS\n"); 
        } else if(S[0]==1 && S[1]==0 && S[2]==0){
            printf("Next state: PRINTING\n"); 
        }
    }

    return 0;
}
