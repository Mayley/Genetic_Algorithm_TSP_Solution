#include "MenuController.h"

void MenuController::display(std::vector<std::string> options) {
	option = options;
	display_Title();
	display_Options();
}

void MenuController::set_Title(std::string titleText) {
	this->titleText = titleText;
}

void MenuController::display_Title() {
	std::cout << "---------------------------" << std::endl;
	std::cout << titleText << std::endl;
	std::cout << "---------------------------" << std::endl;
}

void MenuController::display_Options() {
	for (int i = 0; i < option.size(); i++)
	{
		std::cout << i << ": " << option[i] << std::endl;
	}

	std::cout << "-1: Quit" << std::endl;
}
