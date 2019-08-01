#include "HTTPRequest.hpp"

HTTPRequest::HTTPRequest(const std::string& url,
						const std::map<std::string, std::string>& header,
						const std::map<std::string, std::string>& body,
						Method method,
						ContentType type) : 
	m_url(url), m_header(header),m_body(body), m_method(method), m_type(type) {}

const std::string& HTTPRequest::getUrl() const { return m_url; }

std::string HTTPRequest::getHeader() const { 
	std::string res;

	if (m_header.begin() != m_header.end()) {
		for (auto parameter : m_header) {
				res += parameter.first + '=' + parameter.second + '&';
		}
		res.pop_back();
	}
	
	return res;
}

std::string HTTPRequest::getBody() const { 
	std::string res;

	if (m_body.begin() != m_body.end()) {
		for (auto parameter : m_body) {
			res += parameter.first + '=' + parameter.second + '&';
		}
		res.pop_back();
	}

	return res;
}

Method HTTPRequest::getMehod() const { return m_method; }

ContentType HTTPRequest::getContentType() const { return m_type; }

size_t  HTTPRequest::writeCallback(void* content, size_t size, size_t nmemb, void* userData) {
	static_cast<std::string*>(userData)->append(static_cast<char*>(content), size * nmemb);
	return size * nmemb;
}

HTTPResponse* HTTPRequest::execute() 
{ 
	CURL* curl;
	CURLcode res;
	long code;
	std::string readBuffer;

	curl = curl_easy_init();
	if (curl) {
		std::string body = getBody();
		//char* encodedBody = curl_easy_escape(curl, body.c_str(), body.length());

		curl_easy_setopt(curl, CURLOPT_URL, (m_url + body).c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
		curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

		res = curl_easy_perform(curl);
		curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &code);
		curl_easy_cleanup(curl);

		return new HTTPResponse(code, readBuffer);
	}

	return nullptr;
}
