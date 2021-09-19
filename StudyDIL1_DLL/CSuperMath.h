#pragma once
#include"ISuperMath_h.h"
class CSuperMath :public ISuperMath
{
public:
	static int m_nRefCount;
public:
	virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Add(
		/* [in] */ long n1,
		/* [in] */ long n2,
		/* [retval][out] */ long *result);


	virtual HRESULT STDMETHODCALLTYPE QueryInterface(
		/* [in] */ REFIID riid,
		/* [iid_is][out] */ _COM_Outptr_ void __RPC_FAR *__RPC_FAR *ppvObject) ;

	virtual ULONG STDMETHODCALLTYPE AddRef(void);

	virtual ULONG STDMETHODCALLTYPE Release(void);

};

