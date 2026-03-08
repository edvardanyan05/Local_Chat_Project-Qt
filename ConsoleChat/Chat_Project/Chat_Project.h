#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <thread>      
#include <chrono>
#include <ctime>
using namespace std;

string getTime();
void takeChatHistory(vector<string>&);
void printHistory(vector<string>&, size_t&);
bool commands(string& , string& , size_t&);