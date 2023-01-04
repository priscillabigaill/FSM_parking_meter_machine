#include <stdio.h>
#include <unistd.h>
#include "mylib/mylib.h"

int main(void){

    int input=0;

    int s[3] = {0,0,0}; // current state
    int i[3]; // input bits
    int S[3];  // next state

    // internal memory
    int duration_chosen = 0;
    char duration[20];
    char checkout[20];
    char checkin[20];

    while(1){
        printf("\033[2J");
        printf("\033[1;1H");
        print_monitor(s[0],s[1],s[2]);

        if(s[0]==0 && s[1]==0 && s[2]==0){
            do{
                printf("Please tap your card (type 1 to emulate a tap event): ");
                scanf("%d",&input);
            } while(input != 1);
            if(input == 1){
                i[0] = 1;
                i[1] = 0; 
                i[2] = 0; 
            } else{
                i[0] = 0;
                i[1] = 0;
                i[2] = 0;
            }
        } else if(s[0]==0 && s[1]==0 && s[2]==1){
            do{
                printf("Please type 1 for the '+' button, type 0 for the 'OK' button: ");
                scanf("%d",&input);
            } while(input != 1 && input != 0);
            if(input == 1){
                i[0] = 0;
                i[1] = 1; 
                i[2] = 0; 
            } else {
                i[0] = 0;
                i[1] = 0;
                i[2] = 1;
            } 

            duration_chosen = 1;

        } else if(s[0]==0 && s[1]==1 && s[2]==0){
            do{
                printf("Please type 1 for the '+' button, type 0 for the 'OK' button: ");
                scanf("%d",&input);
            } while(input != 1 && input != 0);
            if(input == 1){
                i[0] = 0;
                i[1] = 1; 
                i[2] = 0; 
            } else {
                i[0] = 0;
                i[1] = 0;
                i[2] = 1;
            } 
            
            duration_chosen = 2;

        } else if(s[0]==0 && s[1]==1 && s[2]==1){
            do{
                printf("Please type 1 for the '+' button, type 0 for the 'OK' button: ");
                scanf("%d",&input);
            } while(input != 1 && input != 0);
            if(input == 1){
                i[0] = 0;
                i[1] = 1; 
                i[2] = 0; 
            } else {
                i[0] = 0;
                i[1] = 0;
                i[2] = 1;
            } 

            duration_chosen = 3;

        } else if(s[0]==1 && s[1]==0 && s[2]==0){
            
            if(duration_chosen == 1){
                sprintf(duration,"1 HOUR");
                sprintf(checkout,"01:00:05");
            } else if(duration_chosen == 2){
                sprintf(duration,"2 HOUR");
                sprintf(checkout,"02:00:05");
            } else {
                sprintf(duration,"3 HOUR");
                sprintf(checkout,"03:00:05");
            }

            sprintf(checkin,"00:00:05");

            sleep(3); // sleep 1 sec
            print_receipt(duration,checkin,checkout);
            sleep(3);
        }

        combinational(
            i[0], i[1], i[2], 
            s[0], s[1], s[2],
            S);


        // next state = current state in the next loop
        s[0] = S[0];
        s[1] = S[1];
        s[2] = S[2];
        
    }

    return 0;
}