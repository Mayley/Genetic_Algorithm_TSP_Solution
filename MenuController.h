#ifndef MENU_CONTROLLER_H
#define MENU_CONTROLLER_H

#include <string>
#include <iostream>
#include <vector>

class MenuController
{
private:
	std::string titleText;
	std::vector<std::string> option;
public:
	void display(std::vector<std::string> options);
	void set_Title(std::string titleText);
private:
	void display_Title();
	void display_Options();
};

#endif // !MENU_CONTROLLER_H
