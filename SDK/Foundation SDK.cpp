#include <Windows.h>

// WndProc의 선언부, WinMain함수에서 사용할 예정
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// 메인 함수
// hInstance : 현재 실행되고 있는 프로세스의 인스턴스 핸들, 실행 파일에 포함된 리소스에 접근할  종종 사용
// hPrevInstance : 바로 앞에 실행된 프로그램(프로세스)의 인스턴스 핸들. 보통 NULL
// lpCmdLine : 명령행 인자, main 함수의 argv에 해당된다.
// nCmdShow : 윈도우를 보여주는 형태의 플래그(flag, 설정)
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	
	WNDCLASS wndclass; // 윈도우 클래스
	HWND hwnd;		   // 윈도우(창)을 커널 오브젝트에 접근하기 위한 핸들
	MSG msg;		   // 운영체제로부터 받을 메세지를 담을 변수


	//--- 윈도우 클래스를 초기화하고 운영체제에 등록 ---

	wndclass.style = CS_HREDRAW | CS_VREDRAW; // 스타일 지정 ClassStyle == CS
	// CS_VREDRAW : 윈도우의 이동이나 크기 조절시 세로의 크기가 변경되면 다시 그린다.
	// CS_HREDRAW : 윈도우의 이동이나 크기 조절시 가로의 큭가 변경되면 다시 그린다.
	// CS_DBLCLKS : 윈도우 내부에서 사용자가 더블 클릭시 더블 클릭 메시지를 윈도우 프로시저로 보낸다.
	// CS_OWNDC : 클래스 내부의 각 윈도우들은 고유의 DC(출력에 필요한 정보를 갖는 구조체)가 할당 됨
	// CS_CLASSDE : 클래스 내부의 각 윈도우들은 하나의 DC를 공유 단, 멀티 쓰레딩 시 하나의 쓰레드만 DC에 접근함
	// CS_PARENTDC : 부모 윈도우에서 자식 윈도우를 클리핑한 사각형을 만들어 자식이 부모에 그릴 수 있도록 함
	// CS_NOCLOSE : 윈도우 메뉴의 닫기 버튼을 비활성화 함
	// CS_SAVEBITS : 가려진 스크린의 일부를 비트맵으로 저장됨, 가려진 윈도우는 WM_PAINT 메시지 발생x
	// CS_BYTEALIGNCLIENT : 윈도우의 클라이언트 영역을 바이트 경계에 정렬한다.
	// CS_BYTEALIGNWINDOW : 윈도우를 바이트 경계에 정렬한다.
	// CS_IME : IME 사용자 인터페이스에 사용할 IME(Input Method Editor) 윈도우로 지정한다.
	wndclass.lpfnWndProc = WndProc; // 프로시저(메시지 핸들러의 집합)을 처리할 함수를 WndProc함수로 할당
	wndclass.cbClsExtra = 0; // 여분 메모리(0 바이트)
	wndclass.cbWndExtra = 0; // 여분 메모리 (0 바이트)
	wndclass.hInstance = hInstance; // 인스턴스(같은 프로그램에서 프로세스 구분하기 위한) 핸들
	wndclass.hIcon = LoadIcon(NULL, IDI_WINLOGO); // 아이콘 모양, IDI 예상 : ID Icon 
	// IDI_APPLICATION : 기본 어플리케이션 아이콘
	// IDI_INFORMATION : 별표 아이콘
	// IDI_ASTERISK : IDI_INFORMATION과 비슷함
	// IDI_ERROR : 손모양 아이콘(에러 아이콘)
	// IDI_HAND :IDI_ERROR과 유사
	// IDI_WARNNING : 경고 표시 아이콘
	// IDI_EXCLAMATION : IDI_WARNNING과 유사
	// IDI_QUESTION : 질문 마크 아이콘
	// IDI_WINLOGO : 윈도우 로고
	wndclass.hCursor = LoadCursorW(NULL, IDC_ARROW); // 커서 모양, IDC 예상 : ID Cusor
	// IDC_APPSTARTING : 표준, 화살표, 작은 모래시계
	// IDC_ARROW : 표준 화살표
	// ICD_CROSS : 십자가, 과녁
	// IDC_HAND : 손모양
	// IDC_HELP : 화살표, 물음표
	// IDC_IBEAM : 텍스트 같은 것을 편집할 때 보이는 대문자 i(I) 모양
	// ICD_NO : 윈에 슬레쉬가 그어진 모양의 커서
	// ICD_SIZEALL : 동서남북의 화살표 모양
	// ICD_SIZENESW // ICD_SIZENS // ICD_SIZENWSE // ICD_SIZEWE // ICD_SIZEWE 동서남북 모양의 방향 지정
	// IDC_UPARROW : 수평의 화살표
	// IDC_WAIT : 모래시계
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); // 배경 색, 색_BRUSH로 찾아보기
	// NULL_BRUSH : 투명 브러쉬
	// WHITE_BRUSH : 흰색 브러쉬
	// BLACK_BRUSH : 검은색 브러쉬 
	wndclass.lpszMenuName = NULL; // 메뉴 (NULL-> 메뉴 없음)
	wndclass.lpszClassName = TEXT("HelloWndClass"); // 윈도우 클래스 이름, CreateWindow할 때 동일하게 하기
	if (!RegisterClass(&wndclass)) return 1; // 성공하면 true 실패시 false 따라서 false면 잘못榮募 뜻

	// --- *** ---
	
	// --- 윈도우를 생성하고 화면에 나타낸다. ---

	hwnd = CreateWindow(TEXT("HelloWndClass"), TEXT("HelloSDK"), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
	/* CreateWindow 함수 인자 = '클래스 이름, 윈도우 이름, 윈도우 스타일, x좌표, y좌표, 윈도우의 폭, 윈도우의 높이,
	 부모 윈도우의 핸들, 메뉴 핸들, 인스턴스 핸들, 옵션' */
	/* 윈도우 스타일 Window Style */
	// WS_OVERLAPPEDWINDOW : 가장 일반적인 속성을 조합된 스타일 윈도우
	// WS_POPUPWINDOW : 가장 일반적인 속성을 조합된 팝업 윈도우이다.
	// WS_OVERLAPPED : 기본이 되는 윈도우
	// WS_POPUP : 팝업 윈도우 WS_CHILD와 같이 사용 불가
	// WS_CHILD : 차일드 윈도우를 만든다. WS_POPUP과 같이 사용 불가
	// WS_MINIMIZE : 최소 최소화된 상태로 윈도우를 만든다.
	// WS_VISIBLE : 윈도우를 만들자 마자 화면에 출력한다.
	// WS_DISABLED : 사용금지, 입력을 받지 못함
	// WS_CLIPSIBLINGS : 차일드끼리 겹치면 그리지 않음
	// WS_CLIPCHILDREN : 차일드가 위치한 영역은 그리지 않음
	// WS_MAXIMIZE : 최초 최대화된 상태로 윈도우를 만든다.
	// WS_CAPTION : 타이틀 바를 가진 윈도우를 만든다.
	// WS_BORDER : 단선으로 된 경계선을 만들고 크기 조정 불가
	// WS_DLGFRAME : 두꺼운 경계선을 가지며 타이틀 바를 가질 수 없다.
	// WS_VSCROLL : 수직 스크롤 바를 가진 윈도우를 만든다.
	// WS_HSCROLL : 수평 스크롤 바를 가진 윈도우를 만든다.
	// WS_SYSMENU : 시스템 메뉴를 가진 윈도우를 만든다.
	// WS_THCKFRAME : 크기 조정이 가능한 두꺼운 경계선을 가진다.
	// WS_GROUP : 라디오 버튼 등 그룹을 이루는 컨트롤의 그룹 지정을 한다
	// WS_TABSTOP : Tab 키로 포커스를 이동할 수 있도록 한다.
	// WS_MINIMIZEOBX : 최소화 버튼을 만든다.
	// WS_MAXIMIZEBOX : 최대화 버튼을 만든다.
	// WS_CHULDWINDO : WS_CHILD와 동일하다.
	ShowWindow(hwnd, nCmdShow); // 윈도우를 화면에 보이게 한다. ShowWindow = SW
	// SW_SHOWNORMAL : 일반적인 형태로 나타냄
	// SW_SHWMAXIMIZED : 최대화 모드 형태로 나타냄
	// SW_SHOWMINIMIZE : 최대화 모드 형태로 나타ㅐㅁ
	// SW_HIDE : 화면에 나타나지 않는 형태
	// 위 함수처럼 nCmdShow로 파라미터로 받아온 값을 그대로 사용할 수도 있다.

	// --- *** ---

	//--- 메시지 큐에서 메시지를 하나씩 꺼내서 처리한다. ---


	// GerMessage는 메시지 큐에서 메시지 하나를 꺼내 msg변수에 저장
	// 반환 값이 0일시(VM_QUIT) 종료,
	// 인자 -> 메시지 포인터, 핸들, 필터 최소값, 필터 최대값
	while (GetMessage(&msg, NULL, 0, 0) > 0) {
		TranslateMessage(&msg);
		// msg 변수에 키보드 메시지가 들어있을 경우, 키에 대응하는 문자를 만든다.
		DispatchMessageW(&msg);
		// 메시지를 윈도우 프로시저로 보낸다. (윈도우 클래스로 지정한 프로시저로 보낸다.)
	}
	
	// --- *** ---

	return msg.wParam;
}

// 윈도우 프로시저, 위에서 선언을 했었다.
// 인자 -> 프로세스 핸들, DispatchMessage한 메시지의 값, 가상키에 대한 코드 값, key data 
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	HDC hdc; // BeginPaint 함수로 윈도우 핸들과 PAINTSTRUCT를 묶어서 사용할 그림그리기 핸들
	PAINTSTRUCT ps; // 페인트 구조체
	LPCTCH str = TEXT("Hello, SDK"); // const TCHAR * str (윈도우 창에 TextOut으로 그릴 문자열)

	switch (message) {
	case WM_CREATE: // CreateWindow()함수를 호출 했을 때
		return 0;
	case WM_LBUTTONDOWN: // 클라이언트 영역에서 마우스 왼쪽 버튼을 누를 때
		MessageBox(hwnd, TEXT("마우스 클릭"), TEXT("마우스 메시지"), MB_OK);
		// 메세지 박스  인자 -> 윈도우 핸들, 메시지 내용, 타이틀, 메세지박스 형태 
		/* 메세지박스 형태  Message Box -> MB */
		// MB_OK : 단순한 확인 버튼만 갖는다.
		// MB_OKCANCEL : 확인과 취소 버튼을 갖는다.
		// MB_RETRYCANCEL : 다시시도와 취소 버튼을 갖는다.
		// MB_YESNO : 예, 아니오 버튼을 갖는다.
		// MB_YESNOCANCEL : 예, 아니오, 취소 버튼을 갖느다.
		// MB_ABORTRETRYIGYIGNORE : 중단, 다시시도, 무시 버튼을 갖는다.
		// MB_HELP : 도움말 버튼을 추가로 갖는다.
		return 0;
	case WM_PAINT: // 클라이언트 영역의 일부 또는 전체를 다시 그릴 필요가 있을 때
		hdc = BeginPaint(hwnd, &ps); // BeginPaint 함수로 그림그리기 핸들 생성
		TextOut(hdc, 100, 100, str, lstrlen(str)); // 클라이언트 영역 x,y좌표에 문자열 그리기
		EndPaint(hwnd, &ps); // BeginPaint 함수를 한 것을 다시 닫아준다. 닫시 않으면 계속해서 그려서 과부하가 걸린다.
		return 0;
	case WM_DESTROY: // 윈도우의 종료 버튼을 클릭했을 때
		PostQuitMessage(0); // 메시지에 0값(종료)를 넣는다.
		return 0;
	case WM_KEYDOWN :
		switch (wParam) {
		case 0x41:
			MessageBox(hwnd, TEXT("A 버튼 입력"), TEXT("키보드 메시지"), MB_OK);
			return 0;
		case 0x42:
			MessageBox(hwnd, TEXT("B 버튼 입력"), TEXT("키보드 메시지"), MB_OK);
			return 0;
		case VK_TAB:
			MessageBox(hwnd, TEXT("Tab 버튼 입력"), TEXT("키보드 메시지"), MB_OK);
			return 0;
		}

	}
	// WPARAM wParam (UINT_PTR) 의 값
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

	return DefWindowProc(hwnd, message, wParam, lParam); 
	// 응용 프로그램이 처리하지하지 않는 메시지는 운영체제한테 처리를 부탁함
}
