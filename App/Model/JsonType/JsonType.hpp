#pragma once
#include <string>
#include "json.hpp"

using json = nlohmann::json;

class JsonType
{
public:
	JsonType();
	~JsonType() = default;

	static json getObject(const json& j, const std::string& name);
	static int getInt(const json& j, const std::string& name);
	static double getDouble(const json& j, const std::string& name);
	static std::string getString(const json& j, const std::string& name);
	static json getArray(const json& j, const std::string& name) ;
	static json parseToJson(const std::string& str);
};

