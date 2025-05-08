/*
 * ============================================================================================================*
 * Author      : Alaa Emad
 * File name   : C_Final_Project_functions.h
 * Description : Implementation for the functions of the project
 ============================================================================================================
*/

/*Including libraries from the system files*/
#include <stdio.h>
#include <stdlib.h>
/*Include the "stdType.h" header file from the user files*/
#include "stdType.h"
/*Include the "C_Final_Project_struct.h" header file from the user files*/
#include "C_Final_Project_struct.h"

/*Starting pointer*/
PATIENT_INFO * start = NULL;
TIMES * BEGIN = NULL;

/*Defining the functions used in the project*/

/*Define the LOG_IN function*/
u8 LOG_IN(){
    /*Welcome message for the system*/
    printf("Welcome to the Clinic Management System \n");
    /*Creating variables*/
    u8 AdminOrUser = 0;
    /*Telling the user to choose the ADMIN mode or the USER mode*/
    printf("Do you want to join as ADMIN or USER \n");
    printf("To join as ADMIN please enter the 'A' or 'a' character \n");
    printf("To join as USER please enter the 'U' or 'u' character \n");
    /*Scanning the AdmainOrUser variable from the user*/
    printf("Please enter your choice: ");
    scanf(" %c", &AdminOrUser);
    return AdminOrUser;
}

/*Define the FLAG_PASSWORD function*/
u8 FLAG_PASSWORD(u8 AdminOrUser){
    /*Creating variables*/
    u16 Password = 0;   //Variable to hold the admin password
    u8 counter = 0;     //Variable for the loop to count the 3 times of entering the password
    u8 FlagPassword = 0;    //Variable to check the password
    switch(AdminOrUser){
        case 'A':
        case 'a':
            /*Welcome message for the ADMIN*/
            printf("Welcome to the ADMIN mode \n");
            /*Loop for taking the password from the admin for up to three times*/
            for(counter = 0; counter < 3; counter++){
                /*Asking the admin to enter the password*/
                printf("Please enter the Admin password: ");
                /*Scanning the password from the user*/
                scanf("%hd", &Password);
                /*Checking if the password is correct or not*/
                if(Password == 1234){
                    FlagPassword = 1;
                    break; //The loop will be terminated if the password correct
                }
                else if(Password != 1234 && counter == 2){
                    /*If the password entered wrong for three times the program will be terminated*/
                    printf("Wrong password please try again later \n");
                    printf("Thank you for using our Clinic Management System \n");
                }
                else{
                    /*Each time the password entered wrong the system will print this to the admin*/
                    printf("Wrong password try again \n");
                }
            }
            break;
        case 'U':
        case 'u':
            /*Welcome message for the USER*/
            printf("Welcome to the USER mode \n");
            FlagPassword = 2;
            break;
        default:
            /*Telling the user that the chossen option was wrong*/
            printf("Sorry the choosen option was wrong please try again later \n");
            printf("Thank you for using our Clinic Management System \n");
            break;
    }
    /*Returning the FlagPassword states*/
    return FlagPassword;
}

/*Define the SEARCH_ID function*/
u8 SEARCH_ID(PATIENT_INFO * start, u32 Id){
    // Initialize curr with the head of linked list
    PATIENT_INFO * head = start;
    // Iterate over all the nodes
    while (head != NULL) {
        // If the current node's value is equal to key,
        // return true
        if (head -> ID == Id)
            return 1;
        // Move to the next node
        head = head -> Next;
    }
    // If there is no node with value as key, return false
    return 0;
}

/*Define the SEARCH_SlotID function*/
u8 SEARCH_SlotID(TIMES * BEGIN, u8 slot){
    // Initialize curr with the head of linked list
    TIMES * head = BEGIN;
    // Iterate over all the nodes
    while (head != NULL) {
        // If the current node's value is equal to key,
        // return true
        if (head -> SlotID == slot)
            return 1;
        // Move to the next node
        head = head -> Next;
    }
    // If there is no node with value as key, return false
    return 0;
}

/*Define the ADD_PATIENT function*/
void ADD_PATIENT(){
    /*Creating variables*/
    u8 CheckFlag = 0; //Check if patient is already exists
	/*Create new patient*/
	PATIENT_INFO * Element = (PATIENT_INFO*)malloc(sizeof(PATIENT_INFO));
	Element -> Next = NULL;
	/*Scan Information*/
    /*Scanning the name of the patient*/
	printf("Please enter the patient name: ");
	scanf(" %[^\n]s", Element -> name);
    /*Scanning the age of the patient*/
	printf("Please enter the patient age: ");
	scanf("%hhd", &Element -> age);
    /*Scanning the gender of the patient*/
	printf("Please enter the patient gender 'enter Male or Female': ");
	scanf(" %[^\n]s", Element -> gender);
    /*Scanning the ID of the patient 'NOTE THAT ID MUST BE UNQUE'*/
    printf("Please enter the patient ID 'NOTE THAT ID MUST BE UNQUE': ");
    scanf("%ld", &Element -> ID);
    /*Calling the SEARCH_ID function to check if the patient is already exists*/
    CheckFlag = SEARCH_ID(start , Element -> ID);
    /*In case of the patient is already exists*/
    if(CheckFlag == 1){
        /*The system will print this for the user*/
        printf("This patient is rejected 'CAUTION: ID MUST BE UNIQUE' \n");
        printf("Please try again later... \n");
        printf("Thank you for using our Clinic Management System \n");
    }
    /*In case of the patient is new*/
    if(CheckFlag == 0){
        /*Check on the linked list*/
        if(start == NULL){
            start = Element;
        }
        else{
            /*Check on the last Element*/
            PATIENT_INFO * temp = start;
            /*Adding the patient in the data of the clinic*/
            while(temp -> Next != NULL){
                temp = temp -> Next;
            }
            temp -> Next = Element;
        }
    }
}

/*Define the TIMES_AVAILABLE function*/
void TIMES_AVAILABLE(){
    // Create the first avaliable time of the clinic
    TIMES * time1 = (TIMES*)malloc(sizeof(TIMES));
    // Assigning data
    time1 -> SlotID = 'A';
    /*Set BEGIN point to the first node*/
    BEGIN = time1;
    // Create the second avaliable time of the clinic
    TIMES * time2 = (TIMES*)malloc(sizeof(TIMES));
    // Assigning data
    time2 -> SlotID = 'B';
    // Create the third avaliable time of the clinic
    TIMES * time3 = (TIMES*)malloc(sizeof(TIMES));
    // Assigning data
    time3 -> SlotID = 'C';
    // Create the fourth avaliable time of the clinic
    TIMES * time4 = (TIMES*)malloc(sizeof(TIMES));
    // Assigning data
    time4 -> SlotID = 'D';
    // Create the fifth avaliable time of the clinic
    TIMES * time5 = (TIMES*)malloc(sizeof(TIMES));
    // Assigning data
    time5 -> SlotID = 'E';
    // Linking all the avaliable times together
    time1 -> Next = time2;
    time2 -> Next = time3;
    time3 -> Next = time4;
    time4 -> Next = time5;
    time5 -> Next = NULL;
}

/*Define the EDIT_PATIENT function*/
void EDIT_PATIENT(){
    /*Creating variables*/
    u8 CheckFlag = 0;   //Variable to check the states of the searched Id
    u32 Id = 0;     //Variable to hold the Id of the patient to edit
    /*Telling the user to enter the patient ID to edit*/
    printf("Please enter ID of the patient you want to edit: ");
    /*Scanning the patient ID*/
    scanf("%ld", &Id);
    /*Calling the SEARCH_ID function to check if the patient is already exists*/
    CheckFlag = SEARCH_ID(start , Id);
    /*In case of the ID exists*/
    if(CheckFlag == 1){
        /*Creating temp node to search for the patient node with its ID*/
        PATIENT_INFO * temp = start;
        /*Loop through all patients data*/
        while(temp != NULL){
            if(temp -> ID == Id){
                /*Telling the admain to edit the patient information*/
                printf("Please edit the information of patient %ld \n", temp -> ID);
                /*Scan Information*/
                /*The new name of the patient*/
                printf("Please enter the patient name: ");
                scanf(" %[^\n]s", temp -> name);
                /*The new age of the patient*/
                printf("Please enter the patient age: ");
                scanf("%hhd", &temp -> age);
                /*The new geneder of the patient*/
                printf("Please enter the patient gender 'enter Male or Female': ");
                scanf(" %[^\n]s", temp -> gender);
                break;
            }
            temp = temp -> Next;
        }
    }
    /*In case of the ID not exists*/
    else if(CheckFlag == 0){
        /*The system will print this for the user*/
        printf("ID not exist \n");
        printf("Please add a new patient then try again \n");
        printf("Thank you for using our Clinic Management System \n");
    }
}

/*Define the DELETE_SLOT function*/
void DELETE_SLOT(TIMES**head, u8 slot)
{
    //Creating temp node
    TIMES * temp;
    //key found on the head node.
    //move to head node to the next and free the head.
    if((*head)->SlotID == slot){
        temp = (*head);    //backup to free the memory
        (*head) = (*head)->Next;
        free(temp);
    }
    else{
        //Creating current node
        TIMES * current  = (*head);
        while(current->Next != NULL){
            //if yes, we need to delete the current->next node
            if(current->Next->SlotID == slot)
            {
                temp = current->Next;
                //node will be disconnected from the linked list.
                current->Next = current->Next->Next;
                free(temp);
                break;
            }
            //Otherwise, move the current node and proceed
            else{
                current = current->Next;
            }
        }
    }
}

/*Define the RESERVE_SLOT function*/
void RESERVE_SLOT(){
    /*Creating variables*/
    u8 CheckFlag = 0;   //Variable to check the states of the searched Id
    u8 checkSlot = 0;
    u8 ChoosenSlot = 0;
    u32 Id = 0;     //Variable to hold the Id of the patient to edit
    /*Telling the user to enter the patient ID to edit*/
    printf("Please enter ID of the patient you want to reserve a slot: ");
    /*Scanning the patient ID*/
    scanf("%ld", &Id);
    /*Calling the SEARCH_ID function to check if the patient is already exists*/
    CheckFlag = SEARCH_ID(start , Id);
    /*In case of the ID exists*/
    if(CheckFlag == 1){
        /*Creating temp node to search for the patient node with its ID*/
        PATIENT_INFO * temp = start;
        /*Loop through all patients data*/
        while(temp != NULL){
            if(temp -> ID == Id){
                /*Telling the admain to edit the patient information*/
                printf("Please enter the desired slot for the patient %ld: ", temp -> ID);
                /*Scanning the ChoosenSlot from the user*/
                scanf(" %c", &ChoosenSlot);
                /*Checking if the slot is allready reserved*/
                checkSlot = SEARCH_SlotID(BEGIN , ChoosenSlot);
                if(checkSlot == 1){
                    /*if it is not reserved*/
                    temp -> slot = ChoosenSlot;
                    DELETE_SLOT(&BEGIN , temp -> slot);
                }
                else if(checkSlot == 0){
                    /*If it is reserved*/
                    printf("The slot you choose not avaliable right now \n");
                    printf("Please choose another slot later... \n");
                    printf("Thank you for using our Clinic Management System \n");
                }
                break;
            }
            /*Moving to the next node*/
            temp = temp -> Next;
        }
    }
    /*In case of the ID not exists*/
    else if(CheckFlag == 0){
        /*The system will print this for the user*/
        printf("ID not exist \n");
        printf("Please add a new patient then try again \n");
        printf("Thank you for using our Clinic Management System \n");
    }
}
    
/*Define the DISPLAY_AVALIABLE_SLOT function*/
void DISPLAY_AVALIABLE_SLOT(){
    /*Creating temp node*/
    TIMES * temp = BEGIN;
    /*Displaying all the avaliable slots*/
      while(temp != NULL) {
      printf("SLOT(%c)  ", temp -> SlotID);
      temp = temp -> Next;
    }
    printf("\n");
    /*Calling the RESERVE_SLOT function*/
    RESERVE_SLOT();
}

/*Define the DISPLAY_ALLPATIENTINFO function*/
void DISPLAY_ALLPATIENTINFO(){
    /*Checking if there is a data in the Clinic system or not*/
    /*In case of there is no data in the system*/
	if(start == NULL){
        /*The system will print this to the user*/
		printf("No patient added, please add patient and try again \n");
        printf("Thank you for using our Clinic Management System \n");
	}
    /*In case of there is a data in the clinic system*/
	else{
        /*Starting node for showing all the patient information*/
		PATIENT_INFO * temp = start;
        /*Loop through the data of the patient*/
		while(temp != NULL){
            /*Printing the data of the patient*/
			printf("The name of the patient is: %s \n", temp -> name);
			printf("The age of the patient is: %hhd \n", temp -> age);
			printf("The gender of the patient is: %s \n", temp -> gender);
            printf("The ID of the payient is: %ld \n", temp -> ID);
            /*Moving to the next patient*/
			temp = temp -> Next;
		}
	}
}

/*Define the DISPLAY_PATIENT_RESERVATION function*/
void DISPLAY_PATIENT_RESERVATION(){
    /*Checking if there is a data in the Clinic system or not*/
    /*In case of there is no data in the system*/
	if(start == NULL){
        /*The system will print this to the user*/
		printf("No patient added, please add patient and try again \n");
        printf("Thank you for using our Clinic Management System \n");
	}
    /*In case of there is a data in the clinic system*/
	else{
        /*Starting node for showing all the patient information*/
		PATIENT_INFO * temp = start;
        /*Loop through the data of the patient*/
		while(temp != NULL){
            /*Printing the data of the patient*/
            printf("Patient ID          Reserved slot \n");
            printf("  %ld                     %c \n", temp -> ID , temp -> slot);
            /*Moving to the next patient*/
			temp = temp -> Next;
		}
	}
}

/*Define the CANCEL_RESERVATION function*/
void CANCEL_RESERVATION(){
    /*Creating variables*/
    u8 CheckFlag = 0;   //Variable to check the states of the searched Id
    u32 Id = 0;     //Variable to hold the Id of the patient to edit
    /*Telling the user to enter the patient ID to edit*/
    printf("Please enter ID of the patient you want to cancel reservation: ");
    /*Scanning the patient ID*/
    scanf("%ld", &Id);
    /*Calling the SEARCH_ID function to check if the patient is already exists*/
    CheckFlag = SEARCH_ID(start , Id);
    /*In case of the ID exists*/
    if(CheckFlag == 1){
        /*Creating temp node to search for the patient node with its ID*/
        PATIENT_INFO * temp = start;
        /*Loop through all patients data*/
        while(temp != NULL){
            /*Checking if the entered ID is on the system data*/
            if(temp -> ID == Id){
                /*Creating head node*/
                TIMES * head = BEGIN;
                /*Adding the canceled slot to the avaliable slots*/
                while(head != NULL){
                    /*Check the last place in the avaliable slots*/
                    if(head -> Next == NULL){
                        /*Allocating a space for the new slot*/
                        TIMES * timeTemp = (TIMES*)malloc(sizeof(TIMES));
                        /*Assigning data*/
                        timeTemp -> SlotID = temp -> slot;
                        /*linking the node*/
                        head -> Next = timeTemp;
                        break;
                    }
                    /*Moving to the next node*/
                    head = head -> Next;
                }
                /*Cancel the reservation of the patient*/
                temp -> slot = '\0';
                break;
            }
            /*Moving to the next node*/
            temp = temp -> Next;
        }
    }
    /*In case of the ID not exists*/
    else if(CheckFlag == 0){
        /*The system will print this for the user*/
        printf("ID not exist \n");
        printf("Please add a new patient then try again \n");
        printf("Thank you for using our Clinic Management System \n");
    }
}

/*Define the ADMIN_FEATURES function*/
void ADMIN_FEATURES(u8 FlagPassword){
    /*Creating variables*/
    u8 AdminFeatures = 0;
    u8 FlagFeature = 0;
    /*Loop for choosing the feature that the admin will use*/
    do{
        /*In case the user choose undefined option in the list*/
        if(FlagFeature == 1){
            /*The system will print this to the user*/
            printf("The feature code entered is wrong please try again \n");
        }
        /*If password is correct show the admin features*/
        if(FlagPassword == 1){
            /*Showing the admin the features provided by the system*/
            printf("Welcome admin, here is the features that the system provide to you: \n");
            printf("Feature code            Feature \n");
            printf("    A           Add new patient record \n");
            printf("    E           Edit patient record \n");
            printf("    R           Reserve a slot with the doctor \n");
            printf("    C           Cancel reservation \n");
            /*Telling the admin to enter the feature code*/
            printf("Please choose a feature: ");
            /*Scanning the feature code from the admin*/
            scanf(" %c", &AdminFeatures);
            /*Checing if the admin chose undefined option on the list*/
            if(AdminFeatures != 'A' && AdminFeatures != 'E' && AdminFeatures != 'R' && AdminFeatures != 'C'){
                FlagFeature = 1;
            }
        }
    }while(AdminFeatures != 'A' && AdminFeatures != 'E' && AdminFeatures != 'R' && AdminFeatures != 'C');
    /*Switch statement for entering the feature choosen by the user*/
    switch(AdminFeatures){
        /*In case of choosing the Add new patient record option*/
        case 'A':
            /*Calling the ADD_PATIENT function*/
            ADD_PATIENT();
            break;
        /*In case of choosing the Edit patient record option*/
        case 'E':
            /*Calling the EDIT_PATIENT function*/
            EDIT_PATIENT();
            break;
        /*In case of choosing the Reserve a slot with the doctor option*/
        case 'R':
            printf("There are 5 slots: \n");
            printf("    Time        SlotID \n");
            printf("2pm to 2:30pm      A \n");
            printf("2:30pm to 3pm      B \n");
            printf("3pm to 3:30pm      C \n");
            printf("4pm to 4:30pm      D \n");
            printf("4:30pm to 5pm      E \n");
            printf("The avaliable slots now: \n");
            /*Calling the DISPLAY_AVALIABLE_SLOT function*/
            DISPLAY_AVALIABLE_SLOT();
            break;
        /*In case of choosing the Cancel reservation option*/
        case 'C':
            /*Calling the CANCEL_RESERVATION function*/
            CANCEL_RESERVATION();
            break;
        /*If the chossen option undefined*/
        default:
            /*The system will print this for the user*/
            printf("Unexpected error happen please try again later \n");
            printf("Thank you for using our Clinic Management System \n");
            break; 
    }
}

/*Define the USER_FEATURES function*/
void USER_FEATURES(u8 FlagPassword){
    /*Creating variables*/
    u8 UserFeatures = 0;    //Variable to hold the user option
    u8 FlagFeature = 0;     //Variable to check if the choosen option exists
    /*Loop for choosing the feature that the admin will use*/
    do{
        /*If the choosen option is not exists*/
        if(FlagFeature == 1){
            /*The system will print this for the user*/
            printf("The feature code entered is wrong please try again \n");
        }
        /*If password is correct show the admin features*/
        if(FlagPassword == 2){
            /*Showing the admin the features provided by the system*/
            printf("Welcome user, here is the features that the system provide to you: \n");
            printf("Feature code            Feature \n");
            printf("    P             View patient record \n");
            printf("    T             View today's reservations \n");
            /*Telling the user to choose a feature*/
            printf("Please choose a feature: ");
            /*Scanning the feature from the user*/
            scanf(" %c", &UserFeatures);
            /*Checking if the user choosen feature exists*/
            if(UserFeatures != 'P' && UserFeatures != 'T'){
                FlagFeature = 1;
            }
        }
    }while(UserFeatures != 'P' && UserFeatures != 'T');
    /*Switch statement for entering the feature choosen by the user*/
    switch(UserFeatures){
        /*In case of choosing the View patient record*/
        case 'P':
            /*Calling the DISPLAY_ALLPATIENTINFO function*/
            DISPLAY_ALLPATIENTINFO();
            break;
        /*In case of choosing the View today's reservations*/
        case 'T':
            /*Calling the DISPLAY_PATIENT_RESERVATION function*/
            DISPLAY_PATIENT_RESERVATION();
            break;
        /*If the choosen option undefined*/
        default:
            /*The system will print this for the user*/
            printf("Unexpected error happen please try again later \n");
            printf("Thank you for using our Clinic Management System \n");
            break; 
    }
}