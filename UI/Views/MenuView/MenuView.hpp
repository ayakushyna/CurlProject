#pragma once
#include <iostream>
#include <string>
#include "../Observers/IMenuObserver.h"
#include "../../../App/Model/App/App.hpp"

class MenuView :
	public IMenuObserver
{
public:
	MenuView();
	~MenuView() = default;

	void onMenuChanged(Menu* menu, MenuType type);

	void inputOption(Menu* menu);
	void inputName(Menu* menu);
	void inputLatitude(Menu* menu);
	void inputLongitude(Menu* menu);
	void inputDate(Menu* menu);
};

