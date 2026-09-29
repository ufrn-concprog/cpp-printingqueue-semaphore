/**
 * @file	printingqueue.h
 * @brief	Representation of a printing queue as a shared resource
 * @author	Everton Cavalcante (everton.cavalcante@ufrn.br)
 * @since	September 28, 2026
 * @date	September 29, 2026
 */

#ifndef PRINTINGQUEUE_H
#define PRINTINGQUEUE_H

#include <semaphore>
using std::binary_semaphore;

#include <string>
using std::string;

/**
 * @class PrintingQueue
 * @brief Represents a printing queue as a shared resource, with exclusive access controlled by a binary semaphore.
 */
class PrintingQueue {
public:
    /** @brief Default constructor */
    PrintingQueue();

    /**
     * @brief Add a print job to the queue and simulate printing it.
     * @param jobName The name of the print job to be added to the queue.
     */
    void printJob(const string& jobName);

private:
    /** @brief Binary semaphore to control exclusive access to the printing queue. */
    std::binary_semaphore access;
};

#endif // PRINTINGQUEUE_H