#!/bin/bash

grep '^#include' $1 | cpp -P -dD -undef -nostdinc -Iinclude/ -DREGION_US | xclip -select clipboard
