#pragma once
#include <iostream>
#include "../../Controllers/City/CityController.hpp"
#include "../../Controllers/Weather/WeatherController.hpp"
#include "../../Controllers/GeoPoint/GeoPointController.hpp"
#include "../../../UI/Controllers/Menu/MenuController.hpp"
#include "../../../Net/Controllers/HTTPNetwork/HTTPNetworkController.hpp"

#include "../../Views/CityView/CityView.hpp"
#include "../../Views/WeatherView/WeatherView.hpp"
#include "../../Views/GeoPointView/GeoPointView.hpp"
#include "../../../UI/Views/MenuView/MenuView.hpp"

class CityView;
class CityController;
class MenuView;

class App
{
public:
	static App* sharedApp();
	~App();

	static HTTPNetworkController* getHTTPNetworkController();
	static CityController* getCityController();
	static WeatherController* getWeatherController();
	static GeoPointController* getGeoPointController();
	static MenuController* getMenuController();

private:
	App();
};

