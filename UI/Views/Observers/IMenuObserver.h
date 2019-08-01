#pragma once
#include "../../../Enums/CPEnums.h"
#include "../../Model/Menu/Menu.hpp"
#include <string>
class IMenuObserver
{
public:
	virtual ~IMenuObserver() = default;

	virtual void onMenuChanged(Menu* menu, MenuType type) = 0;
};