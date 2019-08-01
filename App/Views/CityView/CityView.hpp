#pragma once
#include <iostream>
#include <string>
#include "../Observers/ICityObserver.h"
#include "../GeoPointView/GeoPointView.hpp"
#include "../../Model/App/App.hpp"

class CityView :
	public ICityObserver
{
public:
	CityView();
	~CityView() = default;

	void onCityChanged(City* city
		, Action action
		, CityProperty property
		, std::string oldValue
		, std::string newValue);

	void printCity(City* city);
	static void printForecasts(City* city, const std::string& date);
};

