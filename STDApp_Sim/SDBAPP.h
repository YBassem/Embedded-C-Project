/*
*******************************************************************************
* @file: SDBAPP.h
* @author: Youssef Bassem
* @brief: Contains Action Types for the user and fuctions prototype
*******************************************************************************
*/

#pragma once
#ifndef _SDBAPP_H_
#define _SDBAPP_H_

#include "../STDatabase/SDB.h"

typedef enum
{
    EXIT,
    ADD_ENTRY,
    GET_USED_SIZE,
    READ_STUDENT_DATA,
    GET_LIST,
    IS_ID_EXIST,
    DELETE_STUDENT,
    CHECK_IS_FULL
} ACTION_TYPE;

void SDB_action(uint32 choice);
void SDB_APP(void);

#endif