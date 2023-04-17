// PROGRAM FOR CIRCULAR QUEUE
// Circular Queue is just a variation of the linear queue in which front and
// rear-end are connected to each //other to optimize the space wastage of the
// Linear queue and make it efficient

#include <stdio.h>
#define max 5
int f = -1, r = -1;
int queue[max];
void enqueue();
void dequeue();
void display();
int main() {
  int ch, val;
  do {
    printf("\n\n Enter 1. To perform Enqueue Operation\n Enter 2. To Perform "
           "Dequeue operation\n Enter 3. To Display all the Stack Elements \n "
           "Enter 4. To Exit \n  -->  ");
    scanf("%d", &ch);
    switch (ch) {
    case 1:
      enqueue();
      break;
    case 2:
      dequeue();
      break;
    case 3:
      display();
      break;
    case 4:
      break;
    default:
      printf("Invalid Input\n");
    }
  } while (ch != 4);
}
void enqueue() {
  int ele;
  if ((r + 1) % max == f) {
    printf("Queue Full!!\n");
    return;
  }
  printf("Enter the Element : ");
  scanf("%d", &ele);
  r = (r + 1) % max;
  queue[r] = ele;
  printf("%d Queued Successfully \n", ele);
  if (f == -1)
    f = 0;
}
void dequeue() {
  int ele;
  if (f == -1) {
    printf("Queue is Empty!!\n");
    return;
  }
  ele = queue[f];
  printf("%d is Dequeued Successfully \n", ele);
  if (f == r) {
    f = r = -1; // Reinitialise to -1 when there is no element present
  } else
    f = (f + 1) % max;
}
void display() {
  int i;
  if (f == -1) {
    printf("Queue is Empty\n");
    return;
  }
  printf("Queue Elements are \n");
  for (i = f; i != r; i = (i + 1) % max)
    printf("%d\t", queue[i]);
  printf("%d\t", queue[i]);
}