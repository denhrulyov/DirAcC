//
// Created by denis on 03.11.20.
//

#include "Directory.h"

std::optional<Directory> Directory::Enter(const std::string &dir) {
    std::filesystem::directory_entry dir_entry(dir);
    if (!dir_entry.is_directory()) {
        try {
            std::filesystem::create_directory(dir_entry);
        }
        catch (...) {
            return std::nullopt;
        }
    }
    return Directory(dir_entry);
}

bool Directory::CheckCreatePermissions() {
    try {
        std::string test_path = static_cast<std::string>(path_) + "/.achecker";
        // also checks create permissions
        std::filesystem::create_directory(test_path);
        // rollback test creation
        std::filesystem::remove(test_path);
    } catch (...) {
        return false;
    }
    return true;
}

std::unique_ptr<DirectoryLock> Directory::Lock() {
    int descriptor = open(path_.c_str(),
                          O_RDONLY,
                          O_CLOEXEC   ,   // close on execute
                          S_IRUSR     |   // user permission: read
                          S_IWUSR     );  // user permission: write
    if (descriptor < 0) {
        throw std::system_error(errno, std::generic_category());
    }
    return std::move(DirectoryLock::Create(descriptor));
}