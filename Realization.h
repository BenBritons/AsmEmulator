//
// Created by Ivan on 15.03.22.
//

#include<fstream>
#include<iostream>
#include<map>
#include<string>
#include<sstream>
#include<vector>
#include "Command.h"

using std::cout;
using std::ifstream;
using std::map;
using std::getline;
using std::string;
using std::stringstream;
using std::vector;

int MakeLab( const std::string& path){
    string line;
    int volue;
    string variable;
    string action;
    vector<int> volues;
    map<string, int> data_list;
    ifstream infile;

    infile.open(path, std::fstream::in);


    if (!infile) {
        cout << "error";
    }
    data_list["Ak"] = 0;
    getline(infile, line);
    while (true) {
        getline(infile, line);
        if (line == ".code"){
            break;
        }
        stringstream ss(line);
        ss >> variable >> volue;
        data_list[variable] = volue;
    }

    //MAKING ACTIONS VECTOR WITH COMMANDS TO EXECUTE
    string receiver;
    string source;
    vector<Command*> actions;
    while (true) {
        getline(infile, line);
        if (line == "end"){
            break;
        }
        stringstream ss(line);
        ss >> action >> receiver >> source;
        Command* command = nullptr;

        if (action == "mov") {
            command = new Mov(receiver, source);
        }
        else if (action == "mul") {
            command = new Mul(receiver, source);
        }
        else if (action == "add")
        {
            command = new Add(receiver, source);
        }
        else if (action == "sub")
        {
            command = new Sub(receiver, source);
        }
        else
        {
            command = new WrongCommand(receiver, source);
        }
        actions.push_back(command);
    }

    for (int i = 0; i < actions.size(); ++i) {
        actions[i]->Execute(data_list);
    }
    return data_list["x05"];
}