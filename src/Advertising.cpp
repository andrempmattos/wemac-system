/**
 * \file Advertising class 
 * \brief It implements the advertising system
 * 
 * \author André Mattos <andrempmattos@gmail.com>
 * \author Daniel Baron <zdaniz22@gmail.com>
 * 
 * \date 11/06/2017
 * 
 * \defgroup VendingMachineCore
 */

#include "../include/Advertising.hpp"

using namespace VMCore;

Advertising::Advertising() {
	logAdvertising->setLevel(Log::noLog);
	logAdvertising->warn("(CONSTRUCTOR)Advertising");
	getAdvertisingDatabase();
}

Advertising::~Advertising() {
	logAdvertising->warn("(DESTRUCTOR)Advertising");
	delete logAdvertising;
}

std::string Advertising::getAdvertising(void) {
	return advertisingQueue.peekCyclic();
}

void Advertising::getAdvertisingDatabase(void) {
	using namespace std;
	string line;

  	ifstream advertising("src/../include/_AdvertisingDatabase.txt");
  	if (advertising.is_open()) {
  		logAdvertising->warn("(Database)Advertising database data");
		
		while(getline(advertising, line)) {
			advertisingQueue.enqueue(line);
			logAdvertising->debug("(Database)" + advertisingQueue.peek());			
		}
    	advertising.close();
  	}
  	else {
  		logAdvertising->error("(Database)Unable to open file");
  	}

}