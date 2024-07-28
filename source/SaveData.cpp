#include "SaveData.hpp"
#include "tonc.h"

SaveData loadSaveData(){
    u8* current = sram_mem;
    SaveData sd;
    int ii = 0;
    sd.x = (current[ii]<<24) + (current[ii+1]<<16) + (current[ii+2]<<8) + (current[ii+3]);
    ii += 4;
    sd.y = (current[ii]<<24) + (current[ii+1]<<16) + (current[ii+2]<<8) + (current[ii+3]);
    return sd;
}

void saveSaveData(SaveData sd){
    u8* current = sram_mem;
    for(int i = 3; i >= 0; i--){
        *current++ = (u8)sd.x>>(i * 8);
    }
    for(int i = 3; i >= 0; i--){
        *current++ = (u8)sd.y>>(i * 8);
    }
}

void resetSaveData(){
    u8* current = sram_mem;
    for(int i = 3; i >= 0; i--){
        *current++ = 0;
    }
    for(int i = 3; i >= 0; i--){
        *current++ = 0;
    }
}