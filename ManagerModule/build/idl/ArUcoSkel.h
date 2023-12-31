// -*- C++ -*-
/*!
 *
 * THIS FILE IS GENERATED AUTOMATICALLY!! DO NOT EDIT!!
 *
 * @file ArUcoSkel.h 
 * @brief ArUco server skeleton header wrapper code
 * @date Fri Aug 25 14:21:02 2023 
 *
 */

#ifndef ARUCOSKEL_H
#define ARUCOSKEL_H


#include <rtm/config_rtc.h>
#undef PACKAGE_BUGREPORT
#undef PACKAGE_NAME
#undef PACKAGE_STRING
#undef PACKAGE_TARNAME
#undef PACKAGE_VERSION

#if   defined ORB_IS_TAO
#  include "ArUcoC.h"
#  include "ArUcoS.h"
#elif defined ORB_IS_OMNIORB
#  if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#    ifdef USE_stub_in_nt_dll
#        undef USE_stub_in_nt_dll
#    endif
#    ifdef OpenRTM_IMPORT_SYMBOL
#        define USE_stub_in_nt_dll
#    endif
#  endif
#  include "ArUco.hh"
//#  include "ArUcoUtil.h"
#elif defined ORB_IS_MICO
#  include "ArUco.h"
#elif defined ORB_IS_ORBIT2
#  include "/ArUco-cpp-stubs.h"
#  include "/ArUco-cpp-skels.h"
#elif defined ORB_IS_RTORB
#  include "ArUco.h"
#elif defined ORB_IS_ORBEXPRESS
#  include "ArUco.h"
#else
#  error "NO ORB defined"
#endif

#endif // ARUCOSKEL_H
