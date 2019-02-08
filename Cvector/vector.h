#ifndef VECTOR_H
#define VECTOR_H

#define VECTOR_INIT_CAPACITY 4



typedef struct vector
{
    void **items;
    int capacity;
    int total;
} vector;

int vector_init(vector *);
int vector_total(vector *);
static int vector_resize(vector *, int);
int vector_add(vector *, void *);
int vector_set(vector *, int, void *);
void* vector_get(vector *, int); 
int vector_delete(vector *, int);
void vector_free(vector *);

#endif