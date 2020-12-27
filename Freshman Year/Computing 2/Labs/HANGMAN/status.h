#ifndef STATUS_H
#define STATUS_H

enum status { FAILURE, SUCCESS };
typedef enum status Status;
typedef enum Boolean {FALSE, TRUE} Boolean;

#define NYI(x)          \
{                       \
    fprintf(stderr, "Not Yet Implemented: %s\n", x);        \
    exit(1);            \
}                       \

#endif
