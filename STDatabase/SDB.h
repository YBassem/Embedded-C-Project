/*
*******************************************************************************
* @file: SDB.h
* @author: Youssef Bassem
* @brief: Contains student database and fuctions prototype
*******************************************************************************
*/

#pragma once
#ifndef _SDB_H_
#define _SDB_H_

#include "../Data_Types/STD.h"

#define MAX_STUDENTS 10

typedef struct
{
    uint32 Student_ID;
    uint32 Student_year;
    uint32 Course1_ID;
    uint32 Course1_grade;
    uint32 Course2_ID;
    uint32 Course2_grade;
    uint32 Course3_ID;
    uint32 Course3_grade;
} student;

student Student_DB[MAX_STUDENTS];

Bool SDB_IsFull(void);
uint8 SDB_GetUsedSize(void);
Bool SDB_AddEntry(void);
Bool SDB_IsIdExist(uint32 id, uint8 *idx);
void SDB_DeleteEntry(uint32 id);
Bool SDB_ReadEntry(uint32 id);
void SDB_GetList(uint8 *count, uint32 *list);

#endif