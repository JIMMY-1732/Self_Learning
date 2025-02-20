//Github: Jimmy_1732, 20,Feb,25
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
PROVIDED_TEST("Each option has the right length.") {
    string sentence = "Hello, Welcome Home!";
    for (string option: allEmphasesOf(sentence)) {
        EXPECT_EQUAL(option.length(), sentence.length());
    }
}


PROVIDED_TEST("Stress test: Generates each option once (should take at most a few seconds)") {
    /* This sentence has 13 words in it. There are therefore 2^13 = 8192 possible emphases for
     * the words there, which is a big number but not so large that the computer can't handle
     * it if generates each emphasis exactly once.
     *
     * On the other hand, if your code tries to generate the same emphases multiple times,
     * this test may take a very, very long time to complete, and might even appear to freeze
     * up.
     *
     * If your code gets stuck in this test, trace through your code and confirm that you can't
     * produce the same emphasis multiple times. Check to make sure you aren't, for example,
     * looping over every token in the input sentence and deciding which one to capitalize
     * next. The recursion here follows more of an include/exclude type pattern (more like
     * subsets and combinations) than it does a "which is next?" type pattern (more like
     * permutations).
     */
    string yeats = "Turing and turning in a widening gyre / the falcon cannot hear the falconer.";
    EXPECT_EQUAL(allEmphasesOf(yeats).size(), 8192);
}
