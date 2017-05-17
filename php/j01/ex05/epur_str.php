#!/usr/bin/php
<?php
if($argc == 2)
{
	$out = trim($argv[1]);
	while(strstr($out, "  "))
		$out = str_replace("  ", " ", $out);
	echo $out."\n";
}
?>