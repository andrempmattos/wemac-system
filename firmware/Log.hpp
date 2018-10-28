#ifndef VMCORE_LOG_HPP
#define VMCORE_LOG_HPP

#include <string>
#include <iostream>

namespace VMCore {
	class Log {
		public:
			enum Level {
				levelError = 0, levelWarning, levelInfo
			};
		private:
			Level m_logLevel = levelInfo;
		public:
			void setLevel(Level t_level);
			void error(std::string t_message);
			void warn(std::string t_message);
			void info(std::string t_message);
	};	
}

#endif