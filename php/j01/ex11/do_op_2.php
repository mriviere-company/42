#!/usr/bin/php
<?php
if ($argc != 2)
       echo "Incorrect Parameters\n";
else
{
explode(";", "+;-;*;/;%");
$op = sscanf($argv[1], "%d %c %d %s");
if(ctype_alpha($op[3]) == FALSE)
{
	if($op[0] && $op[1] && $op[2])
	{
		if($op[1] == "+")
			  echo $op[0] + $op[2]."\n";
		if($op[1] == "-")
			echo $op[0] - $op[2]."\n";
		if($op[1] == "*")
			echo $op[0] * $op[2]."\n";
		if($op[1] == "/")
			echo $op[0] / $op[2]."\n";
		if($op[1] == "%")
			echo $op[0] % $op[2]."\n";
		if($op[1] != "*" && $op[1] != "-" && $op[1] != "+" && $op[1] != "/" && $op[1] != "%")
			echo "Syntax Error\n";
	}
}
else
	echo "Syntax Error\n";
}
?>