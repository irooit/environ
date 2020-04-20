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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_version.h"
#include "php_ini.h"
#include "Zend/zend_API.h"
#include "ext/standard/info.h"
#include "php_environ.h"


ZEND_DECLARE_MODULE_GLOBALS(environ)

PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("environ.name", ENVIRON_DEV, PHP_INI_SYSTEM, OnUpdateString, name, zend_environ_globals, environ_globals)
    STD_PHP_INI_ENTRY("environ.location", ENVIRON_LOCAL, PHP_INI_SYSTEM, OnUpdateString, location, zend_environ_globals, environ_globals)
PHP_INI_END()

PHP_METHOD(environ, isProduction)
{
	if(strcmp(ENVIRON_G(name),ENVIRON_PRODUCT)==0){
		RETURN_TRUE
	}
	RETURN_FALSE
}

PHP_METHOD(environ, isGray)
{
	if(strcmp(ENVIRON_G(name),ENVIRON_GRAY)==0){
		RETURN_TRUE
	}
	RETURN_FALSE
}

PHP_METHOD(environ, isTest)
{
    if(strcmp(ENVIRON_G(name),ENVIRON_TEST)==0){
        RETURN_TRUE
    }
    RETURN_FALSE
}

PHP_METHOD(environ, isLocal)
{
	if(strcmp(ENVIRON_G(name),ENVIRON_LOCAL)==0){
		RETURN_TRUE
	}
	RETURN_FALSE
}

PHP_METHOD(environ, isPreRelease)
{
    if(strcmp(ENVIRON_G(name),ENVIRON_PRE_RELEASE)==0){
        RETURN_TRUE
    }
    RETURN_FALSE
}

PHP_METHOD(environ, isDevelopment)
{
    if(strcmp(ENVIRON_G(name),ENVIRON_DEV)==0){
        RETURN_TRUE
    }
    RETURN_FALSE
}

PHP_METHOD(environ, getName)
{
    ENVIRON_RETURN_STRING(ENVIRON_G(name));
}

PHP_METHOD(environ, getLocation)
{
    ENVIRON_RETURN_STRING(ENVIRON_G(location));
}

zend_function_entry environ_methods[] =
{
	PHP_ME(environ, isProduction, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	PHP_ME(environ, isGray, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	PHP_ME(environ, isDevelopment, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
  PHP_ME(environ, isPreRelease, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	PHP_ME(environ, isLocal, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	PHP_ME(environ, isTest, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
  PHP_ME(environ, getLocation, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	PHP_ME(environ, getName, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
    {NULL, NULL, NULL}
};

PHP_MINIT_FUNCTION (environ)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "PersiLiao\\Environ", environ_methods);
    zend_register_internal_class(&ce);
    REGISTER_INI_ENTRIES();
    return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(environ)
{
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(environ)
{
#if defined(COMPILE_DL_ENVIRON) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(environ)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(environ)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "environ support", "enabled");
    php_info_print_table_row(2, "Version", PHP_ENVIRON_VERSION);
    php_info_print_table_row(2, "Author", "PersiLiao");
    php_info_print_table_row(2, "Email", "xiangchu.liao@gmail.com");
    php_info_print_table_row(2, "Home", "https://github.com/persiliao/environ");
    php_info_print_table_end();
    DISPLAY_INI_ENTRIES();
}
/* }}} */

/* {{{ environ_functions[]
 *
 * Every user visible function must have an entry in environ_functions[].
 */
const zend_function_entry environ_functions[] = {
	PHP_FE_END	/* Must be the last line in environ_functions[] */
};
/* }}} */

/* {{{ environ_module_entry
 */
zend_module_entry environ_module_entry = {
	STANDARD_MODULE_HEADER,
	"environ",
	environ_functions,
	PHP_MINIT(environ),
	PHP_MSHUTDOWN(environ),
	PHP_RINIT(environ),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(environ),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(environ),
	PHP_ENVIRON_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_ENVIRON
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(environ)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
