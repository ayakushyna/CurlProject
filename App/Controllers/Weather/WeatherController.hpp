#pragma once
#include <set>
#include "../../Model/Weather/Weather.hpp"
#include "../../Views/Observers/IWeatherObserver.h"
#include "../../Model/JsonType/JsonType.hpp"

class WeatherController
{
public:
	WeatherController();
	~WeatherController();

	Weather* createWeather(const std::string& date
						, const std::string& description
						, double temp
						, double pressure
						, double windSpeed
						, int humidity);
	bool deleteWeather(Weather* weather);

	const std::string& readDate(Weather* weather) const;
	Weather* updateDate(Weather* weather, const std::string& date);

	const std::string& readDescription(Weather* weather) const;
	Weather* updateDescription(Weather* weather, const std::string& description);

	double readTemperature(Weather* weather) const;
	Weather* updateTemperature(Weather* weather, double temperature);

	double readPressure(Weather* weather) const;
	Weather* updatePressure(Weather* weather, double pressure);

	double readWindSpeed(Weather* weather) const;
	Weather* updateWindSpeed(Weather* weather, double windSpeed);

	int readHumidity(Weather* weather) const;
	Weather* updateHumidity(Weather* weather, int humidity);

	void addObserver(IWeatherObserver* observer);
	void removeObserver(IWeatherObserver* observer);

	void sendEvent(Weather* weather
				, Action action
				, WeatherProperty property
				, std::string oldValue
				, std::string newValue);

	Weather* createFromJson(const json& object);

private:
	std::set<IWeatherObserver*> m_observers;
};

