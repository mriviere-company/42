#!/usr/bin/php
<?php
$end = NULL;
foreach ($argv as $key)
	{
	if ($key == $argv[0] || $key == $argv[1])
	   {
	   }
	else
	{
	   $v = explode(':', $key);
	   if ($v[0] == $argv[1])
	   $end = $v[1];
	   }
	 }
echo $end;
if (is_null($end) == FALSE)
   echo "\n";
?>