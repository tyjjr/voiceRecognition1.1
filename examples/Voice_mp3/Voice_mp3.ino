/*============================================================

Voice_mp3.ino——Voice Recognition模块样例程序
上海智位机器人有限公司 版权所有
http://www.dfrobot.com.cn
2014-8-11

===========================================================*/
#include <VoiceRecognition.h>
#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>//加载MP3模块库文件

VoiceRecognition Voice;

void setup() {
    Serial.begin(9600);
    mp3_set_serial (Serial);	//设置MP3模块通讯方式
    mp3_set_volume (15);//音量调节
    
    Voice.init();//初始化VoiceRecognition模块
    
    Voice.micVol(85);//麦克风放大增益，参数（10-100）默认85
    Voice.speechEndpoint(15);//语音/背噪对比度,参数（10-50），默认15
    Voice.speechStartTime(8);//背噪-语音辨别时间，参数（00~50）单位10MS，默认80ms
    Voice.speechEndTime(15);//语音-背噪辨别时间，参数（00~200）单位10MS，默认150ms
    Voice.voiceMaxLength(200);//最长语音段时间，参数（0~200）单位100MS,默认20s
    Voice.noiseTime(2);//上电噪声忽略时间，参数（00~255）单位20ms,默认40ms
    
    Voice.addCommand("bo fang",0);//添加指令，参数（指令内容，指令标签（可重复））
    Voice.addCommand("ting zhi",1);//添加指令，参数（指令内容，指令标签（可重复））

	Voice.start();//开始识别
}
void loop() {
  // put your main code here, to run repeatedly:
  // Serial.println(Voice.ASR(2,80,sRecog));
  switch(Voice.read())//判断识别内容，在有识别结果的情况下Voice.Read()会返回该指令标签，否则返回-1
  {
    case 0://若是指令“bo fang”
    	mp3_play (4);

    break;
    case 1://若是指令“ting zhi”
    	mp3_stop ();
    break;   
  }
}
