#pragma once
#include <set>
#include "../../Model/GeoPoint/GeoPoint.hpp"
#include "../../Views/Observers/IGeoPointObserver.h"
#include "../../Model/JsonType/JsonType.hpp"

class GeoPointController
{
public:
	GeoPointController();
	~GeoPointController();

	GeoPoint* createGeoPoint(double latitude, double longitude);
	bool deleteGeoPoint(GeoPoint* geoPoint);

	double readLatitude(GeoPoint* geoPoint) const;
	GeoPoint* updateLatitude(GeoPoint* geoPoint, double latitude);

	double readLongitude(GeoPoint* geoPoint) const;
	GeoPoint* updateLongitude(GeoPoint* geoPoint, double longitude);

	void addObserver(IGeoPointObserver* observer);
	void removeObserver(IGeoPointObserver* observer);

	void sendEvent(GeoPoint* geoPoint
				, Action action
				, GeoPointProperty property
				, std::string oldValue
				, std::string newValue);

	GeoPoint* createFromJson(const json& object);

private:
	std::set<IGeoPointObserver*> m_observers;
};

