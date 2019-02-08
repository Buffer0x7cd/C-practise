#include <stdio.h>
#include <stdlib.h>
#include <error.h>

#include "vector.h"


int error_code;
int vector_init(vector *v)
{
    v->capacity = VECTOR_INIT_CAPACITY;
    v->total = 0;
    v->items =  malloc(sizeof(void *)  * v->capacity);
    if (v->items == NULL)
    {
        #ifdef DEBUG_ON
        fprintf(stderr, "Failed to allocate the initial capacity pool of %d\n", v->capacity);
        #endif
        return 1;
    }
    return 0;
}

int vector_total(vector *v)
{
    return v->total;
}

static int vector_resize(vector *v, int capacity)
{
    #ifdef DEBUG_ON
    fprintf(stdout, "Resizing vector from %d to %d\n", v->capacity, capacity);
    #endif

    void **newitems = realloc(v->items, sizeof(void *) * capacity);

    if (!newitems)
    {
        #ifdef DEBUG_ON
        perror("Error while allocating a new capacity: ");
        #endif
        return 1;
    }

    v->items = newitems;
    v->capacity = capacity;

    return 0;
}

int vector_add(vector *v, void *element)
{
    if (v->total == v->capacity)
        vector_resize(v, v->capacity * 2);
    v->items[v->total++] = element;
    return 0;
}

int vector_set(vector *v, int index, void *element)
{
    if (index >= 0 && index < v->total)
        v->items[index] = element;
    else
    {
        #ifdef DEBUG_ON
        fprintf(stderr, "Index %d, is not in valid range", index);
        #endif
        return 1;
    }
    
}

void* vector_get(vector *v, int index)
{
    if (index >= 0 && index < v->total)
        return v->items[index];
    else
    {
        #ifdef DEBUG_ON
        fprintf(stderr, "Index %d, is not in valid range", index);
        #endif
    }
}

int vector_delete(vector *v, int index)
{
    if (index >= 0 && index < v->total)
    {
        v->items[index] = NULL;

        for (int i = index; i < v->total; i++)
        {
            v->items[i] = v->items[i+1];
            v->items[i+1] = NULL;
        }

        v->total -= 1;

        if (v->total > 0 && v->total ==  v->capacity /4 )
            vector_resize(v, VECTOR_INIT_CAPACITY / 2);
    }
}

void vector_free(vector *v)
{
    free(v->items);
}





