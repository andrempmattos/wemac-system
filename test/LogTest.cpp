#include "../src/Log.hpp"
#include <iostream>

int main() {

	using namespace VMCore;

	int stopCondition;

	while(1) { 
		Log log;

		std::cout << std::endl << "Info level" << std::endl;
		log.setLevel(Log::levelInfo);
		log.warn("Warn here!");
		log.error("Error here!");
		log.info("Info here!");

		std::cout << std::endl << "Warning level" << std::endl;
		log.setLevel(Log::levelWarning);
		log.warn("Warn here!");
		log.error("Error here!");
		log.info("Info here!");

		std::cout << std::endl << "Error level" << std::endl;
		log.setLevel(Log::levelError);
		log.warn("Warn here!");
		log.error("Error here!");
		log.info("Info here!");
		
		std::cin >> stopCondition;
	}
	return 0;
}


