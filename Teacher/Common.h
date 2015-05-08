#pragma once
#include <wtypesbase.h>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")
//#include <windows.h>
//#include "MySocket.h"
//#include "ScreenDlg.h"
//#include "zlib.h"
// #include "zconf.h"
// #pragma comment(lib,"zdll.lib")
#define SCREEN_TRANS_SIZE (20*1024)
#define MULTICAST_TRANS_SIZE (50*1024)
#define LISTEN_PORT 8000
#define SCREEN_TRANS_PORT 8010
#define MULTICAST_IP "224.0.0.210"
#define MULTICAST_TRANS_PORT 8030
// �ܹ�ͬʱ����Ļ��ص�ѧ����������
#define  MAX_MONITOR 16
//#define DISKINFO_TRANS_PORT 8020
//#define DISKDOWNLOAD_TRANS_PORT 8030
#define MAX_LISTEN  200

#define SYSINFO  0x01
#define DISKINFO 0x02
#define FILELIST 0x03
#define DOWNLOAD 0x04
#define UPLOAD 0x05
#define FILEDATA 0x06
#define RUNEXE 0x07
#define DELFILE 0x08
#define NEWDIR 0x09
#define CMDSHELL 0x0A
#define COMMAND 0x0B
#define TASKLIST 0x0C
#define TASKKILL 0x0D
#define SCREENDATA 0x0E
#define SCREENINFO 0x10
#define SCREENTRANEND 0x11
#define MULTICASTBEGIN 0x20
#define MULTICASTINFO 0x21
#define MULTICASTEND 0X22
#define MULTICAST 0x23



#define ID_ONLINE WM_USER + 1
#define ID_OFFLINE WM_USER + 2
#define ID_SETBMPDATA WM_USER + 3
#define ID_MONITOREND WM_USER + 4
#define ID_ONESTUINSCREEN WM_USER + 5
#define ID_SETONESTUBMPDATA WM_USER + 6
#define ID_ONESTUINSCREENEND  WM_USER + 7

// typedef struct tagMSGINFO //������Ϣ�ṹ��
// {
// 	int Msg_id;
// 	BYTE context[1024 * 4];
// }MSGINFO;
typedef struct tagITEMDATA
{
	LPVOID screenDlg;
	LPVOID multicastDlg;
}ITEMDATA;


typedef struct tagMSGTYPE
{
	int msgID;
//	bool flag;// ��־λ�����ڽ�����ʼ���ж�
}MSGTYPE;

typedef struct tagSTUINFO
{
	// ѧ������
	TCHAR m_stuName[20];
	// ѧ���İ༶
	TCHAR m_stuClass[20];
	// ѧ����ѧ��
	TCHAR m_stuID[20];
	// ѧ����רҵ
	TCHAR m_stuMajor[20];
}STUINFODATA;

typedef struct tagSYSTEMINFO
{
	int os;
//	bool Cam; //����ͷ
	double ver;
}SYSTEMINFO;


typedef struct tagBMPHEADINFO
{
//	int imgTotalSize;
	//	int HeadSize;
	unsigned long bmpCompressSize;
	BITMAPINFO bmpHeadInfo;
}BMPINFO;

typedef struct tagBMPDATA
{
	bool isShow; // �Ƿ������ʾͼ��
	int infoType;
	UINT beginPos;
//	int ID;
	unsigned long bmpCompressSize;
	BITMAPINFO bmpHeadInfo;
	BYTE transData[SCREEN_TRANS_SIZE];
}BMPDATA;

typedef struct tagMULTICAST
{
	bool isShow; // �Ƿ������ʾͼ��
	int infoType;    
	UINT beginPos;
	int ID;      // һ����Ļ���ݵĵڼ��δ���
	unsigned long bmpCompressSize;
	BITMAPINFO bmpHeadInfo;
	BYTE transData[MULTICAST_TRANS_SIZE];
}MULTICASTDATA;

typedef struct tagBMP
{
	BYTE* pBmpCompressData;
	BITMAPINFO* pBMPINFO;
	unsigned long bmpCompressSize;
}BMP;