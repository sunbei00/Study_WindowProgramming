#include <afxwin.h> // �������

// --- Ŭ���� ����� ---

// �������α׷� Ŭ���� ����, �����ϸ� �������ִ� ����Ŭ������ �� Ŭ������ ������ ��ü�� ã�Ƽ� ������ ���̴�.
class CHelloApp : public CWinApp { // CWinApp Ŭ������ ���� ���α׷��� �ʱ�ȭ �ڵ�, �޽��� ����, �����ڵ带 �����Ѵ�.
public:
	virtual BOOL InitInstance(); // �����ڰ� ����Ǹ� �ٷ� InitInstance �Լ��� �����Ѵ�.(virtual ������)
};

// ���� ������ Ŭ������ ����, ������ CWinApp�� ����� CHelloApp�� �����츦 �ش� Ŭ������ ��ü�� ����� ���̴�.
class CMainFrame : public CFrameWnd { // CFrameWnd�� �������� ���� ����� ����� ���̴�.
public:
	CMainFrame(); // �����ڷ� SDK�� CreateWindow������ �� ���̴�.
protected: 
	// �޽��� �ڵ鷯���� �������ϴµ�, afx_msg�� �ش� �Լ��� �޽����ڵ鷯��� ��ũ���̴�.
	afx_msg void OnPaint(); // ������ ȭ�� �׸���
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point); // ���� ���콺 Ŭ������ ��
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags); // Ű�� ������ ��
	DECLARE_MESSAGE_MAP(); // ���� ��Ȯ�� ����� �𸣰���, �޽��� ��(���ν���)�� ������ ����
};

// --- *** ---

// --- ���� ���α׷� ��ü ---
CHelloApp theFirstApp; 
// ������ϸ� �ش� ��ü�� ã�Ƽ� �Ҵ�Ǹ�, ������ �ȴ�.
// ��ü�� �̸��� �߿������ʰ�, ���� ��ü�� ���� �Ѱ��� �־�� �Ѵ�.
// --- *** ---

// --- Ŭ���� ���Ǻ� ---

// MFC ���ο� ������ WinMain�� CWinApp�� ��ü�� ã�Ƽ� �����ڷ� �� �Լ��� ���� ���� �����Ѵ�.
BOOL CHelloApp::InitInstance() { // �ݴ��� �Լ���(�����)�� ExitInstance�� �����Ѵ�.
	m_pMainWnd = new CMainFrame; // CWinApp�� ���� �����츦 CMainFrame���� �Ѵ�.
	m_pMainWnd->ShowWindow(m_nCmdShow); // SDK�� ����������, �������� ���¸� �����Ѵ�.
	// ShowWindow -> SW
	// SW_SHOWNORMAL : �Ϲ����� ���·� ��Ÿ��
	// SW_SHWMAXIMIZED : �ִ�ȭ ��� ���·� ��Ÿ��
	// SW_SHOWMINIMIZE : �ִ�ȭ ��� ���·� ��Ÿ��
	// SW_HIDE : ȭ�鿡 ��Ÿ���� �ʴ� ����
	// �� �Լ�ó�� m_nCmdShow�� CWinApp�� ����Լ��� �״�� ����� ���� �ִ�.
	return true; // �ʱ�ȭ �۾� �� �ݵ�� true�� �����ؾ� �Ѵ�. FALSE�� ���α׷��� ����ȴ�.
}

CMainFrame::CMainFrame() {
	Create(NULL, _T("HelloMFC")); 
	// SDK�� CreateWindow�̸�, �⺻ ������ �����ؼ� ª�� �����δ� �� ���.
	// ù��° ���ڿ� NULL�� �ָ�, MFC ���ο� ��ϵ� ������ Ŭ������ ���ȴ�.
	// �����ϸ鼭 �߰��� �ۼ��ϰڴ�.
}

void CMainFrame::OnPaint() { // SDK�� WM_PAINT ó��
	CPaintDC dc(this); // ���� Frame(������)�� �׸��� �׸��� ��ü�� ����
					   // �����ڿ� SDK�� BeginPaint()�� �Ҹ��ڿ� SDK�� EndPaint()�� �����Ѵ�.
	LPCTCH str = _T("Hello, MFC"); // const TCHAR* str, �����쿡 �׸� ���ڿ�
	dc.TextOut(100, 100, str); // x��ǥ y��ǥ 100,100�� str �׸���
}

void CMainFrame::OnLButtonDown(UINT nFlags, CPoint point) { // SDK�� WM_LNUTTONDOWN ó��
	MessageBox(_T("���콺 Ŭ��"), _T("���콺 �޽���"), MB_OK);
	// �޼��� �ڽ�  ���� -> �޽��� ����, Ÿ��Ʋ, �޼����ڽ� ���� (�޽����ڽ� ���´� ��������)
	/* �޼����ڽ� ����  Message Box -> MB */
	// MB_OK : �ܼ��� Ȯ�� ��ư�� ���´�.
	// MB_OKCANCEL : Ȯ�ΰ� ��� ��ư�� ���´�.
	// MB_RETRYCANCEL : �ٽýõ��� ��� ��ư�� ���´�.
	// MB_YESNO : ��, �ƴϿ� ��ư�� ���´�.
	// MB_YESNOCANCEL : ��, �ƴϿ�, ��� ��ư�� ������.
	// MB_ABORTRETRYIGYIGNORE : �ߴ�, �ٽýõ�, ���� ��ư�� ���´�.
	// MB_HELP : ���� ��ư�� �߰��� ���´�.
}

void CMainFrame::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) { // SDK�� WM_KeyDown ó��
	switch (nChar) {
	case 0x41:
		MessageBox(_T("A ��ư �Է�"), _T("Ű���� �޽���"));
		return;
	case 0x42:
		MessageBox(_T("B ��ư �Է�"), _T("Ű���� �޽���"));
		return;
	case VK_TAB:
		MessageBox(_T("Tab ��ư �Է�"), _T("Ű���� �޽���"));
		return;
	}
	// UINT nChar (UINT) �� ��
/*  ����Ű �̸�     Hex ��(16����) Ű���� ����
	VK_LBUTTON		0x01			���� Ŭ��
	VK_RBUTTON		0x02			������ Ŭ��
	VK_CANCEL		0x03			Control-break processing
	VK_MBUTTON		0x04			���콺 �߰��� �ִ� ��ư Ŭ��
	VK_BACK			0x08			�齺���̽�
	VK_TAB			0x09			�� ��ư
	VK_RETURN		0x0D			���� ��ư
	VK_SHIFT		0x10			����Ʈ ��ư
	VK_CONTROL		0x01			��Ʈ�� ��ư
	VK_MENU			0x12			��Ʈ�� ��ư
	VK_PAUSE		0x13			PAUSE ��ư
	VK_CAPITAL		0x14			CAPS LOCK��ư(�빮��, �ҹ���)
	VK_HANGUEL		0x15			��/�� ��ư
	VK_HANGUL		0x15			��/�� ��ư (���� ����)
	VK_ESCAPE		0x1B			ESC ��ư
	VK_SPACE		0x20			�����̽� �� ��ư
	VK_PRIOR		0x21			������ �� ��ư / PAGE UP
	VK_NEXT			0x22			������ �ٿ� ��ư / PAGE DOWN
	VK_END			0x23			END ��ư
	VK_HOME			0x24			HOME ��ư
	VK_LEFT			0x25			���� ȭ��ǥ
	VK_UP			0x26			���� ȭ��ǥ
	VK_RIGHT		0x27			������ ȭ��ǥ
	VK_DOWN			0x28			�Ʒ��� ȭ��ǥ
	VK_SELECT		0x29			SELECT ��ư
	VK_PRINT		0x2A			PRINT ��ư
	VK_INSERT		0x2D			INS ��ư
	VK_DELETE		0x2E			DEL ��ư
	VK_HELP			0x2F			HELP ��ư
	-				0x30 ~ 0x39		0 ~ 9 ��ư
	-				0x41 ~ 0x5A		A ~ Z ��ư
	VK_NUMPAD0~		0x60 ~ 0x69		�ѹ� �е� Ű����
	VK_NUMPAD9						0�� ~ 9�� ��ư
	VK_F1 ~			0x70 ~ 0x7B		F1 ~ F12 ��ư
	VK_F12
*/
}

// --- *** ---

// --- �޽��� �� --- 

// MFC�� �޽��� ���̶�� ��Ư�� ������� ������ �޽����� �ش� �޽��� �ڵ鷯�� �����Ѵ�.
BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd) // ���ڷ�, ��ӵ� ������(CMainFrame), ����� ������(CFrameWnd)
	ON_WM_PAINT()  // ON_WM_PAINT() ��ũ�δ� WM_PAINT �޽����� OnPaint()�Լ��� �����Ѵ�.
	ON_WM_LBUTTONDOWN() // ON_WM_LBUTTONDOWN() ��ũ�δ� WM_LBUTTON �޽����� OnLButtonDown �Լ��� �����Ѵ�.
	ON_WM_KEYDOWN() // ���� ���������� WM_KEYDOWN �޽����� OnKeyDown �Լ��� �����Ѵ�.
END_MESSAGE_MAP() 

// --- *** ---