#include "PriorityQueue.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
int main(int argc, char** argv){
double waitTotal = 0;
fstream file;
string filename(argv [1]);
double threshHold = atoi(argv [2]);
string word;
file.open(filename.c_str());
stringstream ss1,ss2,ss3,ss4;
PriorityQueue prioqueForReq ;
PriorityQueue prioqueForEvent;
string a ;
getline(file,a);
stringstream toInt(a); //convert string to int
int x = 0 ;            // x is total request count
toInt >> x;
int y;
//cout << "x : "<<x << endl;
prioqueForReq.h.items = new Request[x];
prioqueForEvent.h.items = new Request[x];

prioqueForEvent.h.setMaxItems(x);
prioqueForReq.h.setMaxItems(x);

//cout << "Max Item : " << prioqueForReq.getHeap().maxItems << endl;
//cout << "Max Item : " << prioqueForEvent.getHeap().maxItems << endl;

//cout << prioqueForReq.h.size << endl;
int values[4];
int i = 0;
while (file >> word){
    stringstream toInt(word);
    toInt >> y;
    values[i] = y;
    //cout << "Value : " << i <<" "<< values[i] << endl;
    if(i == 3)
    {
        Request add(values[0],values[1],values[2],values[3]);

        prioqueForReq.pqInsertEvent(add);
        i = -1;
    }
    i++;
}
Request req1;
//prioqueForReq.pqDeleteEvent(req1);
//cout << "REq: " << req1.time << endl;
//prioqueForReq.pqDeleteEvent(req1);
//prioqueForReq.pqDeleteEvent(req1);
//prioqueForReq.print();
int cIndex=-1; //Computers are available
string strTemp;
string str = "";
string str1,str2,str3,str4;
int freeComp = 1;
//cout <<"------------------------------"<<endl;
int* compBag = new int[1];
int computerSize;
bool flag = true;
for(computerSize = 1 ; flag || (x == computerSize) ;computerSize++){
    str="";
    waitTotal = 0;
    if(computerSize !=1){
    file.clear();
    file.seekg(0, ios::beg);
    getline(file,a);
    while (file >> word){
    stringstream toInt(word);
    toInt >> y;
    values[i] = y;
    //cout << "Value : " << i <<" "<< values[i] << endl;
    if(i == 3)
    {
        Request add(values[0],values[1],values[2],values[3]);
        //cout << "Request adding" << endl;
        prioqueForReq.pqInsertEvent(add);
        i = -1;
    }
    i++;
}
}
    delete compBag;
    compBag = new int[computerSize];
    for(int i = 0; i < computerSize;i++){
        //cout << "Initialize : -->"<< computerSize << endl;
        compBag[i] = -1;  // Initializing computers
    }
    freeComp = computerSize;
    for(int time = 0; ((prioqueForReq.pqIsEmpty()) && (prioqueForEvent.pqIsEmpty())) == 0  ; time++){
        //cout << "Size: "<< prioqueForReq.h.size << endl;
        for(int i = 0; i < computerSize;i++){
            //cout <<"i: "<<i << endl;
            //cout <<"time: " << time << endl;
            if(time == compBag[i]){
                compBag[i] = -1;
                //cIndex = -1;
                freeComp++;
                }
            //if(i+1 == computerSize && cIndex !=-1)
              //  cIndex = 0;  //Computers are not available
        }
        while(prioqueForReq.getHeap().retrieve().time == time && !prioqueForReq.pqIsEmpty()){
            prioqueForReq.pqDeleteEvent(req1);
            prioqueForEvent.pqInsert(req1);
            //cout << "Added : " << prioqueForEvent.getHeap().retrieve().id << endl;
            //time--;
            }
        //cout << "cIndex : "<< cIndex << endl;
        while(freeComp > 0 && !prioqueForEvent.pqIsEmpty()){
                prioqueForEvent.pqDelete(req1);
                for(int i = 0; i < computerSize;i++){
                        if(compBag[i] == -1){
                            compBag[i] = req1.process + time;
                            cIndex = i ;
                            freeComp--;
                            break;
                            }
                }
                //cout << "Computer "<<cIndex<<" takes request " << req1.id <<" at ms "<< time <<"(wait " << time-req1.time<<" ms)"<< endl;

                ss1 << cIndex;
                str1 = ss1.str();
                ss1.clear();
                ss1.str("");
                ss2 << req1.id;
                str2 = ss2.str();
                ss2.clear();
                ss2.str("");
                ss3 << time;
                str3 = ss3.str();
                ss3.clear();
                ss3.str("");
                ss4 << (time-req1.time);
                str4 = ss4.str();
                ss4.clear();
                ss4.str("");
                strTemp = "Computer "+str1+" takes request " + str2 +" at ms "+ str3 +"(wait "+str4+" ms)";
                //cout << strTemp << endl;
                str = str + strTemp + "\n";
                waitTotal = waitTotal + (time-req1.time);
                }
    }
    //cout << "Average wait time is : " << waitTotal/x << endl;
    if((waitTotal/x) <= threshHold){
        flag = false;
    }
}
    cout << "Minimum number of computers required: " << computerSize-1 << endl;
    cout << "Simulation with  " << computerSize-1 <<" computers"<< endl;
    cout << str << endl;
    cout << "Average wait time is : " << waitTotal/x << endl;

//delete prioqueForEvent.getHeap().items;
//delete prioqueForReq.getHeap().items;

//prioqueForEvent.print();
}
