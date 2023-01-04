#include <stdio.h>

void background_gray() {
    printf("\033[100m");
}

void reset() {
    printf("\033[0m");
}

void combinational(int i0, int i1, int i2, int s0, int s1, int s2, int* S){

    // AND --> & , OR --> |, NOT --> !
    S[0] = (s2 & (!i0) & (!i1) & i2) | (s1 & (!i0) & (!i1) & i2); // s2i0'i1'i2 + s1i0'i1'i2
    S[1] = (s1 & i0) | (s1 & (!s2) & (!i2)) | (s1 & (!i1) & (!i2)) | (s1 & i1 & i2) | ((!s1) & s2 & (!i0) & i1 & (!i2)); // s1i0 + s1s2'i2' + s1i1'i2' + s1i1i2 + s1's2i0'i1i2'
    S[2] = (s2 & i0) | ((!s0) & (!s1) & i0) | (s2 & (!i1) & (!i2)) | (s2 & i1 & i2) | (s1 & (!i0) & i1 & (!i2)); // s2i0 + s0's1'i0 + s2i1'i2' + s2i1i2 + s1i0'i1i2'

}

// original
// void print_monitor(int s0, int s1, int s2){
// printf("              ,---------------------------, \n");
// printf("              |  /---------------------\\  | \n");
// printf("              | |                       | | \n");
//     if(s0==0 && s1==0 && s2==0){
// printf("              | |  PLEASE TAP YOUR CARD | | \n");    
//     } else if(s0==0 && s1==0 && s2==1){
// printf("              | |    DURATION: 1 HOUR   | | \n");        
//     } else if(s0==0 && s1==1 && s2==0){
// printf("              | |    DURATION: 2 HOURS  | | \n");           
//     } else if(s0==0 && s1==1 && s2==1){
// printf("              | |    DURATION: 3 HOURS  | | \n");           
//     } else if(s0==1 && s1==0 && s2==0){  
// printf("              | |        PRINTING...    | | \n");         
//     }            
        
// printf("              | |                 \033[0m      | | \n");
// printf("              |  \\_____________________/  | \n");
// printf("              |                           | \n");
// printf("              |                           | \n");
// printf("              |       +          ok       | \n");
// printf("              |                           | \n");
// printf("              |___________________________| \n\n");
// }

// colored
void print_monitor(int s0, int s1, int s2){
printf("              ,---------------------------, \n");
printf("              |  /---------------------\\  | \n");
printf("              | |\033[44m                       \033[0m| | \n");
    if(s0==0 && s1==0 && s2==0){
printf("              | |\033[44m  \033[0m\033[33m\033[1mPLEASE TAP YOUR CARD\033[0m\033[44m \033[0m| | \n");    
    } else if(s0==0 && s1==0 && s2==1){
printf("              | |\033[44m    \033[0m\033[33m\033[1mDURATION: 1 HOUR\033[0m\033[44m   \033[0m| | \n");        
    } else if(s0==0 && s1==1 && s2==0){
printf("              | |\033[44m    \033[0m\033[33m\033[1mDURATION: 2 HOURS\033[0m\033[44m  \033[0m| | \n");           
    } else if(s0==0 && s1==1 && s2==1){
printf("              | |\033[44m    \033[0m\033[33m\033[1mDURATION: 3 HOURS\033[0m\033[44m  \033[0m| | \n");           
    } else if(s0==1 && s1==0 && s2==0){  
printf("              | |\033[44m       \033[0m\033[33m\033[1mPRINTING...\033[0m\033[44m     \033[0m| | \n");         
    }              
printf("              | |\033[44m                       \033[0m| | \n");
printf("              |  \\_____________________/  | \n");
printf("              |                           | \n");
printf("              |                           | \n");
printf("              |       \033[34m\033[1m+\033[0m          \033[32m\033[1mok\033[0m       | \n");
printf("              |                           | \n");
printf("              |___________________________| \n\n");
}




void print_receipt(char* duration, char* checkin, char* checkout){

// system("clear");  
printf("         +-------------------------------------+\n");
printf("         |                                     |\n");
printf("         |            Abi's car park           |\n");
printf("         |                                     |\n");  
printf("         |            Member's name            |\n");
printf("         |              AB 10V3 AP             |\n");
printf("         |                                     |\n");
printf("         |              %-23s|\n",duration);
printf("         |                                     |\n");
printf("         |                                     |\n");
printf("         |          check in%10s         |\n",checkin);
printf("         |          check out%10s        |\n",checkout);
printf("         |                                     |\n");
printf("         |                                     |\n");
printf("         |             THANK YOU!              |\n");
printf("         |                                     |\n");
printf("         +-------------------------------------+\n\n\n");


}
