#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include "Vector.h"

void __printVector(Vector *vectorPtr)
{
    for (int i = 0; i < vectorPtr->currentSize ; i++)
        printf(" %d,", vectorPtr->elementBuffer[i]);
    printf("\n");
}

void Test_vectorPush(Vector * vectorPtr)
{
    srand(time(0));
    for (int i = 0; i < 5; i++)
    {
        vectorType number = rand() % 100;
        vectorPush(vectorPtr, number);
        assert(number == vectorPtr->elementBuffer[i]);
    }
}

void Test_vectorInsert(Vector *vectorPtr)
{
    srand(time(0));
    int index =  rand() % vectorPtr->currentSize;
    vectorType  element =  rand() % 1000;

    //Create an new Array and copy the elementBuffer here, before inserting anything
    vectorType *tmpBuffer =  malloc(sizeof(vectorType) * vectorPtr->currentSize -1);
    int tmpBufferSize = vectorPtr->currentSize;
    memcpy(tmpBuffer, vectorPtr->elementBuffer, sizeof(vectorType) * vectorPtr->currentSize - 1);

    vectorInsert(vectorPtr, index, element);

    assert(vectorPtr->elementBuffer[index] == element);

        //  Check if all the remaning elements after the insert index have been successfully copied to
        // the new array 
    
    for (int i = index; i < tmpBufferSize; i++)
    {
        assert(tmpBuffer[i] == vectorPtr->elementBuffer[i+1]);
    }
    
}


int main(void)
{
    Vector  vector;
    Vector *vectorPtr =  &vector;
    vectorInit(vectorPtr);
    Test_vectorPush(vectorPtr);
    Test_vectorInsert(vectorPtr);
    vectorFree(vectorPtr);
}