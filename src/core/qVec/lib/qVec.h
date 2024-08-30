template <class T>
class qVec {
    private:
        T* values;
        int size;
    public:
        qVec(int size, T values[], int tSize);
        qVec(int size);
        ~qVec();

        int getSize();
        T* valueOf();
};