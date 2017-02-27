#include "main.h"

using namespace std;

mode currentMode = NONE;
bool keepAlive = true;
char* fileName = "";
char** file = 0;

int main(int argc, char** argv)
{
	currentMode = NONE;
	keepAlive = true;
	fileName = "no file";
	file = (char**)malloc(sizeof(char*) * LENGTH);
	for (int i = 0; i < LENGTH; i++)
	{
		file[i] = (char*)malloc(sizeof(char) * (WIDTH+1));
		for (int j = 0; j < WIDTH; j++)
			file[i][j] = 0;
		file[i][WIDTH] = 0;
	}

	while (keepAlive)
	{
		char* input = 0;
		basic_ui(">");
		command_input(input);
	}

	return 0;
}
