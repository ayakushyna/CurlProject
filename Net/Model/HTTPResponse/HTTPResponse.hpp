#pragma once
//#include "../HTTPRequest/HTTPRequest.hpp"
#include <string>


class HTTPResponse
{
public:
	HTTPResponse(int code , const std::string& body);
	~HTTPResponse() = default;

	int getCode() const;
	const std::string getBody() const;

private:
	//HTTPRequest& m_request;
	int m_code;
	std::string m_body;
};

