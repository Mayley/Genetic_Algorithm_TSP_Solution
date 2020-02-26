#include "MenuController.h"

void MenuController::display() {
	display_Title();
	display_Options();
}

/* Display list of options from a vector */
void MenuController::display(std::vector<std::string> options, bool saveOptions) {
	if (saveOptions)
	{
		option = options;
		display_Title();
		display_Options();
	}
	else {
		for (int i = 0; i < option.size(); i++)
		{
			std::cout << (i + 1) << ": " << option[i] << std::endl;
		}

		if (subMenu)
		{
			std::cout << "-1: Back" << std::endl;
		}
		else {
			std::cout << "-1: Quit" << std::endl;
		}
	}
}

void MenuController::set_Title(std::string titleText) {
	this->titleText = titleText;
}

void MenuController::display_Title() {
	std::cout << "---------------------------" << std::endl;
	std::cout << titleText << std::endl;
	std::cout << "---------------------------" << std::endl;
}

/* Displays all options added to menu, default quit option is -1*/
void MenuController::display_Options() {
	for (int i = 0; i < option.size(); i++)
	{
		std::cout << (i+1) << ": " << option[i] << std::endl;
	}

	if (subMenu)
	{
		std::cout << "-1: Back" << std::endl;
	}
	else {
		std::cout << "-1: Quit" << std::endl;
	}
}
