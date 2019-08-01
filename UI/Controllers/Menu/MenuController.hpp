#pragma once
#include <set>
#include <vector>
#include "../../Model/Menu/Menu.hpp"
#include "../../Views/Observers/IMenuObserver.h"

class MenuController
{
public:
	MenuController();
	~MenuController();

	Menu* createMenu();
	bool deleteMenu(Menu* menu);

	const std::string& readDate(Menu* menu) const;
	Menu* updateDate(Menu* menu, const std::string& date);

	const std::string& readName(Menu* menu) const;
	Menu* updateName(Menu* menu, const std::string& name);

	double readLatitude(Menu* menu) const;
	Menu* updateLatitude(Menu* menu, double latitude);

	double readLongitude(Menu* menu) const;
	Menu* updateLongitude(Menu* menu, double longitude);

	int readOption(Menu* menu) const;
	Menu* updateOption(Menu* menu, int option);

	void addObserver(IMenuObserver* observer);
	void removeObserver(IMenuObserver* observer);

	void sendEvent(Menu* menu, MenuType type);

private:
	std::set<IMenuObserver*> m_observers;
};

