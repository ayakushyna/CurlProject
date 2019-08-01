#pragma once
#include <iostream>
#include <string>
#include "../Observers/IWeatherObserver.h"
class WeatherView :
	public IWeatherObserver
{
public:
	WeatherView();
	~WeatherView() = default;

	void onWeatherChanged(Weather* weather
		, Action action
		, WeatherProperty property
		, std::string oldValue
		, std::string newValue);

	static void printWeather(Weather* weather);
};

