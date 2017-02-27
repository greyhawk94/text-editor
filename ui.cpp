#include "ui.h"
#include "commands.h"

using namespace std;

inline void print_line(char* line)
{
	cout << line << endl;
}

inline void print_line_input(char* line)
{
	cout << line;
}

inline void create_line(char* &line)
{
	line = (char*)malloc(sizeof(char) * 81);
	for (int i = 0; i < WIDTH; i++)
		line[i] = '-';
	line[WIDTH] = 0;
}

inline void print_file(char **file)
{
	for (int i = 0; i < LENGTH; i++)
	{
		print_line_input("|");
		print_line(file[i]);
	}
}

inline char* mode_to_char(mode mode_)
{
	switch(mode_)
	{
	case NONE:
		return "NONE";
	case NEW:
		return "NEW";
	case EDIT:
		return "EDIT";
	case OPEN:
		return "OPEN";
	case SAVE:
		return "FILE SAVED";
	default:
		return "";
	}

}

void basic_ui(char* input)
{
	system("cls");
	char* line = 0;
	create_line(line);
	print_line(line);
	print_line_input("| EDITOR - ");
	print_line_input(fileName);
	print_line_input(" - mode : ");
	print_line_input(mode_to_char(currentMode));
	print_line(" - type help for help");
	print_line(line);
	print_file(file);
	print_line(line);
	print_line_input("|");
	print_line_input(input);

}

void help_ui(char* input)
{
	system("cls");
	char* line = 0;
	create_line(line);
	print_line(line);
	print_line("| EDITOR - HELP DISPLAY");
	print_line(line);
	
	print_line("|This is the Help display");
	print_line("|");
	print_line("|type NEW to create a new file");
	print_line("|     then type the file name when prompted");
	print_line("|");
	print_line("|type OPEN to open new file from the filesystem");
	print_line("|     then type the file name when prompted");
	print_line("|");
	print_line("|type SAVE to save the current file to the filesystem");
	print_line("|");
	print_line("|type EDIT to edit the current file");
	print_line("|     then type the line number then a space then a line of text like this :");
	print_line("|     5 this is the 5th line of my file");
	print_line("|");

	print_line(line);
	print_line_input("|");
	print_line_input(input);

}