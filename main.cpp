/**
 * @file    main.cpp
 * @brief   A simple program to demonstrate a printing queue using threads and binary semaphores in C++
 * @author	Everton Cavalcante (everton.cavalcante@ufrn.br)
 * @since	September 28, 2026
 * @date	September 29, 2026
 */

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <thread>
using std::thread;

#include <vector>
using std::vector;

#include "job.h"
#include "printingqueue.h"

/** @brief Number of print jobs to simulate */
# define NUM_JOBS 10

/**
 * @brief Main function
 * @return Exit status code
 */
int main() {
    PrintingQueue queue;

    std::vector<thread> jobList;
    for (int i = 1; i <= NUM_JOBS; ++i) {
        string name = "Job " + std::to_string(i);
        cout << "Printing job sent: " << name << endl;
        jobList.emplace_back(Job(name, queue));
    }

    for (auto& job : jobList) {
        job.join();
    }

    cout << "All printing jobs are finished" << endl;

    return 0;
}