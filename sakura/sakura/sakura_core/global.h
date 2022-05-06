/*!	@file
	@brief ���ʒ�`

	@author Norio Nakatani
*/
/*
	Copyright (C) 1998-2001, Norio Nakatani
	Copyright (C) 2000, Stonee, genta, jepro, MIK
	Copyright (C) 2001, jepro, hor, MIK
	Copyright (C) 2002, MIK, genta, aroka, YAZAKI, Moca, KK, novice
	Copyright (C) 2003, MIK, genta, zenryaku, naoh
	Copyright (C) 2004, Kazika
	Copyright (C) 2005, MIK, Moca, genta
	Copyright (C) 2006, aroka, ryoji
	Copyright (C) 2007, ryoji
	Copyright (C) 2008, nasukoji

	This source code is designed for sakura editor.
	Please contact the copyright holder to use this code for other purpose.
*/

#ifndef _GLOBAL_H_
#define _GLOBAL_H_

//////////////////////////////////////////////////////////////
#include <windows.h>
#include <tchar.h>

// �ȉ��� ifdef �u���b�N�� DLL ����ȒP�ɃG�N�X�|�[�g������}�N�����쐬����W���I�ȕ��@�ł��B
// ���� DLL ���̂��ׂẴt�@�C���̓R�}���h���C���Œ�`���ꂽ SAKURA_CORE_EXPORTS �V���{��
// �ŃR���p�C������܂��B���̃V���{���͂��� DLL ���g�p����ǂ̃v���W�F�N�g��ł�����`�łȂ�
// ��΂Ȃ�܂���B���̕��@�ł̓\�[�X�t�@�C���ɂ��̃t�@�C�����܂ނ��ׂẴv���W�F�N�g�� DLL
// ����C���|�[�g���ꂽ���̂Ƃ��� SAKURA_CORE_API �֐����Q�Ƃ��A���̂��߂��� DLL �͂��̃}�N
// ���Œ�`���ꂽ�V���{�����G�N�X�|�[�g���ꂽ���̂Ƃ��ĎQ�Ƃ��܂��B
#ifdef SAKURA_CORE_EXPORTS
#define SAKURA_CORE_API __declspec(dllexport)
#else
#define SAKURA_CORE_API __declspec(dllimport)
#endif

#ifdef SAKURA_NO_DLL	//@@@ 2001.12.30 add MIK
#undef SAKURA_CORE_API
#define SAKURA_CORE_API
#endif	//SAKURA_NO_DLL

#if defined(__BORLANDC__)
#define __forceinline
#define _itoa itoa
#define _stricmp stricmp
#define _memicmp memicmp
#define _strlwr strlwr
#ifndef __max
#define __max(a,b)  (((a) > (b)) ? (a) : (b))
#endif
#ifndef __min
#define __min(a,b)  (((a) < (b)) ? (a) : (b))
#endif
#define __access access
#ifndef STRICT
#define STRICT
#endif
#endif

//	Sep. 22, 2003 MIK
//	�Â�SDK�΍�D�V����SDK�ł͕s�v
#ifndef _WIN64
#ifndef DWORD_PTR
#define DWORD_PTR DWORD
#endif
#ifndef ULONG_PTR
#define ULONG_PTR ULONG
#endif
#ifndef LONG_PTR
#define LONG_PTR LONG
#endif
#ifndef UINT_PTR
#define UINT_PTR UINT
#endif
#ifndef INT_PTR
#define INT_PTR INT
#endif
#ifndef SetWindowLongPtr
#define SetWindowLongPtr SetWindowLong
#endif
#ifndef GetWindowLongPtr
#define GetWindowLongPtr GetWindowLong
#endif
#ifndef DWLP_USER
#define DWLP_USER DWL_USER
#endif
#ifndef GWLP_WNDPROC
#define GWLP_WNDPROC GWL_WNDPROC
#endif
#ifndef GWLP_USERDATA
#define GWLP_USERDATA GWL_USERDATA
#endif
#ifndef GWLP_HINSTANCE
#define GWLP_HINSTANCE GWL_HINSTANCE
#endif
#endif  //_WIN64

#ifndef COLOR_MENUHILIGHT
#define COLOR_MENUHILIGHT 29
#endif
#ifndef COLOR_MENUBAR
#define COLOR_MENUBAR 30
#endif


//Oct. 31, 2000 JEPRO TeX Keyword �̂��߂�'\'��ǉ�	//Nov. 9, 2000 JEPRO HSP Keyword �̂��߂�'@'��ǉ�
//#define IS_KEYWORD_CHAR(c) ((c) == '#' || (c) == '$' || __iscsym( (c) ))
//#define IS_KEYWORD_CHAR(c) ((c) == '#'/*35*/ || (c) == '$'/*36*/ || (c) == '@'/*64*/ || (c) == '\\'/*92*/ || __iscsym( (c) ))
SAKURA_CORE_API	extern const unsigned char gm_keyword_char[256];	//@@@ 2002.04.27
#define IS_KEYWORD_CHAR(c)	((int)(gm_keyword_char[(unsigned char)((c) & 0xff)]))	//@@@ 2002.04.27 ���P�[���Ɉˑ����Ȃ�


SAKURA_CORE_API extern const char* GSTR_APPNAME;


#ifdef _DEBUG
	#ifndef	GSTR_EDITWINDOWNAME
	#define	GSTR_EDITWINDOWNAME "SakuraEditorWindow_DEBUG"
	#endif
#else
	#ifndef	GSTR_EDITWINDOWNAME
	#define	GSTR_EDITWINDOWNAME "SakuraEditorWindow"
	#endif
#endif

//20020108 aroka �R���g���[���v���Z�X�ƋN�������̂��߂Ƀ~���[�e�b�N�X����ǉ�
// 2006.04.10 ryoji �R���g���[���v���Z�X�����������������C�x���g�t���O����ǉ�
#ifdef _DEBUG
	#ifndef	GSTR_SYNCOBJ_SAKURA
	#define	GSTR_SYNCOBJ_SAKURA
	#define	GSTR_MUTEX_SAKURA "MutexSakuraEditor_DEBUG"
	#define	GSTR_MUTEX_SAKURA_CP _T("MutexSakuraEditorCP_DEBUG")
	#define	GSTR_EVENT_SAKURA_CP_INITIALIZED _T("EventSakuraEditorCPInitialized_DEBUG")
	#define	GSTR_MUTEX_SAKURA_INIT _T("MutexSakuraEditorInit_DEBUG")
	#define	GSTR_MUTEX_SAKURA_EDITARR _T("MutexSakuraEditorEditArr_DEBUG")
	#endif
#else
	#ifndef	GSTR_SYNCOBJ_SAKURA
	#define	GSTR_SYNCOBJ_SAKURA
	#define	GSTR_MUTEX_SAKURA "MutexSakuraEditor"
	#define	GSTR_MUTEX_SAKURA_CP _T("MutexSakuraEditorCP")
	#define	GSTR_EVENT_SAKURA_CP_INITIALIZED _T("EventSakuraEditorCPInitialized")
	#define	GSTR_MUTEX_SAKURA_INIT _T("MutexSakuraEditorInit")
	#define	GSTR_MUTEX_SAKURA_EDITARR _T("MutexSakuraEditorEditArr")
	#endif
#endif

#ifdef _DEBUG
	#ifndef	GSTR_CEDITAPP
#define	GSTR_CEDITAPP "CEditApp_DEBUG"
	#endif
#else
	#ifndef	GSTR_CEDITAPP
	#define	GSTR_CEDITAPP "CEditApp"
	#endif
#endif

#ifdef _DEBUG
	#ifndef	GSTR_CSHAREDATA
	#define	GSTR_CSHAREDATA "CShareData_DEBUG"
	#endif
#else
	#ifndef	GSTR_CSHAREDATA
	#define	GSTR_CSHAREDATA "CShareData"
	#endif
#endif

//	Dec. 2, 2002 genta
//	�Œ�t�@�C����
#define FN_APP_ICON "my_appicon.ico"
#define FN_GREP_ICON "my_grepicon.ico"
#define FN_TOOL_BMP "my_icons.bmp"

//	�W���A�v���P�[�V�����A�C�R�����\�[�X��
#ifdef _DEBUG
	#define ICON_DEFAULT_APP IDI_ICON_DEBUG
	#define ICON_DEFAULT_GREP IDI_ICON_GREP
#else
	#define ICON_DEFAULT_APP IDI_ICON_STD
	#define ICON_DEFAULT_GREP IDI_ICON_GREP
#endif

//#ifndef	GSTR_REG_ROOTPATH
//#define	GSTR_REG_ROOTPATH "Software\\BugSoft\\sakura"
//#endif


/* �E�B���h�E��ID */
#define IDW_STATUSBAR 123


#define IDM_SELWINDOW		10000
#define IDM_SELMRU			11000
#define IDM_SELOPENFOLDER	12000


/* �����R�[�h�Z�b�g��� */
SAKURA_CORE_API enum enumCodeType {
	CODE_SJIS,				/* SJIS */
	CODE_JIS,				/* JIS */
	CODE_EUC,				/* EUC */
	CODE_UNICODE,			/* Unicode */
	CODE_UTF8,				/* UTF-8 */
	CODE_UTF7,				/* UTF-7 */
	CODE_UNICODEBE,			/* Unicode BigEndian */
	CODE_CODEMAX,
	CODE_AUTODETECT	= 99	/* �����R�[�h�������� */
};

SAKURA_CORE_API extern const char* gm_pszCodeNameArr_1[];
SAKURA_CORE_API extern const char* gm_pszCodeNameArr_2[];
SAKURA_CORE_API extern const char* gm_pszCodeNameArr_3[];

/* �R���{�{�b�N�X�p �������ʂ��܂ޔz�� */
SAKURA_CORE_API extern const int gm_nCodeComboValueArr[];
SAKURA_CORE_API extern const char* const gm_pszCodeComboNameArr[];
SAKURA_CORE_API extern const int gm_nCodeComboNameArrNum;

//const char* GetCodeTypeName( enumCodeType nCodeTYpe )
//{
//	const char* pszCodeTypeNameArr[] = {
//		"SJIS",
//		"JIS",
//		"EUC",
//		"Unicode",
//		"UTF-8",
//		"UTF-7"
//	};
//	return pszCodeTypeNameArr[nCodeTYpe];
//}

/* �A�E�g���C����͂̎�� */
SAKURA_CORE_API enum enumOutlineType {
	OUTLINE_C,
	OUTLINE_CPP,
	OUTLINE_PLSQL,
	OUTLINE_TEXT,
	OUTLINE_JAVA,
	OUTLINE_COBOL,
	OUTLINE_ASM,
	OUTLINE_PERL,	//	Sep. 8, 2000 genta
	OUTLINE_VB,	//	June 23, 2001 N.Nakatani
	OUTLINE_WZTXT,		// 2003.05.20 zenryaku �K�w�t�e�L�X�g�A�E�g���C�����
	OUTLINE_HTML,		// 2003.05.20 zenryaku HTML�A�E�g���C�����
	OUTLINE_TEX,		// 2003.07.20 naoh TeX�A�E�g���C�����
	OUTLINE_FILE,		//	2002.04.01 YAZAKI ���[���t�@�C���p
	OUTLINE_PYTHON,		//	2007.02.08 genta Python�A�E�g���C�����
	OUTLINE_ERLANG,		//	2009.08.11 genta Erlang�A�E�g���C�����
	//	�V�����A�E�g���C����͕͂K�����̒��O�֑}��
	OUTLINE_CODEMAX,
	OUTLINE_BOOKMARK,	//	2001.12.03 hor
	OUTLINE_DEFAULT =-1,//	2001.12.03 hor
	OUTLINE_UNKNOWN	= 99
};

// 2002/09/22 Moca EOL_CRLF_UNICODE��p�~
/* �s�I�[�q�̎�� */
SAKURA_CORE_API enum enumEOLType {
	EOL_NONE,
	EOL_CRLF,
	EOL_LFCR,
	EOL_LF,
	EOL_CR,
	EOL_CODEMAX,
	EOL_UNKNOWN = -1
};

/* �s�I�[�q�̃f�[�^�� */
SAKURA_CORE_API enum enumEOLLen {
	LEN_EOL_NONE			= 0,
	LEN_EOL_CRLF			= 2,
	LEN_EOL_LFCR			= 2,
	LEN_EOL_LF				= 1,
	LEN_EOL_CR				= 1
//	LEN_EOL_UNKNOWN		0
};

/* �_�C�A���O�\�����@ */ // �A�E�g���C���E�B���h�E�p�ɍ쐬 20060201 aroka
SAKURA_CORE_API enum enumShowDlg {
	SHOW_NORMAL			= 0,
	SHOW_RELOAD			= 1,
	SHOW_TOGGLE			= 2,
};


#define EOL_TYPE_NUM	5

/* �s�I�[�q�̔z�� */
SAKURA_CORE_API extern const enumEOLType gm_pnEolTypeArr[EOL_TYPE_NUM];

//	May 15, 2000 genta
//	CEOL�ֈړ�
//	From Here
/* �s�I�[�q�̃f�[�^�̔z�� */
// SAKURA_CORE_API extern const char* gm_pszEolDataArr[EOL_TYPE_NUM];

/* �s�I�[�q�̃f�[�^���̔z�� */
// SAKURA_CORE_API extern const int gm_pnEolLenArr[EOL_TYPE_NUM];

/* �s�I�[�q�̕\�����̔z�� */
// SAKURA_CORE_API extern const char* gm_pszEolNameArr[EOL_TYPE_NUM];

/* �s�I�[�q�̎�ނ𒲂ׂ� */
// SAKURA_CORE_API enumEOLType GetEOLType( const char*, int );
//	To Here

/* �I��̈�`��p�p�����[�^ */
SAKURA_CORE_API extern const COLORREF	SELECTEDAREA_RGB;
SAKURA_CORE_API extern const int		SELECTEDAREA_ROP2;


/* �X�}�[�g�C���f���g��� */
SAKURA_CORE_API enum enumSmartIndentType {
	SMARTINDENT_NONE,
	SMARTINDENT_CPP
};




// Stonee ���F 2000/01/12
// ������ύX�����Ƃ��́Aglobal.cpp ��g_ColorAttributeArr�̒�`���ύX���ĉ������B
//	From Here Sept. 18, 2000 JEPRO ���Ԃ�啝�ɓ���ւ���
//	2007.09.09 Moca  ���Ԃ̒�`�͂��C���ɕύX
SAKURA_CORE_API enum enumColorIndexType {
	COLORIDX_TEXT = 0,      /* �e�L�X�g */
	COLORIDX_RULER,         /* ���[���[ */
	COLORIDX_CARET,         /* �L�����b�g */    // 2006.12.07 ryoji
	COLORIDX_CARET_IME,     /* IME�L�����b�g */ // 2006.12.07 ryoji
	COLORIDX_UNDERLINE,     /* �J�[�\���s�A���_�[���C�� */
	COLORIDX_CURSORVLINE,   /* �J�[�\���ʒu�c�� */ // 2006.05.13 Moca
	COLORIDX_GYOU,          /* �s�ԍ� */
	COLORIDX_GYOU_MOD,      /* �s�ԍ�(�ύX�s) */
	COLORIDX_TAB,           /* TAB�L�� */
	COLORIDX_SPACE,         /* ���p�� */ //2002.04.28 Add by KK �ȍ~�S��+1
	COLORIDX_ZENSPACE,      /* ���{��� */
	COLORIDX_CTRLCODE,      /* �R���g���[���R�[�h */
	COLORIDX_CRLF,          /* ���s�L�� */
	COLORIDX_WRAP,          /* �܂�Ԃ��L�� */
	COLORIDX_VERTLINE,      /* �w�茅�c�� */    // 2005.11.08 Moca
	COLORIDX_EOF,           /* EOF�L�� */
	COLORIDX_DIGIT,         /* ���p���l */  //@@@ 2001.02.17 by MIK //�F�ݒ�Ver.3���烆�[�U�t�@�C���ɑ΂��Ă͕�����ŏ������Ă���̂Ń��i���o�����O���Ă��悢. Mar. 7, 2001 JEPRO noted
	COLORIDX_SEARCH,        /* ���������� */
	COLORIDX_KEYWORD1,      /* �����L�[���[�h1 */ // 2002/03/13 novice
	COLORIDX_KEYWORD2,      /* �����L�[���[�h2 */ // 2002/03/13 novice  //MIK ADDED
	COLORIDX_KEYWORD3,      /* �����L�[���[�h3 */ // 2005.01.13 MIK 3-10 added
	COLORIDX_KEYWORD4,      /* �����L�[���[�h4 */
	COLORIDX_KEYWORD5,      /* �����L�[���[�h5 */
	COLORIDX_KEYWORD6,      /* �����L�[���[�h6 */
	COLORIDX_KEYWORD7,      /* �����L�[���[�h7 */
	COLORIDX_KEYWORD8,      /* �����L�[���[�h8 */
	COLORIDX_KEYWORD9,      /* �����L�[���[�h9 */
	COLORIDX_KEYWORD10,     /* �����L�[���[�h10 */
	COLORIDX_COMMENT,       /* �s�R�����g */                        //Dec. 4, 2000 shifted by MIK
	COLORIDX_SSTRING,       /* �V���O���N�H�[�e�[�V���������� */    //Dec. 4, 2000 shifted by MIK
	COLORIDX_WSTRING,       /* �_�u���N�H�[�e�[�V���������� */      //Dec. 4, 2000 shifted by MIK
	COLORIDX_URL,           /* URL */                               //Dec. 4, 2000 shifted by MIK
	COLORIDX_REGEX1,        /* ���K�\���L�[���[�h1 */  //@@@ 2001.11.17 add MIK
	COLORIDX_REGEX2,        /* ���K�\���L�[���[�h2 */  //@@@ 2001.11.17 add MIK
	COLORIDX_REGEX3,        /* ���K�\���L�[���[�h3 */  //@@@ 2001.11.17 add MIK
	COLORIDX_REGEX4,        /* ���K�\���L�[���[�h4 */  //@@@ 2001.11.17 add MIK
	COLORIDX_REGEX5,        /* ���K�\���L�[���[�h5 */  //@@@ 2001.11.17 add MIK
	COLORIDX_REGEX6,        /* ���K�\���L�[���[�h6 */  //@@@ 2001.11.17 add MIK
	COLORIDX_REGEX7,        /* ���K�\���L�[���[�h7 */  //@@@ 2001.11.17 add MIK
	COLORIDX_REGEX8,        /* ���K�\���L�[���[�h8 */  //@@@ 2001.11.17 add MIK
	COLORIDX_REGEX9,        /* ���K�\���L�[���[�h9 */  //@@@ 2001.11.17 add MIK
	COLORIDX_REGEX10,       /* ���K�\���L�[���[�h10 */  //@@@ 2001.11.17 add MIK
	COLORIDX_DIFF_APPEND,   /* DIFF�ǉ� */  //@@@ 2002.06.01 MIK
	COLORIDX_DIFF_CHANGE,   /* DIFF�ǉ� */  //@@@ 2002.06.01 MIK
	COLORIDX_DIFF_DELETE,   /* DIFF�ǉ� */  //@@@ 2002.06.01 MIK
	COLORIDX_BRACKET_PAIR,  /* �Ί��� */    // 02/09/18 ai Add
	COLORIDX_MARK,          /* �u�b�N�}�[�N */  // 02/10/16 ai Add

	//�J���[�̍Ō�
	COLORIDX_LAST,          //Dec. 4, 2000 @@@2001.02.17 renumber by MIK				/* 2002/10/16 ai Mod 34��35 */

	//�J���[�\������p
	COLORIDX_BLOCK1,        /* �u���b�N�R�����g1(�����F�Ɣw�i�F�͍s�R�����g�Ɠ���) */	/* 02/10/16 ai Mod 35��36 */
	COLORIDX_BLOCK2,        /* �u���b�N�R�����g2(�����F�Ɣw�i�F�͍s�R�����g�Ɠ���) */	/* 02/10/16 ai Mod 36��37 */

	//1000-1099 : �J���[�\������p(���K�\���L�[���[�h)
	COLORIDX_REGEX_FIRST = 1000,
	COLORIDX_REGEX_LAST = 1099,
};
//	To Here Sept. 18, 2000



//@@@ From Here 2003.05.31 MIK
/*! �^�u�E�C���h�E�p���b�Z�[�W�T�u�R�}���h */
SAKURA_CORE_API enum enumTabWndNotifyType {
	TWNT_REFRESH	= 0,		//�ĕ\��
	TWNT_ADD		= 1,		//�E�C���h�E�o�^
	TWNT_DEL		= 2,		//�E�C���h�E�폜
	TWNT_ORDER		= 3,		//�E�C���h�E�����ύX
	TWNT_FILE		= 4,		//�t�@�C�����ύX
	TWNT_MODE_ENABLE= 5,		//�^�u���[�h�L����	//2004.07.14 Kazika �ǉ�
	TWNT_MODE_DISABLE= 6,		//�^�u���[�h������	//2004.08.27 Kazika �ǉ�
	TWNT_WNDPL_ADJUST= 7,		//�E�B���h�E�ʒu���킹	// 2007.04.03 ryoji �ǉ�
};

/*! �o�[�̕\���E��\�� */
SAKURA_CORE_API	enum enumBarChangeNotifyType {
	MYBCN_TOOLBAR	= 0,		//�c�[���o�[
	MYBCN_FUNCKEY	= 1,		//�t�@���N�V�����L�[
	MYBCN_TAB		= 2,		//�^�u
	MYBCN_STATUSBAR	= 3,		//�X�e�[�^�X�o�[
};
//@@@ To Here 2003.05.31 MIK

//�^�u�Ŏg���J�X�^�����j���[�̃C���f�b�N�X	//@@@ 2003.06.13 MIK
#define	CUSTMENU_INDEX_FOR_TABWND		24
//�E�N���b�N���j���[�Ŏg���J�X�^�����j���[�̃C���f�b�N�X	//@@@ 2003.06.13 MIK
#define	CUSTMENU_INDEX_FOR_RBUTTONUP	0


/*!< �F�^�C�v */
//@@@ From Here 2006.12.18 ryoji
#define COLOR_ATTRIB_FORCE_DISP		0x00000001
//#define COLOR_ATTRIB_NO_TEXT		0x00000010	�\��l
#define COLOR_ATTRIB_NO_BACK		0x00000020
#define COLOR_ATTRIB_NO_BOLD		0x00000100
#define COLOR_ATTRIB_NO_UNDERLINE	0x00000200
//#define COLOR_ATTRIB_NO_ITALIC		0x00000400	�\��l
#define COLOR_ATTRIB_NO_EFFECTS		0x00000F00

typedef struct ColorAttributeData_t{
	char* szName;
	unsigned int fAttribute;
} ColorAttributeData;

SAKURA_CORE_API extern const ColorAttributeData g_ColorAttributeArr[];
//@@@ To Here 2006.12.18 ryoji

/*!< �ݒ�l�̏���E���� */
//	���[���̍���
const int IDC_SPIN_nRulerHeight_MIN = 2;
const int IDC_SPIN_nRulerHeight_MAX = 32;

// Feb. 18, 2003 genta �ő�l�̒萔���ƒl�ύX
const int LINESPACE_MAX = 128;
const int COLUMNSPACE_MAX = 64;


// novice 2002/09/14
#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef NULL
#define NULL 0
#endif

#ifndef BOOL
#define BOOL	int
#endif

//	Aug. 14, 2005 genta �萔��`�ǉ�
const int MAXLINESIZE	= 10240;	//!<	1�s�̌����̍ő�l
const int MINLINESIZE	= 20;		//!<	1�s�̌����̍ŏ��l

const int LINEREADBUFSIZE	= 10240;	//!<	�t�@�C������1�s���f�[�^��ǂݍ��ނƂ��̃o�b�t�@�T�C�Y

/**	�}�E�X�N���b�N�ƃL�[��`�̑Ή�

	@date 2007.11.04 genta �V�K�쐬�D���l����Ɣ͈̓T�C�Y��`�̂���
*/
enum MOUSEFUNCTION_ASSIGN {
	MOUSEFUNCTION_DOUBLECLICK	= 0,	//!< �_�u���N���b�N
	MOUSEFUNCTION_RIGHT			= 1,	//!< �E�N���b�N
	MOUSEFUNCTION_CENTER		= 2,	//!< ���N���b�N
	MOUSEFUNCTION_LEFTSIDE		= 3,	//!< ���T�C�h�N���b�N
	MOUSEFUNCTION_RIGHTSIDE		= 4,	//!< �E�T�C�h�N���b�N
	MOUSEFUNCTION_TRIPLECLICK	= 5,	//!< �g���v���N���b�N
	MOUSEFUNCTION_QUADCLICK		= 6,	//!< �N�A�h���v���N���b�N
	MOUSEFUNCTION_KEYBEGIN		= 7,	//!< �}�E�X�ւ̊��蓖�Č����{���̃L�[���蓖�Đ擪INDEX
};

// 2008.05.30 nasukoji	�e�L�X�g�̐܂�Ԃ����@
enum WRAP_TEXT_WRAP_METHOD {
	WRAP_NO_TEXT_WRAP		= 0,		// �܂�Ԃ��Ȃ��i�X�N���[���o�[���e�L�X�g���ɍ��킹��j
	WRAP_SETTING_WIDTH,					// �w�茅�Ő܂�Ԃ�
	WRAP_WINDOW_WIDTH,					// �E�[�Ő܂�Ԃ�
};

///////////////////////////////////////////////////////////////////////
#endif /* _GLOBAL_H_ */


/*[EOF]*/