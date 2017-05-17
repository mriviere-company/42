<?php
session_start();
if($_GET["submit"] == TRUE)
{
	if($_GET["submit"] == "OK")
	{
	 	$_SESSION['login'] = $_GET['login'];
	 	$_SESSION['passwd'] = $_GET['passwd'];
	}
}
?>
<html><body>
<form method="get" action=".">
Identifiant: <input type="text" name="login" value = "<?php if($_SESSION["login"] == TRUE) echo $_SESSION["login"];?>" />
<br>
Mot de passe: <input type="password" name="passwd" value = "<?php if($_SESSION["passwd"] == TRUE) echo $_SESSION["passwd"];?>" />
<input type="submit" name="submit" value="OK">
</form>
</body></html>