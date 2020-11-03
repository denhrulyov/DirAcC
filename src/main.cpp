#include "directory/Directory.h"

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cout << "Incorrect number of arguments";
        return 0;
    }
    auto dir = Directory::Enter(argv[1]);
    if (!dir) {
        std::cout << "Cannot create directory" << std::endl;
        return 0;
    }
    std::cout << "Create permissions : " << std::boolalpha << dir->CheckCreatePermissions() << std::endl;
    auto dir_lock = dir->Lock();
    if (dir_lock) {
        getchar();
    } else {
        return -1;
    }
    return 0;
}