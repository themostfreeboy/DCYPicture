
// DCY_Picture.h : DCY_Picture 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CDCY_PictureApp:
// 有关此类的实现，请参阅 DCY_Picture.cpp
//

class CDCY_PictureApp : public CWinAppEx
{
public:
	CDCY_PictureApp();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
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
int JudgeYear(int year);//判断平闰年
int  JudgeMonth(int year,int month);//判断某月有多少天
int CalculuteDay(int startyear,int startmonth,int startday,int endyear,int endmonth,int endday);//计算两日期相距多少天
int CalculuteDayInOneYear(int year,int month,int day);//计算某一日期为该年的第几天
int JudgeWeek(int year,int month,int day);//判断某一日期星期几