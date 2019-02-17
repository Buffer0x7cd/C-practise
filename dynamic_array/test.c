#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>


struct Vector
{
    int data;
    int cap;
    struct Vector* vec;
};

void print_struct(struct Vector *vec)
{
    printf("Data is %d\nCap is %d\n", vec->data, vec->cap);
}

struct Vector* init_on_stack(void)
{
    struct Vector stack_vector = {.data = 10, .cap = 20, .vec = NULL};
    return &stack_vector;
}

struct Vector* init_on_heap(void)
{
    struct Vector *heap_vector = (struct Vector *)malloc(sizeof(struct Vector));
    heap_vector->data = 200;
    heap_vector-> cap = 300;
    return heap_vector;
}
void main(void)
{
    printf("Printing Heap struct\n");
    // Initialize on Heap and return pointer to a memory allocated in heap
    struct Vector *heap_vector = init_on_heap();
    print_struct(heap_vector);
    // Initialize in Stack and return pointer to memory in stack
    printf("Printing Stack struct");
    struct Vector *stack_vector = init_on_stack();
    print_struct(stack_vector);


}
