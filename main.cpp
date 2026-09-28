/**
 * @file    main.cpp
 * @brief   A simple program to demonstrate a printing queue using threads and binary semaphores in C++
 * @author	Everton Cavalcante (everton.cavalcante@ufrn.br)
 * @since	September 28, 2026
 * @date	September 28, 2026
 */

#include <iostream>
using std::cout;
using std::endl;

#include <thread>
using std::thread;

#include <vector>
using std::vector;

#include "job.h"
#include "printingqueue.h"

# define NUM_JOBS 10

/** @brief Main function */
int main() {
    PrintingQueue queue;

    std::vector<Job> jobs;
    for (int i = 1; i <= NUM_JOBS; ++i) {
        jobs.emplace_back("Job " + std::to_string(i), queue);
    }

    std::vector<std::thread> threads;
    for (auto& job : jobs) {
        threads.emplace_back(std::ref(job));
    }

    for (auto& t : threads) {
        t.join();
    }

    cout << "All printing jobs are finished" << endl;

    return 0;
}