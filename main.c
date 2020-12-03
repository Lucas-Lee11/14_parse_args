#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

char ** parse_args( char * line ){
    char * s = line;
    char ** args = malloc(256 * sizeof(char));
    int i = 0;

    while(s != NULL){
        args[i] = strsep(&s, " ");
        i++;
    }
    args[i] = 0;
    return args;
}

int main(int argc, char *argv[]) {
    if(argc < 2) return -1;
    char ** args = parse_args( argv[1] );
    execvp(args[0], args);
    free(args);

    return 0;
}
