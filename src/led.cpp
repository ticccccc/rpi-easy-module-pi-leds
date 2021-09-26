#include <iostream>
#include <vector>

#include "wiringPi.h"

using namespace std;

int main(int, char**) {
    cout << "Raspberry Pi blink\n" << endl;

    vector<int> vs(3);
    vector<int> leds={0, 2, 3, 21};

    wiringPiSetup () ;
    for (int i : leds) {
        pinMode (i, OUTPUT);
    }

    // 只连续点亮3轮
    for (int i : vs){
        // 每一轮对多有的led点亮一次
        for (int l : leds) {
            digitalWrite (l, HIGH) ;	// On
            delay (1000) ;		// mS
            digitalWrite (l, LOW) ;	// Off
            delay (1000) ;
        }
    }
    return 0 ;
}
