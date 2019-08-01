#pragma once
#include <iostream>
#include <string>
#include "../Observers/IGeoPointObserver.h"

class GeoPointView :
	public IGeoPointObserver
{
public:
	GeoPointView();
	~GeoPointView() = default;

	void onGeoPointChanged(GeoPoint* geoPoint
		, Action action
		, GeoPointProperty property
		, std::string oldValue
		, std::string newValue);

	static void printGeoPoint(GeoPoint* geoPoint);
};

