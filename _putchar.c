#include <unistd.h>  // Include for the write function
#include "main.h"

int _putchar(char c) {
    write(1, &c, 1); /* Write the character to stdout (file descriptor 1)*/
    return 1;        /* Return the number of characters written (1 in this case)*/
}
