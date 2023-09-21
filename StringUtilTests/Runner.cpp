// ExampleHooksTests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <afx.h> // Only to turn off MFC's false leak detection
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <objbase.h>
#include <fstream>

// google test and mock
#include <gmock/gmock.h>
#include <gtest/gtest.h>

//#include <TestHelpers/TestTaskbarProgress.h>

int main( int argc, char* argv[] )
{
   AfxEnableMemoryTracking( FALSE );

   ::testing::InitGoogleTest( &argc, argv );
   ::testing::InitGoogleMock( &argc, argv );

   //TestTaskbarProgress taskbarProgress;

   int result = RUN_ALL_TESTS();

   return result;
}

