#include "mbed.h"

#define START_PULSE       40ms
#define WAIT_PERIOD       817ms

DigitalOut START_AB(PA_0);
DigitalOut led(LED1);  // オンボードLED（NUCLEO-F303K8ならPA_5）

int main() {
    START_AB = 0;
    led = 0;

    while (true) {
        // 0.5秒待機
        ThisThread::sleep_for(WAIT_PERIOD);

        // START_AB を1にしてLEDもON
        START_AB = 1;
        led = 1;

        // パルス
        ThisThread::sleep_for(START_PULSE);

        // START_AB を0にしてLEDもOFF
        START_AB = 0;
        led = 0;
    }
}