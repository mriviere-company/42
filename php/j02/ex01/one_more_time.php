#!/usr/bin/php
<?php
function check_format($argv)
{
	return(((preg_match("/(^[L|l]undi|^[M|m]ardi|^[M|m]ercredi|^[J|j]eudi|^[V|v]endredi|^[S|s]amedi|^[D|d]imanche) ([0-9]{1,2}) ([J|j]anvier|[F|f][e]vrier|[M|m]ars|[A|a]vril|[M|m]ai|[J|j]uin|[J|j]uillet|[A|a]o[u]t|[S|s]eptembre|[O|o]ctobre|[N|n]ovembre|[D|d][e]cembre) {1}[0-9]{4} {1}[0-9]{2}:[0-9]{2}:[0-9]{2}$/", $argv))));
}
function get_number($where)
{
	if ($where == "janvier" || $where == "Janvier")
	   return (1);
	if ($where == "fevrier" || $where == "Fevrier")
	    return (2);
	if ($where == "mars" || $where == "Mars")
	     return (3);
	if ($where == "avril" || $where == "Avril")
		return (4);
	if ($where == "mai" || $where == "Mai")
		return (5);
	if ($where == "Juin" || $where == "juin")
		return (6);
	if ($where == "juillet" || $where == "Juillet")
		return (7);
	if ($where == "Aout" || $where == "aout")
		return (8);
	if ($where == "septembre" || $where == "Septembre")
		return (9);
	if ($where == "octobre" || $where == "Octobre")
		return (10);
	if ($where == "novembre" || $where == "Novembre")
		return (11);
	if ($where == "decembre" || $where == "Decembre")
		return (12);
}
if($argc > 1)
{
	if (check_format($argv[1]) == FALSE)
	{
		echo "Wrong Format\n";
		     exit();
	 }
	else
	{
	    preg_match("/([0-9]{1,2})/", $argv[1], $day);
		preg_match("/([J|j]anvier|[F|f][e]vrier|[M|m]ars|[A|a]vril|[M|m]ai|[J|j]uin|[J|j]uillet|[A|a]o[u|û]t|[S|s]eptembre|[N|n]ovembre|[D|d][e]cembre)/", $argv[1], $month);
		$month = get_number($month[0]);
		preg_match("/[0-9]{4}/", $argv[1], $year);
	    preg_match("/[0-9]{2}:/", $argv[1], $hour);
		$hour[0] = substr($hour[0], 0, 2);
		preg_match("/:[0-9]{2}:/", $argv[1], $min);
		$min[0] = substr($min[0], 1);
		$min[0] = substr($min[0], 0, 2);
		preg_match("/:[0-9]{2}$/", $argv[1], $sec);
		$sec[0] = substr($sec[0], 1);
		date_default_timezone_set('Europe/Paris');
	if (checkdate($month, $day[0], $year[0]) == FALSE)
	{
			echo "Wrong Format\n";
		    exit();
	 }
		echo mktime($hour[0], $min[0], $sec[0], $month, $day[0], $year[0])."\n";
	}
}																	       
?>