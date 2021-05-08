<?php
if ($_POST['login'] && $_POST['passwd'] && $_POST['submit'] == "OK")
{
	$pwd = hash("whirlpool", $_POST['passwd'], FALSE);
	$session = array("login"=>$_POST['login'], "passwd"=>$pwd);
	if (!file_exists("private"))
		mkdir("private");
	if (file_exists("private/passwd"))
		$content = unserialize(file_get_contents("private/passwd"));
	foreach($content as $elem)
	{
		if ($elem['login'] === $session['login'])
		{
			echo "ERROR\n";
			return;
		}
	}
	$content[] = $session;
	file_put_contents("private/passwd", serialize($content));
	echo "OK\n";
}
else
	echo "ERROR\n";
?>
