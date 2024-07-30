/*
*******************************************************************************
* @file: SDBAPP.c
* @author: Youssef Bassem
* @brief: Application Manager
*******************************************************************************
*/

#include "SDBAPP.h"


uint32 id = 0;
uint8 count = 0;
uint32 list[MAX_STUDENTS];
uint8 idx = 0;
void SDB_action(uint32 choice){
    switch (choice)
    {
    case EXIT:
        exit(0);
        return;
    case ADD_ENTRY:
        if(SDB_AddEntry()){
            printf("Student %d added successfully\n",SDB_GetUsedSize());
        }
        break;
    case GET_USED_SIZE:
        printf("There are %d Student added successfully in our database\n",SDB_GetUsedSize());
        break;
    case READ_STUDENT_DATA:
        printf("Please enter student ID to search for: ");
        scanf("%d",&id);
        if(!SDB_IsIdExist(id,&idx)){
            printf("ID not found! Try again\n");
        }else{
            SDB_ReadEntry(id);
        }
        
        break;
    case GET_LIST:
        printf("Enter the number of IDs you want to display: ");
        scanf("%d",&count);
        SDB_GetList(&count,list);
        printf("List of IDs [ ");
        for (uint8 i = 0; i < count; i++)
        {
            printf("%d ",list[i]);
        }
        printf("]\n");
        
        break;
    case IS_ID_EXIST:
        printf("Enter Student ID to search for: ");
        scanf("%d",&id);
        if(SDB_IsIdExist(id,&idx)){
            printf("Student with ID %d is successfuly found\n",id);
        }else{
            printf("ID not found! Try again\n");
        }
        break;
    case DELETE_STUDENT:
        printf("Enter Student ID to delete: ");
        scanf("%d",&id);
        if(!SDB_IsIdExist(id,&idx)){
            printf("ID not found! Try again\n");
        }else{
            SDB_DeleteEntry(id);
        }
        
        
        break;
    case CHECK_IS_FULL:
        if(!SDB_IsFull()){
            printf("Database is not full, there are %d positions available\n",MAX_STUDENTS - SDB_GetUsedSize());
        }
        
        break;
    default:
        printf("Invalid Action! Please enter a valid number from 0 to 7\n");
        break;
    }
}

void SDB_APP(void){
    while (1)
    {
        printf("Which operation would you like to perform\n");
        printf("To add entry -> enter 1\nTo get used size in database -> enter 2\nTo read student data -> enter 3\nTo get the list of all student IDs -> enter 4\nTo check is ID is existed -> enter 5\nTo delete student data -> enter 6\nTo check is database is full -> enter 7\nTo exit -> enter 0\n");
        uint32 action;

        scanf("%d",&action);

        SDB_action(action);

    }
    
}