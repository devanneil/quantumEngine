#include<qMat.h>
//Variable used for general purpose, always set back to 0 when done
int failCatch = 0;
int main() {
    /**
     * TEST 1: INITIALIZATION
     * 
     * This test will fail if there is a memory problem or if the libraries are not correctly linked
     * Will also fail if getSize is not working
     */
    printf("INITIALIZE QMAT: ");

    /**
     * TEST 2: MODIFICATION
     * 
     * This test will fail if modification is not correctly implemented
     */
    printf("MODIFY QMAT: ");

    /**
     * TEST 3: BOUNDARY CHECKING
     * 
     * This test will fail if modification is not correctly implemented
     */
    printf("BOUNDARY CHECK: \n");

    /**
     * TEST 4: OPERATORS
     * 
     * This test will fail if the operator [] is not working
     */
    printf("MODIFY qMat WITH OPERATORS: ");

    /**
     * TEST 5: INITIALIZING EMPTY
     * 
     * This test will fail if the default constructor does not work
     */
    printf("INITIALIZE EMPTY qMat: ");

    /**
     * TEST 6: INITIALIZING WITH SIZE
     * 
     * This test will fail if the size constructor does not work
     */
    printf("INITIALIZE WITH SIZE: ");

    /** TEST 7: INITIALIZING FROM INTEGER ARRAY
     * 
     * This test will fail if the array constructor does not work
     */
    printf("INITIALIZING qMat FROM INTEGER ARRAY: ");

    /**
     * TEST 8: TEMPLATE TEST
     * 
     * This test will fail if the template is not implemented correctly
     */
    printf("TEMPLATE TEST: ");

    /**
     * TEST 9: MATRIX COMPARISON
     * 
     * This test will fail if the equals() function does not work
     * This test will also fail if the == and != operators do not work
     */
    printf("qMat COMPARISON:\n");

    /**
     * TEST 10: ASSIGNMENT TEST
     * 
     * This test will fail if the copy function is not working 
     * This test will fail if the copy constructor is not working
     * This test will also fail if the = operator is not working
     */
    printf("ASSIGNMENT TEST: \n");

    /**
     * TEST 11: MOVE SEMANTICS
     * 
     * This test will fail if the move constructors change the behaviour of the matrix
     */
    printf("MOVE TEST: \n");

    /**
     * TEST 12: DESTRUCTOR AND CLEAR
     * 
     * This test will fail if the clear() function does not work or the destructor does not work
     * This test does not check if the matxi is actually cleared but rather if it seg faults in the clearing process
     */
    printf("DESTRUCTOR TEST: ");

    printf("SUCCESS!\n");

    printf("---------FUNCTIONALITY TESTS---------\n");

    
    return 0;
}