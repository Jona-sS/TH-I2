#include "io.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

/******************************************************************************/
/* Module intern macros *******************************************************/
/******************************************************************************/
/* unfortunatly can't write this code as function, because of stack management
 * => use makro instead */
#define DO_PRINTING(output_str) \
do { \
    if (output_str != NULL) { \
        va_list args; \
        va_start(args, output_str); \
        vprintf(output_str, args); \
        va_end(args); \
    } \
} while (0)


/******************************************************************************/
/* Implementations ************************************************************/
/******************************************************************************/
char * io_read_string(char * read_buffer, size_t buffer_size,
                      const char * output_str, ...)
{
    char * ret, * ptr;

    DO_PRINTING(output_str);
    ret = fgets(read_buffer, buffer_size, stdin);
    if (ret == NULL) return NULL; 

    /* search for \n */
    ptr = strchr(read_buffer, '\n');
    /* if found write \0 instead of \n */
    if (ptr) *ptr = '\0';
    /* else buffer is not read completly => clear buffer */
    else while (getchar() != '\n');

    return read_buffer;
}

int io_read_signed_number(const char * output_str, ...)
{
    int number;

    while (1) {
        int ret;

        DO_PRINTING(output_str);

        ret = scanf("%d", &number);
        /* clear buffer */
        while (getchar() != '\n');

        if (ret == 1) break;
        else          printf("Eingabefehler!!!\n");
    }
    return number;
}

unsigned int io_read_unsigned_number(const char * output_str, ...)
{
    unsigned int number;

    while (1) {
        int ret;

        DO_PRINTING(output_str);

        ret = scanf("%u", &number);
        /* clear buffer */
        while (getchar() != '\n');

        if (ret == 1) break;
        else          printf("Eingabefehler!!!\n");
    }
    return number;
}
