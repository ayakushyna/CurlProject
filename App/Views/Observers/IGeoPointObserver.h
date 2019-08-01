#pragma once
#include "../../../Enums/CPEnums.h"
#include "../../Model/GeoPoint/GeoPoint.hpp"
#include <string>
class IGeoPointObserver
{
public:
	virtual ~IGeoPointObserver() = default;

	virtual void onGeoPointChanged(GeoPoint* geoPoint
								, Action action
								, GeoPointProperty property
								, std::string oldValue
								, std::string newValue) = 0;
};