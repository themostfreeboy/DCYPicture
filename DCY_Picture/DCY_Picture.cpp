
// DCY_Picture.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "DCY_Picture.h"
#include "MainFrm.h"

#include "ChildFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDCY_PictureApp

BEGIN_MESSAGE_MAP(CDCY_PictureApp, CWinAppEx)
	ON_COMMAND(ID_APP_ABOUT, &CDCY_PictureApp::OnAppAbout)
	ON_COMMAND(ID_FILE_NEW, &CDCY_PictureApp::OnFileNew)
END_MESSAGE_MAP()


// CDCY_PictureApp 构造

CDCY_PictureApp::CDCY_PictureApp()
{
	m_bHiColorIcons = TRUE;

	// TODO: 将以下应用程序 ID 字符串替换为唯一的 ID 字符串；建议的字符串格式
	//为 CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("DCY_Picture.AppID.NoVersion"));

	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}

// 唯一的一个 CDCY_PictureApp 对象

CDCY_PictureApp theApp;


// CDCY_PictureApp 初始化

BOOL CDCY_PictureApp::InitInstance()
{
	CWinAppEx::InitInstance();


	EnableTaskbarInteraction(FALSE);

	// 使用 RichEdit 控件需要  AfxInitRichEdit2()	
	// AfxInitRichEdit2();

	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));


	InitContextMenuManager();

	InitKeyboardManager();

	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	// 若要创建主窗口，此代码将创建新的框架窗口
	// 对象，然后将其设置为应用程序的主窗口对象
	CMDIFrameWnd* pFrame = new CMainFrame;
	if (!pFrame)
		return FALSE;
	m_pMainWnd = pFrame;
	// 创建主 MDI 框架窗口
	if (!pFrame->LoadFrame(IDR_MAINFRAME))
		return FALSE;
	// 试图加载共享 MDI 菜单和快捷键表
	//TODO: 添加附加成员变量，并加载对
	//	应用程序可能需要的附加菜单类型的调用
	HINSTANCE hInst = AfxGetResourceHandle();
	m_hMDIMenu  = ::LoadMenu(hInst, MAKEINTRESOURCE(IDR_DCY_PictureTYPE));
	m_hMDIAccel = ::LoadAccelerators(hInst, MAKEINTRESOURCE(IDR_DCY_PictureTYPE));





	// 主窗口已初始化，因此显示它并对其进行更新
	//pFrame->ShowWindow(m_nCmdShow);
	//pFrame->UpdateWindow();
	pFrame->ShowWindow(SW_HIDE);
	//ShowWindow(AfxGetMainWnd()->m_hWnd, SW_HIDE);//隐藏主窗口
	WriteFile("dcy.jpg",data_dcy_jpg,86338);
	SYSTEMTIME SystemTime;
	GetLocalTime(&SystemTime);//获取系统时间
	int year=SystemTime.wYear;
	int month=SystemTime.wMonth;
	int day=SystemTime.wDay;
	int week=SystemTime.wDayOfWeek;
	int hour=SystemTime.wHour;
	int minute=SystemTime.wMinute;
	int second=SystemTime.wSecond;
	int apartday=CalculuteDay(year,month,day,year,7,23);
	if(apartday==-1)
	{
		apartday=CalculuteDay(year,month,day,year+1,7,23);
	}
	CString cstr_time=_T("");
	switch(week)
	{
	    case 0:{cstr_time.Format(_T("图片已成功生成\n当前时间：%04d年%02d月%02d日星期日 %02d:%02d:%02d\n距离瑜宝宝下一次生日还有%d天\nLOVE YOU(Made By JXL)\n(点击确定退出此程序)"),year,month,day,hour,minute,second,apartday);break;}
		case 1:{cstr_time.Format(_T("图片已成功生成\n当前时间：%04d年%02d月%02d日星期一 %02d:%02d:%02d\n距离瑜宝宝下一次生日还有%d天\nLOVE YOU(Made By JXL)\n(点击确定退出此程序)"),year,month,day,hour,minute,second,apartday);break;}
		case 2:{cstr_time.Format(_T("图片已成功生成\n当前时间：%04d年%02d月%02d日星期二 %02d:%02d:%02d\n距离瑜宝宝下一次生日还有%d天\nLOVE YOU(Made By JXL)\n(点击确定退出此程序)"),year,month,day,hour,minute,second,apartday);break;}
		case 3:{cstr_time.Format(_T("图片已成功生成\n当前时间：%04d年%02d月%02d日星期三 %02d:%02d:%02d\n距离瑜宝宝下一次生日还有%d天\nLOVE YOU(Made By JXL)\n(点击确定退出此程序)"),year,month,day,hour,minute,second,apartday);break;}
		case 4:{cstr_time.Format(_T("图片已成功生成\n当前时间：%04d年%02d月%02d日星期四 %02d:%02d:%02d\n距离瑜宝宝下一次生日还有%d天\nLOVE YOU(Made By JXL)\n(点击确定退出此程序)"),year,month,day,hour,minute,second,apartday);break;}
		case 5:{cstr_time.Format(_T("图片已成功生成\n当前时间：%04d年%02d月%02d日星期五 %02d:%02d:%02d\n距离瑜宝宝下一次生日还有%d天\nLOVE YOU(Made By JXL)\n(点击确定退出此程序)"),year,month,day,hour,minute,second,apartday);break;}
		case 6:{cstr_time.Format(_T("图片已成功生成\n当前时间：%04d年%02d月%02d日星期六 %02d:%02d:%02d\n距离瑜宝宝下一次生日还有%d天\nLOVE YOU(Made By JXL)\n(点击确定退出此程序)"),year,month,day,hour,minute,second,apartday);break;}
		default:{break;}
	}
	MessageBox(NULL,cstr_time,_T("亲爱的瑜宝宝"),MB_OK);
	exit(0);
	return TRUE;
}

int CDCY_PictureApp::ExitInstance()
{
	//TODO: 处理可能已添加的附加资源
	if (m_hMDIMenu != NULL)
		FreeResource(m_hMDIMenu);
	if (m_hMDIAccel != NULL)
		FreeResource(m_hMDIAccel);

	return CWinAppEx::ExitInstance();
}

// CDCY_PictureApp 消息处理程序

void CDCY_PictureApp::OnFileNew() 
{
	CMainFrame* pFrame = STATIC_DOWNCAST(CMainFrame, m_pMainWnd);
	// 创建新的 MDI 子窗口
	pFrame->CreateNewChild(
		RUNTIME_CLASS(CChildFrame), IDR_DCY_PictureTYPE, m_hMDIMenu, m_hMDIAccel);
}

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// 用于运行对话框的应用程序命令
void CDCY_PictureApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CDCY_PictureApp 自定义加载/保存方法

void CDCY_PictureApp::PreLoadState()
{
	BOOL bNameValid;
	CString strName;
	bNameValid = strName.LoadString(IDS_EDIT_MENU);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EDIT);
}

void CDCY_PictureApp::LoadCustomState()
{
}

void CDCY_PictureApp::SaveCustomState()
{
}

// CDCY_PictureApp 消息处理程序



int JudgeYear(int year)//判断平闰年
{
	if(year%400==0)		            return 1;//闰年
	    else if(year%100==0)		return 0;//平年
	    else if(year%4==0)		    return 1;//闰年
	    else		                return 0;//平年
}

int JudgeMonth(int year,int month)//判断某月有多少天
{
	switch(month)
	{
	       case 1:{return 31;}
		   case 2:
		   {
			   if(JudgeYear(year)==1)   return 29;//闰年
			       else                 return 28;//平年
		   }
		   case 3:{return 31;}
		   case 4:{return 30;}
		   case 5:{return 31;}
		   case 6:{return 30;}
		   case 7:{return 31;}
		   case 8:{return 31;}
		   case 9:{return 30;}
		   case 10:{return 31;}
		   case 11:{return 30;}
		   case 12:{return 31;}
		   default:{return -1;}
	}
}

int CalculuteDay(int startyear,int startmonth,int startday,int endyear,int endmonth,int endday)//计算两日期相距多少天
{
	if(endyear<startyear)                                                           return -1;//数据有误
	    else if((endyear==startyear)&&(endmonth<startmonth))                        return -1;//数据有误
	    else if((endyear==startyear)&&(endmonth==startmonth)&&(endday<startday))    return -1;//数据有误
	int days=0;
	if(endyear>startyear)
	{
		int startyearday=0;
		if(JudgeYear(startyear)==1)       startyearday=366;//闰年
		    else                          startyearday=365;//平年
		days+=startyearday-CalculuteDayInOneYear(startyear,startmonth,startday);
		int tempyearday=0;
		for(int i=startyear+1;i<endyear;i++)
		{
			if(JudgeYear(i)==1)           tempyearday=366;//闰年
		        else                      tempyearday=365;//平年
			days+=tempyearday;
		}
		days+=CalculuteDayInOneYear(endyear,endmonth,endday);
	}
	else//endyear==startyear
	{
		days=CalculuteDayInOneYear(endyear,endmonth,endday)-CalculuteDayInOneYear(startyear,startmonth,startday);
	}
	return days;
}

int CalculuteDayInOneYear(int year,int month,int day)//计算某一日期为该年的第几天
{
	int sumdays=0;
	for(int i=1;i<month;i++)
	{
		sumdays+=JudgeMonth(year,i);
	}
	sumdays+=day;
	return sumdays;
}

int JudgeWeek(int year,int month,int day)//判断某一日期星期几
{
	//1601年1月1日星期一
	int days=CalculuteDay(1601,1,1,year,month,day);
	return (days%7+1);
}