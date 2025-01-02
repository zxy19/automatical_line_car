#include "debug.h"
tmpBuf _tmpBuf;
Stream *getDebugStream(){
    if(currentDbg == debugClientCount){
        return &INITIAL_STREAM;
    }else{
        if(!clients[currentDbg].connected()){
            currentDbg = debugClientCount;
            return &INITIAL_STREAM;
        }
        return clients+currentDbg;
    }
}