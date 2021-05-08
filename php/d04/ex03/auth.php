<?php
function auth($login, $passwd)
{
	if (!file_exists("../ex01/private/passwd"))
		return (FALSE);
	$passwd = hash("whirlpool", $passwd, FALSE);
	$content = unserialize(file_get_contents("../ex01/private/passwd"));
	echo "TEST\n";
	foreach($content as $elem)
	{
		if ($elem['login'] === $login)
		{
			if ($elem['passwd'] === $passwd)
				return (TRUE);
		}
	}
	return (FALSE);
}
?>
