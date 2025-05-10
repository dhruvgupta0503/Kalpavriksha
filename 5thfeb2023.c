// A user enters a list of timestamps in the format "hh:mm am/pm" separated by commas (e.g., "10:30 am, 2:45 pm, 6:10 am").
// Extracts the hour and minute from each timestamp and Converts it into 24-hour format.

// INPUT : 
// "10:30 am, 2:45 pm, 6:10 am, 12:00 am, 12:30 pm"

// OUTPUT: 
// 10:30 am → 10:30
// 2:45 pm → 14:45
// 6:10 am → 06:10
// 12:00 am → 00:00
// 12:30 pm → 12:30


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convert(char* timestamp) {
    int hour, minute;
    char period[3];
    sscanf(timestamp, " %d :%d %s", &hour, &minute, period);
    if(strcmp(period,"am")==0){
        if(hour==12) {
            hour=0;
        }
    }
    else {
        hour+=12;
    }
    printf("%d:%d\n", hour, minute);
}
int main(){
    char input[100000];
    printf("enter the input");
    fgets(input,sizeof(input),stdin);

    char *token=strtok(input,",");
    while(token!=NULL){
        
        convert(token);
        token=strtok(NULL,",");

    } 

    return 0;
}








































