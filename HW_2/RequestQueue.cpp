/*
* Title: Priotiy Queue for Request
* Author: Muhammed Huseyin AYDIN
* ID: 22203683
* Section: 1
* Assignment: 2
* Description:
*/

#include "RequestQueue.h"
#include "Request.h"
#include <cmath>
#include <iostream>
using namespace std;

RequestQueue::RequestQueue(){
        queue = nullptr;
        size = 0;
}

RequestQueue::RequestQueue(const RequestQueue &copyQueue){
        size = copyQueue.size;

        if (size == 0) {
                queue = nullptr;
                return;
        }

        queue = new Request[size];

        for (int i = 0; i < size; i++) {
                queue[i] = copyQueue.queue[i];
        }
}

RequestQueue::~RequestQueue() { if (size != 0) delete[] queue; }

RequestQueue& RequestQueue::operator= (const RequestQueue &copyQueue){
        if (& copyQueue == this ) return *this;

        if (size != 0) delete[] queue;

        size = copyQueue.size;

        if (size == 0) {
                queue = nullptr;
                return *this;
        }

        queue = new Request[size];

        for (int i = 0; i < size; i++) {
                queue[i] = copyQueue.queue[i];
        }

        return *this;
}

void RequestQueue::insert(Request request){
        size++;
        Request *newQueue = new Request[size];

        newQueue[size - 1] = request;
        for (int i = 0; i < size - 1; i++) {
                newQueue[i] = queue[i];
        }
        if (size != 1) delete[] queue;
        queue = newQueue;

        int index = size - 1;

        while (index > 0 && queue[index] > queue[(index - 1) / 2]){
                swapWithParent(index);
                index = (index - 1) / 2;
        }
}
Request RequestQueue::remove(){
        Request request;
        if (size == 0) return request;

        size--;
        request = queue[0];

        if (size == 0) {
                delete[] queue;
                queue = nullptr;
                return request;
        }

        Request *newQueue = new Request[size];
        newQueue[0] = queue[size];

        for (int i = 1; i < size; i++) {
                newQueue[i] = queue[i];
        }

        delete[] queue;
        queue = newQueue;

        heapify();
        handleSamePriority();

        return request;
}

int RequestQueue::getSize() const { return size; }

void RequestQueue::print(){
        cout << "[";
        for (int i = 0; i < size; i++) cout << queue[i].getID() << ",";
        cout << "]" << endl;
}


void RequestQueue::heapify(int index){
        int child = 2 * index + 1;

        if (child >= size) return;

        // Comparison operators compares priorities for Request class
        if (child + 1 < size && queue[child] < queue[child + 1]) child++;

        if (queue[index] < queue[child]) {
                swapWithParent(child);
                heapify(child);
        }
}

void RequestQueue::handleSamePriority(int index){
        int child = 2 * index + 1;

        if (child < size && queue[index] == queue[child]) handleSamePriority(child);
        if (child + 1 < size && queue[index] == queue[child + 1]) handleSamePriority(child + 1);

        if (index == 0) return;

        int parent = (index - 1) / 2;
        if (queue[index].getArrivalTime() < queue[parent].getArrivalTime() ||
        (queue[index].getArrivalTime() == queue[parent].getArrivalTime() && queue[index].getID() < queue[parent].getID()))
                swapWithParent(index);
}

void RequestQueue::swapWithParent(int index){
        if (index >= size || index == 0) return;

        Request temp = queue[index];
        queue[index] = queue[(index - 1) / 2];
        queue[(index - 1) / 2] = temp;
}

