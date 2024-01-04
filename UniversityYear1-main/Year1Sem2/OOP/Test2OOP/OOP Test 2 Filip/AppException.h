#pragma once
#include <exception>
class AppException : public std::exception
{
	using exception::exception;
};