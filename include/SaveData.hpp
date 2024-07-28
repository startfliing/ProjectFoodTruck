#ifndef __SAVE_DATA__
#define __SAVE_DATA__

struct SaveData{
    int x;
    int y;
};

SaveData loadSaveData();

void saveSaveData(SaveData sd);

void resetSaveData();

#endif