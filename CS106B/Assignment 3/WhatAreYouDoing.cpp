//Github: JIMMY_1732, 20,Feb,25
#include "WhatAreYouDoing.h"
#include "strlib.h"



using namespace std;

/* TODO: Read the comments in WhatAreYouDoing.h to see what this function needs to do, then
 * delete this comment.
 *
 * Don't forget about the tokenize function defined in WhatAreYouDoing.h; you'll almost
 * certainly want to use it.
 */


string allEmphasesOfhelper(int number, string output,Vector <string>& word_list);

Set<string> allEmphasesOf(const string& sentence) {
    /* TODO: Delete this line and the next one, then implement this function. */

    Set <string> original;
    Vector <string> output_sentence;
    Vector <string> words;
    Vector <string> symbols;
    Vector <int> changed_pos = {0};
    string sentence_output;
    int cnt = 0;
    int pos = 0;
    int flag = false;

    for (string word : tokenize(sentence)){
        if(isalpha(word[0])){
            cnt++;
            words.add(word);
        }
        else if(word[0] == ' ' || !isalpha(word[0]))
            symbols.add(word);
    }

    if(words.size() == 0){
        for(string symbol : symbols)
            output_sentence.add(symbol);

        sentence_output = "";

        for(string str: output_sentence)
            sentence_output += str;
        original.add(sentence_output);
        return {original};

    }


    allEmphasesOfhelper(words.size(),"", words);
    for(int i = 0; i < cnt; i++)
        words.remove(0);

    for(string& word : words){  //loop for words set

        if(word[word.size() - 1] == ' ')
            word.erase(word.size() - 1);

        changed_pos = {-1};
        output_sentence = tokenize(sentence);
        for(string word1 : tokenize(word)){
            pos = 0;
            flag = false;
            if(word1[0] != ' '){
                for (string& word2 : output_sentence){ //loop for single word, slow af ;(
                    for(int value : changed_pos){
                        if(value == pos){
                            flag = true;
                            break;
                        }
                    }
                    if(isalpha(word2[0]) && !flag){
                        output_sentence.set(pos,word1);
                        changed_pos.add(pos);
                        break;
                    }
                    else{
                        flag = false;
                        pos++;
                        continue;
                        }pos++;
                    }
                }
            }

        sentence_output = "";
        for(string str: output_sentence)
            sentence_output += str;
        original.add(sentence_output);

        }
    return original;
}


string allEmphasesOfhelper(int number, string output,Vector <string>& word_list){

    string word;

    if(number == 0){
        return output;}

    else if(number > 0){
        word = allEmphasesOfhelper(number - 1, toLowerCase(word_list[number - 1]) + " " + output, word_list);
        if(word != "" && word != " ")
            word_list.add(word);

        word = "";

        word = allEmphasesOfhelper(number - 1, toUpperCase(word_list[number - 1]) + " " + output, word_list);
        word += " ";
        if(word != "" && word != " ")
            word_list.add(word);
    }
    return "";
}


/* * * * * * Test Cases * * * * * */
#include "GUI/SimpleTest.h"

/* TODO: Add your own tests here. You know the drill - look for edge cases, think about
 * very small and very large cases, etc.
 */














/* * * * * * Test cases from the starter files below this point. * * * * * */

PROVIDED_TEST("Enumerates all options in a simple case.") {
    Set<string> expected = {
        "hello",
        "HELLO",
    };

    EXPECT_EQUAL(allEmphasesOf("Hello"), expected);
}

PROVIDED_TEST("Each option has the right length.") {
    string sentence = "Hello, World!";
    for (string option: allEmphasesOf(sentence)) {
        EXPECT_EQUAL(option.length(), sentence.length());
    }
}

PROVIDED_TEST("Enumerates all options in a more typical case.") {
    Set<string> expected = {
        "you are?",
        "you ARE?",
        "YOU are?",
        "YOU ARE?"
    };

    EXPECT_EQUAL(allEmphasesOf("You Are?"), expected);
}

PROVIDED_TEST("Stress Test: Recursion only branches on words (should take under a second)") {
    /* We're producing a string consisting of fifty copies of the * character. This tokenizes
     * into fifty separate stars. A star is the same whether or not you capitalize it - there
     * is no such thing as an "upper-case" or "lower-case" star. Therefore, your code should
     * not try to form two versions of the sentence, one with the star capitalized and one
     * without, because the two versions will end up being the same and the work to compute
     * both options will dramatically increase the runtime.
     *
     * For reference, if you do try branching the recursion and checking what happens both if
     * you capitalize the star and if you don't, you'll try exploring 2^50 different possible
     * capitalizations. That's 1,125,899,906,842,624 options, and even doing a billion of
     * these a second is going to take over two years to generate them all! And of course,
     * that's all wasted work, since there's only one way to capitalize this sentence, and
     * that's just to leave it as-is.
     *
     * If your code is hanging when this test is running, it likely means that your code is
     * trying to enumerate all of these options. See if you can edit your code so that, if
     * you're given a non-word token, you just leave it as-is and don't change anything.
     */
    string punctuation(50, '*'); // 50 copies of *

    /* The only emphasis is itself. */
    Set<string> expected = {
        punctuation
    };

    EXPECT_EQUAL(allEmphasesOf(punctuation), expected);
}
