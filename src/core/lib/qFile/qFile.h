#ifndef QFILE_H
#define QFILE_H
#include <stdio.h>
#include <dirent.h>
enum FileType {
    FOLDER, DATA, CLOSED, WRITE, APPEND
};
/**
 * Cannot be bothered to make this right now, might make Courage do it unsure yet
 * 
 * qFile will handle all fileIO operations in quantum engine. a qFile object can be any object in the OS file system.
 * FileType specifies which type it is. It has to be one of the file types and cannot be more than one file type. A data
 * file for instance cannot be a folder. There is some hierarchy as a data file can become a write or append file
 * 
 * qFile init() will also be important as it will find the path to the home directory. We will use the C file directory
 * system and the C file management system. In quantumEngine proper qFile will run in it's own process so if quantumEngine
 * crashes we can still close all the relevent files
 * 
 * qFile will also handle our logger class once I figure out what I want to do with that
 */
class qFile {
    private:
    unsigned int size;
    char* filePath;
    FileType type;
    union fileSruct {
        FILE* file;
        DIR* dir;
    } data;
    unsigned int line;

    public:
    qFile() {type = CLOSED; filePath = nullptr; size = 0;};
    qFile(char* filePath);
    ~qFile();

    void openFile(char* filePath);
    void close();

    char* getLine();
    char nextChar();
    char* nextWord(char delim = ' ');
    int nextInt(char delim = ' ');
    double nextDouble(char delim = ' ');
    float nextFloat(char delim = ' ');

    int getSize() {return size;};
};
//unsigned int openFiles[] = {};
void init(char* homePath);
void closeAll();
#endif