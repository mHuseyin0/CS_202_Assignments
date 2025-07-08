/*
* Title: Priotiy Queue for Request
* Author: Muhammed Huseyin AYDIN
* ID: 22203683
* Section: 1
* Assignment: 2
* Description:
*/

#ifndef REQUESTQUEUE_H
#define REQUESTQUEUE_H

#include "Request.h"

class RequestQueue{
public:
        RequestQueue();
        RequestQueue(const RequestQueue &copyQueue);
        ~RequestQueue();
        RequestQueue& operator= (const RequestQueue &copyQueue);

        void insert(Request request);
        Request remove();
        int getSize() const;
        void print();
private:
        int size;
        Request *queue;

        void heapify(int index = 0);
        void handleSamePriority(int index = 0);
        void swapWithParent(int index);
};

#endif
