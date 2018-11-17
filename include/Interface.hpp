#ifndef VMCORE_INTERFACE_HPP
#define VMCORE_INTERFACE_HPP

#include "ProjectIncludes.hpp"

namespace VMCore {
    struct SystemData {
    	std::string systemInput = "";
    	std::string systemOutput = "";     
    };

    struct UserData {
    	std::string userInput = "";
    	std::string userOutput = "";  
    };

    struct AdvertisingData {
    	std::string advertisingInput = "";
    	std::string advertisingOutput = "";  
    };

	class Interface {
		public:
			Interface();
			virtual ~Interface() {}

		public:
			virtual void getSystemInput(SystemData* = nullptr) = 0;
			virtual void setSystemOutput(SystemData* = nullptr) = 0;
			
			virtual void getUserInput(UserData* = nullptr) = 0;
			virtual void setUserOutput(UserData* = nullptr) = 0;
			virtual void decodeUserInput(UserData* = nullptr) = 0;

			virtual void printAdvertising(AdvertisingData* = nullptr) = 0;
			virtual void insertAdvertising(AdvertisingData* = nullptr) = 0;

	};
}

#endif