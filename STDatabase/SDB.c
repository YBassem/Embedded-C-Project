/*
*******************************************************************************
* @file: SDB.c
* @param: itemCount to keep trace of the numbers of students in the database
* @author: Youssef Bassem
* @brief: Implementation of student database functions
*******************************************************************************
*/

#include "SDB.h"


uint8 itemCount = 0;

Bool SDB_IsFull (void){
    if(itemCount == MAX_STUDENTS){
        printf("Failed to add student! Database is full\n");
        return True;
    }
    
    return False;
}

uint8 SDB_GetUsedSize(void){
    return itemCount;
}

Bool SDB_AddEntry(void){
    if(SDB_IsFull()){
        return False;
    }
    uint8 x = 0;
    printf("Enter Student ID: ");
    scanf("%d",&Student_DB[itemCount].Student_ID);
    if(SDB_IsIdExist(Student_DB[itemCount].Student_ID,&x)){
        printf("Student with ID: %d already exist at Student %d\n",Student_DB[itemCount].Student_ID,x+1);
        Student_DB[itemCount].Student_ID = 0;
        return False;
    }

    printf("Enter Student Year: ");
    scanf("%d",&Student_DB[itemCount].Student_year);

    printf("Enter Course 1 ID: ");
    scanf("%d",&Student_DB[itemCount].Course1_ID);
    
    printf("Enter Course 1 Grade: ");
    scanf("%d",&Student_DB[itemCount].Course1_grade);

    printf("Enter Course 2 ID: ");
    scanf("%d",&Student_DB[itemCount].Course2_ID);

    printf("Enter Course 2 Grade: ");
    scanf("%d",&Student_DB[itemCount].Course2_grade);

    printf("Enter Course 3 ID: ");
    scanf("%d",&Student_DB[itemCount].Course3_ID);

    printf("Enter Course 3 Grade: ");
    scanf("%d",&Student_DB[itemCount].Course3_grade);

    itemCount++;
    
    return True;
}

Bool SDB_IsIdExist (uint32 id,uint8* idx){
    for(uint8 i = 0; i < itemCount;i++){
        if(id == Student_DB[i].Student_ID){
            *idx = i;
            return True;
        }
    }
    return False;
}

void SDB_DeleteEntry (uint32 id){
    uint8 i = 0;
    if(SDB_IsIdExist(id,&i)){
            Student_DB[i] = Student_DB[itemCount - 1];
            itemCount--;
            printf("Student Deleted successfuly\n");
        }
}

  


Bool SDB_ReadEntry (uint32 id){
    uint8 i = 0;
    Bool found = SDB_IsIdExist(id,&i);

    if(found){
        printf("Student ID: %d\n",Student_DB[i].Student_ID);
        printf("Student Year: %d\n",Student_DB[i].Student_year);
        printf("Course 1 ID: %d\n",Student_DB[i].Course1_ID);
        printf("Course 1 Grade: %d\n",Student_DB[i].Course1_grade);
        printf("Course 2 ID: %d\n",Student_DB[i].Course2_ID);
        printf("Course 2 Grade: %d\n",Student_DB[i].Course2_grade);
        printf("Course 3 ID: %d\n",Student_DB[i].Course3_ID);
        printf("Course 3 Grade: %d\n",Student_DB[i].Course3_grade);
    }
    

    return found;
       
}

void SDB_GetList (uint8 * count, uint32 * list){
    if(*count > itemCount){
        printf("Number exceeds the total number of students\nAvailable students are:\n");
        *count = itemCount;
    }
    for(int i = 0 ; i < *count;i++){
        list[i] =  Student_DB[i].Student_ID;
    }
}