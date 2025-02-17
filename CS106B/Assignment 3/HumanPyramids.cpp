//Github: JIMMY_1732, 17,Feb,25
#include "HumanPyramids.h"
#include "error.h"
#include "map.h"
#include "gridlocation.h"

using namespace std;

/* TODO: Refer to HumanPyramids.h for more information about what this function should do.
 * Then, delete this comment.
 */

double weightOnBackOf(int row, int col, int pyramidHeight);
double memoizationRec(int row, int col, Map <GridLocation,double>& Table);

/* Milestone 1:
 * double weightOnBackOf(int row, int col, int pyramidHeight) {


    double weight = 0;

    if(row > pyramidHeight || pyramidHeight <= 0|| row < 0|| col < 0)
        error("Invalid Input");

    if(row == 0 && col == 0)
        return 0;

    else{
        if(col == 0){
            weight = weightOnBackOf(row - 1, col, pyramidHeight) / 2 + 80;
            return weight;
        }
        if(col == row){
            weight = weightOnBackOf(row - 1, col - 1, pyramidHeight) / 2 + 80;
            return weight;
        }
        if(col > 0 && row > 0){
            weight += weightOnBackOf(row - 1, col - 1, pyramidHeight)/2 + 80;
            weight += weightOnBackOf(row - 1, col, pyramidHeight)/2 + 80;
            return weight;
        }
    }
    return weight;
}*/



double memoizationRec(int row, int col,int pyramidHeight, Map <GridLocation,double>& Table) {


    GridLocation location;
    double weight = 0;
    location = {row,col};


    if(row == 0 && col == 0)
        return 0;

    else if(Table.containsKey(location))
        return Table[location];

    else{
        if(col == 0){
            weight = memoizationRec(row - 1, col, pyramidHeight,Table) / 2 + 80;
            Table.put(location,weight);
            return Table[location];
        }
        if(col == row){
            weight = memoizationRec(row - 1, col - 1,pyramidHeight,Table) / 2 + 80;
            Table.put(location,weight);
            return Table[location];
        }
        if(col > 0 && row > 0){
            weight += memoizationRec(row - 1, col - 1,pyramidHeight,Table)/2 + 80 + memoizationRec(row - 1, col,pyramidHeight,Table)/2 + 80;
            Table.put(location, weight);
            return Table[location];
        }
    }
    return weight;
}

double weightOnBackOf(int row, int col, int pyramidHeight) {
    Map<GridLocation,double> Location;

    if(row > pyramidHeight || pyramidHeight <= 0|| row < 0|| col < 0)
        error("Invalid Input");

    return memoizationRec(row, col, pyramidHeight, Location);
}





/* * * * * * Test Cases * * * * * */
#include "GUI/SimpleTest.h"

/* TODO: Add your own tests here. You know the drill - look for edge cases, think about
 * very small and very large cases, etc.
 */


STUDENT_TEST("Check Person H from the handout.") {
    /*Person H is located at row 3, column 1. */
    EXPECT_EQUAL(weightOnBackOf(3, 1, 5), 340);
}









/* * * * * * Test cases from the starter files below this point. * * * * * */

PROVIDED_TEST("Check Person E from the handout.") {
    /* Person E is located at row 2, column 1. */
    EXPECT_EQUAL(weightOnBackOf(2, 1, 5), 240);
}

PROVIDED_TEST("Function reports errors in invalid cases.") {
    EXPECT_ERROR(weightOnBackOf(-1, 0, 10));
    EXPECT_ERROR(weightOnBackOf(10, 10, 5));
    EXPECT_ERROR(weightOnBackOf(-1, 10, 20));
}

PROVIDED_TEST("Stress test: Memoization is implemented (should take under a second)") {
    /* TODO: Yes, we are asking you to make a change to this test case! Delete the
     * line immediately after this one - the one that starts with SHOW_ERROR - once
     * you have implemented memoization to test whether it works correctly.
     */
    //SHOW_ERROR("This test is configured to always fail until you delete this line from\n         HumanPyramids.cpp. Once you have implemented memoization and want\n         to check whether it works correctly, remove the indicated line.");

    /* Do not delete anything below this point. :-) */

    /* This will take a LONG time to complete if memoization isn't implemented.
     * We're talking "heat death of the universe" amounts of time. :-)
     *
     * If you did implement memoization but this test case is still hanging, make
     * sure that in your recursive function (not the wrapper) that your recursive
     * calls are to your new recursive function and not back to the wrapper. If you
     * call the wrapper again, you'll get a fresh new memoization table rather than
     * preserving the one you're building up in your recursive exploration, and the
     * effect will be as if you hadn't implemented memoization at all.
     */
    EXPECT(weightOnBackOf(100, 50, 200) >= 10000);
}

/* TODO: Add your own tests here. You know the drill - look for edge cases, think about
 * very small and very large cases, etc.
 */
