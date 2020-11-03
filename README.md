# Directory Access Checker

## 1. Overview
Directory access checker for linux systems:<br>
1. Takes some directory as argument.<br>
2. Checks if the given folder exists. If no, tries to create it.<br>
3. Checks if program has permissions to create files int the directory.<br>
4. Checks if another instance of application is already using the directory.<br>
5. If another instance of application is already using the directory returns -1.

# Note: program is for linux systems.

#### To run execute the following:

## 2. Running the program
#### To run execute the following:

cd <b>dir_with_exe</b><br>
./DirAcC <b>dir_to_lock</b><br>

where <b>dir_with_exe</b> is a directory where the executable is located<br>,
and <b>dir_to_lock</b> is a directory you want to lock and check.

## 3. Building from source

#### Requirements:
cmake and compiler supporting C++17.

#### To build execute the following:

git clone https://github.com/denhrulyov/DirAcC<br>
cd DirAcC<br>
cmake .<br>
cmake --build .<br>

