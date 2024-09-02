#include "admin_functions.h"
#include "STD_Types.h"
#include "node.h"
#include <stdio.h>
#include <stdlib.h>

void AddPatient(void) {
    u8 flag = 0;
    u16 id;

    printf("Enter Patient's ID: "); fflush(stdout);
    scanf("%hu", &id);

    Node* temp = (Node*) malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    if (ListLength == 0) {
        printf("Enter Patient's Name: "); fflush(stdout);
        scanf("%s", temp->Name);
        printf("Enter Patient's Age: "); fflush(stdout);
        scanf("%hhu", &temp->Age);
        printf("Enter Patient's Gender: "); fflush(stdout);
        scanf("%s", temp->Gender);
        temp->ID = id;
        temp->res = 5;
        temp->Next = head;
        head = temp;

        printf("New patient added successfully.\n\n");
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
            printf("ID already exists.\n\n");
            free(temp);
        } else {
            printf("Enter Patient's Name: "); fflush(stdout);
            scanf("%s", temp->Name);
            printf("Enter Patient's Age: "); fflush(stdout);
            scanf("%hhu", &temp->Age);
            printf("Enter Patient's Gender: "); fflush(stdout);
            scanf("%s", temp->Gender);
            temp->ID = id;
            temp->res = 5;
            temp->Next = NULL;

            Last = head;
            while (Last->Next != NULL) {
                Last = Last->Next;
            }
            Last->Next = temp;

            printf("New patient added successfully.\n\n");
        }
    }
    ListLength++;
}

void EditPatient(void) {
    // Example implementation; adjust as needed
    printf("EditPatient function is not implemented yet.\n");
}

void ReserveSlot(void) {
    // Example implementation; adjust as needed
    printf("ReserveSlot function is not implemented yet.\n");
}

void CancelReservation(void) {
    // Example implementation; adjust as needed
    printf("CancelReservation function is not implemented yet.\n");
}
