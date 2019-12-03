#pragma once

// CMessageLog
#include <iostream>
#include <string>
#include <stdlib.h>

#ifdef IS_WINDOWS
	#include <sys/utime.h>
	#include <windows.h>
	#include <sstream>
	#include <iomanip>
	
	#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#elif IS_LINUX
	#include <sys/time.h>
	#include <unistd.h>
	#include <cstring>
	
	#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#else
	
#endif

#define FILENAME_AND_LINE  __FILENAME__ << ':' << __LINE__ << "/" << __FUNCTION__ << "/"
#define BUILD_DATE_AND_TIME  __DATE__ << ' ' << __TIME__
#define CURRENT_TIME getCurrentMSTimeString()

#define BUILD_LOG()					std::cout << blue << CURRENT_TIME << " [build]: " << BUILD_DATE_AND_TIME << white << '\n'
#define STATE_LOG(stuff)			std::cout << blue << CURRENT_TIME << " [state]: " << white << stuff << '\n'
#define INFO_LOG(stuff)				std::cout << blue << CURRENT_TIME << " [info]: " << FILENAME_AND_LINE << white << stuff << '\n'
#define WARNING_LOG(stuff)			std::cout << red  << CURRENT_TIME << " [warning]: " << FILENAME_AND_LINE << white << stuff << '\n'
#define ERROR_LOG(stuff)			std::cout << red  << CURRENT_TIME << " [error]: " << FILENAME_AND_LINE << white << stuff << '\n'
#define DEBUG_LOG(stuff)			std::cout << yellow << CURRENT_TIME << " [debug]: " << FILENAME_AND_LINE << white << stuff << '\n'
#define DEBUG_NDU(stuff)			std::cout << blackOnWhite << CURRENT_TIME << " [debug]: " << FILENAME_AND_LINE << white << stuff << '\n'
#define DEBUG_SPECTRUM_LOG(stuff)	std::cout << yellow << CURRENT_TIME << " [debugSpectrum]: " << FILENAME_AND_LINE << white << stuff << '\n'


std::string getCurrentMSTimeString()
{
#ifdef IS_LINUX
	static char timeString[255];
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	struct timeval  tv;
	gettimeofday(&tv, NULL);
	sprintf(timeString, "%02d:%02d:%02d:%03d", tm.tm_hour, tm.tm_min, tm.tm_sec, (int)(tv.tv_usec / 1000));
	return timeString;
#endif

#ifdef IS_WINDOWS
	std::stringstream timeStream;
	SYSTEMTIME st;
	GetLocalTime(&st);
	timeStream << std::setfill('0') << std::setw(2) << st.wHour << ':';
	timeStream << std::setfill('0') << std::setw(2) << st.wMinute << ':';
	timeStream << std::setfill('0') << std::setw(2) << st.wSecond << ':';
	timeStream << std::setfill('0') << std::setw(3) << st.wMilliseconds;
	return timeStream.str();
#endif

}


#ifdef IS_WINDOWS

/**
* @brief Functions to set console colors
" @note Copyleft Vincent Godin
*
*/
inline std::ostream& blue(std::ostream& s)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	return s;
}

inline std::ostream& red(std::ostream& s)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_INTENSITY);
	return s;
}

inline std::ostream& green(std::ostream& s)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	return s;
}

inline std::ostream& blackOnWhite(std::ostream& s)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	return s;
}

inline std::ostream& yellow(std::ostream& s)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	return s;
}



inline std::ostream& white(std::ostream& s)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	return s;
}

struct color {
	color(WORD attribute) :m_color(attribute) {};
	WORD m_color;
};

template <class _Elem, class _Traits>
std::basic_ostream<_Elem, _Traits>&
operator<<(std::basic_ostream<_Elem, _Traits>& i, color& c)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, c.m_color);
	return i;
}
#endif
