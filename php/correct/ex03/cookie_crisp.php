<?php
	if ($_GET['action'] && $_GET['name'])
	{
		if ($_GET['action'] === "set")
		{
			if ($_GET['value'])
				setcookie($_GET['name'], $_GET['value']);
			else
				setcookie($_GET['name']);
		}
		else if ($_GET['action'] === "get" && $_COOKIE[$_GET['name']])
				echo $_COOKIE[$_GET['name']]."\n";
		else if ($_GET['action'] === "del")
		{
			setcookie($_GET['name'], "", time() - 3600);
		}
	}
?>
