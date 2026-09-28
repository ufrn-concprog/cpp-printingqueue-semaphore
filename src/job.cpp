/**
 * @file    job.cpp
 * @brief	Implementation of a print job
 * @author	Everton Cavalcante (everton.cavalcante@ufrn.br)
 * @since	September 28, 2026
 * @date	September 28, 2026
 */

#include "job.h"

#include <iostream>
using std::cout;
using std::endl;

/**
 * @brief Parameterized constructor for Job.
 * @param id The ID of the print job.
 * @param queue The PrintingQueue to which the job belongs.
 */
Job::Job(string id, PrintingQueue& queue) : id(std::move(id)), queue(queue) {}

/** @brief Overloaded function call operator to execute the print job.*/
void Job::operator()() {
    cout << "Sending printing job to printer: " << id << endl;
    queue.printJob(id);
}