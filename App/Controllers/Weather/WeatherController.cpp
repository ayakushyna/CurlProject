#include "WeatherController.hpp"

WeatherController::WeatherController() {}

WeatherController::~WeatherController() {
	for (IWeatherObserver* observer : m_observers) {
		delete observer;
		observer = nullptr;
	}
	m_observers.clear();
}

Weather* WeatherController::createWeather(const std::string& date
										, const std::string& description
										, double temp
										, double pressure
										, double windSpeed
										, int humidity)
{
	Weather* weather = new Weather(date, description, temp, pressure, windSpeed, humidity);
	sendEvent(weather, Create, WP_Weather, "", "");
	return weather;
}

bool WeatherController::deleteWeather(Weather* weather) {
	if (weather != nullptr) {
		sendEvent(weather, Delete, WP_Weather, "", "");
		delete weather;
		weather = nullptr;
		return true;
	}
	return false;
}

const std::string& WeatherController::readDate(Weather* weather) const {
	if (weather != nullptr) {
		return weather->getDate();
	}
	return "";
}

Weather* WeatherController::updateDate(Weather* weather, const std::string& date) {
	if (weather != nullptr) {
		const std::string& oldDate = weather->getDate();
		weather->setDate(date);
		sendEvent(weather, Update, WP_Date, oldDate, date);
	}
	return weather;
}

const std::string& WeatherController::readDescription(Weather* weather) const {
	if (weather != nullptr) {
		return weather->getDescription();
	}
	return "";
}

Weather* WeatherController::updateDescription(Weather* weather, const std::string& description) {
	if (weather != nullptr) {
		const std::string& oldDescription = weather->getDescription();
		weather->setDescription(description);
		sendEvent(weather, Update, WP_Description, oldDescription, description);
	}
	return weather;
}

double WeatherController::readTemperature(Weather* weather) const {
	if (weather != nullptr) {
		return weather->getTemperature();
	}
	return 0;
}

Weather* WeatherController::updateTemperature(Weather* weather, double temperature) {
	if (weather != nullptr) {
		double oldTemperature = weather->getTemperature();
		weather->setTemperature(temperature);
		sendEvent(weather, Update, WP_Temperature, std::to_string(oldTemperature), std::to_string(temperature));
	}
	return weather;
}

double WeatherController::readPressure(Weather* weather) const {
	if (weather != nullptr) {
		return weather->getPressure();
	}
	return 0;
}

Weather* WeatherController::updatePressure(Weather* weather, double pressure) {
	if (weather != nullptr) {
		double oldPressure = weather->getPressure();
		weather->setPressure(pressure);
		sendEvent(weather, Update, WP_Temperature, std::to_string(oldPressure), std::to_string(pressure));
	}
	return weather;
}

double WeatherController::readWindSpeed(Weather* weather) const {
	if (weather != nullptr) {
		return weather->getWindSpeed();
	}
	return 0;
}

Weather* WeatherController::updateWindSpeed(Weather* weather, double windSpeed) {
	if (weather != nullptr) {
		double oldWindSpeed = weather->getWindSpeed();
		weather->setWindSpeed(windSpeed);
		sendEvent(weather, Update, WP_WindSpeed, std::to_string(oldWindSpeed), std::to_string(windSpeed));
	}
	return weather;
}

int WeatherController::readHumidity(Weather* weather) const {
	if (weather != nullptr) {
		return weather->getHumidity();
	}
	return 0;
}

Weather* WeatherController::updateHumidity(Weather* weather, int visibility) {
	if (weather != nullptr) {
		int oldVisibility = weather->getHumidity();
		weather->setHumidity(visibility);
		sendEvent(weather, Update, WP_Temperature, std::to_string(oldVisibility), std::to_string(visibility));
	}
	return weather;
}

void WeatherController::addObserver(IWeatherObserver* observer) {
	if (observer != nullptr) {
		m_observers.insert(observer);
	}
}

void WeatherController::removeObserver(IWeatherObserver* observer) {
	if (observer != nullptr) {
		m_observers.erase(observer);
		delete observer;
		observer = nullptr;
	}
}

void WeatherController::sendEvent(Weather* weather
								, Action action
								, WeatherProperty property
								, std::string oldValue
								, std::string newValue) 
{
	for (IWeatherObserver* observer : m_observers) {
		observer->onWeatherChanged(weather, action, property, oldValue, newValue);
	}
}

Weather* WeatherController::createFromJson(const json& object) {
	if (object.contains("dt_txt") && object.contains("main") ) {
		return createWeather( JsonType::getString(object,"dt_txt")
							, JsonType::getString(JsonType::getArray(object, "weather")[0], "description")
							, JsonType::getDouble(JsonType::getObject(object, "main"),"temp")
							, JsonType::getDouble(JsonType::getObject(object, "main"),"pressure")
							, JsonType::getDouble(JsonType::getObject(object, "wind"), "speed")
							, JsonType::getInt(JsonType::getObject(object, "main"),"humidity"));
	}
	return nullptr;
}
