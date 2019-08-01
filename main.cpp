#include <iostream>
#include <fstream>
#include <conio.h>
#include "App/Model/App/App.hpp"

int main()
{
	App* app = App::sharedApp();
	HTTPNetworkController* netC = App::getHTTPNetworkController();
	CityController* cityC = App::getCityController();
	MenuController* menuC = App::getMenuController();

	std::ifstream ifs("./small_list.json");
	json j;
	ifs >> j;
	cityC->loadCities(j);

	Menu* menu = menuC->createMenu();

	HTTPResponse* response = nullptr;
	City* city = nullptr;

	switch (menuC->readOption(menu))
	{
		case 1:
		{
			city = cityC->getCity(menuC->readName(menu));

			if (city != nullptr) {
				response = netC->sendRequest("https://api.openweathermap.org/data/2.5/forecast?", {}
								, { {"q", menuC->readName(menu)}
								, {"appid", "4edc9573e58ce31bffcaafb806f4db06"}
								, {"units","metric" } }
								, M_GET, PERCENT_ENC);
			}
			break;
		}
		case 2:
		{
			city = cityC->getCity(menuC->readLatitude(menu), menuC->readLongitude(menu));

			if (city != nullptr) {
				response = netC->sendRequest("https://api.openweathermap.org/data/2.5/forecast?", {}
								, { {"lat", std::to_string(menuC->readLatitude(menu))}
								, {"lon", std::to_string(menuC->readLongitude(menu))}
								, {"appid", "4edc9573e58ce31bffcaafb806f4db06"}
								, {"units","metric" } }
								, M_GET, PERCENT_ENC);
			}
		}
	}

	if (response != nullptr && !response->getBody().empty()) {
		json body = JsonType::parseToJson(response->getBody());
		cityC->loadForecasts(city, JsonType::getArray(body, "list"));

		std::cout << "\n!!!Forecast for " << cityC->readName(city) << " on " << menuC->readDate(menu) << "!!!\n\n";
		std::vector<Weather*> forecasts = cityC->readForecasts(city, menuC->readDate(menu));
		for (Weather* weather : forecasts) {
			WeatherView::printWeather(weather);
		}
		std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
	}

	std::cout << "Press any buttom to quit.";
	_getch();

	delete menu;
	delete app;
	return 0;
}
