//
// Created by Ivan on 25.02.22.
//

#ifndef LAB_13_COMMAND_H
#define LAB_13_COMMAND_H
#include <string>
#include <map>
#include <utility>
#include <iostream>
#include "spdlog/spdlog.h"

class Command {
protected:
    const std::string receiver_;
    const std::string source_;
public:
    Command() = default;
    Command(std::string receiver, std::string source): receiver_(std::move(receiver)), source_(std::move(source)){}
    virtual void Execute(std::map<std::string, int>& data) = 0;
};

class Add:public Command{
public:
    Add(std::string receiver, std::string source) : Command(receiver, source) {}
    virtual void Execute(std::map<std::string, int>& data) override {
        int tmp = data[source_];
        data[receiver_] = data[receiver_] + tmp;
    }
};

class Mul:public Command{
public:
    Mul(std::string receiver, std::string source) : Command(receiver, source) {}
    virtual void Execute(std::map<std::string, int>& data) override {
        int tmp = data[source_];
        data[receiver_] = data[receiver_] * tmp;
    }
};

class Mov:public Command{
public:
    Mov(std::string receiver, std::string source) : Command(receiver, source) {}
    virtual void Execute(std::map<std::string, int>& data) override {
        spdlog::debug("Moving tmp = {:08d}", data[source_]);
        data[receiver_] = data[source_];
    }
};
class Sub :public Command {
public:
    Sub(std::string receiver, std::string source) : Command(receiver, source) {}
    virtual void Execute(std::map<std::string, int>& data) override {
        int tmp = data[source_];
        data[receiver_] = data[receiver_] - tmp;
    }
};
class WrongCommand :public Command {
public:
    virtual void Execute(std::map<std::string, int>& data)override {};
    WrongCommand(std::string receiver, std::string source){
        std::cout << "Error: Command undefined";
        throw std::logic_error("unknown command");
    }

};


#endif //LAB_13_COMMAND_H
