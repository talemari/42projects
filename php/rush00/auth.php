<?php
	session_start();
	require_once './fonctions/ft_database.php';

	$link = ft_database_connect();
	$login = htmlspecialchars(mysqli_real_escape_string($link, $_POST['login']));
	$passwd = hash("sha512", htmlspecialchars(mysqli_real_escape_string($link, $_POST['passwd'])));

	if ($login != NULL && $passwd != NULL)
	{
		$info = ft_get_pass($link, $login);
		if ($info["passwd"] === $passwd)
		{
			$_SESSION['login'] = $login;
			$_SESSION['group'] = $info["group"];
			header('Location: ./index.php');
		}
		else
			echo "identifiant ou mot de passe invalide\n";
	}
?>
