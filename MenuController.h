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
	/* Create object with title, if submenu then will display back instead of quit in menu*/
	MenuController(std::string title = "Menu", bool subMenu = false) 
		: titleText(title), subMenu(subMenu) {};
	/* Display currently added options */
	void display();
	/* Pass in a vector of options to be displayed */
	void display(std::vector<std::string> options, bool saveOptions = false);
	/* Add option with string, add in order you want to appear */
	void add_Menu_Option(std::string optionText) { option.push_back(optionText); }
	/* Change an option to a new string */
	void set_Menu_Option(int optionID, std::string text) { option[optionID] = text; }

	void set_Title(std::string titleText);
private:
	void display_Title();
	void display_Options();
	bool subMenu;
};

#endif // !MENU_CONTROLLER_H
