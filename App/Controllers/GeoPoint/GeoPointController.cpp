#include "GeoPointController.hpp"

GeoPointController::GeoPointController() {}

GeoPointController::~GeoPointController() {
	for (IGeoPointObserver* observer : m_observers) {
		delete observer;
		observer = nullptr;
	}
	m_observers.clear();
}

GeoPoint* GeoPointController::createGeoPoint(double latitude, double longitude) {
	GeoPoint* geoPoint = new GeoPoint(latitude, longitude);
	sendEvent(geoPoint, Create, GP_GeoPoint, "", "");
	return geoPoint;
}

bool GeoPointController::deleteGeoPoint(GeoPoint* geoPoint) {
	if (geoPoint != nullptr) {
		sendEvent(geoPoint, Delete, GP_GeoPoint, "", "");
		delete geoPoint;
		geoPoint = nullptr;
		return true;
	}
	return false;
}

double GeoPointController::readLatitude(GeoPoint* geoPoint) const {
	if (geoPoint != nullptr) {
		return geoPoint->getLatitude();
	}
	return 0;
}

GeoPoint* GeoPointController::updateLatitude(GeoPoint* geoPoint, double latitude) {
	if (geoPoint != nullptr) {
		double oldLatitude = geoPoint->getLatitude();
		geoPoint->setLatitude(latitude);
		sendEvent(geoPoint, Update, GP_Latitude, std::to_string(oldLatitude), std::to_string(latitude));
	}
	return geoPoint;
}

double GeoPointController::readLongitude(GeoPoint* geoPoint) const {
	if (geoPoint != nullptr) {
		return geoPoint->getLongitude();
	}
	return 0;
}

GeoPoint* GeoPointController::updateLongitude(GeoPoint* geoPoint, double longitude) {
	if (geoPoint != nullptr) {
		double oldLongitude = geoPoint->getLongitude();
		geoPoint->setLongitude(longitude);
		sendEvent(geoPoint, Update, GP_Longitude, std::to_string(oldLongitude), std::to_string(longitude));
	}
	return geoPoint;
}

void GeoPointController::addObserver(IGeoPointObserver* observer) {
	if (observer != nullptr) {
		m_observers.insert(observer);
	}
}

void GeoPointController::removeObserver(IGeoPointObserver* observer) {
	if (observer != nullptr) {
		m_observers.erase(observer);
		delete observer;
		observer = nullptr;
	}
}

void GeoPointController::sendEvent(GeoPoint* geoPoint
								, Action action
								, GeoPointProperty property
								, std::string oldValue
								, std::string newValue) 
{
	for (IGeoPointObserver* observer : m_observers) {
		observer->onGeoPointChanged(geoPoint, action, property, oldValue, newValue);
	}
}

GeoPoint* GeoPointController::createFromJson(const json& object) {
	if (object.contains("lat")  && object.contains("lon") ) {
		return createGeoPoint(JsonType::getDouble(object,"lat"), JsonType::getDouble(object,"lon"));
	}
	return nullptr;
}