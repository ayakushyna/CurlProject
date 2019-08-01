#include "City.hpp"

City::City(const std::string& name, GeoPoint* position): m_name(name), m_position(position) {}

City::~City() {
	delete m_position;
	m_position = nullptr;

	for (auto it = m_forecasts.begin(); it != m_forecasts.end(); ++it) {
		delete it->second;
		it->second = nullptr;
	}
	m_forecasts.clear();
}

const std::string& City::getName() const { return m_name; }

void City::setName(const std::string& name) { m_name = name; }

GeoPoint* City::getPosition() const { return m_position; }

void City::setPosition(GeoPoint* position) { m_position = position; }

const std::map<std::string, Weather*>& City::getForecasts() const { return m_forecasts; }

void City::addForecast(Weather* weather) {
	m_forecasts.insert({ weather->getDate(), weather });
}

void City::removeForecast(const std::string& date) {
	auto it = m_forecasts.find(date);
	
	if (it != m_forecasts.end()) {
		delete it->second;
		it->second = nullptr;
		m_forecasts.erase(it);
	}
}

std::string City::toString() const {
	std::stringstream  ss;
	ss << "Name: " << m_name << '\n'
		<< "Position: " << m_position->toString();

	return ss.str();
}