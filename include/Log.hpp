#ifndef VMCORE_LOG_HPP
#define VMCORE_LOG_HPP

#include "ProjectIncludes.hpp"

namespace VMCore {
	class Log {
		public:
			enum Level {
				noLog = 0, levelError, levelWarning, levelInfo, levelDebug
			};
		private:
			Level m_logLevel = levelInfo;
			std::string m_scope;

			std::ofstream logFile;
			std::string logFileLocation = "src/../include/LogSection.txt";

		public:
			Log(std::string t_scope) : m_scope(t_scope) {}
			void setLevel(Level t_level);
			void error(std::string t_message);
			void warn(std::string t_message);
			void info(std::string t_message);
			void debug(std::string t_message);
	};	
}

#endif