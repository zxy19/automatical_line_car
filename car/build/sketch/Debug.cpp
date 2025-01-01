#line 1 "D:\\study\\automatical_line_car\\car\\Debug.cpp"
#include "debug.h"
Stream *getDebugStream(){
    if(currentDbg == debugClientCount){
        return &Serial;
    }else{
        if(!clients[currentDbg].connected()){
            currentDbg = debugClientCount;
            return &Serial;
        }
        return clients+currentDbg;
    }
}