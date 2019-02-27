#include "Vector.h"
#include "stdlib.h"
#include "stdio.h"

void __printVectorDebug(Vector *vectorPtr)
{
    for (int i = 0; i < vectorPtr->currentSize ; i++)
        printf(" %d,", vectorPtr->elementBuffer[i]);
    printf("\n");
}

static void  __vectorResize(Vector *vector, int newCapacity)
{
    vector ->elementBuffer = realloc(vector->elementBuffer,
                                    newCapacity);

    assert(vector->elementBuffer != NULL);
}


/* Check Buffer size and grow or shrink it based on current
and max size */
static void __checkAndResizeBuffer(Vector *vector)
{
    if (vector->currentSize == vector->maxSize)
    {
        __vectorResize(vector, vector->maxSize * 2);
    }
    else if (vector->currentSize == vector->maxSize / 4)
    {
        __vectorResize(vector, vector->maxSize / 2);
    }
}

static void __swap(vectorType *element1, vectorType *element2)
{
    vectorType tmp =  *element1;
    *element1 = *element2;
    *element2 = tmp;
}

static void __shiftVectorToRight(Vector *vector, int startIndex)
{
    vectorType temp = vector->elementBuffer[startIndex];
    for (int i = (startIndex + 1); i < vector->currentSize; i++)
    {

        __swap(&temp, (vector->elementBuffer + i));
    }

    __checkAndResizeBuffer(vector);
    vector->elementBuffer[vector->currentSize] = temp;
    vector->currentSize += 1;
}

static void __shiftVectorToLeft(Vector *vector, int startIndex)
{
    for (int i = startIndex; i  < (vector->currentSize - 1); i++ )
    {
        __swap(vector->elementBuffer + i, vector->elementBuffer + (i + 1));
    }
    vector->elementBuffer[vector->currentSize - 1] = -1;
    vector->currentSize -= 1;
    __checkAndResizeBuffer(vector);
}

void vectorInit(Vector *vector)
{
    vector->currentSize = 0;
    vector->maxSize = 16;
    vector->elementBuffer = malloc(VECTOR_INITIAL_SIZE *
                                    sizeof(vectorType));
    
    assert (vector->elementBuffer != NULL);
}

int vectorSize(Vector *vector)
{
    return vector->currentSize;
}

int vectorCapacity(Vector *vector)
{
    return  vector->maxSize;
}

bool vectorIsEmpty(Vector *vector)
{
    return vector->currentSize == 0 ? true: false;
}

vectorType vectorAt(Vector *vector, int index)
{
    assert( (index < vector->currentSize) && (index >= 0) );
    assert(vector->elementBuffer  != NULL);

    return vector->elementBuffer[index]; 
}

void vectorPush(Vector *vector, vectorType element)
{
    assert(vector->elementBuffer != NULL);
    __checkAndResizeBuffer(vector);
    vector->elementBuffer[vector->currentSize] = element;
    vector->currentSize += 1;
}

void vectorInsert(Vector *vector, int index, vectorType element)
{
    assert(vector->elementBuffer != NULL);

    __shiftVectorToRight(vector, index);

    vector->elementBuffer[index] = element;
}

void vectorPrepend(Vector *vector, vectorType element)
{
    vectorInsert(vector, 0, element);
}

vectorType vectorPop(Vector *vector)
{
    assert(vector->elementBuffer != NULL);
    vectorType value = vector->elementBuffer[vector->currentSize -1];
    vector->currentSize -= 1;
    __checkAndResizeBuffer(vector);
    return value;
}

void vectorDelete(Vector *vector, int index)
{
    assert(vector->elementBuffer != NULL);
    __shiftVectorToLeft(vector, index);
}

vectorType vectorFind(Vector *vector, vectorType element)
{
    assert(vector->elementBuffer != NULL);
    for (int i = 0; i < vector->currentSize; i++)
    {
        if (vector->elementBuffer[i] == element)
            return i;
    }
    return -1;
}

void vectorFree(Vector *vector)
{
    free(vector->elementBuffer);
    vector->currentSize = 0;
    vector->maxSize = VECTOR_INITIAL_SIZE;
}

