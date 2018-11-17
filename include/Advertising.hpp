#ifndef VMCORE_ADVERTISING_HPP
#define VMCORE_ADVERTISING_HPP

#include "Queue.hpp"
#include "Log.hpp"
#include "ProjectIncludes.hpp"

namespace VMCore {
    class Advertising {      
        private:
            Queue advertisingQueue;
            Log* logAdvertising = new Log("[ADVERTISING]"); 
        public:
            Advertising();
            ~Advertising();
            std::string getAdvertising(void);
            void getAdvertisingDatabase(void);
    };  
}

#endif