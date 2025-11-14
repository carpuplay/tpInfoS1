/* File: tp1-ex1.cpp
 * Author: Philippe Latu
 * Source: https://github.com/platu/libsensehat-cpp
 *
 * Student lab template source file
 *
 * This program waits for the joystick button to be pressed
 */

#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

#include <sensehat.h>

using namespace std;
using namespace std::this_thread;  // sleep_for, sleep_until
using namespace std::chrono;       // system_clock, seconds, milliseconds

int main() {
    // Declare your variables below !
    const rgb_pixel_t P = {.color = {238, 128, 180}};      // pink
    const rgb_pixel_t W = {.color = {255, 255, 255}};  // White
    const rgb_pixel_t M = {.color = {133, 98, 175}};    // Purple


    rgb_pixels_t question_mark_RedOnWhite = {
    .array = {{W, W, W, W, W, W, W, W},
        {W, P, P, P, P, P, P, W},
        {W, P, M, P, P, M, P, W},
        {W, P, P, P, P, P, P, W},
        {W, P, P, W, W, P, P, W},
        {W, P, M, P, P, M, P, W},
        {W, P, P, M, M, P, P, W},
        {W, W, W, W, W, W, W, W}}};              

    int count;
    // End of variables declarations

    if (senseInit()) {
        cout << "Sense Hat initialization Ok." << endl;
        // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        // Insert your code below !

        count = 1;

        do {
            senseSetRGBpixels(question_mark_RedOnWhite);

            sleep_for(seconds(1));

            question_mark_RedOnWhite = senseFlip_v(false);

            count = count + 1;
        } while (count < 5);

        cout << "Press joystick button to quit." << endl;
        senseWaitForJoystickEnter();

        // Insert your code above !
        // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        senseShutdown();
        cout << "Sense Hat shut down." << endl;
    }

    return EXIT_SUCCESS;
}
