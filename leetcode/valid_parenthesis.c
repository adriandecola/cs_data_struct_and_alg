/*
Author: Adrian deCola
Leetcode link: https://leetcode.com/problems/valid-parentheses
*/


////////// structs //////////
typedef struct stack{
    int size;
    int capacity;
    char* array;
} STACK;

////////// Function Declarations //////////
STACK* stack_init();
void stack_destroy(STACK* stack);
void stack_pop(STACK* stack);
char stack_top(STACK* stack);
void stack_push(STACK* stack, char paren);
void stack_resize(STACK* stack);


bool isValid(char * s){
    STACK* stack = stack_init();
    int i = 0;
    // iterating through the string
    while (s[i] != '\0'){
        if (s[i] == '(' || s[i] == '{' || s[i] == '['){
            stack_push(stack, s[i]);
        }
        else if (s[i] == ')'){
            if (stack_top(stack) == '('){
                stack_pop(stack);
            }
            else{
                stack_destroy(stack);
                return false;
            }
        }
        else if (s[i] == '}'){
            if (stack_top(stack) == '{'){
                stack_pop(stack);
            }
            else{
                stack_destroy(stack);
                return false;
            }
        }
        else{
            if (stack_top(stack) == '['){
                stack_pop(stack);
            }
            else{
                stack_destroy(stack);
                return false;
            }
        }
        i++;
    }
    if (stack->size != 0){
        stack_destroy(stack);
        return false;
    }
    stack_destroy(stack);
    return true;
}



////////// Function Implementations //////////

// initialized a stack object with a capacity of 10
// I'm going to assume all the mallocs work
// this is a stack of characters
STACK* stack_init(){
    STACK* stack = (STACK*)malloc(sizeof(STACK));
    stack->size = 0;
    stack->capacity = 10;
    stack->array = (char*)malloc(sizeof(char) * stack->capacity);
    return stack;
}

void stack_destroy(STACK* stack){
    free(stack->array);
    free(stack);
    return;
}

void stack_pop(STACK* stack){
    if (stack->size == 0){
        printf("popping from empty stack\n");
        exit(-1);
    }
    stack->size--;
    return;
}

char stack_top(STACK* stack){
    if (stack->size == 0){
        return '\0';
    }
    return stack->array[stack->size - 1];
}

void stack_push(STACK* stack, char paren){
    if (stack->size == stack->capacity){
        stack_resize(stack);
    }
    stack->array[stack->size] = paren;
    stack->size++;
    return;
}

void stack_resize(STACK* stack){
    stack->capacity *= 2;
    char* new_array = (char*)malloc(sizeof(char) * stack->capacity);
    // copying the old data
    int i;
    for (i = 0; i < stack->size; i++){
        new_array[i] = stack->array[i];
    }
    free(stack->array);
    stack->array = new_array;
    return;
}