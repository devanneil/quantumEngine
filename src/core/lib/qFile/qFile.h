#ifndef QFILE_H
#define QFILE_H
enum FileType {
    FOLDER, DATA, NONE, CLOSED, WRITE
};

class qFile {
    private:
    unsigned int size;
    char* filePath;
    FileType type;
    unsigned int ID;
    unsigned int line;

    public:
    qFile() {type = NONE; filePath = nullptr; size = 0;};
    qFile(char* filePath);

    void openFile(char* filePath);
    void close();

    char* getLine();
    char nextChar();
    char* nextWord(char delim = ' ');
    int nextInt(char delim = ' ');
    double nextDouble(char delim = ' ');
    float nextFloat(char delim = ' ');
};
unsigned int openFiles[] = {};
void init(char* homePath);
void closeAll();
#endif