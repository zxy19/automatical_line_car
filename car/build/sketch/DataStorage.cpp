#line 1 "C:\\Users\\18668\\Desktop\\automatical_line_car\\car\\DataStorage.cpp"
#include "DataStorage.h"
#include "Debug.h"
int data_storage::DATA[data_storage::MAX_DATA_SIZE];
bool data_storage::modified[data_storage::MAX_DATA_SIZE];
int data_storage::getData(int index) {
    if (index >= data_storage::MAX_DATA_SIZE)
        return 0;
    if (index < 0)
        return 0;
#ifdef DEBUG
    getDebugStream()->printf("getData(%d) = %d\n", index, DATA[index]);
#endif
    return DATA[index];
}

void data_storage::setData(int index, int value, bool persist) {
    if (index >= data_storage::MAX_DATA_SIZE)
        return;
    if (index < 0)
        return;
#ifdef DEBUG
    getDebugStream()->printf("setData(%d, %d)\n", index, value);
#endif
    DATA[index] = value;
    modified[index] = true;
    if (persist)
        data_storage::persist();
}

void data_storage::init() {
    EEPROM.begin(data_storage::MAX_DATA_SIZE * 4 + 1);
    if (EEPROM.read(0) != data_storage::DATA_VERSION) {
        for (int i = 0; i < data_storage::MAX_DATA_SIZE; i++) {
            DATA[i] = 0;
            modified[i] = true;
        }
        persist();
        EEPROM.write(0, data_storage::DATA_VERSION);
        EEPROM.commit();
        return;
    }
    for (int i = 0; i < data_storage::MAX_DATA_SIZE; i++) {
        int temp = 0;
        temp = ((int)EEPROM.read(1 + i * 4)) + (((int)EEPROM.read(1 + i * 4 + 1)) << 8) + (((int)EEPROM.read(1 + i * 4 + 2)) << 16) + (((int)EEPROM.read(1 + i * 4 + 3)) << 24);
        DATA[i] = temp;
        modified[i] = false;
    }
}
void data_storage::persist() {
    bool isModified = false;
    for (int i = 0; i < data_storage::MAX_DATA_SIZE; i++) {
        if (modified[i]) {
            isModified = true;
            EEPROM.write(1 + i * 4 + 0, (DATA[i]) & 0xff);
            EEPROM.write(1 + i * 4 + 1, (DATA[i] >> 8) & 0xff);
            EEPROM.write(1 + i * 4 + 2, (DATA[i] >> 16) & 0xff);
            EEPROM.write(1 + i * 4 + 3, (DATA[i] >> 24) & 0xff);
            modified[i] = false;
        }
    }
    if (isModified)
        EEPROM.commit();
}
void data_storage::setDefaultIfZero(int index,int value){
    if (DATA[index] == 0)
        DATA[index] = value;
    persist();
}