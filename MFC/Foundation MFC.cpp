#include <afxwin.h> // 헤더파일

// --- 클래스 선언부 ---

// 응용프로그램 클래스 선언, 시작하면 숨어져있는 메인클래스가 이 클래스를 선언한 객체를 찾아서 실행할 것이다.
class CHelloApp : public CWinApp { // CWinApp 클래스는 응용 프로그램의 초기화 코드, 메시지 루프, 종료코드를 제공한다.
public:
	virtual BOOL InitInstance(); // 생성자가 실행되면 바로 InitInstance 함수를 실행한다.(virtual 재정의)
};

// 메인 윈도우 클래스를 선언, 앞으로 CWinApp을 상속한 CHelloApp이 윈도우를 해당 클래스의 객체로 사용할 것이다.
class CMainFrame : public CFrameWnd { // CFrameWnd는 윈도우의 실제 기능을 담당할 것이다.
public:
	CMainFrame(); // 생성자로 SDK의 CreateWindow역할을 할 것이다.
protected: 
	// 메시지 핸들러들을 재정의하는데, afx_msg는 해당 함수가 메시지핸들러라는 메크로이다.
	afx_msg void OnPaint(); // 윈도우 화면 그리기
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point); // 왼쪽 마우스 클릭했을 때
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags); // 키가 눌렸을 때
	DECLARE_MESSAGE_MAP(); // 아직 정확한 기능은 모르겠음, 메시지 맵(프로시저)와 관련이 있음
};

// --- *** ---

// --- 응용 프로그램 객체 ---
CHelloApp theFirstApp; 
// 디버깅하면 해당 객체를 찾아서 할당되며, 실행이 된다.
// 객체의 이름은 중요하지않고, 전역 객체가 오직 한개만 있어야 한다.
// --- *** ---

// --- 클래스 정의부 ---

// MFC 내부에 숨겨진 WinMain은 CWinApp의 객체를 찾아서 생성자로 이 함수를 가장 먼저 실행한다.
BOOL CHelloApp::InitInstance() { // 반대의 함수로(종료시)는 ExitInstance가 존재한다.
	m_pMainWnd = new CMainFrame; // CWinApp의 메인 윈도우를 CMainFrame으로 한다.
	m_pMainWnd->ShowWindow(m_nCmdShow); // SDK와 마찬가지로, 윈도우의 형태를 설정한다.
	// ShowWindow -> SW
	// SW_SHOWNORMAL : 일반적인 형태로 나타냄
	// SW_SHWMAXIMIZED : 최대화 모드 형태로 나타냄
	// SW_SHOWMINIMIZE : 최대화 모드 형태로 나타냄
	// SW_HIDE : 화면에 나타나지 않는 형태
	// 위 함수처럼 m_nCmdShow로 CWinApp의 멤버함수로 그대로 사용할 수도 있다.
	return true; // 초기화 작업 후 반드시 true로 리턴해야 한다. FALSE면 프로그램이 종료된다.
}

CMainFrame::CMainFrame() {
	Create(NULL, _T("HelloMFC")); 
	// SDK의 CreateWindow이며, 기본 설정이 존재해서 짧지 실제로는 더 길다.
	// 첫번째 인자에 NULL을 주면, MFC 내부에 등록된 윈도우 클래스가 사용된다.
	// 공부하면서 추가로 작성하겠다.
}

void CMainFrame::OnPaint() { // SDK의 WM_PAINT 처리
	CPaintDC dc(this); // 현재 Frame(윈도우)의 그림을 그리는 객체를 생성
					   // 생성자에 SDK의 BeginPaint()가 소멸자에 SDK의 EndPaint()가 존재한다.
	LPCTCH str = _T("Hello, MFC"); // const TCHAR* str, 윈도우에 그릴 문자열
	dc.TextOut(100, 100, str); // x좌표 y좌표 100,100에 str 그리기
}

void CMainFrame::OnLButtonDown(UINT nFlags, CPoint point) { // SDK의 WM_LNUTTONDOWN 처리
	MessageBox(_T("마우스 클릭"), _T("마우스 메시지"), MB_OK);
	// 메세지 박스  인자 -> 메시지 내용, 타이틀, 메세지박스 형태 (메시지박스 형태는 생략가능)
	/* 메세지박스 형태  Message Box -> MB */
	// MB_OK : 단순한 확인 버튼만 갖는다.
	// MB_OKCANCEL : 확인과 취소 버튼을 갖는다.
	// MB_RETRYCANCEL : 다시시도와 취소 버튼을 갖는다.
	// MB_YESNO : 예, 아니오 버튼을 갖는다.
	// MB_YESNOCANCEL : 예, 아니오, 취소 버튼을 갖느다.
	// MB_ABORTRETRYIGYIGNORE : 중단, 다시시도, 무시 버튼을 갖는다.
	// MB_HELP : 도움말 버튼을 추가로 갖는다.
}

void CMainFrame::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) { // SDK의 WM_KeyDown 처리
	switch (nChar) {
	case 0x41:
		MessageBox(_T("A 버튼 입력"), _T("키보드 메시지"));
		return;
	case 0x42:
		MessageBox(_T("B 버튼 입력"), _T("키보드 메시지"));
		return;
	case VK_TAB:
		MessageBox(_T("Tab 버튼 입력"), _T("키보드 메시지"));
		return;
	}
	// UINT nChar (UINT) 의 값
/*  가상키 이름     Hex 값(16진수) 키보드 동작
	VK_LBUTTON		0x01			왼쪽 클릭
	VK_RBUTTON		0x02			오른쪽 클릭
	VK_CANCEL		0x03			Control-break processing
	VK_MBUTTON		0x04			마우스 중간에 있는 버튼 클릭
	VK_BACK			0x08			백스페이스
	VK_TAB			0x09			탭 버튼
	VK_RETURN		0x0D			엔터 버튼
	VK_SHIFT		0x10			시프트 버튼
	VK_CONTROL		0x01			컨트롤 버튼
	VK_MENU			0x12			컨트롤 버튼
	VK_PAUSE		0x13			PAUSE 버튼
	VK_CAPITAL		0x14			CAPS LOCK버튼(대문자, 소문자)
	VK_HANGUEL		0x15			한/영 버튼
	VK_HANGUL		0x15			한/영 버튼 (위와 동일)
	VK_ESCAPE		0x1B			ESC 버튼
	VK_SPACE		0x20			스페이스 바 버튼
	VK_PRIOR		0x21			페이지 업 버튼 / PAGE UP
	VK_NEXT			0x22			페이지 다운 버튼 / PAGE DOWN
	VK_END			0x23			END 버튼
	VK_HOME			0x24			HOME 버튼
	VK_LEFT			0x25			왼쪽 화살표
	VK_UP			0x26			위쪽 화살표
	VK_RIGHT		0x27			오른쪽 화살표
	VK_DOWN			0x28			아래쪽 화살표
	VK_SELECT		0x29			SELECT 버튼
	VK_PRINT		0x2A			PRINT 버튼
	VK_INSERT		0x2D			INS 버튼
	VK_DELETE		0x2E			DEL 버튼
	VK_HELP			0x2F			HELP 버튼
	-				0x30 ~ 0x39		0 ~ 9 버튼
	-				0x41 ~ 0x5A		A ~ Z 버튼
	VK_NUMPAD0~		0x60 ~ 0x69		넘버 패드 키보드
	VK_NUMPAD9						0번 ~ 9번 버튼
	VK_F1 ~			0x70 ~ 0x7B		F1 ~ F12 버튼
	VK_F12
*/
}

// --- *** ---

// --- 메시지 맵 --- 

// MFC는 메시지 맵이라는 독특한 방식으로 윈도우 메시지와 해당 메시지 핸들러를 연결한다.
BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd) // 인자로, 상속된 윈도우(CMainFrame), 상속한 윈도우(CFrameWnd)
	ON_WM_PAINT()  // ON_WM_PAINT() 매크로는 WM_PAINT 메시지와 OnPaint()함수를 연결한다.
	ON_WM_LBUTTONDOWN() // ON_WM_LBUTTONDOWN() 매크로는 WM_LBUTTON 메시지와 OnLButtonDown 함수를 연결한다.
	ON_WM_KEYDOWN() // 위와 마찬가지로 WM_KEYDOWN 메시지와 OnKeyDown 함수를 연결한다.
END_MESSAGE_MAP() 

// --- *** ---