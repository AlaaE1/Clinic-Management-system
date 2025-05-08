/*
 * ============================================================================================================*
 * Author      : Alaa Emad
 * File name   : C_Final_Project_main.c
 * Description : Implementation for project core
 ============================================================================================================
*/


/*Including libraries from the system files*/
#include <stdio.h>
#include <stdlib.h>
/*Including the "stdType.h" header file from the user files*/
#include "stdType.h"
/*Including the "C_Final_Project_header.h" header file from the user files*/
#include "C_Final_Project_header.h"

/*Define the main function*/
int main(){
    /*When the system start the system will print this for the user*/
    printf("Welcome to Clinic Management System \n");
    printf("To exit the system please click (Ctrl + C) \n");
    printf("By clicking (Ctrl + C) All the data will be lost \n");
    /*Calling the TIMES_AVAILABLE function*/
    TIMES_AVAILABLE();
    /*Make the program run all the time until the user click (Ctrl + C)*/
    while(1){
        /*Creating variables*/
        u8 AdminOrUser = 0;
        u8 FlagPassword = 0;
        u8 CheckBack = 0;
        /*Calling the LOG_IN function*/
        AdminOrUser = LOG_IN();
        /*Calling the FLAG_PASSWORD function*/
        FlagPassword = FLAG_PASSWORD(AdminOrUser);
        /*Checking if the user choose the ADMIN mode or the USER mode*/
        if(FlagPassword == 1){
            do{
				system("clear");
                /*Calling the ADMIN_FEATURES function*/
                ADMIN_FEATURES(FlagPassword);
                printf("If you want to return to the main menu of ADMIN or USER press '<' otherwise press any other key: ");
                scanf(" %c", &CheckBack);
            }while(CheckBack != '<');
        }
        else if(FlagPassword == 2){
            do{
				system("clear");
                /*Calling the USER_FEATURES function*/
                USER_FEATURES(FlagPassword);
                printf("If you want to return to the main menu of ADMIN or USER press '<' otherwise press any other key: ");
                scanf(" %c", &CheckBack);
            }while(CheckBack != '<');
        }
    }
    return 0;
}