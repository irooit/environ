--TEST--
Check for environ presence
--SKIPIF--
<?php if (!extension_loaded("environ")) print "skip"; ?>
--FILE--
<?php 
echo PersiLiao\Environ::getName();
echo PHP_EOL;
echo PersiLiao\Environ::getLocation();
echo PHP_EOL;
?>
--EXPECT--
development
local

