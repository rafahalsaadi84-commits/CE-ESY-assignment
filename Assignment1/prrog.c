#include <stdio.h>
#include <string.h>

#define SIZE 10

typedef struct {
    char buffer[SIZE];
    int head;
    int tail;
    int count;
} CircularBuffer;

void init(CircularBuffer *cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

int isFull(CircularBuffer *cb) {
    return cb->count == SIZE;
}

int isEmpty(CircularBuffer *cb) {
    return cb->count == 0;
}

void writeBuffer(CircularBuffer *cb, char data) {
    if (isFull(cb)) {
        printf("Buffer Overflow\n");
        return;
    }
    cb->buffer[cb->head] = data;
    cb->head = (cb->head + 1) % SIZE;
    cb->count++;
}

char readBuffer(CircularBuffer *cb) {
    if (isEmpty(cb)) {
        printf("Buffer Underflow\n");
        return '\0';
    }
    char data = cb->buffer[cb->tail];
    cb->tail = (cb->tail + 1) % SIZE;
    cb->count--;
    return data;
}

int main() {
    CircularBuffer cb;
    init(&cb);

    char name[50];
    printf("Enter your name: ");
    scanf("%49s", name);

    strcat(name, "CE-ESY");

    
    for (int i = 0; i < (int)strlen(name); i++) {
        writeBuffer(&cb, name[i]);
    }

    printf("Result: ");
    while (!isEmpty(&cb)) {
        char c = readBuffer(&cb);
        printf("%c", c);
    }
    printf("\n");

    /
    if (isEmpty(&cb)) {
        printf("Buffer is empty now.\n");
    }

    return 0;
}
