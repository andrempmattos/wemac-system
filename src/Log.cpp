/**
 * \file Log system class 
 * \brief It implements an effective log for debug sections
 * 
 * \author André Mattos <andrempmattos@gmail.com>
 * \author Daniel Baron <zdaniz22@gmail.com>
 * 
 * \date 10/28/2017
 * 
 * \defgroup VendingMachineCore
 */

#include "../include/Log.hpp"

using namespace VMCore;
using namespace std;

void Log::setLevel(Level t_level) {
	m_logLevel = t_level;
	logFile.open(logFileLocation);
	if (logFile.is_open()) {
		logFile << ("This file contains the current log section! \n \n");
		logFile.close();
	}
	else cout << "[Log][ERROR]Unable to open file" << endl;

}

void Log::error(string t_message) {
	logFile.open(logFileLocation, ios_base::app);
	if (logFile.is_open()) {
		logFile << (m_scope + "[ERROR]:" + t_message + "\n");
		logFile.close();
	}
	else cout << "[Log][ERROR]Unable to open file" << endl;

	if (m_logLevel >= levelError) {
		cout << m_scope << "[ERROR]:" << t_message << endl; 
	}
}

void Log::warn(string t_message) {
	logFile.open(logFileLocation, ios_base::app);
	if (logFile.is_open()) {
		logFile << (m_scope + "[WARN]:" + t_message + "\n");
		logFile.close();
	}
	else cout << "[Log][ERROR]Unable to open file" << endl;

	if (m_logLevel >= levelWarning) {
		cout << m_scope << "[WARNING]:" << t_message << endl; 
	}
}

void Log::info(string t_message) {
	logFile.open(logFileLocation, ios_base::app);
	if (logFile.is_open()) {
		logFile << (m_scope + "[INFO]:" + t_message + "\n");
		logFile.close();
	}
	else cout << "[Log][ERROR]Unable to open file" << endl;

	if (m_logLevel >= levelInfo) {
		cout << m_scope << "[INFO]:" << t_message << endl; 
	}
}

void Log::debug(string t_message) {
	logFile.open(logFileLocation, ios_base::app);
	if (logFile.is_open()) {
		logFile << (m_scope + "[DEBUG]:" + t_message + "\n");
		logFile.close();
	}
	else cout << "[Log][ERROR]Unable to open file" << endl;

	if (m_logLevel >= levelDebug) {
		cout << m_scope << "[DEBUG]:" << t_message << endl; 
	}
}