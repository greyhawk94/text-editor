#include "commands.h"
#include "ui.h"

using namespace std;

inline int match(char* pattern, char* string)
{
	int i = 0;
	while (string[i] != 0)
	{
		int j = 0;
		int formeri = i;
		while ((pattern[j] != 0) && (string[i] != 0) && (pattern[j] == string[i]))
		{
			j++;
			i++;
		}

		if (pattern[j] == 0)
			return formeri;
		i = formeri;
		i++;
	}
	return -1;
}

inline void strcopy(char* src, char *dest, int start)
{
	int i = start;
	int j = 0;

	while (src[i] != 0)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
}

inline void parse_input(char* input)
{
	int i = 0;
	int line = 0;

	while ((input[i] != 0) && (input[i]>='0') && (input[i]<='9'))
	{
		line *= 10;
		line += (input[i]-48);
		i++;

	}

	if (line <= LENGTH)
	{
		line--;
		strcopy(input, file[line], i+1);
	}
}

void command_input(char* &input)
{
	input = (char*)malloc(sizeof(char) * WIDTH);
	for (int j = 0; j < 81; j++)
		input[j] = 0;
	cin.getline(input, WIDTH);

	if ((currentMode == NONE) && (match("new", input) != -1))
	{
		currentMode = NEW;
		basic_ui(" filename? >");
		command_input(input);
	}

	else if (currentMode == NEW)
	{
		currentMode = NONE;
		fileName = input;
	}

	else if ((currentMode == NONE) && (match("edit", input) != -1))
	{
		currentMode = EDIT;
		basic_ui(" line text? >");
		command_input(input);
	}
	
	else if (currentMode == EDIT)
	{
		currentMode = NONE;
		parse_input(input);
	}

	else if ((currentMode == NONE) && (match("save", input) != -1))
	{
		currentMode = NONE;
		ofstream myfile;
		myfile.open(fileName);
		for (int i = 0; i < LENGTH; i++)
			myfile << file[i] << endl;
		myfile.close();
		basic_ui(" File saved >");
		command_input(input);
	}

	else if (currentMode == SAVE)
	{
		currentMode = NONE;
	}

	else if ((currentMode == NONE) && (match("quit", input) != -1))
	{
		keepAlive = false;
	}
	else if ((currentMode == NONE) && (match("exit", input) != -1))
	{
		keepAlive = false;
	}

	else if ((currentMode == NONE) && (match("open", input) != -1))
	{
		currentMode = OPEN;
		basic_ui(" filename? >");
		command_input(input);
	}

	else if (currentMode == OPEN)
	{
		currentMode = NONE;
		fileName = input;

		ifstream myfile(fileName);
		if (myfile.is_open())
		{
			int i = 0;
			while ((i<LENGTH) && myfile.getline(file[i], WIDTH))
				i++;
			myfile.close();
		}

		basic_ui(" File opened >");
		command_input(input);
	}

	else if ((currentMode == NONE) && (match("help", input) != -1))
	{
		help_ui(" press ENTER to return to the file editor... ");
		command_input(input);
	}
}
