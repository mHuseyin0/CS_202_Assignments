/*
* Title: Request Class
* Author: Muhammed Huseyin AYDIN
* ID: 22203683
* Section: 1
* Assignment: 2
* Description:
*/

#include "Request.h"
#include <string>

Request::Request(int id, int priority, int arrivalTime, int processTime){
        this->id = id;
        this->priority = priority;
        this->arrivalTime = arrivalTime;
        this->processTime = processTime;
        startTime = -1;
}

Request::Request(Request& copyRequest){
        id = copyRequest.id;
        priority = copyRequest.priority;
        arrivalTime = copyRequest.arrivalTime;
        processTime = copyRequest.processTime;
        startTime = copyRequest.startTime;
}

bool Request::operator< (const Request &otherRequest) const { return priority < otherRequest.priority; }
bool Request::operator> (const Request &otherRequest) const { return priority > otherRequest.priority; }
bool Request::operator<= (const Request &otherRequest) const { return priority <= otherRequest.priority; }
bool Request::operator>= (const Request &otherRequest) const { return priority >= otherRequest.priority; }
bool Request::operator== (const Request &otherRequest) const { return priority == otherRequest.priority; }


int Request::getID() { return id; }
int Request::getPriority(){ return priority; }
int Request::getArrivalTime(){ return arrivalTime; }
int Request::getProcessTime(){ return processTime; }
int Request::getStartTime(){ return startTime;}
void Request::setStartTime(int time){ if (startTime == -1) startTime = time; }
string Request::toString(){ return to_string(id); }

