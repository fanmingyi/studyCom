// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include"CSuperMathFactory.h"

//

const char * g_szRegTable[][3] = {
	{"CLSID\\{963E0E6C-5CB2-8C16-93B8-1A4AFB30CEF9}",0,"MySuperMath"	},
	{"CLSID\\{963E0E6C-5CB2-8C16-93B8-1A4AFB30CEF9}\\InprocServer32",0,(const char*)-1},
	{"CLSID\\{963E0E6C-5CB2-8C16-93B8-1A4AFB30CEF9}\\ProngID",0,"MySuperMathsrv.1"	},
	{"CLSID\\{963E0E6C-5CB2-8C16-93B8-1A4AFB30CEF9}\\TypeLib",0,"{963E0E6C-5CB2-8C16-93B8-1A4AFB30CEF9}"	},
	{"MySuperMathsrv.1",0,"MySuperMath"	},
	{"MySuperMathsrv.1\\CLSID",0,"{963E0E6C-5CB2-8C16-93B8-1A4AFB30CEF9}"	}

};
//
HMODULE g_hModule;
BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{

	g_hModule = hModule;
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
//
STDAPI DllCanUnloadNow() {
	return S_OK;
}
//安装
STDAPI DllRegisterServer(void) {
	char szBuf[MAX_PATH];
	for (size_t i = 0; i < (sizeof(g_szRegTable) / sizeof(g_szRegTable[0])); i++)
	{
		const char * pszSubKey = g_szRegTable[i][0];
		const char * pszValueName = g_szRegTable[i][1];
		const char * pszValue = g_szRegTable[i][2];

		HKEY hKey;

		int nRet= RegCreateKey(HKEY_CLASSES_ROOT, pszSubKey, &hKey);

		if (nRet != ERROR_SUCCESS)
		{
			
			return EXIT_FAILURE;
		}
		if (pszValue == (const char *)-1)
		{
			GetModuleFileName(g_hModule, szBuf, sizeof(szBuf));
			pszValue = szBuf;
		}
		RegSetValueEx(hKey, pszValueName, NULL, REG_SZ, (CONST BYTE*)pszValue, strlen(pszValue));
	}
	return S_OK;
}
//卸载
STDAPI DllUnregisterServer(void) {
	for (size_t i = (sizeof(g_szRegTable) / sizeof(g_szRegTable[0])) - 1; i >= 0; i--)
	{
		const char * pszSubKey = g_szRegTable[i][0];
		RegDeleteKey(HKEY_CLASSES_ROOT, pszSubKey);

	}
	return S_OK;
}

_Check_return_
STDAPI  DllGetClassObject(_In_ REFCLSID clsid, _In_ REFIID iid, _Outptr_ LPVOID FAR* ppv) {
	//判断创建哪个工厂
	if (memcmp(&clsid, &CLSID_CSuperMath, sizeof(GUID)) == 0)
	{
		static CSuperMathFactory*pObject = NULL;
		if (pObject == NULL)
		{
			pObject = new CSuperMathFactory();
		}
		HRESULT hr = pObject->QueryInterface(iid, ppv);
		if (FAILED(hr) && CSuperMathFactory::m_nRefCount == 0)
		{
			delete pObject;
			pObject = NULL;
			return hr;
		}
		return hr;

	}

	return E_NOINTERFACE;

}