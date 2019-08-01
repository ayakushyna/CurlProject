#pragma once
#include <string>
#include <map>
#include "../../../Enums/CPEnums.h"
#include "../../Model/HTTPResponse/HTTPResponse.hpp"
#include "../../Model/HTTPRequest/HTTPRequest.hpp"

class HTTPNetworkController
{
public:
	HTTPNetworkController();
	~HTTPNetworkController();

	HTTPResponse* sendRequest(
		const std::string& url,
		const std::map<std::string, std::string>& header,
		const std::map<std::string, std::string>& body,
		Method method,
		ContentType type);

private:
	std::map< HTTPRequest*, HTTPResponse*> m_history;
};

