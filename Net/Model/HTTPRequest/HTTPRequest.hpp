#pragma once
#include <string>
#include <map>

#define CURL_STATICLIB
#include "curl/curl.h"

#include "../../../Enums/CPEnums.h"
#include "../HTTPResponse/HTTPResponse.hpp"

class HTTPRequest
{
public:
	HTTPRequest(const std::string& url,
				const std::map<std::string, std::string>& header,
				const std::map<std::string, std::string>& body,
				Method method,
				ContentType type);
	~HTTPRequest() = default;

	const std::string& getUrl() const;
	std::string getHeader() const;
	std::string getBody() const;
	Method getMehod() const;
	ContentType getContentType() const;

	HTTPResponse* execute();

private:
	static size_t writeCallback(void* content, size_t size, size_t nmemb, void* userData);

	std::string m_url;
	std::map<std::string, std::string> m_header;
	std::map<std::string, std::string> m_body;
	Method m_method;
	ContentType m_type;
};

