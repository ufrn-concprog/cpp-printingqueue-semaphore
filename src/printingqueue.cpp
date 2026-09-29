/**
 * @file	printingqueue.cpp
 * @brief	Implementation of a printing queue as a shared resource
 * @author	Everton Cavalcante (everton.cavalcante@ufrn.br)
 * @since	September 28, 2026
 * @date	September 29, 2026
 */

#include <chrono>
using std::chrono::seconds;

#include <iostream>
using std::cout;
using std::endl;

#include <syncstream>
using std::osyncstream;

#include <thread>
using std::this_thread::sleep_for;

#include "printingqueue.h"

/**
 * @brief Constructor for PrintingQueue.
 * @param initialCount The initial count for the binary semaphore.
 */
PrintingQueue::PrintingQueue() : access(1) {}

/**
 * @brief Add a print job to the queue and simulate printing it.
 * @param jobName The name of the print job to be added to the queue.
 */
void PrintingQueue::printJob(const string& jobName) {
    osyncstream scout(std::cout);
    access.acquire();  // down / wait

    // Thread is suspended by a random time interval to
    // simulate the printing job
    int delay = rand() % 5 + 1;
    scout << jobName << " printing for " << delay << " second(s)" << endl;
    sleep_for(seconds(delay));

    access.release();  // up / signal
}