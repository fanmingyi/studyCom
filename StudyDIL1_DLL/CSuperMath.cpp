#include "CSuperMath.h"
#include "CSuperMath.h"    

HRESULT __stdcall CSuperMath::Add(long n1, long n2, long * result)
{
	*result = n1 + n2;
	return S_OK;
}

HRESULT __stdcall CSuperMath::QueryInterface(REFIID riid, void ** ppvObject)
{

	if (memcmp(&riid, &IID_IUnknown, sizeof(REFIID)) == 0)
	{
		*ppvObject = (IUnknown *)this;
	}
	else if (memcmp(&riid, &IID_ISuperMath, sizeof(REFIID)) == 0)
	{
		*ppvObject = (ISuperMath *)this;
	}
	else {
		return E_NOINTERFACE;
	}
	AddRef();
	return S_OK;
}

ULONG __stdcall CSuperMath::AddRef(void)
{
	CSuperMath::m_nRefCount++;
	return 0;
}

ULONG __stdcall CSuperMath::Release(void)
{
	CSuperMath::m_nRefCount--;
	if (CSuperMath::m_nRefCount <= 0)
	{
		delete this;
	}
	return 0;
}
int CSuperMath::m_nRefCount = 0;