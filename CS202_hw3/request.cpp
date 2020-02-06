#include "request.h"
Request::Request():id(0),priority(0),time(0),process(0){
}
Request::Request(int id, int priority, int time, int process) : id(id),priority(priority),time(time),process(process){
}
Request::~Request(){

}

