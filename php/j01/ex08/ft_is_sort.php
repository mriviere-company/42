#!/usr/bin/php
<?php
function ft_is_sort($tab)
{
	$tmp = array_merge($tab);
	sort($tmp);
	$nb = count($tab)-1;
	$i = 0;
	while($i++ != $nb)
{
	if($tmp[$i] != $tab[$i])
		    return(FALSE);
}
	return(TRUE);
}
?>