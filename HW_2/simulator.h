/*
* Title: Heaps
* Author: Muhammed Huseyin AYDIN
* ID: 22203683
* Section: 1
* Assignment: 2
* Description:
*/

#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "Request.h"
#include "RequestQueue.h"

#include <iostream>
using namespace std;

struct Printer{
        bool isAvailable = true;
        Request currentRequest;
};

class Simulator{
public:
        Simulator(string filename, int timeLimit);
        void solve();
private:
        int requestCount;
        int timeLimit;
        string input;
        string parseString;
        double simulate(int noOfPrinters, string &output);
        Request* initRequest(int index);
};

#endif
