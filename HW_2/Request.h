/*
* Title: Request Class
* Author: Muhammed Huseyin AYDIN
* ID: 22203683
* Section: 1
* Assignment: 2
* Description:
*/

#ifndef REQUEST_H
#define REQUEST_H

#include <iostream>
using namespace std;

class Request{
public:
        Request(int id = 0, int priority = 0, int arrivalTime = 0, int processTime = 0);
        Request(Request& copyRequest);
        bool operator< (const Request &otherRequest) const;
        bool operator> (const Request &otherRequest) const;
        bool operator<= (const Request &otherRequest) const;
        bool operator>= (const Request &otherRequest) const;
        bool operator== (const Request &otherRequest) const;

        int getID();
        int getPriority();
        int getArrivalTime();
        int getProcessTime();
        int getStartTime();
        void setStartTime(int time);
        string toString();
private:
        int id;
        int priority;
        int arrivalTime;
        int processTime;
        int startTime;
};

#endif
