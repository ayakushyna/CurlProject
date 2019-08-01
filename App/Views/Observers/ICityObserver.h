#pragma once
#include "../../../Enums/CPEnums.h"
#include "../../Model/City/City.hpp"
#include <string>
class ICityObserver 
{
public:
	virtual ~ICityObserver() = default;

	virtual void onCityChanged(City* city
							, Action action
							, CityProperty property
							, std::string oldValue
							, std::string newValue) = 0;
};