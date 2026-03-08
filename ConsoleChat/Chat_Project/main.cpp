#include "Chat_Project.h"


int main() {

    // Intro
    cout << "------------------------------------------------------------------------------------------------" << endl;
    cout << "Hi, this is a chat in which you can communicate with others." << endl
        << "Type /help after entering your name to see available commands." << endl
        << "Also if you tipe '/' you have to write one of the commands." << endl;
    cout << "------------------------------------------------------------------------------------------------" << endl;
    
    // Make user
    string username;
    cout << "Enter your name: ";
    do {
        getline(cin, username);
        if (username.empty())
            cout << "Name cannot be empty. Please enter your name: ";
    } while (username.empty());

    size_t lineCount = 0;
    while (true) {

        vector<string> lines;
        takeChatHistory(lines);
        printHistory(lines,lineCount);

        string message;
        cout << username << ": ";
        getline(cin, message);

        if (message.empty()) {
            continue;
        }
        
        if (message[0] == '/') {
            if (commands(message, username, lineCount))
                break; 
            continue;
        }

        

        ofstream outFile("chat.txt", ios::app);
        outFile << getTime() << " " << username << ": " << message << "\n";
        outFile.close();

        this_thread::sleep_for(chrono::milliseconds(200));
    }

    return 0;
}