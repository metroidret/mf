#!/bin/bash

# retrieves the headers associated with the file specified in $1, 
# must be run from the root of the project tree
# pipes the output to a file specified with $2
grep '^#include' $1 | cpp -P -dD -undef -nostdinc -Iinclude/ -DREGION_US > $2
