#include "forthutil.h"

int countWords(char *string) {
    int i = 0;
    while(string++) {
        if(string[0] == ' ') {
            i++;
        }
    }
    return i;
}
