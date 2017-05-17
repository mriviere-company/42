#!/usr/bin/php
<?php
function ft_split($entry)
{
	$out = trim($entry);
	while(strstr($out, "  "))
		$out = str_replace("  ", " ", $out);
	$out = explode(" ", $out);
	if($out != NULL)
		sort($out);
	return($out);
}
?>