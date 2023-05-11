#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

static Node *Allocate(void){
    return calloc(1, sizeof(Node));
}