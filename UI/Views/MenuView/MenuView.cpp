#include "MenuView.hpp"

MenuView::MenuView() {}

void MenuView::onMenuChanged(Menu* menu, MenuType type) {
	switch (type)
	{
		case InputName:
		{
			inputName(menu);
			break;
		}
		case InputLatitude:
		{
			inputLatitude(menu);
			break;
		}
		case InputLongitude:
		{
			inputLongitude(menu);
			break;
		}
		case InputDate:
		{
			inputDate(menu);
			break;
		}
		default:
		{
			inputOption(menu);
			break;
		}
	}
}

void MenuView::inputOption(Menu* menu){
	int option = 0;

	std::cout << "\nSearch city by:";
	std::cout << "\n 1 - City name;";
	std::cout << "\n 2 - City coordinates;";
	std::cout << "\nEnter:";
	std::cin >> option;

	App::getMenuController()->updateOption(menu, option);
}

void MenuView::inputName(Menu* menu) {
	std::string name;

	std::cout << "\nInput city name :";
	std::cin.ignore();
	std::getline(std::cin, name);

	App::getMenuController()->updateName(menu, name);
}

void MenuView::inputLatitude(Menu* menu) {
	double latitude = 0;

	std::cout << "\nInput city latitude: ";
	std::cin >> latitude;

	App::getMenuController()->updateLatitude(menu, latitude);
}

void MenuView::inputLongitude(Menu* menu) {
	double longitude = 0;

	std::cout << "\nInput city longitude: ";
	std::cin >> longitude;

	App::getMenuController()->updateLongitude(menu, longitude);
}

void MenuView::inputDate(Menu* menu) {
	int year = 0, month = 0, day = 0;

	std::cout << "\nInput date (available forecast for next 5 days)";
	std::cout << "\nYear: ";
	std::cin >> year;

	std::cout << "Month: ";
	std::cin >> month;

	std::cout << "Day: ";
	std::cin >> day;

	std::string date = std::to_string(year) + "-"
		+ (month < 10 ? "0" + std::to_string(month) : std::to_string(month)) + "-"
		+ (day < 10 ? "0" + std::to_string(day) : std::to_string(day));

	App::getMenuController()->updateDate(menu, date);
}