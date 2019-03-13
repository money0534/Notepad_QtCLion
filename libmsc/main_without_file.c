/*
* 语音合成（Text To Speech，TTS）技术能够自动将任意文字实时转换为连续的
* 自然语音，是一种能够在任何时间、任何地点，向任何人提供语音信息服务的
* 高效便捷手段，非常符合信息时代海量数据、动态更新和个性化查询的需求。
*/

#include <stdio.h>
#include "qtts.h"
#include "msp_types.h"
#include "msp_errors.h"
#include "msp_cmn.h"
#include <memory.h>
#include <mem.h>
#include <stdlib.h>

/*
 https://en.wikipedia.org/wiki/WAV
 Specification RIFF chunk
 https://en.wikipedia.org/wiki/Resource_Interchange_File_Format
 */
/* wav音频头部格式 44 bytes in total*/
typedef struct _wave_pcm_hdr {
    // RIFF Header
    char riff[4];//4                // = "RIFF"
    int size_8;//4                 // = FileSize - 8
    char wave[4];//4                // = "WAVE"

    // Format Header
    char fmt[4];//4                 // = "fmt "
    int fmt_size;//4                // = 下一个结构体的大小 : 16
    short int format_tag;//2             // = PCM : 1；其他值非PCM http://www.lightlink.com/tjweber/StripWav/WAVE.html
    short int channels;//2               // = 通道数 : 1
    int samples_per_sec;//4        // = 采样率 : 8000 | 6000 | 11025 | 16000
    int avg_bytes_per_sec;//4      // = 每秒字节数 : samples_per_sec * bits_per_sample / 8
    short int block_align;//2            // = 每采样点字节数 : wBitsPerSample / 8
    short int bits_per_sample;//2        // = 量化比特数: 8 | 16

    // Data
    char data[4];//4                // = "data";
    int data_size;//4              // = 纯数据长度 : FileSize - 44
} wave_pcm_hdr;

/* 默认wav音频头部数据 */
wave_pcm_hdr default_wav_hdr =
        {
                {'R', 'I', 'F', 'F'},
                0,
                {'W', 'A', 'V', 'E'},
                {'f', 'm', 't', ' '},
                16,
                1,
                1,
                16000,
                32000,
                2,
                16,
                {'d', 'a', 't', 'a'},
                0
        };

void set_value(void * data, void * value, size_t size, int index){
    void * position = (char*)data + index*size;
    memcpy(position, value, size);
}

// 头大小
#define HEADER_SIZE 44
size_t total_len=HEADER_SIZE;


void print_header(char* fp){
    printf("0:%s\n",&fp[0]);//char *
    printf("4:%d\n",fp[4]);
    printf("8:%s\n",&fp[8]);//char *
    printf("12:%s\n",&fp[12]);//char *
    printf("16:%d\n",fp[16]);
    printf("20:%hd\n",(short)fp[20]);
    printf("22:%hd\n",(short)fp[22]);
    printf("24:%d\n",(int)fp[24]);
    printf("28:%d\n",(int)fp[28]);
    printf("32:%hd\n",(short)fp[32]);
    printf("34:%hd\n",(short)fp[34]);
    printf("36:%s\n",&fp[36]);//char *
    printf("40:%d\n",fp[40]);
}

int main_char_ptr(){
    printf("malloc test start >>>\n");
    char * fp = malloc(total_len);
    unsigned int audio_len = 0;
    wave_pcm_hdr wav_hdr = default_wav_hdr;
    fp=(char *)&wav_hdr;

    print_header(fp);


    system("pause");
    free(fp);
    printf("malloc test end >>>\n");

}


/**
 * 文本合成
 * @param src_text 合成文本
 * @param params 合成参数
 * @return ret 合成结果 0成功，-1失败
 */
int text_to_speech(const char *src_text, const char *params) {
    int ret = -1;
    //todo 先开辟WAV头文件的大小
    char * fp = malloc(HEADER_SIZE);
    const char *sessionID = NULL;
    unsigned int audio_len = 0;
    wave_pcm_hdr wav_hdr = default_wav_hdr;
    int synth_status = MSP_TTS_FLAG_STILL_HAVE_DATA;

    /* 开始合成 */
    sessionID = QTTSSessionBegin(params, &ret);
    if (MSP_SUCCESS != ret) {
        printf("QTTSSessionBegin failed, error code: %d.\n", ret);
        free(fp);
        return ret;
    }
    ret = QTTSTextPut(sessionID, src_text, (unsigned int) strlen(src_text), NULL);
    if (MSP_SUCCESS != ret) {
        printf("QTTSTextPut failed, error code: %d.\n", ret);
        QTTSSessionEnd(sessionID, "TextPutError");
        free(fp);
        return ret;
    }
    printf("正在合成 ...\n");
//    fwrite(&wav_hdr, sizeof(wav_hdr), 1, fp); //添加wav音频头，使用采样率为16000
    while (1) {
        /* 获取合成音频 */
        const void *data = QTTSAudioGet(sessionID, &audio_len, &synth_status, &ret);
        if (MSP_SUCCESS != ret)
            break;
        if (NULL != data) {
            fp = realloc(fp,total_len+audio_len);
            /*
            buffer	-	pointer to the first object in the array to be written
            size	-	size of each object
            count	-	the number of the objects to be written
            stream	-	pointer to the output stream
             */
//            fwrite(data, audio_len, 1, fp);
//            memcpy(data,fp,)
            //纯数据大小，每次返回的数据 累加到大小
            wav_hdr.data_size += audio_len; //计算data_size大小
            fp[total_len] = *((char*)data);
            total_len+=audio_len;

        }
        if (MSP_TTS_FLAG_DATA_END == synth_status)
            break;
    }
    printf("\n");
    if (MSP_SUCCESS != ret) {
        printf("QTTSAudioGet failed, error code: %d.\n", ret);
        QTTSSessionEnd(sessionID, "AudioGetError");
        free(fp);
        return ret;
    }
    /* 修正wav文件头数据的大小 */
    /*
     这里结构体大小-8? 本身占用4 bytes，跳过8 bytes之后所有数据的大小。
     Size of the wav portion of the file, which follows the first 8 bytes
     参考 http://www.lightlink.com/tjweber/StripWav/Canon.html
     */
    wav_hdr.size_8 += wav_hdr.data_size + (sizeof(wav_hdr) - 8);

    char * header=(char *)&wav_hdr;
    memcpy(fp,header,HEADER_SIZE);
    print_header(fp);



    //释放
    free(fp);
    fp = NULL;
    /* 合成完毕 */
    ret = QTTSSessionEnd(sessionID, "Normal");
    if (MSP_SUCCESS != ret) {
        printf("QTTSSessionEnd failed, error code: %d.\n", ret);
    }


    return ret;
}


int main(int argc, char *argv[]) {
    int ret = MSP_SUCCESS;
    const char *login_params = "appid = 5b9f21b7, work_dir = .";//登录参数,appid与msc库绑定,请勿随意改动
    /*
    * rdn:           合成音频数字发音方式
    * volume:        合成音频的音量
    * pitch:         合成音频的音调
    * speed:         合成音频对应的语速
    * voice_name:    合成发音人
    * sample_rate:   合成音频采样率
    * text_encoding: 合成文本编码格式
    *
    */
    const char *session_begin_params = "engine_type = local, voice_name = xiaoyan, text_encoding = utf-8, tts_res_path = fo|res\\tts\\xiaoyan.jet;fo|res\\tts\\common.jet, sample_rate = 16000, speed = 50, volume = 50, pitch = 50, rdn = 2";
    const char *text = "您好，请关好车门"; //合成文本
    /* 用户登录 */
    ret = MSPLogin(NULL, NULL,
                   login_params); //第一个参数是用户名，第二个参数是密码，第三个参数是登录参数，用户名和密码可在http://www.xfyun.cn注册获取
    if (MSP_SUCCESS != ret) {
        printf("MSPLogin failed, error code: %d.\n", ret);
        goto exit;//登录失败，退出登录
    }

    /* 文本合成 */
    printf("start tts ...\n");
    ret = text_to_speech(text, session_begin_params);
    if (MSP_SUCCESS != ret) {
        printf("text_to_speech failed, error code: %d.\n", ret);
    }
    printf("tts done!\n");

    exit:
    system("pause");
    MSPLogout(); //退出登录

    return 0;
}
