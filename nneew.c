#include<stdio.h>
#include<string.h>
/*Q1) Temperature Monitoring and Conversion System 
A temperature monitoring device logs temperature readings in the format:
"TimeStamp-TemperatureUnit, TimeStamp-TemperatureUnit"
For example:
"08:30-22.5F, 12:15-25.0C, 15:45-24.8F"
Extracts the timestamp and temperature along with its unit (Celsius or Fahrenheit).
Converts the temperature:
If the input temperature is in Celsius (C), convert it to Fahrenheit (F) using the formula:
F=(C×9/5)+32
If the input temperature is in Fahrenheit (F), convert it to Celsius (C) using the formula:
C=(F−32)×5/9
INPUT : 
"08:30-22.5F, 12:15-25.0C, 15:45-24.8F"
OUTPUT : 
08:30 - Original: 22.5°F, Converted: -5.3°C
12:15 - Original: 25.0°C, Converted: 77.0°F
15:45 - Original: 24.8°F, Converted: -4.0°C
*/
 
int main(){
    char input[100];
    fgets(input,sizeof(input),stdin);
    int n=strlen(input);
    if(n>0 && input[n-1]=='\n'){
        input[n-1]='\0';
        n--;
    }
    char *ptr=input;
    int h,m;
    char ch;
    double temp;
    while(*ptr){
    if(sscanf(ptr,"%d:%d - %lf %c,",&h,&m,&temp,&ch)==4){
        if(ch=='F'){
            double c =(temp-32)*5/9;
            printf("%02d:%02d - Original: %.1f°F, Converted:%.1f°C\n",h,m,temp,c);
        }else{
            double f=(temp*9/5)+32;
            printf("%02d:%02d - Original: %.1f°C, Converted:%.1f°F\n",h,m,temp,f);         
        }
    }
    while(*ptr && *ptr!=','){
            ptr++;
        }
        if (*ptr==',')
          ptr++;
    }
return 0;
}