#include "qFile.h"
#ifndef QFILE
#define QFILE
void init(char* homePath) {

}
qFile::qFile(char* filePath) {
    int pathSize = sizeof(filePath) / sizeof(filePath[0]);
    if(filePath[pathSize - 1] == '\0') {
        //Null terminated
        pathSize --;
    }
    this->size = 0;
    if(filePath[pathSize - 1] == '/') {
        //File is a directory
        this->data.dir = opendir(filePath);
        if(this->data.dir == NULL) {
            perror(filePath);
            this->type = CLOSED;
            this->size = 0;
        } else {
            this->type = FOLDER;
            while(readdir(this->data.dir) != NULL) this->size++;
            rewinddir(this->data.dir);
        }
    } else {
        //File is a file
        this->data.file = fopen(filePath, "r");
        if(this->data.file == NULL) {
            perror(filePath);
            this->type = CLOSED;
            this->size = 0;
        } else {
            this->type = DATA;
            char emptyString[255];
            while(!feof(this->data.file)) {
                char ch = fgetc(this->data.file);
                if(ch == '\n') this->size++;
            }
            rewind(this->data.file);
        }
    }
}

qFile::~qFile() {
    this->close();
}
void qFile::openFile(char* filePath) {
    if(this->type != CLOSED) this->close();
    int pathSize = sizeof(filePath) / sizeof(filePath[0]);
    if(filePath[pathSize - 1] == '\0') {
        //Null terminated
        pathSize --;
    }
    this->size = 0;
    if(filePath[pathSize - 1] == '/') {
        //File is a directory
        this->data.dir = opendir(filePath);
        if(this->data.dir == NULL) {
            perror(filePath);
            this->type = CLOSED;
            this->size = 0;
        } else {
            this->type = FOLDER;
            while(readdir(this->data.dir) != NULL) this->size++;
            rewinddir(this->data.dir);
        }
    } else {
        //File is a file
        this->data.file = fopen(filePath, "r");
        if(this->data.file == NULL) {
            perror(filePath);
            this->type = CLOSED;
            this->size = 0;
        } else {
            this->type = DATA;
            char emptyString[255];
            while(!feof(this->data.file)) {
                char ch = fgetc(this->data.file);
                if(ch == '\n') this->size++;
            }
            rewind(this->data.file);
        }
    }
}
void qFile::close() {
    if(this->type != CLOSED) {
        if(this->type == FOLDER) closedir(this->data.dir);
        else fclose(this->data.file);
    }
    this->type = CLOSED;
    this->size = 0;
}

char* qFile::getLine() {

}
char qFile::nextChar() {

}
char* qFile::nextWord(char delim) {

}
int qFile::nextInt(char delim) {

}
double qFile::nextDouble(char delim) {

}
float qFile::nextFloat(char delim) {
    
}
#endif