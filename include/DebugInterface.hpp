#ifndef VMCORE_DEBUG_INTERFACE_HPP
#define VMCORE_DEBUG_INTERFACE_HPP

#include "Interface.hpp"
#include "ProjectIncludes.hpp"

namespace VMCore {
	class DebugInterface : public Interface {
		public:
			DebugInterface();
			~DebugInterface();

			void getSystemInput(SystemData* = nullptr);
			void setSystemOutput(SystemData* = nullptr);
			
			void getUserInput(UserData* = nullptr);
			void setUserOutput(UserData* = nullptr);

			void printAdvertising(AdvertisingData* = nullptr);
			void insertAdvertising(AdvertisingData* = nullptr);
	};
}

#endif