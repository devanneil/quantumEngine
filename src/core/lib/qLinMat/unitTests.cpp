#include<qVec.h>
#include<qMat.h>
#include<qVec.h>
//Variable used for general purpose, always set back to 0 when done
int failCatch = 0;
int main() {
    /**
     * TEST 1: INITIALIZATION
     * 
     * This test will fail if there is a memory problem or if the libraries are not correctly linked
     * Will also fail if getSize is not working
     */
    printf("INITIALIZE QVEC: ");
    qVec<int> testVec = {1,2,3};
    if(testVec.getSize() != 3) return 1;
    else printf("PASSED!\n");
    /**
     * TEST 2: MODIFICATION
     * 
     * This test will fail if modification is not correctly implemented
     */
    printf("MODIFY QVEC: ");
    testVec.setValue(0, -1);
    if(testVec.getValue(0) != -1) return 1;
    else printf("PASSED!\n");
    /**
     * TEST 3: BOUNDARY CHECKING
     * 
     * This test will fail if modification is not correctly implemented
     */
    printf("BOUNDARY CHECK: \n");
    try {
        testVec.setValue(-1, 0);
    } catch (std::exception& e){
        printf("Low pass catch: %s\n", e.what());
        failCatch++;
    }
    try {
        testVec.setValue(-1, 0);
    } catch (std::exception& e){
        printf("High pass catch: %s\n", e.what());
        failCatch++;
    }
    if(failCatch != 2) return 1;
    else printf("PASSED!\n");
    failCatch = 0;
    /**
     * TEST 4: OPERATORS
     * 
     * This test will fail if the operator [] is not working
     */
    printf("MODIFY QVEC WITH OPERATORS: ");
    testVec[0] = -1;
    if(testVec[0] != -1) return 1;
    else printf("PASSED!\n");

    /**
     * TEST 5: INITIALIZING EMPTY
     * 
     * This test will fail if the default constructor does not work
     */
    printf("INITIALIZE EMPTY QVEC: ");
    qVec<int> emptyVec;
    if(emptyVec.getSize() != 0) return 1;
    else printf("PASSED!\n");
    /**
     * TEST 6: INITIALIZING WITH SIZE
     * 
     * This test will fail if the size constructor does not work
     */
    printf("INITIALIZE WITH SIZE: ");
    qVec<int> sizedVec(3);
    if(sizedVec.getSize() != 3) return 1;
    if(sizedVec.getValue(0) != 0) return 1;
    else printf("PASSED!\n");
    /** TEST 7: INITIALIZING FROM INTEGER ARRAY
     * 
     * This test will fail if the array constructor does not work
     */
    printf("INITIALIZING QVEC FROM INTEGER ARRAY: ");
    int intArray[] = {0, 1, 2};
    qVec<int> arrayVecInt(3, intArray);
    if(sizedVec.getSize() != 3) return 1;
    if(sizedVec.getValue(0) != 0) return 1;
    else printf("PASSED!\n");
    /**
     * TEST 8: TEMPLATE TEST
     * 
     * This test will fail if the template is not implemented correctly
     */
    printf("TEMPLATE TEST: ");
    qVec<float> floatVec = {0.0f, 1.0f, 2.0f};
    if(floatVec.getSize() != 3) return 1;
    if(floatVec.getValue(0) != 0.0f) return 0;
    else printf("PASSED!\n");
    /**
     * TEST 9: VECTOR COMPARISON
     * 
     * This test will fail if the equals() function does not work
     * This test will also fail if the == and != operators do not work
     */
    printf("QVEC COMPARISON:\n");
    //Check for self assignment
    if(testVec != testVec) return 1;
    printf("SELF ASSIGNMENT\n");
    //Check for size inequality
    if(testVec == emptyVec) return 1;
    //Check for value inequality
    if(testVec == sizedVec) return 1;
    printf("INEQUALITY\n");
    //Check for type inequality
    if(testVec == floatVec) return 1;
    printf("TYPE CHECK\n");
    //Check for equality
    sizedVec[0] = testVec[0];
    sizedVec[1] = testVec[1];
    sizedVec[2] = testVec[2];
    if(testVec != sizedVec) return 1;
    else printf("PASSED!\n");
    /**
     * TEST 10: ASSIGNMENT TEST
     * 
     * This test will fail if the copy function is not working 
     * This test will fail if the copy constructor is not working
     * This test will also fail if the = operator is not working
     */
    printf("ASSIGNMENT TEST: \n");
    sizedVec.copy(testVec);
    if(sizedVec != testVec) return 1;
    printf("COPY SUCCESS\n");
    qVec<int> copyVec = testVec;
    if(copyVec != testVec) return 1;
    printf("CONSTRUCTOR SUCCESS\n");
    copyVec = emptyVec;
    if(copyVec.getSize() != 0) return 1;
    printf("OPERATOR SUCCESS\n");
    if(&copyVec == &emptyVec) {
        printf("SELF ASSIGNMENT ERROR!");
        return 1;
    } else printf("SUCCESS!\n");
    /**
     * TEST 11: MOVE SEMANTICS
     * 
     * THIS TEST IS TBD
     */
    return 0;
}