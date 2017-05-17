#!/usr/bin/php
<?php
function ft_split($entry)
{
	$out = explode(" ", $entry);
	if($entry != NULL)
		  sort($out);
	  return($out);
}
$out = trim($argv[1]);
while(strstr($out, "  "))
	$out = str_replace("  ", " ", $out);
$tmp = explode(" ", $out);
$one = array_shift($tmp);
foreach($tmp as $ex)
     echo $ex." ";
if($argc != 1)
	 echo $one."\n";
?>