#pragma once
#include <string>
#include <sstream> 
#include <map>
#include "../GeoPoint/GeoPoint.hpp"
#include "../Weather/Weather.hpp"

class City
{
public:
	City(const std::string& name, GeoPoint* position);
	~City();

	const std::string& getName() const;
	void setName(const std::string& name);

	GeoPoint* getPosition() const;
	void setPosition(GeoPoint* position);

	const std::map<std::string, Weather*>& getForecasts() const;
	void addForecast(Weather* weather);
	void removeForecast(const std::string& date);

	std::string toString() const;

private:
	std::string m_name;
	GeoPoint* m_position;
	std::map<std::string, Weather*> m_forecasts;
};

