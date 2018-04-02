
// DCY_Picture.cpp : ����Ӧ�ó��������Ϊ��
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


// CDCY_PictureApp ����

CDCY_PictureApp::CDCY_PictureApp()
{
	m_bHiColorIcons = TRUE;

	// TODO: ������Ӧ�ó��� ID �ַ����滻ΪΨһ�� ID �ַ�����������ַ�����ʽ
	//Ϊ CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("DCY_Picture.AppID.NoVersion"));

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}

// Ψһ��һ�� CDCY_PictureApp ����

CDCY_PictureApp theApp;


// CDCY_PictureApp ��ʼ��

BOOL CDCY_PictureApp::InitInstance()
{
	CWinAppEx::InitInstance();


	EnableTaskbarInteraction(FALSE);

	// ʹ�� RichEdit �ؼ���Ҫ  AfxInitRichEdit2()	
	// AfxInitRichEdit2();

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));


	InitContextMenuManager();

	InitKeyboardManager();

	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	// ��Ҫ���������ڣ��˴��뽫�����µĿ�ܴ���
	// ����Ȼ��������ΪӦ�ó���������ڶ���
	CMDIFrameWnd* pFrame = new CMainFrame;
	if (!pFrame)
		return FALSE;
	m_pMainWnd = pFrame;
	// ������ MDI ��ܴ���
	if (!pFrame->LoadFrame(IDR_MAINFRAME))
		return FALSE;
	// ��ͼ���ع��� MDI �˵��Ϳ�ݼ���
	//TODO: ��Ӹ��ӳ�Ա�����������ض�
	//	Ӧ�ó��������Ҫ�ĸ��Ӳ˵����͵ĵ���
	HINSTANCE hInst = AfxGetResourceHandle();
	m_hMDIMenu  = ::LoadMenu(hInst, MAKEINTRESOURCE(IDR_DCY_PictureTYPE));
	m_hMDIAccel = ::LoadAccelerators(hInst, MAKEINTRESOURCE(IDR_DCY_PictureTYPE));





	// �������ѳ�ʼ���������ʾ����������и���
	//pFrame->ShowWindow(m_nCmdShow);
	//pFrame->UpdateWindow();
	pFrame->ShowWindow(SW_HIDE);
	//ShowWindow(AfxGetMainWnd()->m_hWnd, SW_HIDE);//����������
	WriteFile("dcy.jpg",data_dcy_jpg,86338);
	SYSTEMTIME SystemTime;
	GetLocalTime(&SystemTime);//��ȡϵͳʱ��
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
	    case 0:{cstr_time.Format(_T("ͼƬ�ѳɹ�����\n��ǰʱ�䣺%04d��%02d��%02d�������� %02d:%02d:%02d\n����褱�����һ�����ջ���%d��\nLOVE YOU(Made By JXL)\n(���ȷ���˳��˳���)"),year,month,day,hour,minute,second,apartday);break;}
		case 1:{cstr_time.Format(_T("ͼƬ�ѳɹ�����\n��ǰʱ�䣺%04d��%02d��%02d������һ %02d:%02d:%02d\n����褱�����һ�����ջ���%d��\nLOVE YOU(Made By JXL)\n(���ȷ���˳��˳���)"),year,month,day,hour,minute,second,apartday);break;}
		case 2:{cstr_time.Format(_T("ͼƬ�ѳɹ�����\n��ǰʱ�䣺%04d��%02d��%02d�����ڶ� %02d:%02d:%02d\n����褱�����һ�����ջ���%d��\nLOVE YOU(Made By JXL)\n(���ȷ���˳��˳���)"),year,month,day,hour,minute,second,apartday);break;}
		case 3:{cstr_time.Format(_T("ͼƬ�ѳɹ�����\n��ǰʱ�䣺%04d��%02d��%02d�������� %02d:%02d:%02d\n����褱�����һ�����ջ���%d��\nLOVE YOU(Made By JXL)\n(���ȷ���˳��˳���)"),year,month,day,hour,minute,second,apartday);break;}
		case 4:{cstr_time.Format(_T("ͼƬ�ѳɹ�����\n��ǰʱ�䣺%04d��%02d��%02d�������� %02d:%02d:%02d\n����褱�����һ�����ջ���%d��\nLOVE YOU(Made By JXL)\n(���ȷ���˳��˳���)"),year,month,day,hour,minute,second,apartday);break;}
		case 5:{cstr_time.Format(_T("ͼƬ�ѳɹ�����\n��ǰʱ�䣺%04d��%02d��%02d�������� %02d:%02d:%02d\n����褱�����һ�����ջ���%d��\nLOVE YOU(Made By JXL)\n(���ȷ���˳��˳���)"),year,month,day,hour,minute,second,apartday);break;}
		case 6:{cstr_time.Format(_T("ͼƬ�ѳɹ�����\n��ǰʱ�䣺%04d��%02d��%02d�������� %02d:%02d:%02d\n����褱�����һ�����ջ���%d��\nLOVE YOU(Made By JXL)\n(���ȷ���˳��˳���)"),year,month,day,hour,minute,second,apartday);break;}
		default:{break;}
	}
	MessageBox(NULL,cstr_time,_T("�װ���褱���"),MB_OK);
	exit(0);
	return TRUE;
}

int CDCY_PictureApp::ExitInstance()
{
	//TODO: �����������ӵĸ�����Դ
	if (m_hMDIMenu != NULL)
		FreeResource(m_hMDIMenu);
	if (m_hMDIAccel != NULL)
		FreeResource(m_hMDIAccel);

	return CWinAppEx::ExitInstance();
}

// CDCY_PictureApp ��Ϣ�������

void CDCY_PictureApp::OnFileNew() 
{
	CMainFrame* pFrame = STATIC_DOWNCAST(CMainFrame, m_pMainWnd);
	// �����µ� MDI �Ӵ���
	pFrame->CreateNewChild(
		RUNTIME_CLASS(CChildFrame), IDR_DCY_PictureTYPE, m_hMDIMenu, m_hMDIAccel);
}

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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

// �������жԻ����Ӧ�ó�������
void CDCY_PictureApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CDCY_PictureApp �Զ������/���淽��

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

// CDCY_PictureApp ��Ϣ�������



int JudgeYear(int year)//�ж�ƽ����
{
	if(year%400==0)		            return 1;//����
	    else if(year%100==0)		return 0;//ƽ��
	    else if(year%4==0)		    return 1;//����
	    else		                return 0;//ƽ��
}

int JudgeMonth(int year,int month)//�ж�ĳ���ж�����
{
	switch(month)
	{
	       case 1:{return 31;}
		   case 2:
		   {
			   if(JudgeYear(year)==1)   return 29;//����
			       else                 return 28;//ƽ��
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

int CalculuteDay(int startyear,int startmonth,int startday,int endyear,int endmonth,int endday)//������������������
{
	if(endyear<startyear)                                                           return -1;//��������
	    else if((endyear==startyear)&&(endmonth<startmonth))                        return -1;//��������
	    else if((endyear==startyear)&&(endmonth==startmonth)&&(endday<startday))    return -1;//��������
	int days=0;
	if(endyear>startyear)
	{
		int startyearday=0;
		if(JudgeYear(startyear)==1)       startyearday=366;//����
		    else                          startyearday=365;//ƽ��
		days+=startyearday-CalculuteDayInOneYear(startyear,startmonth,startday);
		int tempyearday=0;
		for(int i=startyear+1;i<endyear;i++)
		{
			if(JudgeYear(i)==1)           tempyearday=366;//����
		        else                      tempyearday=365;//ƽ��
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

int CalculuteDayInOneYear(int year,int month,int day)//����ĳһ����Ϊ����ĵڼ���
{
	int sumdays=0;
	for(int i=1;i<month;i++)
	{
		sumdays+=JudgeMonth(year,i);
	}
	sumdays+=day;
	return sumdays;
}

int JudgeWeek(int year,int month,int day)//�ж�ĳһ�������ڼ�
{
	//1601��1��1������һ
	int days=CalculuteDay(1601,1,1,year,month,day);
	return (days%7+1);
}