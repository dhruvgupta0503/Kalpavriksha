// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 
// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 
// Constraints:
 
// 2 <= nums.length <= 10^4
// -10^9 <= nums[i] <= 10^9
// -10^9 <= target <= 10^9
 
// Time constraint : O(n) using hash map

#include <stdio.h>
#include <stdlib.h>
#define TABLE 10
typedef struct {
    int key;
    int value;
    struct Node* next;
}Node;

typedef struct Hash{
    Node*table[TABLE];
}Map;

int hash(int key){
    return key%TABLE;
}
void init(Map*mp){
    for(int i=0;i<TABLE;i++){
        mp->table[i]=NULL;
    }
}

void insert(Map* mp,int key,int value){
    int index=hash(key);
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->key=key;
    newNode->value=value;
    newNode->next=mp->table[index];
    mp->table[index]=newNode;
}
int search(Map* mp,int key){
    int index=hash(key);
    Node* temp=mp->table[index];
    while(temp!=NULL)
    {
        if(temp->key==key){
            return temp->value;
        }
        temp=temp->next;
    }
    return -1;
}


int* twoSum(int* nums, int n, int target) {
    Map map;
    init(&map); 
    int* result = (int*)malloc(2 * sizeof(int));
    
for (int i = 0; i < n; i++) {
        int k = target - nums[i];
        int index = search(&map, k);

    if (index != -1) {
            result[0] = index;
            result[1] = i;
            return result;
        }

        insert(&map, nums[i], i);  
    }

  
    return NULL;
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int target;
    scanf("%d",&target);
 
    int *result=twoSum(a,n,target);
    if(result!=NULL){
        printf("[%d,%d]",result[0],result[1]);
        free(result);
    }else {
        printf("No solution found");
    }
    return 0;

}





































