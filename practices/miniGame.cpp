#include <iostream>
#include <cmath>

using namespace std;

// Grettings
string dialogGrettings = "Hello, I'm your PC... \nWould you like to know... Who is more intelligent between you and me?";
string optionsdialogGrettings[] = {"Hello, yes of course, let's play", "No, I would not like it!"};
string responseDialogGrettings[] = {"Let's!", "Se you later"};
// Quest 1
string quest1 = "What is the name of the nuclear plant that closed forever in Ukraine?";
string optionsQuest1[] = {"Chernobyl. ", "Yangjiang. ", "Singapore. "};
int correctQuest1 = 1;
// Quest 2
string quest2 = "What is Ganymede?";
string optionsQuest2[] = {"A moon of Uranus. ", "A moon of Jupiter.", "It is not a moon. "};
int correctQuest2 = 2;
// Quest 3
string quest3 = "Who said, “All falling bodies, irrespective of their size, descend at the same speed”?";
string optionsQuest3[] = {"Galileo Galilei. ", "Ernest Mach.", "Thomas Alva Edison. "};
int correctQuest3 = 1;
// Quest 4
string quest4 = "In the Terminator, Sarah Conner was played by who?";
string optionsQuest4[] = {"Anne Hathaway . ", "Milla Jovovich. ", "Linda Hamilton. "};
int correctQuest4 = 3;
// Quest 5
string quest5 = "The Scottish bacteriologist who discovered penicillin was";
string optionsQuest5[] = {"Archimeder. ", "Alexander Fleming.", "Louis Pasteur. "};
int correctQuest5 = 2;
// Goodbye
string responseDialogGoodbye[] = {"You definitely know more than me. ", "I told you, I know more than you. ", "We know the same. "};
// Response pc
string responsePC[] = {"Correct. ", "Incorrect. "};

int pointsPlayer = 0;
int pointsPC = 0;

int displayQuest(int questNumber)
{
    int response;
    switch (questNumber)
    {
    case 1:
        cout << " " << endl;
        cout << quest1 << endl;
        cout << " 1 --> " << optionsQuest1[0] << "\n 2 --> " << optionsQuest1[1] << "\n 3 --> " << optionsQuest1[2] << endl;
        break;
    case 2:

        cout << " " << endl;
        cout << quest2 << endl;
        cout << " 1 --> " << optionsQuest2[0] << "\n 2 --> " << optionsQuest2[1] << "\n 3 --> " << optionsQuest2[2] << endl;
        break;

    case 3:

        cout << " " << endl;
        cout << quest3 << endl;
        cout << " 1 --> " << optionsQuest3[0] << "\n 2 --> " << optionsQuest3[1] << "\n 3 --> " << optionsQuest3[2] << endl;
        break;

    case 4:
        cout << " " << endl;
        cout << quest4 << endl;
        cout << " 1 --> " << optionsQuest4[0] << "\n 2 --> " << optionsQuest4[1] << "\n 3 --> " << optionsQuest4[2] << endl;
        break;

    case 5:
        cout << " " << endl;
        cout << quest5 << endl;
        cout << " 1 --> " << optionsQuest5[0] << "\n 2 --> " << optionsQuest5[1] << "\n 3 --> " << optionsQuest5[2] << endl;
        break;

    default:
        response = -1;
        break;
    }
    cin >> response;
    return response;
};

void checkResponse(int response, int correctResponse)
{
    if (response == correctResponse)
    {
        pointsPlayer++;
        cout << responsePC[0] << endl;
    }
    else
    {
        pointsPC++;
        cout << responsePC[1] << endl;
    }
};

void startQuest()
{
    int resp = -1;

    cout << responseDialogGrettings[0] << endl;

    resp = displayQuest(1);
    checkResponse(resp, correctQuest1);

    resp = displayQuest(2);
    checkResponse(resp, correctQuest2);

    resp = displayQuest(3);
    checkResponse(resp, correctQuest3);

    resp = displayQuest(4);
    checkResponse(resp, correctQuest4);

    resp = displayQuest(5);
    checkResponse(resp, correctQuest5);
};

void sayGoodBye()
{
    cout << responseDialogGrettings[1] << endl;
};

void printScore()
{
    cout << " Your Score --> " << pointsPlayer << "\n My Score --> " << pointsPC << endl;

    if(pointsPlayer > pointsPC)
    {
        cout << responseDialogGoodbye[0] << endl;
    }
    else if(pointsPlayer < pointsPC)
    {
        cout << responseDialogGoodbye[1] << endl;
    }
    else if(pointsPlayer == pointsPC)
    {
        cout << responseDialogGoodbye[2] << endl;
    }
}

int main()
{
    int response = -1;

    cout << dialogGrettings << endl;
    cout << " 1 --> " << optionsdialogGrettings[0] << "\n 2 --> " << optionsdialogGrettings[1] << endl;
    cout << "Enter 1 or 2 to response" << endl;

    cin >> response;

    switch (response)
    {
    case 1:
        startQuest();
        printScore();
        break;
    case 2:
        sayGoodBye();
        break;
    default:
        break;
    }
    return 0;
}