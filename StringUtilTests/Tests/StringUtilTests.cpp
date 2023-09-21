#include "stdafx.h"

// google test and mock
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <StringUtil/StringUtil.h>

#include <atlstr.h>
#include <string>
#include <string_view>

using namespace testing;
using namespace std::string_literals;
using namespace std::string_view_literals;

class StringUtilTests : public ::testing::Test
{
};

#ifndef NEVER_TRANSLATE
#define NEVER_TRANSLATE(x) _T(x)
#define NEVER_TRANSLATEA(x)   x
#define NEVER_TRANSLATEL(x) L ## x
#endif

/////// ToStdString( CAtlString )

TEST_F( StringUtilTests, ToStdString_AnsiCAtlString_ReturnsCorrectStdString )
{
   CAtlString cstrInput( NEVER_TRANSLATE( "ABC123" ) );
   std::string strExpected = NEVER_TRANSLATEA( "ABC123"s );

   EXPECT_EQ( strExpected, StringUtil::ToStdString( cstrInput ) );
}

TEST_F( StringUtilTests, ToStdString_EmptyCAtlString_ReturnsEmptyStdString )
{
   CAtlString cstrInput;
   std::string strExpected;

   EXPECT_EQ( strExpected, StringUtil::ToStdString( cstrInput ) );
}

TEST_F( StringUtilTests, ToStdString_UnicodeCharacterCAtlString_ReturnsCorrectStdString )
{
   CAtlString cstrInput( NEVER_TRANSLATE( "\u2764\u2602\u260E\u2744" ) ); //Heart-symbol umbrella telephone snowflake
   std::u8string strExpectedAsU8( NEVER_TRANSLATEA( u8"\u2764\u2602\u260E\u2744"s ) );
   std::string strExpected( strExpectedAsU8.begin(), strExpectedAsU8.end() );

   EXPECT_EQ( strExpected, StringUtil::ToStdString( cstrInput ) );
}

///// ToStdString( std::wstring )

TEST_F( StringUtilTests, ToStdString_AnsiStdWString_ReturnsCorrectStdString )
{
   std::wstring strInput( NEVER_TRANSLATE( "ABC123" ) );
   std::string strExpected = NEVER_TRANSLATEA( "ABC123"s );

   EXPECT_EQ( strExpected, StringUtil::ToStdString( strInput ) );
}

TEST_F( StringUtilTests, ToStdString_EmptyStdWString_ReturnsEmptyStdString )
{
   std::wstring strInput;
   std::string strExpected;

   EXPECT_EQ( strExpected, StringUtil::ToStdString( strInput ) );
}

TEST_F( StringUtilTests, ToStdString_UnicodeCharacterStdWString_ReturnsCorrectStdString )
{
   std::wstring strInput( NEVER_TRANSLATE( "\u2764\u2602\u260E\u2744" ) ); //Heart-symbol umbrella telephone snowflake
   std::u8string strExpectedAsU8( NEVER_TRANSLATEA( u8"\u2764\u2602\u260E\u2744"s ) );
   std::string strExpected( strExpectedAsU8.begin(), strExpectedAsU8.end() );

   EXPECT_EQ( strExpected, StringUtil::ToStdString( strInput ) );
}

/////// ToStdWString( CAtlString )

TEST_F( StringUtilTests, ToStdWString_AnsiCAtlString_ReturnsCorrectStdWString )
{
   CAtlString cstrInput( NEVER_TRANSLATE( "ABC123" ) );
   std::wstring strExpected = NEVER_TRANSLATE( "ABC123" );

   EXPECT_EQ( strExpected, StringUtil::ToStdWString( cstrInput ) );
}

TEST_F( StringUtilTests, ToStdWString_EmptyCAtlString_ReturnsEmptyStdWString )
{
   CAtlString cstrInput;
   std::wstring strExpected;

   EXPECT_EQ( strExpected, StringUtil::ToStdWString( cstrInput ) );
}

TEST_F( StringUtilTests, ToStdWString_UnicodeCharacterCAtlString_ReturnsCorrectStdWString )
{
   CAtlString cstrInput( NEVER_TRANSLATE( "\u2764\u2602\u260E\u2744" ) ); //Heart-symbol umbrella telephone snowflake
   std::wstring strExpected = NEVER_TRANSLATE( "\u2764\u2602\u260E\u2744" );

   EXPECT_EQ( strExpected, StringUtil::ToStdWString( cstrInput ) );
}

/////// ToStdWString( std::string )

TEST_F( StringUtilTests, ToStdWString_AnsiStdString_ReturnsCorrectStdWString )
{
   std::string strInput( NEVER_TRANSLATEA( "ABC123"s ) );
   std::wstring strExpected = NEVER_TRANSLATE( "ABC123" );

   EXPECT_EQ( strExpected, StringUtil::ToStdWString( strInput ) );
}

TEST_F( StringUtilTests, ToStdWString_EmptyStdString_ReturnsEmptyStdWString )
{
   std::string strInput;
   std::wstring strExpected;

   EXPECT_EQ( strExpected, StringUtil::ToStdWString( strInput ) );
}

TEST_F( StringUtilTests, ToStdWString_UnicodeCharacterStdString_ReturnsCorrectStdWString )
{
   std::u8string strInputAsU8( NEVER_TRANSLATEA( u8"\u2764\u2602\u260E\u2744"s ) ); //Heart-symbol umbrella telephone snowflake
   std::string strInput( strInputAsU8.begin(), strInputAsU8.end() );
   std::wstring strExpected = NEVER_TRANSLATE( "\u2764\u2602\u260E\u2744" );

   EXPECT_EQ( strExpected, StringUtil::ToStdWString( strInput ) );
}

/////// ToCAtlString( std::string )

TEST_F( StringUtilTests, ToCAtlString_AnsiStdString_ReturnsCorrectCAtlString )
{
   std::string strInput( NEVER_TRANSLATEA( "ABC123"s ) );
   CAtlString cstrExpected = NEVER_TRANSLATE( "ABC123" );

   EXPECT_EQ( cstrExpected, StringUtil::ToCAtlString( strInput ) );
}

TEST_F( StringUtilTests, ToCAtlString_EmptyStdString_ReturnsEmptyCAtlString )
{
   std::string strInput;
   CAtlString cstrExpected;

   EXPECT_EQ( cstrExpected, StringUtil::ToCAtlString( strInput ) );
}

TEST_F( StringUtilTests, ToCAtlString_UnicodeCharacterStdString_ReturnsCorrectCAtlString )
{
   std::u8string strInputAsU8( NEVER_TRANSLATEA( u8"\u2764\u2602\u260E\u2744"s ) ); //Heart-symbol umbrella telephone snowflake
   std::string strInput( strInputAsU8.begin(), strInputAsU8.end() );
   CAtlString cstrExpected( NEVER_TRANSLATE( "\u2764\u2602\u260E\u2744" ) );

   EXPECT_EQ( cstrExpected, StringUtil::ToCAtlString( strInput ) );
}

/////// ToCAtlString( std::wstring )

TEST_F( StringUtilTests, ToCAtlString_AnsiStdWString_ReturnsCorrectCAtlString )
{
   std::wstring strInput( NEVER_TRANSLATE( "ABC123" ) );
   CAtlString cstrExpected = NEVER_TRANSLATE( "ABC123" );

   EXPECT_EQ( cstrExpected, StringUtil::ToCAtlString( strInput ) );
}

TEST_F( StringUtilTests, ToCAtlString_EmptyStdWString_ReturnsEmptyCAtlString )
{
   std::wstring strInput;
   CAtlString cstrExpected;

   EXPECT_EQ( cstrExpected, StringUtil::ToCAtlString( strInput ) );
}

TEST_F( StringUtilTests, ToCAtlString_UnicodeCharacterStdWString_ReturnsCorrectCAtlString )
{
   std::wstring strInput = NEVER_TRANSLATE( "\u2764\u2602\u260E\u2744" ); //Heart-symbol umbrella telephone snowflake
   CAtlString cstrExpected( NEVER_TRANSLATE( "\u2764\u2602\u260E\u2744" ) );

   EXPECT_EQ( cstrExpected, StringUtil::ToCAtlString( strInput ) );
}

/////// Comparing implementations

TEST_F( StringUtilTests, ToCAtlString_AnsiStdString_ReturnsCorrectCAtlStringAsToStdWStringToCAtlString )
{
   std::string strInput( NEVER_TRANSLATEA( "ABC123"s ) );
   CAtlString cstrExpected( StringUtil::ToStdWString( strInput ).c_str() );

   EXPECT_EQ( cstrExpected, StringUtil::ToCAtlString( strInput ) );
}

TEST_F( StringUtilTests, ToCAtlString_EmptyStdString_ReturnsEmptyCAtlStringAsToStdWStringToCAtlString )
{
   std::string strInput;
   CAtlString cstrExpected( StringUtil::ToStdWString( strInput ).c_str() );

   EXPECT_EQ( cstrExpected, StringUtil::ToCAtlString( strInput ) );
}

TEST_F( StringUtilTests, ToCAtlString_UnicodeCharacterStdString_ReturnsSameCAtlStringAsToStdWStringToCAtlString )
{
   std::u8string strInputAsU8( NEVER_TRANSLATEA( u8"\u2764\u2602\u260E\u2744"s ) ); //Heart-symbol umbrella telephone snowflake
   std::string strInput( strInputAsU8.begin(), strInputAsU8.end() );

   CAtlString cstrExpected( StringUtil::ToStdWString( strInput ).c_str() );

   EXPECT_EQ( cstrExpected, StringUtil::ToCAtlString( strInput ) );
}

///////// Testing with const char*

TEST_F( StringUtilTests, ToStdString_ConstCharString_ReturnsCorrectStdString )
{
   const char* pstrInput( NEVER_TRANSLATEA( "ABC123" ) );

   std::string strExpected( NEVER_TRANSLATEA( "ABC123" ) );

   EXPECT_EQ( strExpected, StringUtil::ToStdString( pstrInput ) );
}

TEST_F( StringUtilTests, ToStdWString_ConstCharString_ReturnsCorrectStdWString )
{
   const char* pstrInput( NEVER_TRANSLATEA( "ABC123" ) );

   std::wstring strwExpected( NEVER_TRANSLATE( "ABC123" ) );

   EXPECT_EQ( strwExpected, StringUtil::ToStdWString( pstrInput ) );
}

TEST_F( StringUtilTests, ToStdString_ConstWCharString_ReturnsCorrectStdString )
{
   const wchar_t* pwstrInput( NEVER_TRANSLATE( "ABC123" ) );

   std::string strExpected( NEVER_TRANSLATEA( "ABC123" ) );

   EXPECT_EQ( strExpected, StringUtil::ToStdString( pwstrInput ) );
}

TEST_F( StringUtilTests, ToStdWString_ConstWCharString_ReturnsCorrectStdWString )
{
   const wchar_t* pwstrInput( NEVER_TRANSLATE( "ABC123" ) );

   std::wstring strwExpected( NEVER_TRANSLATE( "ABC123" ) );

   EXPECT_EQ( strwExpected, StringUtil::ToStdWString( pwstrInput ) );
}

///////// Testing with std::string_view

TEST_F( StringUtilTests, ToStdString_StringView_ReturnsCorrectStdString )
{
   std::string_view strInput = NEVER_TRANSLATEA( "ABC123"sv );

   std::string strExpected( NEVER_TRANSLATEA( "ABC123" ) );

   EXPECT_EQ( strExpected, StringUtil::ToStdString( strInput ) );
}

TEST_F( StringUtilTests, ToStdWString_StringView_ReturnsCorrectStdWString )
{
   std::string_view strInput = NEVER_TRANSLATEA( "ABC123"sv );

   std::wstring strwExpected( NEVER_TRANSLATE( "ABC123" ) );

   EXPECT_EQ( strwExpected, StringUtil::ToStdWString( strInput ) );
}

TEST_F( StringUtilTests, ToStdString_WideStringView_ReturnsCorrectStdString )
{
   std::wstring_view strInput = NEVER_TRANSLATEA( L"ABC123"sv );

   std::string strExpected( NEVER_TRANSLATEA( "ABC123" ) );

   EXPECT_EQ( strExpected, StringUtil::ToStdString( strInput ) );
}

TEST_F( StringUtilTests, ToStdWString_WideStringView_ReturnsCorrectStdWString )
{
   std::wstring_view strInput = NEVER_TRANSLATEA( L"ABC123"sv );

   std::wstring strwExpected( NEVER_TRANSLATE( "ABC123" ) );

   EXPECT_EQ( strwExpected, StringUtil::ToStdWString( strInput ) );
}

TEST_F( StringUtilTests, ToStdString_CStringWithCRTStringTraits_ConvertsString )
{
   static_assert( std::is_same_v<CAtlString,
                  CStringT<TCHAR, StrTraitATL<TCHAR, ChTraitsCRT<TCHAR>>>> );

   CStringT<TCHAR, StrTraitATL<TCHAR, ChTraitsCRT<TCHAR>>> atlStr = NEVER_TRANSLATE( "ABC123" );
   const std::string strExpected = NEVER_TRANSLATEA( "ABC123" );

   EXPECT_EQ( strExpected, StringUtil::ToStdString( atlStr ) );
}

TEST_F( StringUtilTests, ToStdString_CStringNoCRTStringTraits_ConvertsString )
{
   static_assert( !std::is_same_v<CAtlString,
                  CStringT<TCHAR, StrTraitATL<TCHAR>>> );

   CStringT<TCHAR, StrTraitATL<TCHAR>> atlStr = NEVER_TRANSLATE( "ABC123" );
   const std::string strExpected = NEVER_TRANSLATEA( "ABC123" );

   EXPECT_EQ( strExpected, StringUtil::ToStdString( atlStr ) );
}

TEST_F( StringUtilTests, ToStdString_MFCDynamicCString_ConvertsString )
{
   static_assert( !std::is_same_v<CAtlString,
                  ATL::CStringT<TCHAR, StrTraitMFC_DLL<TCHAR>>> );

   ATL::CStringT<TCHAR, StrTraitMFC_DLL<TCHAR>> mfcStr = NEVER_TRANSLATE( "ABC123" );
   const std::string strExpected = NEVER_TRANSLATEA( "ABC123" );

   EXPECT_EQ( strExpected, StringUtil::ToStdString( mfcStr ) );
}

TEST_F( StringUtilTests, ToStdString_MFCStaticString_ConvertsString )
{
   static_assert( !std::is_same_v<CAtlString,
                  ATL::CStringT<TCHAR, StrTraitMFC<TCHAR>>> );

   ATL::CStringT<TCHAR, StrTraitMFC<TCHAR>> mfcStr = NEVER_TRANSLATE( "ABC123" );
   const std::string strExpected = NEVER_TRANSLATEA( "ABC123" );

   EXPECT_EQ( strExpected, StringUtil::ToStdString( mfcStr ) );
}

