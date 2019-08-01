#include "GeoPoint.hpp"

GeoPoint::GeoPoint(double latitude, double longitude) : m_latitude(latitude), m_longitude(longitude) {}

double GeoPoint::getLatitude() const { return m_latitude; }

void GeoPoint::setLatitude(double latitude) { m_latitude = latitude; }

double GeoPoint::getLongitude() const { return m_longitude; }

void GeoPoint::setLongitude(double longitude) { m_longitude = longitude; }

std::string GeoPoint::toString() const{
	std::stringstream  ss;
	ss << std::fixed << std::setprecision(6) 
		<< "Latitude: " << m_latitude << '\n'
		<< "Longitude: " << m_longitude << '\n';

	return ss.str();
}