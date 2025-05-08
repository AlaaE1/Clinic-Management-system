/*
 * ============================================================================================================*
 * Author      : Alaa Emad
 * File name   : C_Final_Project_header.h
 * Description : Prototypes for the functions of the project
 ============================================================================================================
*/

/*Check if the file defined before or not*/
#ifndef C_FINAL_PROJECT_HEADER_H
/*If the file not defined before define it*/
#define C_FINAL_PROJECT_HEADER_H

/*Include the "C_Final_Project_struct.h" header file from the user files*/
#include "C_Final_Project_struct.h"

/*Prototyping the functions used in the project*/

/*Prototyping the ADD_PATIENT function*/
void ADD_PATIENT();

/*Prototyping the DISPLAY_PATIENTINFO function*/
void DISPLAY_ALLPATIENTINFO();

/*Prototying the DISPLAY_PATIENT_RESERVATION function*/
void DISPLAY_PATIENT_RESERVATION();

/*Prototyping the LOG_IN function*/
u8 LOG_IN();

/*Prototyping the FLAG_PASSWORD function*/
u8 FLAG_PASSWORD(u8 AdminOrUser);

/*Prototyping the ADMIN_FEATURES function*/
void ADMIN_FEATURES(u8 FlagPassword);

/*Prototyping the USER_FEATURES function*/
void USER_FEATURES(u8 FlagPassword);

/*Prototyping the SEARCH_ID function*/
u8 SEARCH_ID(PATIENT_INFO * start, u32 Id);

/*Prototyping the DELETE_SLOT function*/
void DELETE_SLOT(TIMES**head, u8 slot);

/*Prototyping the SEARCH_SlotID function*/
u8 SEARCH_SlotID(TIMES * BEGIN, u8 slot);

/*Prototyping the CANCEL_RESERVATION function*/
void CANCEL_RESERVATION();

/*Prototyping the DISPLAY_AVALIABLE_SLOT function*/
void DISPLAY_AVALIABLE_SLOT();

/*Prototyping the EDIT_PATIENT function*/
void EDIT_PATIENT();

/*Prototyping the RESERVE_SLOT function*/
void RESERVE_SLOT();

/*Prototyping the TIMES_AVAILABLE function*/
void TIMES_AVAILABLE();

/*End the ifndef*/
#endif