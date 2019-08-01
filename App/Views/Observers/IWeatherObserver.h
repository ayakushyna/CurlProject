#pragma once
#include "../../../Enums/CPEnums.h"
#include "../../Model/Weather/Weather.hpp"
#include <string>
class IWeatherObserver
{
public:
	virtual ~IWeatherObserver() = default;

	virtual void onWeatherChanged(Weather* weather
								, Action action
								, WeatherProperty property
								, std::string oldValue
								, std::string newValue) = 0;
};