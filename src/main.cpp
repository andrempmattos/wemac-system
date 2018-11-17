/**
 * \file Main file 
 * \brief It instantiates the vending machine system and the platform-oriented interfaces 
 * 
 * \author André Mattos <andrempmattos@gmail.com>
 * \author Daniel Baron <zdaniz22@gmail.com>
 * 
 * \date 10/28/2017
 * 
 * \defgroup VendingMachineCore
 */

#include "../include/VendingMachine.hpp"
#include "../include/DebugInterface.hpp"
#include "../include/ProjectIncludes.hpp"

using namespace std::chrono;
using namespace VMCore;

//Required processing period
const milliseconds intervalPeriodMillis{100};

//Initialize the chrono timepoints 
system_clock::time_point currentStartTime{system_clock::now()};
system_clock::time_point nextStartTime{currentStartTime};

//Application objects
Interface* interfaceOverride = new DebugInterface();
VendingMachine* machineCore = new VendingMachine(interfaceOverride);

//VMThread loop counter
int timerCounter;

//Generic pointer for extern usage
void* pMachineCore = machineCore;

int main() {
	std::atomic<bool> interrupted;
	UserData* user = new UserData();

	while(true) {
		interrupted.store(false);

		// create a new thread that does stuff in the background
		std::thread VMThread([&]() {
			while(!interrupted) {
				//Get our current "wakeup" time
				currentStartTime = system_clock::now();

				//Determine the point in time at which the system wakeup for the next pass through the loop.
				nextStartTime = currentStartTime + intervalPeriodMillis;
				
				//Timer count for advertising switch
				++timerCounter;
				if (timerCounter % 100 == 0) {
					machineCore->timerEvent();
					timerCounter = 0;
				}

				//User input decoder
				interfaceOverride->decodeUserInput(user);

				//Sleep until the next period start time
				std::this_thread::sleep_until(nextStartTime);
			}
		});

	//User inputs handler
	interfaceOverride->getUserInput(user);

	//When input is complete, interrupt thread and wait for it to finish
	interrupted.store(true);
	VMThread.join();

	}

	delete user;
	delete machineCore;
	delete interfaceOverride;

}