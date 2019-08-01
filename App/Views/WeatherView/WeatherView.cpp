#include "WeatherView.hpp"

WeatherView::WeatherView() {}

void WeatherView::onWeatherChanged(Weather* weather
								, Action action
								, WeatherProperty property
								, std::string oldValue
								, std::string newValue) 
{
	switch (action)
	{
		case Create:
		{
			std::cout << "Created weather:\n";
			break;
		}
		case Update:
		{
			std::cout << "Updated weather`s property:\n";
			switch (property)
			{
				case WP_Date:
				{
					std::cout << "Old date: " << oldValue << ", new: " << newValue << '\n';
					break;
				}
				case WP_Description:
				{
					std::cout << "Old description: " << oldValue << ", new: " << newValue << '\n';
					break;
				}
				case WP_Pressure:
				{
					std::cout << "Old pressure: " << oldValue << ", new: " << newValue << '\n';
					break;
				}
				case WP_Temperature:
				{
					std::cout << "Old temperature: " << oldValue << ", new: " << newValue << '\n';
					break;
				}
				case WP_WindSpeed:
				{
					std::cout << "Old wind speed: " << oldValue << ", new: " << newValue << '\n';
					break;
				}
				case WP_Humidity:
				{
					std::cout << "Old humidity: " << oldValue << ", new: " << newValue << '\n';
					break;
				}
				default:
				{
					std::cout << "The whole weather:\n";
					break;
				}
			}
			break;
		}
		case Delete:
		{
			std::cout << "Deleted weather:\n";
			break;
		}
	}
	printWeather(weather);
}

void WeatherView::printWeather(Weather* weather) 
{
	std::cout << weather->toString() << '\n';
}