#!/usr/bin/php
<?php
date_default_timezone_set('Europe/paris');
$user = get_current_user();
$var = file_get_contents("/var/run/utmpx");
$sub = substr($var, 1256);
$tab = array();
$typedef = 'a256user/a4id/a32line/ipid/itype/I2time/a256host/i16pad';
while ($sub != NULL)
{
	$array = unpack($typedef, $sub);
	if (strcmp(trim($array[user]), $user) == 0 && $array[type] == 7)
		{
			$date = date("M  j H:i", $array["time1"]);
			$tty = trim($array[line]);
			$tty = $tty . "  ";
			$user2 = trim($array[user]);
			$user2 = $user2 . "  ";
			$tab2 = array($user2.$tty.$date);
			$tab = array_merge($tab, $tab2);
		}
	$sub = substr($sub, 628);  
}
sort($tab);
foreach ($tab as $elem)
	echo "$elem\n";
?>