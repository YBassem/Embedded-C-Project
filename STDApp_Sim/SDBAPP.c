/*
*******************************************************************************
* @file: SDBAPP.c
* @author: Youssef Bassem
* @brief: Application Manager
*******************************************************************************
*/

#include "SDBAPP.h"

void SDB_action(uint8 choice){
    switch (choice)
    {
    case EXIT:
        exit(0);
        return;
    case ADD_ENTRY:
        if(SDB_AddEntry()){
            printf("Student %d added successfully\n",SDB_GetUsedSize()+1);
        }
        break;
    case GET_USED_SIZE:
        printf("There are %d Student added successfully in our database\n",SDB_GetUsedSize());
        break;
    case READ_STUDENT_DATA:
        printf("Please enter student ID to search for: ");
        uint32 id;
        scanf("%d",&id);
        SDB_ReadEntry(id);
        break;
    case GET_LIST:
        uint8 count=0;
        uint32 list[MAX_STUDENTS];
        SDB_GetList(&count,list);
        break;
    case IS_ID_EXIST:
        uint32 id = 0, idx = 0;
        printf("Enter Student ID to search for: ");
        scanf("%d",&id);
        if(SDB_IsIdExist(id,&idx)){
            printf("Student with ID %d is successfuly found\n",id);
        }
        break;
    case DELETE_STUDENT:
        uint32 id = 0;
        printf("Enter Student ID to delete: ");
        scanf("%d",&id);
        SDB_DeleteEntry(id);
        break;
    case CHECK_IS_FULL:
        SDB_IsFull();
        break;
    default:
        printf("Invalid Action! Please enter a valid number from 0 to 7\n");
        break;
    }
}

void SDB_APP(void){
    while (1)
    {
        printf("Welcome to our Student Database system :)\n");
        printf("Which operation would you like to perform\n");
        printf("To add entry -> enter 1\nTo get used size in database -> enter 2\nTo read student data -> enter 3\nTo get the list of all student IDs -> enter 4\nTo check is ID is existed -> enter 5\nTo delete student data -> enter 6\nTo check is database is full -> enter 7\nTo exit -> enter 0");
        uint8 action = 0;

        scanf("%d",&action);

        SDB_action(action);

    }
    
}