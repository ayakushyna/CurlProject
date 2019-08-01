#include "CityView.hpp"
CityView::CityView() {}

void CityView::onCityChanged(City* city
							, Action action
							, CityProperty property
							, std::string oldValue
							, std::string newValue)
{
	switch (action)
	{
		case Create:
		{
			std::cout << "Created city:\n";
			break;
		}
		case Update:
		{
			std::cout << "Updated city`s property:\n";
			switch (property)
			{
				case CP_Name:
				{
					std::cout << "Old name: " << oldValue << ", new: " << newValue << '\n';
					break;
				}
				case CP_Position:
				{
					std::cout << "Old position: " << oldValue << ", new: " << newValue << '\n';
					break;
				}
				default:
				{
					std::cout << "The whole city:\n";
					break;
				}
			}
			break;
		}
		case Delete:
		{
			std::cout << "Deleted city:\n";
			break;
		}
	}
	printCity(city);
}

void CityView::printCity(City* city)
{
	std::cout << city->toString() << '\n';
}
