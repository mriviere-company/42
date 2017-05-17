<?php
function auth($login, $passwd)
{
	$same = FALSE;
	$sel = hash('snefru256', '%*@#$%!#%~');
	$sel1 = $sel.$passwd;
	$pwd = hash("whirlpool", $sel1);
	$array = file_get_contents("../private/passwd");
	$test = unserialize($array);
	foreach ($test as $tmp)
	{
		if($tmp === $login)
				$ok = TRUE;
		if($ok === TRUE && $tmp === $oldpwd)
			{
				$serial['passwd'] = $pwd;
				$same = TRUE;
			}
	}
	if ($same == FALSE)
		return (FALSE);
	else
		return (TRUE);
}
?>