#pragma once

#include <cstdint>
#include <string>
#include <string_view>

#include <atlstr.h>

#ifdef _DLL/*static library*/
   #define STRINGUTIL_API
#else
   #ifdef STRINGUTILLIB_EXPORTS
      #define STRINGUTIL_API __declspec( dllexport )
   #else
      #define STRINGUTIL_API __declspec( dllimport )
   #endif
#endif

namespace StringUtil
{
   namespace Details
   {
      template <bool B>
      using Requires = std::enable_if_t<B, bool>;

      template <typename T>
      struct is_CStringT : public std::false_type
      {
      };

      template <typename BaseType, typename StringTraits>
      struct is_CStringT<ATL::CStringT<BaseType, StringTraits>> : public std::true_type
      {
      };
   }

   STRINGUTIL_API std::string ToStdString( std::string_view str );
   STRINGUTIL_API std::string ToStdString( std::wstring_view wstr );
   STRINGUTIL_API std::string ToStdString( std::u8string_view u8str );
   template <typename T, Details::Requires<Details::is_CStringT<T>::value> = true>
   std::string ToStdString( const T& atlStr )
   {
      return ToStdString( std::wstring_view{ atlStr.GetString(), (std::size_t)atlStr.GetLength() } );
   }

   ////////////////////////////////////////////

   STRINGUTIL_API std::wstring ToStdWString( std::string_view str );
   STRINGUTIL_API std::wstring ToStdWString( std::wstring_view wstr );
   STRINGUTIL_API std::wstring ToStdWString( std::u8string_view u8str );
   template <typename T, Details::Requires<Details::is_CStringT<T>::value> = true>
   std::wstring ToStdWString( const T& atlStr )
   {
      return ToStdWString( std::wstring_view{ atlStr.GetString(), (std::size_t)atlStr.GetLength() } );
   }

   ////////////////////////////////////////////

   STRINGUTIL_API std::u8string ToStdu8String( std::string_view str );
   STRINGUTIL_API std::u8string ToStdu8String( std::wstring_view wstr );
   STRINGUTIL_API std::u8string ToStdu8String( std::u8string_view u8str );
   template <typename T, Details::Requires<Details::is_CStringT<T>::value> = true>
   std::u8string ToStdu8String( const T& atlStr )
   {
      return ToStdu8String( std::wstring_view{ atlStr.GetString(), (std::size_t)atlStr.GetLength() } );
   }

   ////////////////////////////////////////////

   STRINGUTIL_API CAtlString ToCAtlString( std::string_view str );
   STRINGUTIL_API CAtlString ToCAtlString( std::wstring_view wstr );
   STRINGUTIL_API CAtlString ToCAtlString( std::u8string_view u8str );
}
