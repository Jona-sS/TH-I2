#include "checker.h"
#include <stdio.h>

int main()
{
    if (checker_check()) {
        printf("alles gut\n");
        return 0;
    } else {
        printf("%s\n", checker_error_string());
        return 1;
    }
}
