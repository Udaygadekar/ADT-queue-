#include<stdio.h>
#include<string.h>
#define max 20

int main()
{
    int ch, rear = -1, front = -1;
    char queue[max][50];
    char song[50];
    int f = 0;

    while(f != 1)
    {
        printf("Which operations do you want to perform\n1. enQueue \n2. deQueue\n3. Display:\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
        case 1:
            printf("Enter new song in play list: ");
            scanf("%s", song);

            if ((rear + 1) % max == front)
            {
                printf("Music playlist is full\n");
            }
            else if (front == -1 && rear == -1)
            {
                front = rear = 0;
                strcpy(queue[rear], song);
            }
            else
            {
                rear = (rear + 1) % max;
                strcpy(queue[rear], song);
            }
            break;

        case 2:
            if (front == -1 && rear == -1)
            {
                printf("Music playlist is empty\n");
            }
            else if (front == rear)
            {
                printf("Current song is %s\n", queue[front]);
                front = rear = -1;
            }
            else
            {
                printf("Current song is %s\n", queue[front]);
                front = (front + 1) % max;
            }
            break;

        case 3:
            if (front == -1 && rear == -1)
            {
                printf("Music playlist is empty\n");
            }
            else
            {
                printf("Songs in playlist are:\n");
                int i = front;
                while(i != rear)
                {
                    printf("queue[%d] = %s\n", i, queue[i]);
                    i = (i + 1) % max;
                }
                printf("queue[%d] = %s\n", rear, queue[rear]);
            }
            break;

        default:
            printf("Enter a correct choice\n");
            break;
        }
    }
    return 0;
}
