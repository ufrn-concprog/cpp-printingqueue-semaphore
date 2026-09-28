/**
 * @file	printingqueue.cpp
 * @brief	Implementation of a printing queue as a shared resource
 * @author	Everton Cavalcante (everton.cavalcante@ufrn.br)
 * @since	September 28, 2026
 * @date	September 28, 2026
 */

#include "printingqueue.h"

#include <chrono>
using std::chrono::seconds;

#include <iostream>
using std::cout;
using std::endl;

#include <thread>
using std::this_thread;

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
    access.acquire();  // down / wait

    cout << "Printing " << jobName << "...\n";
    this_thread::sleep_for(seconds(1));  // simulate printing time
    cout << jobName << " done printing\n";

    access.release();  // up / signal
}