/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2017 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: PersiLiao xiangchu.liao@gmail.com                            |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifndef PHP_ENVIRON_H
#define PHP_ENVIRON_H

extern zend_module_entry environ_module_entry;
#define phpext_environ_ptr &environ_module_entry

#define PHP_ENVIRON_VERSION "1.0.0" /* Replace with version number for your extension */

#define ENVIRON_PRODUCT     "production"
#define ENVIRON_PRE_RELEASE "prerelease"
#define ENVIRON_GRAY 	      "gray"
#define ENVIRON_TEST 	      "test"
#define ENVIRON_LOCAL 	    "local"
#define ENVIRON_DEV         "development"

#if PHP_MAJOR_VERSION < 7
    #define ENVIRON_RETURN_STRING(args) RETURN_STRING(args, 1)
#else
    #define ENVIRON_RETURN_STRING(args) RETURN_STRING(args)
#endif

#ifdef PHP_WIN32
#	define PHP_environ_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_environ_API __attribute__ ((visibility("default")))
#else
#	define PHP_environ_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_BEGIN_MODULE_GLOBALS(environ)
    char *name;
    char *location;
ZEND_END_MODULE_GLOBALS(environ)

#ifdef ZTS
#define ENVIRON_G(v) TSRMG(environ_globals_id, zend_environ_globals *, v)
#else
#define ENVIRON_G(v) (environ_globals.v)
#endif

#if defined(ZTS) && defined(COMPILE_DL_environ)
ZEND_TSRMLS_CACHE_EXTERN()
#endif

#endif	/* PHP_environ_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
