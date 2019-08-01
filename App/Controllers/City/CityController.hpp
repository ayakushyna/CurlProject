#pragma once
#include <string>
#include <set>
#include <vector>
#include "../../Model/App/App.hpp"
#include "../../Model/City/City.hpp"
#include "../../Views/Observers/ICityObserver.h"
#include "../../Model/JsonType/JsonType.hpp"

class CityController
{
public:
	CityController();
	~CityController();

	void loadCities(const json& object);
	void loadForecasts(City* city, const json& object);

	City* getCity(const std::string& name) const;
	City* getCity(double lat, double lon) const;

	City* createCity(const std::string& name, GeoPoint* position);
	bool deleteCity(City* city);

	const std::string& readName(City* city) const;
	City* updateName(City* city, const std::string& name);

	GeoPoint* readPosition(City* city) const;
	City* updatePosition(City* city, GeoPoint* position);

	std::vector<Weather*> readForecasts(City* city, const std::string& date) const;
	City* addForecast(City* city, Weather* weather);
	City* removeForecast(City* city, const std::string& date);

	void addObserver(ICityObserver* observer);
	void removeObserver(ICityObserver* observer);

	void sendEvent(City* city
				, Action action
				, CityProperty property
				, std::string oldValue
				, std::string newValue);

	City* createFromJson(const json& object);

private:
	std::set<City*> m_cities;
	std::set<ICityObserver*> m_observers;
};

