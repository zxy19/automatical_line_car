#line 1 "C:\\Users\\18668\\Desktop\\automatical_line_car\\car\\Debug.cpp"
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