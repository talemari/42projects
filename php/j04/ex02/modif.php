<?php
if ($_POST['login'] && $_POST['oldpw'] && $_POST['newpw'] && $_POST['submit'] == "OK")
{
	$npwd = hash("whirlpool", $_POST['newpw'], FALSE);
	$opwd = hash("whirlpool", $_POST['oldpw'], FALSE);
	$session = array("login"=>$_POST['login'], "npw"=>$npwd, "opw"=>$opwd);
	if (!file_exists("../ex01/private/passwd") || $opwd === $npwd)
	{
		echo "ERROR\n";
		return;
	}
	$content = unserialize(file_get_contents("../ex01/private/passwd"));
	foreach($content as $key => $elem)
	{
		if ($elem['login'] === $session['login'])
		{
			if ($elem['passwd'] === $session['opw'])
			{
				$content[$key]['passwd'] = $session['npw'];
				file_put_contents("../ex01/private/passwd", serialize($content));
				echo "OK\n";
				return;
			}
		}
	}
	echo "ERROR\n";
}
else
	echo "ERROR\n";
?>
