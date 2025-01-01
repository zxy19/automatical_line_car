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