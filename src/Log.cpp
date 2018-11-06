#include "Log.hpp"

using namespace VMCore;

void Log::setLevel(Level t_level) {
	m_logLevel = t_level;
}

void Log::setScope(std::string t_scope) {
	m_scope = t_scope;
}

void Log::error(std::string t_message) {
	if (m_logLevel >= levelError) {
		std::cout << m_scope << "[ERROR]:" << t_message << std::endl; 
	}
}

void Log::warn(std::string t_message) {
	if (m_logLevel >= levelWarning) {
		std::cout << m_scope << "[WARNING]:" << t_message << std::endl; 
	}
}

void Log::info(std::string t_message) {
	if (m_logLevel >= levelInfo) {
		std::cout << m_scope << "[INFO]:" << t_message << std::endl; 
	}
}

void Log::debug(std::string t_message) {
	if (m_logLevel >= levelDebug) {
		std::cout << m_scope << "[DEBUG]:" << t_message << std::endl; 
	}
}
