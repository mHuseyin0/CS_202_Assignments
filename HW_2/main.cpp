/*
* Title: Heaps
* Author: Muhammed Huseyin AYDIN
* ID: 22203683
* Section: 1
* Assignment: 2
* Description:
*/

#include "simulator.h"

using namespace std;

int main (int argc, char *argv[]) {

        string filename = argv[1];
        int averageWaitingTime = stoi(argv[2]);

        Simulator s(filename, averageWaitingTime);
        s.solve();

        return 0;
}
