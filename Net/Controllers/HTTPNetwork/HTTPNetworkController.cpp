#include "HTTPNetworkController.hpp"

HTTPNetworkController::HTTPNetworkController() {}

HTTPNetworkController::~HTTPNetworkController() {
	for (auto it = m_history.begin(); it != m_history.end(); ++it) {
		HTTPRequest* request = it->first;
		delete it->second;
		it->second = nullptr;
		delete request;
		request = nullptr;
	}
	m_history.clear();
}

HTTPResponse* HTTPNetworkController::sendRequest(const std::string& url,
												const std::map<std::string, std::string>& header,
												const std::map<std::string, std::string>& body,
												Method method,
												ContentType type) 
{
	HTTPRequest* request = new HTTPRequest(url, header, body, method, type);
	HTTPResponse* response = request->execute();
	m_history.insert({ request, response });
	return response;
}