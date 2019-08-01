#pragma once
#include <string>
class Menu
{
public:
	Menu();
	~Menu() = default;

	int getOption() const;
	void setOption(int option);

	const std::string& getName() const;
	void setName(const std::string& name);

	const std::string& getDate() const;
	void setDate(const std::string& name);

	double getLatitude() const;
	void setLatitude(double latitude);

	double getLongitude() const;
	void setLongitude(double longitude);

private:
	int m_option;
	std::string m_name, m_date;
	double m_latitude, m_longitude;
};

