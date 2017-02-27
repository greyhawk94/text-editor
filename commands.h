#pragma once

#include <stdlib.h>
#include <iostream>
#include <fstream>

enum mode { NONE, NEW, OPEN, EDIT, SAVE };

extern mode currentMode;

extern bool keepAlive;

void command_input(char* &input);
