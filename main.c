#include <stdio.h>
#include <stdlib.h>
#include "admin_functions.h"
#include "user_functions.h"
#include "STD_Types.h"
#include "node.h"

int main() {
    u8 mode, counter = 0, adminchoice, userchoice, ans;
    u16 pass;

    printf("******************************************************************************\n");
    fflush(stdout);
    printf("******************** Welcome To Clinic Management System. ********************\n");
    fflush(stdout);
    printf("******************************************************************************\n\n");
    fflush(stdout);

    while (ExitFlag == False) {
        printf("For Admin Mode, Please Enter 1\n");
        printf("For User Mode, Please Enter 2\n");
        printf("To Exit, Please Enter 3\n");
        printf("Your Option: ");
        fflush(stdout);
        scanf("%hhu", &mode);

        switch (mode) {
            case 1: 
                system("cls");
                printf("Welcome in Admin Mode.\n");
                
                while (PasswordFlag == False) {
                    printf("Please, Enter your Password: "); fflush(stdout);
                    scanf("%hu", &pass);
                    
                    if (pass == AdminPass) {
                        PasswordFlag = True;
                        break;
                    }
                    
                    counter++;
                    if (counter == 3) {
                        break;
                    }
                    printf("Wrong Password, Try Again.\n");
                    printf("%d remaining Tries.\n\n", 3 - counter);
                }
                
                if (PasswordFlag == True) {
                    PasswordFlag = False;
                    while (1) {
                        printf("\nTo Add new Patient, Enter 1\n");
                        printf("To Edit Patient's Record, Enter 2\n");
                        printf("To Reserve With Doctor, Enter 3\n");
                        printf("To Cancel Reservation, Enter 4\n");
                        printf("Your Option: ");
                        fflush(stdout);
                        scanf("%hhu", &adminchoice);
                        system("cls");
                        switch (adminchoice) {
                            case 1: AddPatient(); break;
                            case 2: EditPatient(); break;
                            case 3: ReserveSlot(); break;
                            case 4: CancelReservation(); break;
                            default: printf("Wrong Entry.\n\n"); break;
                        }
                       
                        printf("Do you want to continue in Admin mode?\n1:yes\t2:no\n");
                        printf("Your answer: "); fflush(stdout);
                        scanf("%hhu", &ans);
                        if (ans == 1)
                            continue;
                        else
                            break;
                    }
                } else {
                    printf("Access Denied.\n\n");
                }
                break;
            
            case 2: 
                system("cls");
                printf("Welcome in User Mode.\n\n");
                
                while (1) {
                    printf("\nTo View Patient's Record, Enter 1\n");
                    printf("To View Patient's Reservation, Enter 2\n");
                    printf("Your Option: ");
                    fflush(stdout);
                    scanf("%hhu", &userchoice);
                    system("cls");
                    switch (userchoice) {
                        case 1: ViewRecord(); break;
                        case 2: ViewReservation(); break;
                        default: printf("Wrong Entry.\n"); break;
                    }
                    printf("Do you want to continue in User mode?\n1:yes\t2:no\n");
                    printf("Your answer: "); fflush(stdout);
                    scanf("%hhu", &ans);
                    if (ans == 1)
                        continue;
                    else
                        break;
                }
                break;
            
            case 3: 
                printf("\nOK.\nGood Bye.\n"); 
                ExitFlag = True;
                break;
            
            default: 
                printf("Wrong Entry.\n\n"); 
                break;
        }
    }
    
    return 0;
}
