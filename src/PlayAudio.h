//
// Created by Shinelon on 2019/2/27.
//

#ifndef MAINTENANCETOOL_PLAYAUDIO_H
#define MAINTENANCETOOL_PLAYAUDIO_H

#include <QtCore/QFile>
#include <QAudioOutput>
#include <QAudioFormat>
#include <QAudioDeviceInfo>
#include <QtGlobal>
#include <iostream>

void play_audio(){
    QFile sourceFile;   // class member.
    QAudioOutput* audio; // class member.
    {
        sourceFile.setFileName("tts_sample.wav");
        sourceFile.open(QIODevice::ReadOnly);

        QAudioFormat format;
        // Set up the format, eg.
        format.setSampleRate(32000);
        format.setChannelCount(1);
        format.setSampleSize(8);
        format.setCodec("audio/pcm");
        format.setByteOrder(QAudioFormat::LittleEndian);
        format.setSampleType(QAudioFormat::UnSignedInt);

        QAudioDeviceInfo info(QAudioDeviceInfo::defaultOutputDevice());
        if (!info.isFormatSupported(format)) {
            std::cout<<"Raw audio format not supported by backend, cannot play audio."<<std::endl;
            return;
        }

        audio = new QAudioOutput(format);
//        connect(audio, SIGNAL(stateChanged(QAudio::State)),this, SLOT(handleStateChanged(QAudio::State)));
        audio->start(&sourceFile);
    }
}

#endif //MAINTENANCETOOL_PLAYAUDIO_H
