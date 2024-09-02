#include "user_functions.h"
#include "STD_Types.h"
#include "node.h"
#include <stdio.h>

void ViewRecord(void) {
    u8 flag = 0;
    u16 id;
    printf("Enter Patient's ID to View: ");
    fflush(stdout);
    scanf("%hu", &id);

    if (ListLength == 0) {
        printf("No information available.\n\n");
    } else {
        Node* Last = head;
        while (Last != NULL) {
            if (Last->ID == id) {
                flag = 1;
                break;
            }
            Last = Last->Next;
        }
        if (flag == 1) {
            printf("Patient's Name: %s\n", Last->Name);
            printf("Patient's Age: %hhu\n", Last->Age);
            printf("Patient's Gender: %s\n", Last->Gender);
        } else {
            printf("Wrong ID.\n\n");
        }
    }
}

void ViewReservation(void) {
    u8 flag = 0;
    u16 id;
    printf("Enter Patient's ID to View: ");
    fflush(stdout);
    scanf("%hu", &id);

    if (ListLength == 0) {
        printf("No information available.\n\n");
    } else {
        Node* Last = head;
        while (Last != NULL) {
            if (Last->ID == id) {
                flag = 1;
                break;
            }
            Last = Last->Next;
        }
        if (flag == 1) {
            if (Last->res == 5) {
                printf("No Reservations for this ID.\n\n");
            } else {
                printf("Patient's Name: %s\n", Last->Name);
                printf("Patient's Reservation Slot: %s\n\n", AvailableSlots[Last->res]);
            }
        } else {
            printf("Wrong ID.\n\n");
        }
    }
}
