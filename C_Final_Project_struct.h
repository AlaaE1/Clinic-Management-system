/*
 * ============================================================================================================*
 * Author      : Alaa Emad
 * File name   : C_Final_Project_struct.h
 * Description : Creating the structs required for the project
 ============================================================================================================
*/


/*Check if the file defined before or not*/
#ifndef C_FINAL_PROJECT_STRUCT_H
/*If the file not defined before define it*/
#define C_FINAL_PROJECT_STRUCT_H

/*Include the "stdType.h" header file from the user files*/
#include "stdType.h"

/*Creating the PATIENT_INFO struct*/
typedef struct PATIENT{
    u8 name[50];
    u8 age;
    u8 gender [10];
    u32 ID;
    u8 slot;
    struct PATIENT * Next;
}PATIENT_INFO;

/*Creating the TIMES struct*/
typedef struct TIMES_AVALIABLE{
    u8 SlotID;
    struct TIMES_AVALIABLE * Next;
}TIMES;

/*End the ifndef*/
#endif