#ifndef VMCORE_LOG_HPP
#define VMCORE_LOG_HPP

#include "ProjectIncludes.hpp"

namespace VMCore {
	class Log {
		public:
			enum Level {
				levelError = 0, levelWarning, levelInfo, levelDebug
			};
		private:
			Level m_logLevel = levelInfo;
			std::string m_scope;
		public:
			void setLevel(Level t_level);
			void setScope(std::string t_scope);
			void error(std::string t_message);
			void warn(std::string t_message);
			void info(std::string t_message);
			void debug(std::string t_message);
	};	
}

#endif