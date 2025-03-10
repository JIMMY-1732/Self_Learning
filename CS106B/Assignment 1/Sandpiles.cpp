//Github: JIMMY-1732, 12,Feb,25
#include "Sandpiles.h"
#include "GUI/SimpleTest.h"
#include "grid.h"
using namespace std;

void dropSandOn(Grid<int>& world, int row, int col) {
    /* TODO: Delete this line and the three after it, then implement this function. */
    (void) world;
    (void) row;
    (void) col;
    Grid<int> temp;
    //r0c0,r1c1,r1c3 +1
    world[row][col]++;

    for(int i = 0;i < world.numRows();i++){
        for(int j = 0;j < world.numCols();j++){
            if(world[i][j] >= 4){
                world[i][j] -=4 ;
                if(i - 1 >= 0){
                    dropSandOn(world,i-1,j);
                }
                if(i + 1 <= world.numRows()){
                    dropSandOn(world,i+1,j);
                }
                if(j - 1 >= 0){
                    dropSandOn(world,i,j-1);
                }
                if(j + 1 <= world.numCols()){
                    dropSandOn(world,i,j+1);
                }
            }
        }
    }

}

/*      { 3, 0, 3 } //i=0,j=1
        { 3, 0, 3 }
        { 3, 3, 3 }
*/






/* * * * * * Provided Test Cases * * * * * */

PROVIDED_TEST("Dropping into an empty cell only changes that cell.") {
    /* Create a simple source grid. */
    Grid<int> before = {
        { 3, 3, 3 },
        { 3, 0, 3 },
        { 3, 3, 3 }
    };
    Grid<int> after = {
        { 3, 3, 3 },
        { 3, 1, 3 },
        { 3, 3, 3 }
    };

    dropSandOn(before, 1, 1);
    EXPECT_EQUAL(before, after); // The above call changes 'before.'
}

PROVIDED_TEST("Non-chaining topples work.") {
    /* Create a simple source grid. */
    Grid<int> before = {
        { 0, 0, 0 },
        { 1, 3, 1 },
        { 0, 2, 0 }
    };
    Grid<int> after = {
        { 0, 1, 0 },
        { 2, 0, 2 },
        { 0, 3, 0 }
    };

    dropSandOn(before, 1, 1);
    EXPECT_EQUAL(before, after); // The above call changes 'before.'
}

PROVIDED_TEST("Two topples chain.") {
    /* Create a simple source grid. */
    Grid<int> before = {
        { 0, 0, 0, 0 },
        { 0, 3, 3, 0 },
        { 0, 0, 0, 0 }
    };
    Grid<int> after = {
        { 0, 1, 1, 0 },
        { 1, 1, 0, 1 },
        { 0, 1, 1, 0 }
    };

    dropSandOn(before, 1, 1);
    EXPECT_EQUAL(before, after); // The above call changes 'before.'
}

/* TODO: You will need to add your own tests into this suite of test cases. Think about the sorts
 * of inputs we tested here, and, importantly, what sorts of inputs we *didn't* test here. Some
 * general rules of testing:
 *
 *    1. Try extreme cases. What are some very large cases to check? What are some very small cases?
 *
 *    2. Be diverse. There are a lot of possible inputs out there. Make sure you have tests that account
 *       for cases that aren't just variations of one another.
 *
 *    3. Be sneaky. Don't just try standard inputs. Try weird ones that you wouldn't expect anyone to
 *       actually enter, but which are still perfectly legal.
 *
 * Happy testing!
 */










