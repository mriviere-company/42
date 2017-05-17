<?php
if($_POST['login'] != "" && $_POST['passwd'] != "" && $_POST['submit'] == "OK")
{
	$sel = hash('snefru256', '%*@#$%!#%~');
	$tmp = $sel.$_POST['passwd'];
	$pwd = hash('whirlpool', $tmp);
	if(file_exists("../private") == FALSE)
		mkdir("../private", 0777, true);
	if(file_exists("../private/passwd") == FALSE)
	{
		$tab = array(array('login'=>$_POST['login'], 'passwd'=>$pwd));
		$serial = serialize($tab);
		file_put_contents("../private/passwd", $serial);
	}
	else
	{
		$same = FALSE;
		$tab = file_get_contents("../private/passwd");
		$serial = unserialize($tab);
		$tmp2 = ("login");
		foreach ($serial as $tmp2)
			if ($tmp2 == $_POST['login'])
				$same = TRUE;
	}
	if($same == FALSE)
	{
		$tab2 = array('login'=>$_POST['login'], 'passwd'=>$pwd);
		$line2 = serialize($tab2);
		file_put_contents("../private/passwd", $line2);
		echo "OK";
	}
	else
		echo "ERROR";
}
else
	echo "ERROR";
?>