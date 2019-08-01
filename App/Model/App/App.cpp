#include "App.hpp"

App* App::sharedApp() {
	static App* app = new App;
	return app;
}

App::App() {
	CityController* cityC = App::getCityController();
	CityView* cityV = new CityView;
	cityC->addObserver(cityV);

	WeatherController* weatherC = App::getWeatherController();
	WeatherView* weatherV = new WeatherView;
	weatherC->addObserver(weatherV);

	GeoPointController* geoPointC = App::getGeoPointController();
	GeoPointView* geoPointV = new GeoPointView;
	geoPointC->addObserver(geoPointV);

	MenuController* menuC = App::getMenuController();
	MenuView* menuV = new MenuView;
	menuC->addObserver(menuV);
}

App::~App() {
	delete App::getHTTPNetworkController();
	delete App::getCityController();
	delete App::getWeatherController();
	delete App::getGeoPointController();
	delete App::getMenuController();
}


HTTPNetworkController* App::getHTTPNetworkController() { 
	static HTTPNetworkController* hnc = new HTTPNetworkController;
	return hnc;
}

CityController* App::getCityController() { 
	static CityController* cc = new CityController;
	return cc;
}

WeatherController* App::getWeatherController() { 
	static WeatherController* wc = new WeatherController;
	return wc;
}

GeoPointController* App::getGeoPointController() { 
	static GeoPointController* gpc = new GeoPointController;
	return gpc;
}

MenuController* App::getMenuController() {
	static MenuController* mc = new MenuController;
	return mc;
}