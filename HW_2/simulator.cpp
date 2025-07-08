/*
* Title: Heaps
* Author: Muhammed Huseyin AYDIN
* ID: 22203683
* Section: 1
* Assignment: 2
* Description:
*/

#include "simulator.h"
#include "Request.h"
#include "RequestQueue.h"

#include <fstream>
#include <sstream>
#include <string>

Simulator::Simulator(string filename, int timeLimit){
        this->timeLimit = timeLimit;

        string newline;
        input = "";
        ifstream inputFile(filename);

        getline(inputFile, newline);
        requestCount = std::stoi(newline);

        while (inputFile) {
                getline(inputFile, newline);
                input += newline + "\n";
        }

        parseString = input;
}

void Simulator::solve(){
        int printerCount = 0;
        string output;
        double result;

        do {
                parseString = input;
                output = "";
                printerCount++;
                result = simulate(printerCount, output);

        } while (result > timeLimit);

        cout << output << result << " minutes\n";
}

double Simulator::simulate(int noOfPrinters, string &output){
        output = "Minimum number of printers required: " + to_string(noOfPrinters);
        output += "\n\nSimulation with " + to_string(noOfPrinters) + " printers:\n\n";
        int time = 1;
        double totalWaitingTime = 0;

        int index = 0;

        RequestQueue queue;
        Request *newRequest = nullptr;

        Printer *printerList = new Printer[noOfPrinters];
        while (index < requestCount || queue.getSize() > 0){

                // Delete requests when they end
                for (int i = 0; i < noOfPrinters; i++) {
                        if (!printerList[i].isAvailable &&
                                time - printerList[i].currentRequest.getStartTime() == printerList[i].currentRequest.getProcessTime()) {

                                printerList[i].isAvailable = true;
                        }
                }

                // Insert new processes when their time has come
                while(index < requestCount && (newRequest == nullptr || newRequest->getArrivalTime() == time)) {
                        if (newRequest == nullptr && index < requestCount) newRequest = initRequest(index);
                        if (newRequest != nullptr && newRequest->getArrivalTime() == time){
                                queue.insert(*newRequest);
                                delete newRequest;
                                newRequest = nullptr;
                                index++;
                        }
                }

                // Fill available printers
                for (int i = 0; i < noOfPrinters; i++) {
                        if (printerList[i].isAvailable && queue.getSize() != 0) {
                                printerList[i].currentRequest = queue.remove();

                                output += "Printer " + to_string(i) + " prints print request ";
                                output += to_string(printerList[i].currentRequest.getID());
                                output += " at minute " + to_string(time) + " (wait: ";
                                output += to_string(time - printerList[i].currentRequest.getArrivalTime()) + " mins)\n";

                                printerList[i].isAvailable = false;
                                printerList[i].currentRequest.setStartTime(time);
                                totalWaitingTime += time - printerList[i].currentRequest.getArrivalTime();
                        }
                }
                time++;
        };

        delete[] printerList;
        output += "\nAverage waiting time: ";
        return totalWaitingTime / requestCount;
}

Request* Simulator::initRequest(int index){
        int id, priority, arrivalTime, processTime;

        string temp;
        stringstream ss(parseString.substr(0, parseString.find('\n')));

        getline(ss, temp, ' ');
        id = stoi(temp);

        getline(ss, temp, ' ');
        priority = stoi(temp);

        getline(ss, temp, ' ');
        arrivalTime = stoi(temp);

        getline(ss, temp);
        processTime = stoi(temp);

        parseString.erase(0, parseString.find("\n") + 1);
        return new Request(id, priority, arrivalTime, processTime);
}

