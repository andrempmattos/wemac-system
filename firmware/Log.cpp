#include "Log.hpp"

using namespace VMCore;

void Log::setLevel(Level t_level) {
	m_logLevel = t_level;
}

void Log::error(std::string t_message) {
	if (m_logLevel >= levelError) {
		std::cout << "[ERROR]:" << t_message << std::endl; 
	}
}

void Log::warn(std::string t_message) {
	if (m_logLevel >= levelWarning) {
		std::cout << "[WARNING]:" << t_message << std::endl; 
	}
}

void Log::info(std::string t_message) {
	if (m_logLevel >= levelInfo) {
		std::cout << "[INFO]:" << t_message << std::endl; 
	}
}