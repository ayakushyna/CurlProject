#include "JsonType.hpp"

JsonType::JsonType() {}


 json JsonType::getObject(const json& j, const std::string& name)  {
	auto it = j.find(name);

	if (it != j.end() && it.value().is_object()) {
		return it.value();
	}
}

int JsonType::getInt(const json& j, const std::string& name)  {
	auto it = j.find(name);

	if (it != j.end() && it.value().is_number()) {
		return it.value();
	}
}

double JsonType::getDouble(const json& j, const std::string& name)  {
	auto it = j.find(name);

	if (it != j.end() && it.value().is_number()) {
		return it.value();
	}
}

std::string JsonType::getString(const json& j, const std::string& name)  {
	auto it = j.find(name);

	if (it != j.end() && it.value().is_string()) {
		return it.value();
	}
}

json JsonType::getArray(const json& j, const std::string& name)  {
	auto it = j.find(name);

	if (it != j.end() && it.value().is_array()) {
		return it.value();
	}
}

json JsonType::parseToJson(const std::string& str) {
	return json::parse(str);
}
