#pragma once
#include"CSuperMath.h"
class CSuperMathFactory:public IClassFactory
{
public:
	virtual /* [local] */ HRESULT STDMETHODCALLTYPE CreateInstance(
		/* [annotation][unique][in] */
		_In_opt_  IUnknown *pUnkOuter,
		/* [annotation][in] */
		_In_  REFIID riid,
		/* [annotation][iid_is][out] */
		_COM_Outptr_  void **ppvObject);

	virtual /* [local] */ HRESULT STDMETHODCALLTYPE LockServer(
		/* [in] */ BOOL fLock);
	virtual HRESULT STDMETHODCALLTYPE QueryInterface(
		/* [in] */ REFIID riid,
		/* [iid_is][out] */ _COM_Outptr_ void __RPC_FAR *__RPC_FAR *ppvObject);

	virtual ULONG STDMETHODCALLTYPE AddRef(void);

	virtual ULONG STDMETHODCALLTYPE Release(void);

public:
	static int m_nRefCount;
};

