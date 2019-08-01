#include "Menu.hpp"

Menu::Menu(): m_option(0), m_latitude(0), m_longitude(0) {}

int Menu::getOption() const { return m_option; }

void Menu::setOption(int option) { m_option = option; }

const std::string& Menu::getName() const { return m_name; }

void Menu::setName(const std::string& name) { m_name = name; }

const std::string& Menu::getDate() const { return m_date; }

void  Menu::setDate(const std::string& date) { m_date = date; }

double Menu::getLatitude() const { return m_latitude; }

void Menu::setLatitude(double latitude) { m_latitude = latitude; }

double Menu::getLongitude() const { return m_longitude; }

void Menu::setLongitude(double longitude) { m_longitude = longitude; }