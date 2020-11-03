//
// Created by denis on 03.11.20.
//

#include "DirectoryLock.h"

std::unique_ptr<DirectoryLock> DirectoryLock::Create(int descriptor) {
    bool status = false;
    std::thread opener([&] { DirectoryLock::TryOpen(descriptor, status); });
    opener.detach();
    // giving enough time to lock directory if it is free
    std::this_thread::sleep_for(std::chrono::milliseconds (100));
    if (!status) {
        // if given time is over but directory is still not locked
        return nullptr;
    }
    return std::unique_ptr<DirectoryLock> {new DirectoryLock(descriptor)};
}

void DirectoryLock::TryOpen(int descriptor, bool& status) {
    flock(descriptor, LOCK_EX);
    status = true;
}

DirectoryLock::~DirectoryLock() {
    flock(descriptor_, LOCK_UN);
}