<?php
if ($_GET["action"] == TRUE && $_GET["name"] == TRUE)
{
	if ($_GET["action"] == "del")
	   setcookie($_GET["name"], NULL, -1);
	if ($_GET["action"] == "set")
	   setcookie($_GET["name"], $_GET["value"], time() + (60 * 60 * 24 * 30));
	if ($_GET["action"] == "get" && $_COOKIE[$_GET["name"]] == TRUE)
	 		echo $_COOKIE[$_GET["name"]]."\n";
}
?>