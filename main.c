// main.c
#include <stdio.h>
#include <stdlib.h>
#include "task_struct.h"

//function prototypes
void roundRobin(struct Node* head, int quantum);
void enqueue(struct PriorityQueue* pq, struct Task task);
void priorityScheduling(struct PriorityQueue* pq);
void insertHeap(struct MinHeap* heap, struct Task task); // For SJF
void sjfScheduling(struct MinHeap* heap, int isPreemptive);


// add task funxtion for round-robin algorithms
void addTask(struct Node** head, struct Task newTask);

int main() {
    int numTasks, i, quantum, choice, isPreemptive;
    struct Task task;
    struct Node* rrTasks = NULL;
    struct PriorityQueue pq = {.size = 0};
    struct MinHeap heap = {.size = 0};
    
    printf("Enter the number of tasks: ");
    scanf("%d", &numTasks);
    
    for (i = 0; i < numTasks; i++) {
        printf("\nEnter details for Task %d:\n", i + 1);
        printf("Task PID: ");
        scanf("%s", task.name);
        printf("Arrival Time: ");
        scanf("%d", &task.arrival_time);
        printf("Burst Time: ");
        scanf("%d", &task.burst_time);
        printf("Priority: ");
        scanf("%d", &task.priority);
        
        
        // add task to their respective daata structure

        addTask(&rrTasks, task);          // Round Robin
        enqueue(&pq, task);               // Priority Scheduling
        insertHeap(&heap, task);          // Shortest Job First
    }
    
    //taking use input
    printf("\nChoose a scheduling algorithm:\n");
    printf("1. Round Robin\n");
    printf("2. Priority Scheduling\n");
    printf("3. Shortest Job First (Non-Preemptive)\n");
    printf("4. Shortest Job First (Preemptive)\n");
    scanf("%d", &choice);
    
    
    //choice of algorithms
    switch (choice) {
        case 1:
            printf("Enter the quantum time for Round Robin: ");
            scanf("%d", &quantum);
            roundRobin(rrTasks, quantum);
            break;
        case 2:
            priorityScheduling(&pq);
            break;
        case 3:
            sjfScheduling(&heap, 0); // Non-Preemptive
            break;
        case 4:
            sjfScheduling(&heap, 1); // Preemptive
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
