//
// Created by Shinelon on 2019/3/9.
//

#include <stdio.h>
#include "bass.h"

DWORD freq=44100;
DWORD chans=1;
DWORD flags=BASS_DEVICE_16BITS|BASS_DEVICE_MONO;
HWND win=0;

#if 1//录音 实时音频处理

HSTREAM stream;

BOOL CALLBACK RecordProc(HRECORD handle, const void *buffer, DWORD length, void *user)
{
    BASS_StreamPutData(stream, buffer, length); // pass the data to the stream
    return TRUE; // continue recording
}

int main(int argc, char** argv){

    //init
    if(!BASS_Init(-1,freq,0,win,NULL)){
        int ret = BASS_ErrorGetCode();
        printf("init failed,error code:%d",ret);
    }

    stream = BASS_StreamCreate(freq,chans, 0, STREAMPROC_PUSH, NULL); // create a push stream
    HRECORD  rchan;
    if (!BASS_RecordInit(-1) || !(rchan=BASS_RecordStart(freq,chans,MAKELONG(0,10),RecordProc,0))) {//start recording (with 10ms period)
        BASS_RecordFree();
        BASS_Free();
        printf("Can't initialize recording\n");
        return FALSE;
    }
    BASS_ChannelPlay(stream, FALSE); // start the stream

    system("pause");

    BASS_RecordFree();
    BASS_Free();
}

#endif

int main_file(int argc, char** argv){

    printf(">>> BASS test >>>\n");

    //init
    if(!BASS_Init(-1,freq,0,win,NULL)){
        int ret = BASS_ErrorGetCode();
        printf("init failed,error code:%d",ret);
    }

//    BASS_SetVolume(1);//0~1 之间的值

//    DWORD flags=BASS_SAMPLE_LOOP;//0不重复
    DWORD flags=0;//0不重复
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