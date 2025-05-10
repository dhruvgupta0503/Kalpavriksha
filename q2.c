#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int sensor_id;
    float temp;
    unsigned long timestamp;
}sensor;

// float generateTemp(){

// }
void addReading(sensor *s,int index,int sensor_id,float temp,unsigned long timestamp){
    s[index].sensor_id=sensor_id;
    s[index].temp=temp;
    s[index].timestamp=timestamp;
    
}
void print(sensor* s,int n){
    for(int i=0;i<n;i++)
    {
        printf("sensor id:%d,temp:%0.2f,Timestamp:%lu/n",s[i].sensor_id,s[i].temp,s[i].timestamp);
    }
    }
void freeMemory(sensor *s){
    free(s);
    printf("Memory freed successfully");
}
int main(){
    int n;
    scanf("%d",&n);
    int sensor_id;
    scanf("%d",&sensor_id);
    float temp;
    scanf("%f",&temp);
    sensor *s=(sensor*)malloc(sizeof(s));
    if(!s){
        printf("Memory allocation failed");
        return 1;
    }
    unsigned long timestamp=1700000000;
    // for(int i=0;i<n;i++){
    //     addReading(s,i,temp,timestamp++);
    // }
    for(int i=0;i<n;i++){
        addReading(s,i,sensor_id,temp,timestamp++);
    }
    print(s,n);
    free(s);
    return 0;

}
