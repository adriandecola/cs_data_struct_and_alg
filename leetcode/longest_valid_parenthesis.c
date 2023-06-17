/*
Author: Adrian deCola
Leetcode link: https://leetcode.com/problems/longest-valid-parentheses
*/



////////// structs //////////
typedef struct stack{
    int size;
    int capacity;
    int* array;
} STACK;

////////// Function Declarations //////////
STACK* stack_init();
void stack_destroy(STACK* stack);
void stack_pop(STACK* stack);
int stack_top(STACK* stack);
void stack_push(STACK* stack, int paren);
void stack_resize(STACK* stack);
int stack_empty(STACK* stack);

int longestValidParentheses(char * s){
    int longest_so_far = 0;
    STACK* stack = stack_init();
    int start_index = 0; // start of valid subset so far
    int i;
    while (s[i] != '\0'){
        printf("i: %d\n", i);
        //pushing to the stack
        if (s[i] == '('){
            stack_push(stack, i);
        }
        // popping from stack
        else{
            // ran into unvalid combo
            if (stack_empty(stack) == 1){
                start_index = i + 1;
            }
            else{
                stack_pop(stack);
                // we could have an empty stack and still continuing
                // a valid subset
                if (stack_empty(stack) == 1){
                    printf("i: %d, start_index: %d\n",i, start_index);
                    if (longest_so_far < i - start_index + 1){
                        longest_so_far = i - start_index + 1;
                    }
                }
                else{
                    // one character past the one not popped is the
                    // 'start index'
                    if (longest_so_far < i - stack_top(stack)){
                        longest_so_far = i - stack_top(stack);
                    }
                }
            }
        }
        i++;
    }
    stack_destroy(stack);
    return longest_so_far;
}



////////// Function Implementations //////////

// initialized a stack object with a capacity of 10
// I'm going to assume all the mallocs work
// this is a stack of the indicies of the open parenthesis
STACK* stack_init(){
    STACK* stack = (STACK*)malloc(sizeof(STACK));
    stack->size = 0;
    stack->capacity = 10;
    stack->array = (int*)malloc(sizeof(int) * stack->capacity);
    return stack;
}

void stack_destroy(STACK* stack){
    free(stack->array);
    free(stack);
    return;
}

// returns 1 if the stack is empty and zero if not
int stack_empty(STACK* stack){
    if (stack->size == 0){
        return 1;
    }
    return 0;
}

void stack_pop(STACK* stack){
    if (stack->size == 0){
        printf("popping from empty stack\n");
        exit(-1);
    }
    stack->size--;
    return;
}

int stack_top(STACK* stack){
    if (stack->size == 0){
        printf("stack is empty");
        exit(-1);
    }
    return stack->array[stack->size - 1];
}

void stack_push(STACK* stack, int index){
    if (stack->size == stack->capacity){
        stack_resize(stack);
    }
    stack->array[stack->size] = index;
    stack->size++;
    return;
}

void stack_resize(STACK* stack){
    stack->capacity *= 2;
    int* new_array = (int*)malloc(sizeof(int) * stack->capacity);
    // copying the old data
    int i;
    for (i = 0; i < stack->size; i++){
        new_array[i] = stack->array[i];
    }
    free(stack->array);
    stack->array = new_array;
    return;
}

