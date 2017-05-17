#!/usr/bin/php
<?php
function ft_split($entry)
{
	$out = explode(" ", $entry);
	if($entry != NULL)
		  sort($out);
	  return($out);
}
if ($argc != 1)
{
	$out = array();
	foreach ($argv as $tmp)
	{
		if ($tmp != $argv[0])
		{
			$new = ft_split($tmp);
			$out = array_merge($out, $new);
	     }
	}
	foreach ($out as $tmp2)
	{
		if(is_numeric($tmp2) == TRUE)
			$numbers[] = $tmp2;
	}
	sort($numbers, SORT_STRING);
	foreach ($out as $tmp2)
	{
		if(ctype_alpha($tmp2) == TRUE)
			$char[] = $tmp2;
	}
	sort($char, SORT_NATURAL | SORT_FLAG_CASE);
	foreach ($out as $tmp2)
	{
	if(ctype_alpha($tmp2) == FALSE && is_numeric($tmp2) == FALSE)
		$others[] = $tmp2;
}
sort($others);
foreach($char as $end)
	echo $end."\n";
foreach($numbers as $end)
	echo $end."\n";
foreach($others as $end)
	echo $end."\n";
}
?>