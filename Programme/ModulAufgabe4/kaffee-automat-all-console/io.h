#ifndef __IO_H__
#define __IO_H__

#include <stddef.h> /* for size_t */

/* prints the given string (if not NULL) and reads a string from stdin and
 * removes \n
 * the functions returns the value of fgets */
extern char * io_read_string(char * read_buffer, size_t buffer_size,
                             const char * output_str, ...);

/* prints the given string (if not NULL) and reads signed number from stdin */
extern int io_read_signed_number(const char * output_str, ...);

/* prints the given string (if not NULL) and reads unsigned number from stdin */
extern unsigned int io_read_unsigned_number(const char * output_str, ...);

#endif /* __IO_H__ */
