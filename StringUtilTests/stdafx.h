// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // some CString constructors will be explicit
#define _AFX_NO_MFC_CONTROLS_IN_DIALOGS         // remove support for MFC controls in dialogs

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // Exclude rarely-used stuff from Windows headers
#endif

#include <afx.h> // Only to turn off MFC's false leak detection

#include <stdio.h>
#include <tchar.h>

//
// Google Test Framework
//
#pragma warning(push)
#pragma warning(disable : 28182 6011 4996) // Dereferencing NULL pointer
#define GTEST_ENV_HAS_STD_TUPLE_ 1
#include <gmock/gmock.h>
#include <gmock/gmock-nice-strict.h>
#include <gtest/gtest.h>
#pragma warning(pop)


#define NEVER_TRANSLATE(x) _T(x)
#define NEVER_TRANSLATEA(x)   x
#define NEVER_TRANSLATEL(x) L ## x
#define NEVER_TRANSLATEQ(x)   x

// TODO: reference additional headers your program requires here
