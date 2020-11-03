//
// Created by denis on 03.11.20.
//

#ifndef DIRACC_DIRECTORYLOCK_H
#define DIRACC_DIRECTORYLOCK_H


#include <iostream>
#include <unistd.h>
#include <sys/file.h>
#include <thread>

/*
 * Class for locking directory
 * Directory is automatically unlocked on object destruction
 */

class DirectoryLock {
public:
    /*
     *
     * Locks directory.
     * If another running instance of application
     * is already locked the directory returns nullptr
     *
     * @param linux file descriptor
     * @return DirectoryLock object if directory is not locked by another instance
     *         and nullptr otherwise
     *
     */
    static std::unique_ptr<DirectoryLock> Create(int descriptor);
    void operator = (const DirectoryLock dir) = delete;
    DirectoryLock(const DirectoryLock& dir) = delete;
    /*
     * Releases directory lock
     */
    ~DirectoryLock();
private:
    explicit DirectoryLock(int descriptor) : descriptor_(descriptor) {}

    /*
     * Tries to acquire directory by descriptor
     *
     * @param           file descriptor representing directory
     * @param[out]      success of acquiring file
     */
    static void TryOpen(int descriptor, bool& status);

private:
    int descriptor_;

};
#endif //DIRACC_DIRECTORYLOCK_H
