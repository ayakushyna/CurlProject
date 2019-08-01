#include "MenuController.hpp"

MenuController::MenuController() {}

MenuController::~MenuController() {
	for (IMenuObserver* observer : m_observers) {
		delete observer;
		observer = nullptr;
	}
	m_observers.clear();
}

Menu* MenuController::createMenu() {
	Menu* menu = new Menu();
	sendEvent(menu, Main);
	return menu;
}

bool MenuController::deleteMenu(Menu* menu) {
	if (menu != nullptr) {
		delete menu;
		menu = nullptr;
		return true;
	}
	return false;
}

const std::string& MenuController::readDate(Menu* menu) const {
	if (menu != nullptr) {
		return menu->getDate();
	}
	return "";
}

Menu* MenuController::updateDate(Menu* menu, const std::string& date) {
	if (menu != nullptr) {
		menu->setDate(date);
	}
	return menu;
}

const std::string& MenuController::readName(Menu* menu) const {
	if (menu != nullptr) {
		return menu->getName();
	}
	return "";
}

Menu* MenuController::updateName(Menu* menu, const std::string& name) {
	if (menu != nullptr) {
		menu->setName(name);
		sendEvent(menu, InputDate);
	}
	return menu;
}

double MenuController::readLatitude(Menu* menu) const {
	if (menu != nullptr) {
		return menu->getLatitude();
	}
	return 0;
}

Menu* MenuController::updateLatitude(Menu* menu, double latitude) {
	if (menu != nullptr) {
		menu->setLatitude(latitude);
		sendEvent(menu, InputLongitude);
	}
	return menu;
}

double MenuController::readLongitude(Menu* menu) const {
	if (menu != nullptr) {
		return menu->getLongitude();
	}
	return 0;
}

Menu* MenuController::updateLongitude(Menu* menu, double longitude) {
	if (menu != nullptr) {
		menu->setLongitude(longitude);
		sendEvent(menu, InputDate);
	}
	return menu;
}

int MenuController::readOption(Menu* menu) const {
	if (menu != nullptr) {
		return menu->getOption();
	}
	return 0;
}

Menu* MenuController::updateOption(Menu* menu, int option) {
	if (menu != nullptr) {
		menu->setOption(option);

		switch (option) 
		{
			case 1: 
			{
				sendEvent(menu, InputName);
				break;
			}
			case 2: 
			{
				sendEvent(menu, InputLatitude);
				break;
			}
			default:
			{
				sendEvent(menu, Main);
				break;
			}
		}
		
	}
	return menu;
}


void MenuController::addObserver(IMenuObserver* observer) {
	if (observer != nullptr) {
		m_observers.insert(observer);
	}
}

void MenuController::removeObserver(IMenuObserver* observer) {
	if (observer != nullptr) {
		m_observers.erase(observer);
		delete observer;
		observer = nullptr;
	}
}

void MenuController::sendEvent(Menu* menu, MenuType type) {
	for (IMenuObserver* observer : m_observers) {
		observer->onMenuChanged(menu, type);
	}
}