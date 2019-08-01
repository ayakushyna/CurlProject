#include "GeoPointView.hpp"

GeoPointView::GeoPointView() {}

void GeoPointView::onGeoPointChanged(GeoPoint* geoPoint
									, Action action
									, GeoPointProperty property
									, std::string oldValue
									, std::string newValue)
{
	switch (action)
	{
		case Create:
		{
			std::cout << "Created geo point:\n";
			break;
		}
		case Update:
		{
			std::cout << "Updated geo point`s property:\n";
			switch (property)
			{
				case GP_Latitude:
				{
					std::cout << "Old latitude: " << oldValue << ", new: " << newValue << '\n';
					break;
				}
				case GP_Longitude:
				{
					std::cout << "Old longitude: " << oldValue << ", new: " << newValue << '\n';
					break;
				}
				default:
				{
					std::cout << "The whole geo point:\n";
					break;
				}
			}
			break;
		}
		case Delete:
		{
			std::cout << "Deleted geo point:\n";
			break;
		}
	}
	printGeoPoint(geoPoint);
}

void GeoPointView::printGeoPoint(GeoPoint* geoPoint)
{
	std::cout << geoPoint->toString() << '\n';
}