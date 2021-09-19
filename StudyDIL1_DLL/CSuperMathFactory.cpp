#include "CSuperMathFactory.h"

HRESULT __stdcall CSuperMathFactory::CreateInstance(IUnknown * pUnkOuter, REFIID riid, void ** ppvObject)
{
	static CSuperMath *pObject = NULL;

	if (pObject == NULL)
		pObject = new CSuperMath();


	HRESULT hr = pObject->QueryInterface(riid, ppvObject);
	if (FAILED(hr) && CSuperMath::m_nRefCount == 0)
	{
		delete pObject;
		pObject = NULL;
		return hr;
	}

	*ppvObject = pObject;
	
	return S_OK;
}

HRESULT __stdcall CSuperMathFactory::LockServer(BOOL fLock)
{
	return S_OK;
}

HRESULT __stdcall CSuperMathFactory::QueryInterface(REFIID riid, void ** ppvObject)
{

	if (memcmp(&riid,&IID_IUnknown,sizeof(REFIID))==0)
	{
		*ppvObject = (IUnknown*)this;
	}
	else if (memcmp(&riid, &IID_IClassFactory, sizeof(REFIID)) == 0)
	{
		*ppvObject = (IClassFactory*)this;

	}else{
		return E_NOINTERFACE;
	}
	AddRef();
	return S_OK;
}

ULONG __stdcall CSuperMathFactory::AddRef(void)
{

	CSuperMathFactory::m_nRefCount++;
	return CSuperMathFactory::m_nRefCount;

}

ULONG __stdcall CSuperMathFactory::Release(void)
{
	CSuperMathFactory::m_nRefCount--;
	return CSuperMathFactory::m_nRefCount;

}
int CSuperMathFactory::m_nRefCount = 0;