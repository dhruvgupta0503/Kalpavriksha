// char str[] = "{add(Document1,5)},{add(Document2,10)},{view()},{update(Document1,6)},{view()},{process()},{view()},{add(Document3,12)},{process()},{view()}";

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char str[] = "{add(Document1,5)},{add(Document2,10)},{view()},{update(Document1,6)},{view()},{process()},{view()},{add(Document3,12)},{process()},{view()}";  
    char *token = strtok(str, "{,}");
    while (token != NULL) {
        if (strlen(token) > 0) {
            printf("Token: %s\n", token);
        }
        token = strtok(NULL, "{,}");
    }

    return 0;
}
