/*!	@file
	@brief 共通定義

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

// 以下の ifdef ブロックは DLL から簡単にエクスポートさせるマクロを作成する標準的な方法です。
// この DLL 内のすべてのファイルはコマンドラインで定義された SAKURA_CORE_EXPORTS シンボル
// でコンパイルされます。このシンボルはこの DLL が使用するどのプロジェクト上でも未定義でなけ
// ればなりません。この方法ではソースファイルにこのファイルを含むすべてのプロジェクトが DLL
// からインポートされたものとして SAKURA_CORE_API 関数を参照し、そのためこの DLL はこのマク
// ロで定義されたシンボルをエクスポートされたものとして参照します。
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
//	古いSDK対策．新しいSDKでは不要
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


//Oct. 31, 2000 JEPRO TeX Keyword のために'\'を追加	//Nov. 9, 2000 JEPRO HSP Keyword のために'@'を追加
//#define IS_KEYWORD_CHAR(c) ((c) == '#' || (c) == '$' || __iscsym( (c) ))
//#define IS_KEYWORD_CHAR(c) ((c) == '#'/*35*/ || (c) == '$'/*36*/ || (c) == '@'/*64*/ || (c) == '\\'/*92*/ || __iscsym( (c) ))
SAKURA_CORE_API	extern const unsigned char gm_keyword_char[256];	//@@@ 2002.04.27
#define IS_KEYWORD_CHAR(c)	((int)(gm_keyword_char[(unsigned char)((c) & 0xff)]))	//@@@ 2002.04.27 ロケールに依存しない


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

//20020108 aroka コントロールプロセスと起動処理のためにミューテックス名を追加
// 2006.04.10 ryoji コントロールプロセス初期化完了を示すイベントフラグ名を追加
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
//	固定ファイル名
#define FN_APP_ICON "my_appicon.ico"
#define FN_GREP_ICON "my_grepicon.ico"
#define FN_TOOL_BMP "my_icons.bmp"

//	標準アプリケーションアイコンリソース名
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


/* ウィンドウのID */
#define IDW_STATUSBAR 123


#define IDM_SELWINDOW		10000
#define IDM_SELMRU			11000
#define IDM_SELOPENFOLDER	12000


/* 文字コードセット種別 */
SAKURA_CORE_API enum enumCodeType {
	CODE_SJIS,				/* SJIS */
	CODE_JIS,				/* JIS */
	CODE_EUC,				/* EUC */
	CODE_UNICODE,			/* Unicode */
	CODE_UTF8,				/* UTF-8 */
	CODE_UTF7,				/* UTF-7 */
	CODE_UNICODEBE,			/* Unicode BigEndian */
	CODE_CODEMAX,
	CODE_AUTODETECT	= 99	/* 文字コード自動判別 */
};

SAKURA_CORE_API extern const char* gm_pszCodeNameArr_1[];
SAKURA_CORE_API extern const char* gm_pszCodeNameArr_2[];
SAKURA_CORE_API extern const char* gm_pszCodeNameArr_3[];

/* コンボボックス用 自動判別を含む配列 */
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

/* アウトライン解析の種類 */
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
	OUTLINE_WZTXT,		// 2003.05.20 zenryaku 階層付テキストアウトライン解析
	OUTLINE_HTML,		// 2003.05.20 zenryaku HTMLアウトライン解析
	OUTLINE_TEX,		// 2003.07.20 naoh TeXアウトライン解析
	OUTLINE_FILE,		//	2002.04.01 YAZAKI ルールファイル用
	OUTLINE_PYTHON,		//	2007.02.08 genta Pythonアウトライン解析
	OUTLINE_ERLANG,		//	2009.08.11 genta Erlangアウトライン解析
	//	新しいアウトライン解析は必ずこの直前へ挿入
	OUTLINE_CODEMAX,
	OUTLINE_BOOKMARK,	//	2001.12.03 hor
	OUTLINE_DEFAULT =-1,//	2001.12.03 hor
	OUTLINE_UNKNOWN	= 99
};

// 2002/09/22 Moca EOL_CRLF_UNICODEを廃止
/* 行終端子の種類 */
SAKURA_CORE_API enum enumEOLType {
	EOL_NONE,
	EOL_CRLF,
	EOL_LFCR,
	EOL_LF,
	EOL_CR,
	EOL_CODEMAX,
	EOL_UNKNOWN = -1
};

/* 行終端子のデータ長 */
SAKURA_CORE_API enum enumEOLLen {
	LEN_EOL_NONE			= 0,
	LEN_EOL_CRLF			= 2,
	LEN_EOL_LFCR			= 2,
	LEN_EOL_LF				= 1,
	LEN_EOL_CR				= 1
//	LEN_EOL_UNKNOWN		0
};

/* ダイアログ表示方法 */ // アウトラインウィンドウ用に作成 20060201 aroka
SAKURA_CORE_API enum enumShowDlg {
	SHOW_NORMAL			= 0,
	SHOW_RELOAD			= 1,
	SHOW_TOGGLE			= 2,
};


#define EOL_TYPE_NUM	5

/* 行終端子の配列 */
SAKURA_CORE_API extern const enumEOLType gm_pnEolTypeArr[EOL_TYPE_NUM];

//	May 15, 2000 genta
//	CEOLへ移動
//	From Here
/* 行終端子のデータの配列 */
// SAKURA_CORE_API extern const char* gm_pszEolDataArr[EOL_TYPE_NUM];

/* 行終端子のデータ長の配列 */
// SAKURA_CORE_API extern const int gm_pnEolLenArr[EOL_TYPE_NUM];

/* 行終端子の表示名の配列 */
// SAKURA_CORE_API extern const char* gm_pszEolNameArr[EOL_TYPE_NUM];

/* 行終端子の種類を調べる */
// SAKURA_CORE_API enumEOLType GetEOLType( const char*, int );
//	To Here

/* 選択領域描画用パラメータ */
SAKURA_CORE_API extern const COLORREF	SELECTEDAREA_RGB;
SAKURA_CORE_API extern const int		SELECTEDAREA_ROP2;


/* スマートインデント種別 */
SAKURA_CORE_API enum enumSmartIndentType {
	SMARTINDENT_NONE,
	SMARTINDENT_CPP
};




// Stonee 注： 2000/01/12
// ここを変更したときは、global.cpp のg_ColorAttributeArrの定義も変更して下さい。
//	From Here Sept. 18, 2000 JEPRO 順番を大幅に入れ替えた
//	2007.09.09 Moca  中間の定義はお任せに変更
SAKURA_CORE_API enum enumColorIndexType {
	COLORIDX_TEXT = 0,      /* テキスト */
	COLORIDX_RULER,         /* ルーラー */
	COLORIDX_CARET,         /* キャレット */    // 2006.12.07 ryoji
	COLORIDX_CARET_IME,     /* IMEキャレット */ // 2006.12.07 ryoji
	COLORIDX_UNDERLINE,     /* カーソル行アンダーライン */
	COLORIDX_CURSORVLINE,   /* カーソル位置縦線 */ // 2006.05.13 Moca
	COLORIDX_GYOU,          /* 行番号 */
	COLORIDX_GYOU_MOD,      /* 行番号(変更行) */
	COLORIDX_TAB,           /* TAB記号 */
	COLORIDX_SPACE,         /* 半角空白 */ //2002.04.28 Add by KK 以降全て+1
	COLORIDX_ZENSPACE,      /* 日本語空白 */
	COLORIDX_CTRLCODE,      /* コントロールコード */
	COLORIDX_CRLF,          /* 改行記号 */
	COLORIDX_WRAP,          /* 折り返し記号 */
	COLORIDX_VERTLINE,      /* 指定桁縦線 */    // 2005.11.08 Moca
	COLORIDX_EOF,           /* EOF記号 */
	COLORIDX_DIGIT,         /* 半角数値 */  //@@@ 2001.02.17 by MIK //色設定Ver.3からユーザファイルに対しては文字列で処理しているのでリナンバリングしてもよい. Mar. 7, 2001 JEPRO noted
	COLORIDX_SEARCH,        /* 検索文字列 */
	COLORIDX_KEYWORD1,      /* 強調キーワード1 */ // 2002/03/13 novice
	COLORIDX_KEYWORD2,      /* 強調キーワード2 */ // 2002/03/13 novice  //MIK ADDED
	COLORIDX_KEYWORD3,      /* 強調キーワード3 */ // 2005.01.13 MIK 3-10 added
	COLORIDX_KEYWORD4,      /* 強調キーワード4 */
	COLORIDX_KEYWORD5,      /* 強調キーワード5 */
	COLORIDX_KEYWORD6,      /* 強調キーワード6 */
	COLORIDX_KEYWORD7,      /* 強調キーワード7 */
	COLORIDX_KEYWORD8,      /* 強調キーワード8 */
	COLORIDX_KEYWORD9,      /* 強調キーワード9 */
	COLORIDX_KEYWORD10,     /* 強調キーワード10 */
	COLORIDX_COMMENT,       /* 行コメント */                        //Dec. 4, 2000 shifted by MIK
	COLORIDX_SSTRING,       /* シングルクォーテーション文字列 */    //Dec. 4, 2000 shifted by MIK
	COLORIDX_WSTRING,       /* ダブルクォーテーション文字列 */      //Dec. 4, 2000 shifted by MIK
	COLORIDX_URL,           /* URL */                               //Dec. 4, 2000 shifted by MIK
	COLORIDX_REGEX1,        /* 正規表現キーワード1 */  //@@@ 2001.11.17 add MIK
	COLORIDX_REGEX2,        /* 正規表現キーワード2 */  //@@@ 2001.11.17 add MIK
	COLORIDX_REGEX3,        /* 正規表現キーワード3 */  //@@@ 2001.11.17 add MIK
	COLORIDX_REGEX4,        /* 正規表現キーワード4 */  //@@@ 2001.11.17 add MIK
	COLORIDX_REGEX5,        /* 正規表現キーワード5 */  //@@@ 2001.11.17 add MIK
	COLORIDX_REGEX6,        /* 正規表現キーワード6 */  //@@@ 2001.11.17 add MIK
	COLORIDX_REGEX7,        /* 正規表現キーワード7 */  //@@@ 2001.11.17 add MIK
	COLORIDX_REGEX8,        /* 正規表現キーワード8 */  //@@@ 2001.11.17 add MIK
	COLORIDX_REGEX9,        /* 正規表現キーワード9 */  //@@@ 2001.11.17 add MIK
	COLORIDX_REGEX10,       /* 正規表現キーワード10 */  //@@@ 2001.11.17 add MIK
	COLORIDX_DIFF_APPEND,   /* DIFF追加 */  //@@@ 2002.06.01 MIK
	COLORIDX_DIFF_CHANGE,   /* DIFF追加 */  //@@@ 2002.06.01 MIK
	COLORIDX_DIFF_DELETE,   /* DIFF追加 */  //@@@ 2002.06.01 MIK
	COLORIDX_BRACKET_PAIR,  /* 対括弧 */    // 02/09/18 ai Add
	COLORIDX_MARK,          /* ブックマーク */  // 02/10/16 ai Add

	//カラーの最後
	COLORIDX_LAST,          //Dec. 4, 2000 @@@2001.02.17 renumber by MIK				/* 2002/10/16 ai Mod 34→35 */

	//カラー表示制御用
	COLORIDX_BLOCK1,        /* ブロックコメント1(文字色と背景色は行コメントと同じ) */	/* 02/10/16 ai Mod 35→36 */
	COLORIDX_BLOCK2,        /* ブロックコメント2(文字色と背景色は行コメントと同じ) */	/* 02/10/16 ai Mod 36→37 */

	//1000-1099 : カラー表示制御用(正規表現キーワード)
	COLORIDX_REGEX_FIRST = 1000,
	COLORIDX_REGEX_LAST = 1099,
};
//	To Here Sept. 18, 2000



//@@@ From Here 2003.05.31 MIK
/*! タブウインドウ用メッセージサブコマンド */
SAKURA_CORE_API enum enumTabWndNotifyType {
	TWNT_REFRESH	= 0,		//再表示
	TWNT_ADD		= 1,		//ウインドウ登録
	TWNT_DEL		= 2,		//ウインドウ削除
	TWNT_ORDER		= 3,		//ウインドウ順序変更
	TWNT_FILE		= 4,		//ファイル名変更
	TWNT_MODE_ENABLE= 5,		//タブモード有効化	//2004.07.14 Kazika 追加
	TWNT_MODE_DISABLE= 6,		//タブモード無効化	//2004.08.27 Kazika 追加
	TWNT_WNDPL_ADJUST= 7,		//ウィンドウ位置合わせ	// 2007.04.03 ryoji 追加
};

/*! バーの表示・非表示 */
SAKURA_CORE_API	enum enumBarChangeNotifyType {
	MYBCN_TOOLBAR	= 0,		//ツールバー
	MYBCN_FUNCKEY	= 1,		//ファンクションキー
	MYBCN_TAB		= 2,		//タブ
	MYBCN_STATUSBAR	= 3,		//ステータスバー
};
//@@@ To Here 2003.05.31 MIK

//タブで使うカスタムメニューのインデックス	//@@@ 2003.06.13 MIK
#define	CUSTMENU_INDEX_FOR_TABWND		24
//右クリックメニューで使うカスタムメニューのインデックス	//@@@ 2003.06.13 MIK
#define	CUSTMENU_INDEX_FOR_RBUTTONUP	0


/*!< 色タイプ */
//@@@ From Here 2006.12.18 ryoji
#define COLOR_ATTRIB_FORCE_DISP		0x00000001
//#define COLOR_ATTRIB_NO_TEXT		0x00000010	予約値
#define COLOR_ATTRIB_NO_BACK		0x00000020
#define COLOR_ATTRIB_NO_BOLD		0x00000100
#define COLOR_ATTRIB_NO_UNDERLINE	0x00000200
//#define COLOR_ATTRIB_NO_ITALIC		0x00000400	予約値
#define COLOR_ATTRIB_NO_EFFECTS		0x00000F00

typedef struct ColorAttributeData_t{
	char* szName;
	unsigned int fAttribute;
} ColorAttributeData;

SAKURA_CORE_API extern const ColorAttributeData g_ColorAttributeArr[];
//@@@ To Here 2006.12.18 ryoji

/*!< 設定値の上限・下限 */
//	ルーラの高さ
const int IDC_SPIN_nRulerHeight_MIN = 2;
const int IDC_SPIN_nRulerHeight_MAX = 32;

// Feb. 18, 2003 genta 最大値の定数化と値変更
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

//	Aug. 14, 2005 genta 定数定義追加
const int MAXLINESIZE	= 10240;	//!<	1行の桁数の最大値
const int MINLINESIZE	= 20;		//!<	1行の桁数の最小値

const int LINEREADBUFSIZE	= 10240;	//!<	ファイルから1行分データを読み込むときのバッファサイズ

/**	マウスクリックとキー定義の対応

	@date 2007.11.04 genta 新規作成．即値回避と範囲サイズ定義のため
*/
enum MOUSEFUNCTION_ASSIGN {
	MOUSEFUNCTION_DOUBLECLICK	= 0,	//!< ダブルクリック
	MOUSEFUNCTION_RIGHT			= 1,	//!< 右クリック
	MOUSEFUNCTION_CENTER		= 2,	//!< 中クリック
	MOUSEFUNCTION_LEFTSIDE		= 3,	//!< 左サイドクリック
	MOUSEFUNCTION_RIGHTSIDE		= 4,	//!< 右サイドクリック
	MOUSEFUNCTION_TRIPLECLICK	= 5,	//!< トリプルクリック
	MOUSEFUNCTION_QUADCLICK		= 6,	//!< クアドラプルクリック
	MOUSEFUNCTION_KEYBEGIN		= 7,	//!< マウスへの割り当て個数＝本当のキー割り当て先頭INDEX
};

// 2008.05.30 nasukoji	テキストの折り返し方法
enum WRAP_TEXT_WRAP_METHOD {
	WRAP_NO_TEXT_WRAP		= 0,		// 折り返さない（スクロールバーをテキスト幅に合わせる）
	WRAP_SETTING_WIDTH,					// 指定桁で折り返す
	WRAP_WINDOW_WIDTH,					// 右端で折り返す
};

///////////////////////////////////////////////////////////////////////
#endif /* _GLOBAL_H_ */


/*[EOF]*/
