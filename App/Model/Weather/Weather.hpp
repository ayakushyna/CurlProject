#pragma once
#include <string>
#include <sstream> 

class Weather
{
public:
	Weather(const std::string& date
		, const std::string& description
		, double temp
		, double pressure
		, double windSpeed
		, int humidity);
	~Weather() = default;

	const std::string& getDate() const;
	void setDate(const std::string& date);

	const std::string& getDescription() const;
	void setDescription(const std::string& description);

	double getTemperature () const;
	void setTemperature(double temp);

	double getPressure() const;
	void setPressure(double pressure);

	double getWindSpeed() const;
	void setWindSpeed(double windSpeed);

	int getHumidity() const;
	void setHumidity(int humidity);

	std::string toString() const;

private:
	std::string m_date, m_description;
	double m_temperature, m_pressure, m_windSpeed;
	int m_humidity;
};

