#ifndef TASK_STRUCT_H
#define TASK_STRUCT_H

//Task
struct Task {
    char name[20];
    int priority;       // priority for tasks , not used for algorithms
    int burst_time;     //  Execution time 
    int arrival_time;   // entering time
};


//Circular list for RR
struct Node {
    struct Task task;
    struct Node* next;
};

// min-heap for sjfs
#define MAX_SIZE 100
struct MinHeap {
    struct Task tasks[MAX_SIZE];        //number of tsaks
    int size;
};

// priority q for priority sheduling
struct PriorityQueue {
    struct Task tasks[MAX_SIZE];        //number of tasks
    int size;
};

// Function prototypes for algorithms
void roundRobin(struct Node* head, int quantum);
void enqueue(struct PriorityQueue* pq, struct Task task); // For Priority Scheduling
void priorityScheduling(struct PriorityQueue* pq);
void insertHeap(struct MinHeap* heap, struct Task task); // For SJF
void sjfScheduling(struct MinHeap* heap, int isPreemptive);

#endif 










// git init
// git add README.md
// git commit -m "first commit"
// git branch -M main
// git remote add origin https://github.com/bhosaleparas/Task-sheduler.git
// git push -u origin main