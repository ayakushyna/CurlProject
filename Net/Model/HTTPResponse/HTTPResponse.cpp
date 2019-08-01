#include "HTTPResponse.hpp"

HTTPResponse::HTTPResponse(int code, const std::string& body): m_code(code), m_body(body) {}

int HTTPResponse::getCode() const { return m_code; }

const std::string HTTPResponse::getBody() const { return m_body; }