#include "CityController.hpp"

CityController::CityController(){}

CityController::~CityController() {
	for (City* city : m_cities) {
		sendEvent(city, Delete, CP_City, "", "");
		delete city;
		city = nullptr;
	}
	m_cities.clear();

	for (ICityObserver* observer : m_observers) {
		delete observer;
		observer = nullptr;
	}
	m_observers.clear();
}

City* CityController::getCity(const std::string& name) const {
	for (City* city: m_cities) {
		if (city->getName() == name) {
			return city;
		}
	}
	return nullptr;
}

City* CityController::getCity(double lat, double lon) const {
	for (City* city : m_cities) {
		if (city->getPosition()->getLatitude() == lat && city->getPosition()->getLongitude() == lon) {
			return city;
		}
	}
	return nullptr;
}

void CityController::loadCities(const json& object) {
	if (!object.empty() && object.is_array()) {
		for (auto it = object.begin(); it != object.end(); ++it) {
			createFromJson(*it);
		}
	}
	
}

void CityController::loadForecasts(City* city, const json& object) {
	if (!object.empty() && object.is_array()) {
		for (auto it = object.begin(); it != object.end(); ++it) {
			addForecast(city, App::getWeatherController()->createFromJson(*it));
		}
	}

}

City* CityController::createCity(const std::string& name, GeoPoint* position) {
	City* city = new City(name, position);
	sendEvent(city, Create, CP_City, "", "");

	m_cities.insert(city);
	return city;
}

bool CityController::deleteCity(City* city) {
	if (city != nullptr) {
		auto it = m_cities.find(city);

		if (city == *it) {
			sendEvent(city, Delete, CP_City, "", "");
			delete *it;
			m_cities.erase(it);

			city = nullptr;
			return true;
		}
	}
	return false;
}

const std::string& CityController::readName(City* city) const {
	if (city != nullptr) {
		return city->getName();
	}
	return "";
}

City* CityController::updateName(City* city, const std::string& name) {
	if (city != nullptr) {
		const std::string& oldName = city->getName();
		city->setName(name);
		sendEvent(city, Update, CP_Name, oldName, name);
	}
	return city;
}

GeoPoint* CityController::readPosition(City* city) const {
	if (city != nullptr) {
		return city->getPosition();
	}
	return nullptr;
}

City* CityController::updatePosition(City* city, GeoPoint* position) {
	if (city != nullptr) {
		GeoPoint* oldPosition = city->getPosition();
		city->setPosition(position);
		sendEvent(city, Update, CP_Position, oldPosition->toString(), position->toString());
	}
	return city;
}

std::vector<Weather*> CityController::readForecasts(City* city, const std::string& date) const {
	std::vector<Weather*> datedForecasts;

	if (city != nullptr) {
		auto forecasts = city->getForecasts();

		for (auto it = forecasts.begin(); it != forecasts.end(); ++it) {
			if (it->first.find(date) != std::string::npos) {
				datedForecasts.push_back(it->second);
			}
		}
	}
	return datedForecasts;
}

City* CityController::addForecast(City* city, Weather* weather) {
	if (city != nullptr && weather != nullptr) {
		city->addForecast(weather);
	}
	return city;
}

City* CityController::removeForecast(City* city, const std::string& date) {
	if (city != nullptr) {
		city->removeForecast(date);
	}
	return city;
}

void CityController::addObserver(ICityObserver* observer) {
	if (observer != nullptr) {
		m_observers.insert(observer);
	}
}

void CityController::removeObserver(ICityObserver* observer) {
	if (observer != nullptr) {
		m_observers.erase(observer);
		delete observer;
		observer = nullptr;
	}
}

void CityController::sendEvent(City* city
							, Action action
							, CityProperty property
							, std::string oldValue
							, std::string newValue) 
{
	for (ICityObserver* observer : m_observers) {
		observer->onCityChanged(city, action, property, oldValue, newValue);
	}
}

City* CityController::createFromJson(const json& object) {
	if (object.contains("name") && object.contains("coord") ) {
		return createCity(JsonType::getString(object,"name")
			, App::getGeoPointController()->createFromJson(JsonType::getObject(object,"coord")));
	}
	return nullptr;
}