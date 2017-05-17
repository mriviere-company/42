#!/usr/bin/php
<?php
while(1)
{
	echo "Entrez un nombre:";
	$nbr = trim(fgets(STDIN));
	if(feof(STDIN) == TRUE)
	       exit();
	if(!is_numeric($nbr))
		echo $nbr." n\'est pas un chiffre\n";
	else
	{
		echo "le nombre ".$nbr." est ";
		if(substr($nbr, -1) % 2 == 0)
			echo "Pair\n";
		else
		echo "Impair\n";
	}
}
?>