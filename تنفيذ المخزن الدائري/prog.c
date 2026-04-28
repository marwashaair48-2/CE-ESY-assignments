#include <stdio.h>
#include <string.h>

#define SIZE 15
char buffer[SIZE];
int head = 0;
int tail = 0;
int count = 0;

// Is the buffer full?
int isFull() {
    if (count == SIZE)
        return 1;
    else
        return 0;
}

// The buffer is empty
int isEmpty() {
    if (count == 0)
        return 1;
    else
        return 0;
}

// Writing inside the file
void write(char data) {
    if (isFull()) {
        printf("Buffer Overflow\n");
        return;
    }

    buffer[tail] = data;
    tail = (tail + 1) % SIZE;
    count++;
}

// Read from the buffer
char readBuffer() {
    char data;

    if (isEmpty()) {
        printf("Buffer Underflow\n");
        return '\0';
    }

    data = buffer[head];
    head = (head + 1) % SIZE;
    count--;

    return data;
}

int main() {
    char name[100];
    int i;

    printf("Enter your name: ");
    scanf("%s", name);

    strcat(name, "CE-ESY");

    // Write each letter
    for (i = 0; i < strlen(name); i++) {
        write(name[i]);
    }

    // Read and print

    printf("Output: ");

    while (!isEmpty()) {
        printf("%c", readBuffer());
    }

    printf("\n");

    if (isEmpty()) {
        printf("Buffer is now empty\n");
    }

    return 0;
}