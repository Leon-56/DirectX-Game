#include "YuGException.h"
#include <sstream>

YuGException::YuGException(int line, const char* file) noexcept
	:
	line(line),
	file(file)
{}

const char* YuGException::what() const noexcept
{
	std::ostringstream oss;
	oss << GetType() << std::endl
		<< GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const char* YuGException::GetType() const noexcept
{
	return "YuG Exception";
}