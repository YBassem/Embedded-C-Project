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

    printf("Enter Student ID: ");
    scanf("%d",&Student_DB[itemCount].Course1_ID);
    IDs[itemCount] = Student_DB[itemCount].Course1_ID;

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

void SDB_DeletEntry (uint32 id){
    uint8 i = 0;
    if(SDB_IsIdExist(id,&i)){
            Student_DB[i].Student_ID = Student_DB[itemCount - 1].Student_ID;
            Student_DB[itemCount - 1].Student_ID = 0;
            IDs[i] = IDs[itemCount - 1];
            IDs[itemCount - 1] = 0;

            Student_DB[i].Student_year = Student_DB[itemCount - 1].Student_year;
            Student_DB[itemCount - 1].Student_year = 0;

            Student_DB[i].Course1_ID = Student_DB[itemCount - 1].Course1_ID;
            Student_DB[itemCount - 1].Course1_ID = 0;

            Student_DB[i].Course1_grade = Student_DB[itemCount - 1].Course1_grade;
            Student_DB[itemCount - 1].Course1_grade = 0;

            Student_DB[i].Course2_ID = Student_DB[itemCount - 1].Course2_ID;
            Student_DB[itemCount - 1].Course2_ID = 0;

            Student_DB[i].Course2_grade = Student_DB[itemCount - 1].Course2_grade;
            Student_DB[itemCount - 1].Course2_grade = 0;

            Student_DB[i].Course3_ID = Student_DB[itemCount - 1].Course3_ID;
            Student_DB[itemCount - 1].Course3_ID = 0;

            Student_DB[i].Course3_grade = Student_DB[itemCount - 1].Course3_grade;
            Student_DB[itemCount - 1].Course3_grade = 0;
            itemCount--;
            
        }else{
             printf("Student ID not found!, Please enter a valid ID\n");
        }
}

  


Bool SDB_ReadEntry (uint32 id){
    uint8 i = 0;
    Bool found = SDB_IsIdExist(id,&i);

    if(found){
        printf("Enter Student ID: %d\n",Student_DB[i].Student_ID);
        printf("Enter Student Year: %d\n",Student_DB[i].Student_year);
        printf("Enter Course 1 ID: %d\n",Student_DB[i].Course1_ID);
        printf("Enter Course 1 Grade: %d\n",Student_DB[i].Course1_grade);
        printf("Enter Course 2 ID: %d\n",Student_DB[i].Course2_ID);
        printf("Enter Course 2 Grade: %d\n",Student_DB[i].Course2_grade);
        printf("Enter Course 3 ID: %d\n",Student_DB[i].Course3_ID);
        printf("Enter Course 3 Grade: %d\n",Student_DB[i].Course3_grade);
    }
    

    return found;
       
}

void SDB_GetList (uint8 * count, uint32 * list){
    *count = itemCount;

    for(int i = 0 ; i<itemCount;i++){
        list[i] =  IDs[i];
    }
}