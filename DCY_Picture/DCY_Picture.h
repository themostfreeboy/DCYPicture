
// DCY_Picture.h : DCY_Picture Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CDCY_PictureApp:
// �йش����ʵ�֣������ DCY_Picture.cpp
//

class CDCY_PictureApp : public CWinAppEx
{
public:
	CDCY_PictureApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
protected:
	HMENU  m_hMDIMenu;
	HACCEL m_hMDIAccel;

public:
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	afx_msg void OnFileNew();
	DECLARE_MESSAGE_MAP()
};

extern CDCY_PictureApp theApp;
int JudgeYear(int year);//�ж�ƽ����
int  JudgeMonth(int year,int month);//�ж�ĳ���ж�����
int CalculuteDay(int startyear,int startmonth,int startday,int endyear,int endmonth,int endday);//������������������
int CalculuteDayInOneYear(int year,int month,int day);//����ĳһ����Ϊ����ĵڼ���
int JudgeWeek(int year,int month,int day);//�ж�ĳһ�������ڼ�