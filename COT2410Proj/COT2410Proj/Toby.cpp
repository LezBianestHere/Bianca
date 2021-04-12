#include "Header.h"

void TextAdventure::loadToby() {
    //This is a file dedicated to creating the character of Toby and adding him to the charactersList

    //Other names for Tobi
    vector<string> tobiAliases = { "tobi", "Tobi", "tobi park", "tobi park", "park", "mr. park" };
    Character tobiPark(tobiAliases, "Tobi Parker");

    //Default response
    tobiPark.setDefaultResponse("I�m sorry, I didn�t understand what you said there, could you run that by me again please?i");
    tobiPark.setIntroduction("Hey, I'm Tobi Park. You must have heard of me.");
    //Adding all of the different variants of questions
    fstream newfile;
    vector<string> questionTokens;
    string answer = "";
    question_t question;

    newfile.open("toby.txt", ios::in);
    if (newfile.is_open()) {
        string fileInput = "";
        while (getline(newfile, fileInput)) {

            //parse the line 
            string word = "";
            vector<string> questionTokens;
            for (auto x : fileInput)
            {
                if (x == ' ')
                {
                    questionTokens.push_back(word);
                    word = "";
                }
                else {
                    word = word + x;
                }
            }
            //Get the last word
            questionTokens.push_back(word);

            //next line is the answer
            getline(newfile, fileInput);
            answer = fileInput;

            question.tokens = questionTokens;
            question.answer = answer;
            tobiPark.addResponse(question);

            //this is for visually to separate tokens/answers in the file
            getline(newfile, fileInput); //should be a blank space, ignore

        }
        newfile.close(); //close the file object.
    }


    addCharacter(tobiPark);
}