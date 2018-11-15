#ifndef VMCORE_ADVERTISING_HPP
#define VMCORE_ADVERTISING_HPP

#include "Queue.hpp"

namespace VMCore {
    class Advertising {
        private:    
           Queue queue;
        public:
            Advertising();
            ~Advertising();
            int getAdvertising();
            void addAdvertising(int);
            
    };  
}

#endif