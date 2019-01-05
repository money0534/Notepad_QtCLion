//
// Created by Shinelon on 2019/1/4.
//

#ifndef SUPERSERIALPORT_APPCONFIG_H
#define SUPERSERIALPORT_APPCONFIG_H

//APP名称、版本
#define APP_NAME "超级串口"
#define APP_VERSION "V1.2"

//上位机指令，模拟软件
#define BRAKE_ON "$BRAKE=1"
#define BRAKE_OFF "$BRAKE=0"
#define OPEN_ON "$OPEN=1"
#define OPEN_OFF "$OPEN=0"

//下位机指令，模拟硬件
#define BRAKE_FRONT "$EVENT=FM"
#define BRAKE_BACK "$EVENT=BM"
#define BRAKE_OVERSPEED "$EVENT=HS"
#define BRAKE_NORMAL "$EVENT=BRAKE"

#define RESP_OK "$OK=CLIENT"

#endif //SUPERSERIALPORT_APPCONFIG_H
