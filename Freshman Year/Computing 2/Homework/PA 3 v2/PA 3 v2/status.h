#ifndef STATUS_H
#define STATUS_H

enum status { FAILURE, SUCCESS };
typedef enum status Status;

#define NYI(x)          \
{                       \
    fprintf(stderr, "Not Yet Implemented: %s\n", x);        \
    exit(1);            \
}                       \

#endif