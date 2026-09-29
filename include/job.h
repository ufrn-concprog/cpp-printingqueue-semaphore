/**
 * @file	job.h
 * @brief	Representation of a print job
 * @author	Everton Cavalcante (everton.cavalcante@ufrn.br)
 * @since	September 28, 2026
 * @date	September 29, 2026
 */

#ifndef JOB_H
#define JOB_H

#include <string>
using std::string;

#include "printingqueue.h"

/**
 * @class Job
 * @brief Represents a print job that can be executed in a separate thread, interacting with a PrintingQueue.
 */
class Job {
public:
    /**
     * @brief Parameterized constructor for Job.
     * @param id The ID of the print job.
     * @param queue The PrintingQueue to which the job belongs.
     */
    Job(string id, PrintingQueue& queue);

    /** @brief Overloaded function call operator to execute the print job.*/
    void operator()();

private:
    /** @brief The ID of the print job. */
    std::string id;
    
    /** @brief A reference to the PrintingQueue to which the job belongs. */
    PrintingQueue& queue;
};

#endif