//TODO: Update and add test header comment!

#include "../src/Queue.hpp"

#include <iostream>

int main() {

    using namespace std;
    using namespace VMCore;

    Queue queue_A;
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

    for(int i=0;i<10; i++) { 
        cout << queue_A.circularPop() << endl;
        cout << queue_A.circularPop() << endl;
        cout << queue_A.circularPop() << endl;
    }


    cin >> output;

    return 0;
}

