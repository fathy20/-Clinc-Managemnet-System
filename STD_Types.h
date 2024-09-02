#ifndef STD_TYPES_H
#define STD_TYPES_H

typedef unsigned char u8;
typedef unsigned short u16;

#define True  1
#define False 0

extern u16 AdminPass; // Declare AdminPass

typedef struct Node_Type {
    u8 Name[30];
    u8 Age;
    u8 Gender[30];
    u16 ID;
    u8 res;
    struct Node_Type* Next;
} Node;

extern Node* head;
extern u8 ListLength;
extern u8 PasswordFlag; // Declare PasswordFlag
extern u8 ExitFlag;     // Declare ExitFlag
extern u8 ReservedSlots[5];
extern const char* AvailableSlots[5];

#endif // STD_TYPES_H
