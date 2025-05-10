// #include <stdio.h>

// void calculateSpan(int prices[], int n, int span[]) {
//     for (int i = 0; i < n; i++) {
//         span[i] = 1;  // Initialize span for the current day
//         for (int j = i - 1; j >= 0 && prices[j] <= prices[i]; j--) {
//             span[i]++;
//         }
//     }
// }

// int main() {
//     int prices[] = {100, 80, 60, 70, 60, 75, 85};
//     int n = sizeof(prices) / sizeof(prices[0]);
//     int span[n];

//     calculateSpan(prices, n, span);

//     printf("Stock spans: ");
//     for (int i = 0; i < n; i++) {
//         printf("%d ", span[i]);
//     }

//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# define MAX 100
typedef struct{
    char stack[MAX];
    int top;
}Stack;

void initStack(Stack *s){
    s->top=-1;
}
int isFull(Stack *s){
    return s->top==MAX-1;
}
int isEmpty(Stack *s){
    return s->top== -1;
}
void push(Stack *s,char c){
    if(!isFull(s)){
        s->stack[++(s->top)]=c;
    }
}
char pop(Stack *s){
    if(!isEmpty(s)){
        return s->stack[(s->top--)];
    }
    return '\0';
}

typedef struct{
    char text[MAX];
    Stack undoStack;
    Stack redoStack;
}TextEditor;

void initEditor(TextEditor *editor){
    editor->text[0]='\0';
    initStack(&editor->undoStack);
    initStack(&editor->redoStack);
}

void type(TextEditor *editor, char c) {
    int len = strlen(editor->text);
    editor->text[len] = c;
    editor->text[len + 1] = '\0';
    push(&editor->undoStack, c);
    initStack(&editor->redoStack); 
}

void undo(TextEditor *editor) {
    if (!isEmpty(&editor->undoStack)) {
        char c = pop(&editor->undoStack);
        push(&editor->redoStack, c);
        editor->text[strlen(editor->text) - 1] = '\0';
    }
}

void redo(TextEditor *editor) {
    if (!isEmpty(&editor->redoStack)) {
        char c = pop(&editor->redoStack);
        type(editor, c);
    }
}

void printText(TextEditor *editor) {
    printf("Text: %s\n", editor->text);
}

int main() {
    TextEditor editor;
    initEditor(&editor);

    char choice;
    char input;

    while (1) {
        printf("Enter 't' to type, 'u' to undo, 'r' to redo, 'q' to quit: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 't':
                printf("Enter character to type: ");
                scanf(" %c", &input);
                type(&editor, input);
                printText(&editor);
                break;
            case 'u':
                undo(&editor);
                printText(&editor);
                break;
            case 'r':
                redo(&editor);
                printText(&editor);
                break;
            case 'q':
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}