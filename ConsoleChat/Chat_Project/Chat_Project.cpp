#include "Chat_Project.h"

// getting time function
string getTime() {
    time_t now = time(nullptr);
    tm localTm;
    localtime_s(&localTm, &now);
    tm* local = &localTm;
    string timeString;
    int hour = local->tm_hour;
    int min = local->tm_min;
    timeString += "[";
    if (hour < 10)
        timeString += "0";
    timeString += to_string(hour);
    timeString += ":";
    if (min < 10) 
        timeString += "0";
    timeString += to_string(min);
    timeString += "]";
    return timeString;
}

// reading chat history
void takeChatHistory(vector<string>& lines) {
    ifstream inFile("chat.txt");
    string temp;
    while (getline(inFile, temp)) {
        lines.push_back(temp);
    }
    inFile.close();
}

// printing chat history
void printHistory(vector<string>& lines, size_t& lineCount) {
    if (lines.size() > lineCount) {
        for (size_t i = lineCount; i < lines.size(); i++) {
            cout << lines[i] << endl;
        }
        lineCount = lines.size();
    }
}


//command logic
//true - the functoin will break the loop in main.cpp
//false - the function will continue the loop in main.cpp
bool commands(string& message, string& username, size_t& lineCount) {
    if (message == "/exit") {
        cout << "Exiting chat...\n";
        return true;
    }

    if (message == "/help") {
        cout << "------------------------------------------------------------------------------------------------" << endl;
        cout << "Here are all the commands you can use:" << endl;
        cout << "/exit -> exit the chat" << endl;
        cout << "/clear -> clear chat history" << endl;
        cout << "/newName -> change username" << endl;
        cout << "------------------------------------------------------------------------------------------------" << endl;
        return false;
        
    }

    if (message == "/clear") {
        ofstream clearHistory("chat.txt", ios::trunc);
        clearHistory.close();
        cout << endl << "Chat history has been deleted." << endl;
        lineCount = 0;
        return false;
    }

    if (message == "/newName") {
        cout << endl << "Enter your name: ";
        string newName;
        do {
            getline(cin, newName);
            if (newName.empty())
                cout << "Name cannot be empty. Please enter your name: ";
        } while (newName.empty());
        cout << "Your username has been changed from " << username << " to " << newName << endl;
        username = newName;
        return false;
    }
    return false;
}
