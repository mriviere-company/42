<?php
if($_POST["submit"] === "OK")
	{
	if($_POST["newpw"] === "")
		echo "ERROR\n";
	else
	{
		$same = FALSE;
		$sel = hash('snefru256', '%*@#$%!#%~');
		$sel1 = $sel.$_POST['newpw'];
		$sel2 = $sel.$_POST['oldpw'];
		$pwd = hash('whirlpool', $sel1);
		$oldpwd = hash('whirlpool', $sel2);
		$array = file_get_contents("../private/passwd");
		$serial = unserialize($array);
		foreach($serial as $tmp)
		{
			if($tmp === $_POST['login'])
				$ok = TRUE;
			if($ok === TRUE && $tmp === $oldpwd)
			{
				$serial['passwd'] = $pwd;
				$same = TRUE;
			}
		}
		if($same == TRUE)
		{
			$serial2 = serialize($serial);
			file_put_contents("../private/passwd", $serial2);
			echo "OK\n";
		}
		else
			echo "ERROR\n";
	}
}
?>