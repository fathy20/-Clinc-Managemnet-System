#include <stdlib.h>  // For NULL
#include "STD_Types.h"

// Define variables
Node* head = NULL;
u8 ListLength = 0;
u8 ReservedSlots[5] = {0, 0, 0, 0, 0};
const char* AvailableSlots[5] = {"2pm to 2:30pm", "2:30pm to 3pm", "3pm to 3:30pm", "3:30pm to 4pm", "4pm to 4:30pm"};
u16 AdminPass = 1234; // Example initialization
u8 PasswordFlag = False; // Add this line
u8 ExitFlag = False;     // Add this line
