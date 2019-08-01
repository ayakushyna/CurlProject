#pragma once
#include <string>
#include <sstream> 
#include <iomanip> 
class GeoPoint
{
public:
	GeoPoint(double latitude, double longitude);
	~GeoPoint() = default;

	double getLatitude() const;
	void setLatitude(double latitude);

	double getLongitude() const;
	void setLongitude(double longitude);

	std::string toString()const;

private:
	double m_latitude;
	double m_longitude;
};

