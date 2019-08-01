#include "Weather.hpp"

Weather::Weather(const std::string& date
				, const std::string& description
				, double temp
				, double pressure
				, double windSpeed
				, int humidity) :
	m_date(date), m_description(description), m_temperature(temp)
	, m_pressure(pressure), m_windSpeed(windSpeed), m_humidity(humidity) {}

const std::string& Weather::getDate() const { return m_date; }

void Weather::setDate(const std::string& date) { m_date = date; }

const std::string& Weather::getDescription() const { return m_description; }

void  Weather::setDescription(const std::string& description) { m_description = description; }

double Weather::getTemperature() const { return m_temperature; }

void Weather::setTemperature(double temp) { m_temperature = temp; }

double Weather::getPressure() const { return m_pressure; }

void Weather::setPressure(double pressure) { m_pressure = pressure; }

double Weather::getWindSpeed() const { return m_windSpeed; }

void Weather::setWindSpeed(double windSpeed) { m_windSpeed = windSpeed; }

int Weather::getHumidity() const { return m_humidity; }

void Weather::setHumidity(int humidity) { m_humidity = humidity; }

std::string Weather::toString() const {
	std::stringstream  ss;
	ss << "Date: " << m_date << '\n'
		<< "Description: " << m_description << '\n'
		<< "Temperature: " << m_temperature << '\n'
		<< "Humidity: " << m_humidity << '\n'
		<< "Pressure: " << m_pressure << '\n'
		<< "Wind speed: " << m_windSpeed << '\n';

	return ss.str();
}