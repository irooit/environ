# Environ -- PHP's extension

A simple PHP server environment judgment extension

## Requirement

PHP 7+

## Install

### Compile Environ in Linux

```bash
$ git clone https://github.com/persiliao/environ
$ cd environ
$ /path/to/phpize
$ ./configure --with-php-config=/path/to/php-config
$ make && make install
```

### Edit php.ini

```ini
[environ]
extension=environ.so
environ.name=development
environ.location=local
```

## IDE helper

```bash
composer require persiliao/environ-ide-helper
```

## Manual

```php
<?php
// Return environ.name
PersiLiao\Environ::getName();

// Return environ.location
PersiLiao\Environ::getLocation();
    
// Check if environ.name is production
PersiLiao\Environ::isProduction();
    
// Check if environ.name is gray
PersiLiao\Environ::isGray();
    
// Check if environ.name is prerelease
PersiLiao\Environ::isPreRelease();
    
// Check if environ.name is test
PersiLiao\Environ::isTest();

// Check if environ.name is development
PersiLiao\Environ::isDevelopment();
    
// Check if environ.name is local
PersiLiao\Environ::isLocal();
```
    