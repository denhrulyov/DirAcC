//
// Created by denis on 03.11.20.
//

#ifndef DIRACC_DIRECTORY_H
#define DIRACC_DIRECTORY_H

#include <optional>
#include <filesystem>
#include "DirectoryLock.h"

class Directory {

public:
    /*
     * If no such directory creates the given directory.
     * If cannot create directory returns std::nullopt
     *
     * @param string representation of the directory
     *
     * @return Directory object
     */
    static std::optional<Directory> Enter(const std::string &dir);
    /*
     *
     * Checks if there is directory and permissions to create files.
     *
     * @return true if can create false otherwise
     */
    bool CheckCreatePermissions();
    /*
     * Tries to acquire directory by descriptor
     * If current directory cannot be opened throws std::system_error
     *
     * @return DirectoryLock object if directory is not locked by another instance
     *         and nullptr otherwise
     */
    std::unique_ptr<DirectoryLock> Lock();

private:
    explicit        Directory(const std::filesystem::path &path) : path_(path) {}

private:
    std::filesystem::path               path_;
};

#endif //DIRACC_DIRECTORY_H
