

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for ISuperMath.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __ISuperMath_h_h__
#define __ISuperMath_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ISuperMath_FWD_DEFINED__
#define __ISuperMath_FWD_DEFINED__
typedef interface ISuperMath ISuperMath;

#endif 	/* __ISuperMath_FWD_DEFINED__ */


#ifndef __CSuperMath_FWD_DEFINED__
#define __CSuperMath_FWD_DEFINED__

#ifdef __cplusplus
typedef class CSuperMath CSuperMath;
#else
typedef struct CSuperMath CSuperMath;
#endif /* __cplusplus */

#endif 	/* __CSuperMath_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __ISuperMath_INTERFACE_DEFINED__
#define __ISuperMath_INTERFACE_DEFINED__

/* interface ISuperMath */
/* [uuid][object] */ 


EXTERN_C const IID IID_ISuperMath;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("963E0E6C-5CB2-8C16-93B8-1A4AFB30CEF7")
    ISuperMath : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ long n1,
            /* [in] */ long n2,
            /* [retval][out] */ long *result) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISuperMathVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISuperMath * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISuperMath * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISuperMath * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            ISuperMath * This,
            /* [in] */ long n1,
            /* [in] */ long n2,
            /* [retval][out] */ long *result);
        
        END_INTERFACE
    } ISuperMathVtbl;

    interface ISuperMath
    {
        CONST_VTBL struct ISuperMathVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISuperMath_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISuperMath_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISuperMath_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISuperMath_Add(This,n1,n2,result)	\
    ( (This)->lpVtbl -> Add(This,n1,n2,result) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISuperMath_INTERFACE_DEFINED__ */



#ifndef __MySuperMathLib_LIBRARY_DEFINED__
#define __MySuperMathLib_LIBRARY_DEFINED__

/* library MySuperMathLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_MySuperMathLib;

EXTERN_C const CLSID CLSID_CSuperMath;

#ifdef __cplusplus

class DECLSPEC_UUID("963E0E6C-5CB2-8C16-93B8-1A4AFB30CEF9")
CSuperMath;
#endif
#endif /* __MySuperMathLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


