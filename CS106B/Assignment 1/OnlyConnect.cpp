//Github: JIMMY-1732, 12,Feb,25
#include "OnlyConnect.h"
#include "GUI/SimpleTest.h"
#include "strlib.h"
#include <string>
using namespace std;

string onlyConnectize(string phrase) {
    /* TODO: The next few lines just exist to make sure you don't get compiler warning messages
     * when this function isn't implemented. Delete these lines, then implement this function.
     */
    string newphrase = "";
    (void) phrase;
    cout << "test:" << phrase << endl;

    if (phrase.size() == 1){
        if(isalpha(phrase[0])){
            if(phrase[0] == 'A'|| phrase[0] == 'E' || phrase[0] == 'I'|| phrase[0] =='O'|| phrase[0] =='U'){
            //if(toupper(phrase[0]) == 'A'|| toupper(phrase[0]) == 'E' || toupper(phrase[0]) == 'I'|| toupper(phrase[0]) =='O'|| toupper(phrase[0]) =='U'){
                return "";
            }
            else{
                return toUpperCase(phrase);
            }
        }
        else
            return "";
    }

    newphrase = onlyConnectize(toUpperCase(phrase.substr(0,phrase.size()-1))) + onlyConnectize(toUpperCase(phrase.substr(phrase.size()-1,1)));
    return newphrase;
}





/* * * * * * Provided Test Cases * * * * * */

PROVIDED_TEST("Converts lower-case to upper-case.") {
    EXPECT_EQUAL(onlyConnectize("lowercase"), "LWRCS");
    EXPECT_EQUAL(onlyConnectize("uppercase"), "PPRCS");
}

PROVIDED_TEST("Handles non-letter characters properly.") {
    EXPECT_EQUAL(onlyConnectize("2.718281828459045"), "");
    EXPECT_EQUAL(onlyConnectize("'Hi, Mom!'"), "HMM");
}

PROVIDED_TEST("Handles single-character inputs.") {
    EXPECT_EQUAL(onlyConnectize("A"), "");
    EXPECT_EQUAL(onlyConnectize("+"), "");
    EXPECT_EQUAL(onlyConnectize("Q"), "Q");
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






