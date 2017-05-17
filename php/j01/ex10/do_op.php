#!/usr/bin/php
<?php
if ($argc == 4)
{
	$nb1 = trim($argv[1]);
	$op = trim($argv[2]);
	$nb2 = trim($argv[3]);
	if(is_numeric($nb1) == FALSE)
	       echo "Incorrect Parameters\n";
	if(is_numeric($nb2) == FALSE)
	       echo "Incorrect Parameters\n";
	if(is_numeric($nb2) == TRUE && is_numeric($nb1) == TRUE)
{
	if($op == "+")
		echo $nb1 + $nb2."\n";
	if($op == "-")
		echo $nb1 - $nb2."\n";
	if($op == "%")
		echo $nb1 % $nb2."\n";
	if($op == "*")
		echo $nb1 * $nb2."\n";
	if($op == "/")
		echo $nb1 / $nb2."\n";
	if($op !=  "*" && $op != "-" && $op != "+" && $op != "/" && $op != "%")
	       echo "Incorrect Parameters\n";
}
}
else
	echo "Incorrect Parameters\n";
?>