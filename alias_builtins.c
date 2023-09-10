/*
 * File: builtin.c
 * Auth: Javis mathews
 *       Brian ngumbau
 *
 
 #include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100

typedef struct {
    int id;
    char description[100];
    int completed;
} Task;

Task taskList[MAX_TASKS];
int taskCount = 0;

void addTask(char *description);
void listTasks();
void completeTask(int taskId);

int main() {
    char choice;
    char description[100];
    int taskId;

    while (1) {
        printf("To-Do List Menu:\n");
        printf("1. Add Task\n");
        printf("2. List Tasks\n");
        printf("3. Complete Task\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Enter task description: ");
                scanf(" %[^\n]", description);
                addTask(description);
                break;
            case '2':
                listTasks();
                break;
            case '3':
                printf("Enter task ID to mark as completed: ");
                scanf("%d", &taskId);
                completeTask(taskId);
                break;
            case '4':
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0

