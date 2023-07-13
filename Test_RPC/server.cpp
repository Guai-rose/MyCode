#include <iostream>
using namespace std;

#include "Server.h"
using namespace yazi::rpc;

string hello(const string &name)
{
    return "hello, " + name;
}

int main()
{
    Server *server = Singleton<Server>::intstance();
    server->listen("127.0.0.1", 8080);
    server->bind("hello", hello);
    server->start();
    return 0;
}