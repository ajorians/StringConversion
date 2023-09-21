#include "StringUtil/StringUtil.h"

#include <Windows.h>
#include <cassert>

#ifndef VERIFY

#ifdef _DEBUG
#define VERIFY( f ) assert( f )
#else
#define VERIFY( f ) ( (void)( f ) )
#endif

#endif

namespace StringUtil
{
   std::string ToStdString( std::string_view str )
   {
      return std::string{ str };
   }

   std::string ToStdString( std::wstring_view wstr )
   {
      std::string str;
      int nchars = ::WideCharToMultiByte( CP_UTF8, 0, wstr.data(), (int)wstr.length(), NULL, NULL, NULL, NULL );
      if ( nchars > 0 )
      {
         str.resize( nchars );
         VERIFY( ::WideCharToMultiByte( CP_UTF8, 0, wstr.data(), (int)wstr.length(), const_cast<char*>( str.c_str() ), nchars, NULL, NULL ) );
      }

      return str;
   }

   ///////////////////////////////////////////

   std::wstring ToStdWString( std::string_view str )
   {
      std::wstring wstr;
      int nchars = ::MultiByteToWideChar( CP_UTF8, 0, str.data(), (int)str.length(), 0, 0 );
      if ( nchars > 0 )
      {
         wstr.resize( nchars );
         VERIFY( ::MultiByteToWideChar( CP_UTF8, 0, str.data(), (int)str.length(), const_cast<wchar_t*>( wstr.c_str() ), nchars ) );
      }

      return wstr;
   }

   std::wstring ToStdWString( std::wstring_view wstr )
   {
      return std::wstring{ wstr };
   }

   ///////////////////////////////////////////

   CAtlString ToCAtlString( std::string_view str )
   {
      CAtlString atlstr;
      int nchars = ::MultiByteToWideChar( CP_UTF8, 0, str.data(), (int)str.length(), 0, 0 );
      if ( nchars > 0 )
      {
         LPWSTR pwstr = atlstr.GetBufferSetLength( nchars );
         VERIFY( ::MultiByteToWideChar( CP_UTF8, 0, str.data(), (int)str.length(), pwstr, nchars ) );
      }

      return atlstr;
   }

   CAtlString ToCAtlString( std::wstring_view wstr )
   {
      return CAtlString( wstr.data() );
   }
}

