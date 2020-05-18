#include "YUGException.h"
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

const std::string& YuGException::GetFile() const noexcept
{
	return file;
}

std::string YuGException::GetOriginString() const noexcept
{
	std::ostringstream oss;
	oss << "[File] " << file << std::endl
		<< "[Line] " << line;
	return oss.str();
}
