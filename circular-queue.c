#include <stdio.h>
#define MAX 2

int main() {
    int ch, rear = -1, front = -1, queue[MAX], element, f = 0;

    while(f != 1)
    {
        printf("Which operations do you want to perform\n1. enQueue(insertion)\n2. deQueue(deletion)\n3. Display\n4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
        case 1: // Enqueue operation
            printf("Enter element to enqueue: ");
            scanf("%d", &element);

            if (front == (rear + 1) % MAX) {
                printf("Queue is full\n");
            } else {
                if (front == -1 && rear == -1) {
                    front = rear = 0;
                } else {
                    rear = (rear + 1) % MAX;
                }
                queue[rear] = element;
            }
            break;

        case 2: // Dequeue operation
            if (front == -1 && rear == -1) {
                printf("Queue is empty\n");
            } else {
                printf("Element removed is %d\n", queue[front]);
                if (front == rear) {
                    front = rear = -1; // Queue is empty after removal
                } else {
                    front = (front + 1) % MAX;
                }
            }
            break;

        case 3: // Display operation
            if (front == -1 && rear == -1) {
                printf("Queue is empty\n");
            } else {
                printf("Queue elements are:\n");
                int i = front;
                while(i != rear) {
                    printf("queue[%d] = %d\n", i, queue[i]);
                    i = (i + 1) % MAX;
                }
                printf("queue[%d] = %d\n", rear, queue[rear]);
            }
            break;

        case 4: // Exit the program
            printf("Exiting the program.\n");
            f = 1;  // Set f to 1 to exit the loop
            break;

        default:
            printf("Enter a correct choice\n");
            break;
        }
    }
    return 0;
}
