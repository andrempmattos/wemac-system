#ifndef VMCORE_DEBUG_INTERFACE_HPP
#define VMCORE_DEBUG_INTERFACE_HPP

#include "Interface.hpp"
#include "VendingMachine.hpp"
#include "Product.hpp"
#include "ProjectIncludes.hpp"

extern void* pMachineCore;

namespace VMCore {
	class DebugInterface : public Interface {
		private:
			int m_productSelected;

		public:
			DebugInterface();
			~DebugInterface();

			void getSystemInput(SystemData* = nullptr);
			void setSystemOutput(SystemData* = nullptr);
			
			void getUserInput(UserData* = nullptr);
			void setUserOutput(UserData* = nullptr);
			void decodeUserInput(UserData* = nullptr);

			void printAdvertising(AdvertisingData* = nullptr);
			void insertAdvertising(AdvertisingData* = nullptr);
	};
}

#endif