//TODO: Update and add test header comment!

#include "../src/Queue.hpp"
#include "../src/Advertising.hpp"


#include <iostream>

int main() {

    using namespace std;
    using namespace VMCore;

    Queue queue_A;
    Advertising advertising;
    int output;

    queue_A.push(5);
    cout << "5" << endl;
    queue_A.push(10);
    cout << "10" << endl;
    queue_A.push(22);
    cout << "22" << endl;

    cout << queue_A.pop() << endl;
    cout << queue_A.pop() << endl;
    cout << queue_A.pop() << endl;

    queue_A.push(5);
    cout << "5" << endl;
    queue_A.push(10);
    cout << "10" << endl;
    queue_A.push(22);
    cout << "22" << endl;

    for(int i=0;i<4; i++) { 
        cout << queue_A.cPop() << endl;
        cout << queue_A.cPop() << endl;
        cout << queue_A.cPop() << endl;
    }

    advertising.addAdvertising(4);
    advertising.addAdvertising(3);
    advertising.addAdvertising(33);
    advertising.addAdvertising(6);
    advertising.addAdvertising(11);
    advertising.addAdvertising(20);

    for(int i=0;i<12; i++) { 
        std::cout << advertising.getAdvertising() << std::endl; 
    }

    advertising.removeAdvertising(33);

    for(int i=0;i<12; i++) { 
        std::cout << advertising.getAdvertising() << std::endl; 
    }

    advertising.removeAdvertising(11);

    cin >> output;

    return 0;
}

