
// TeacherDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "zlib.h"
#include "zconf.h"
#pragma comment(lib,"zdll.lib")
#include "ScreenDlg.h"
#include "Multicast.h"

// �����ID ���빤��������ʱ��ֵ��ID �Ƕ�Ӧ��
#define ID_MULTICAST 1001
#define ID_SCREEN	 1002

// CTeacherDlg �Ի���
class CTeacherDlg : public CDialogEx
{
// ����
public:
	CTeacherDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_TEACHER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	static DWORD WINAPI OnScreenSocketAccept(LPVOID self);
	void ScreenSocketAccept();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	void UpdateMain(int port);
	void OnFileManager();
//	DWORD WINAPI OnMsgListen(LPVOID self);
	bool MsgListen();
	static DWORD WINAPI OnMsgListen(LPVOID self);
	afx_msg LRESULT OnAddStu(WPARAM wparam, LPARAM lparam);
	afx_msg LRESULT OnOffStu(WPARAM wparam, LPARAM lparam);
	LRESULT OnSetBmpCompressData(WPARAM wparam, LPARAM lparam);
	LRESULT OnMonitorEnd(WPARAM wparam, LPARAM lparam);
	LRESULT OnOneStuInScreen(WPARAM wparam, LPARAM lparam);
	LRESULT OnSetOneStuBmpCompData(WPARAM wparam, LPARAM lparam);
	LRESULT OnOneStuInScreenEnd(WPARAM wparam, LPARAM lparam);
	void OnScreen();
	void OnMulticast();
	static DWORD WINAPI OnSendScreenData(LPVOID self);
	void SendScreenData();
	void ShowStuInfo();
private:
	CListCtrl m_list;
	CImageList m_imagelist;
	CToolBar m_toolBar;
	CStatusBar m_statusbar;
	CRect m_rect;
//	CMulticast m_multicast;
	SOCKET m_msgSocket;
//	CScreenDlg* m_pScreenDlg[MAX_LISTEN];
	CScreenDlg* m_pScreenDlg;
	// ��¼����ص�ѧ������ID
	int m_item[MAX_MONITOR];
//	CMulticast m_multicast;
	COneStuScreenDlg* m_oneStuScreenDlg;
	CMulticast m_multicast;
public:
//	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnDestroy();
};
