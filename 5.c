// Q1) Temperature Monitoring and Conversion System 
// A temperature monitoring device logs temperature readings in the format:
// "TimeStamp-TemperatureUnit, TimeStamp-TemperatureUnit"
// For example:
// "08:30-22.5F, 12:15-25.0C, 15:45-24.8F"
// Extracts the timestamp and temperature along with its unit (Celsius or Fahrenheit).
// Converts the temperature:
// If the input temperature is in Celsius (C), convert it to Fahrenheit (F) using the formula:
// F=(C×9/5)+32
// If the input temperature is in Fahrenheit (F), convert it to Celsius (C) using the formula:
// C=(F−32)×5/9
// INPUT : 
// "08:30-22.5F, 12:15-25.0C, 15:45-24.8F"
// OUTPUT : 
// 08:30 - Original: 22.5°F, Converted: -5.3°C
// 12:15 - Original: 25.0°C, Converted: 77.0°F


// 15:45 - Original: 24.8°F, Converted: -4.0°C


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void convert(char *token){
    char time[10];
    float temp;
    char ch;
    float converted_temp;
    char converted_unit;
    sscanf(token," %[^-]-%f%c",time,&temp,&ch);
   printf("%s %f, %c",time,temp,ch);
 if (ch == 'C') {
        converted_temp = (temp * 9 / 5) + 32;
        converted_unit = 'F';

}
else { 
        converted_temp = (temp - 32) * 5 / 9;
        converted_unit = 'C';
    }
     printf("%s - Original: %.1f%c, Converted: %.1f%c\n", time, temp, ch, converted_temp, converted_unit);
}



int main(){
    char input[10000];
    printf("enter the input ");
    fgets(input,sizeof(input),stdin);
   // char input[]="08:30-22.5F, 12:15-25.0C, 15:45-24.8F";
    char *token=strtok(input,", ");
    
 
 
    while (token != NULL) {
        convert(token);
        // printf("%s\n",token);
        token = strtok(NULL, ",");
    }
    return 0;
}



