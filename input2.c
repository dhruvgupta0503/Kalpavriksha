#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct Dictionary
{
    char key[50];
    char val[50];
} Dictionary;

int main()
{
    Dictionary d;
    int top = -1;
    char strp[] = "<name>Dhruv</name><age>21</age><city>Bangalore</city>";
    char *ptr = strp;
    int i = 0;
    char *token = strtok(ptr, "></");
    while (token != NULL)
    {
        i++;
        // printf("%s\n", token);
        if (i % 2 == 1)
            sscanf(token, "%s", d.key);
        else
            sscanf(token, "%s", d.val);
        if (i % 2 == 0)
            printf("%s----%s\n", d.key, d.val);
        token = strtok(NULL, "></");
        if (i % 2 == 0)
            token = strtok(NULL, "></");
    }

    return 0;
}


// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// int main(){
//     char str[]="Dhruv-Gupta";
//     char *token=strtok(str,"-");
//     while(token!=NULL){
//         printf("%s\n",token);
//         token=strtok(NULL,"-");
//     }
//     return 0;
// }


// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// int main(){
//     char [100]=
// }