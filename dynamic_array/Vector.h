#include <stdbool.h>
#define vectorType int
#define VECTOR_INITIAL_SIZE 16

typedef struct{
    int currentSize;
    int maxSize;
    vectorType* elementBuffer;
} Vector;

// Status Code:
// false : last operation failed
// true : last operation passed

//Initialize the Vector struct stored at calling Functions Stack
void vectorInit(Vector *vector);

int vectorSize(Vector *vector);

int vectorCapacity(Vector *vector);

bool vectorIsEmpty(Vector *vector);

vectorType vectorAt(Vector *vector, int index);


//TODO: Handle Out of memory case
void vectorPush(Vector *vector, vectorType element);

//TODO: OOM Handling
void vectorInsert(Vector *vector, int index, vectorType element);

//TODO: OOM Handling
void vectorPrepend(Vector *vector, vectorType element);

vectorType vectorPop(Vector *vector);

void vectorDelete(Vector *vector, int index);

int vectorRemove(Vector *vector, vectorType element);

int vectorFind(Vector *vector, vectorType element);

static void __vectorResize(Vector *vector, int newCapacity);

static void __shiftVectorToRight(Vector *vector, int startIndex);

static void __shiftVectorToLeft(Vector *vector ,int  startIndex);


static void __vectorInsertAt(Vector *vector, int index,
                            vectorType element);