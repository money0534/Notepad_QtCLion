//
// Created by Shinelon on 2019/3/9.
//

#include <stdio.h>
#include "bass.h"

DWORD freq=44100;
DWORD flags=BASS_DEVICE_16BITS|BASS_DEVICE_MONO;
HWND win=0;


int main(int argc, char** argv){

    printf(">>> BASS test >>>\n");

    //init
    if(!BASS_Init(-1,freq,0,win,NULL)){
        int ret = BASS_ErrorGetCode();
        printf("init failed,error code:%d",ret);
    }

//    BASS_SetVolume(1);//0~1 之间的值

    DWORD flags=BASS_SAMPLE_LOOP;//0不重复
    HSTREAM hstream =  BASS_StreamCreateFile(FALSE,"tts_sample.wav",0,0,flags);

//    HSTREAM hstream=BASS_StreamCreateFile(FALSE, "beat it.mp3", 0, 0,BASS_SAMPLE_LOOP);


    int ret = BASS_ChannelPlay(hstream,FALSE);
    printf("play,error code:%d",ret);

    system("pause");

    //release
    if(!BASS_Free()){
        int ret = BASS_ErrorGetCode();
        printf("release failed,error code:%d",ret);
    }
}