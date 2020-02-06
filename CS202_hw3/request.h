#ifndef __REQUEST_H
#define __REQUEST_H
#include <string>

class Request{
public:
    Request();
    Request(int id, int priority,int time,int process);
    ~Request();
    int id,priority,time,process;
};
#endif // __NGRAMTREE_H

