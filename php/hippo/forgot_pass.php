<?php
	session_start();
	require_once './fonctions/ft_database.php';

	$link = ft_database_connect();

	if (!($login = ft_check_login($link, htmlspecialchars(mysqli_real_escape_string($link, $_POST['login'])))))
		echo "email invalide\n";
	$newpw = hash("sha512", htmlspecialchars(mysqli_real_escape_string($link, $_POST['newpw'])));
	$newpw2 = hash("sha512", htmlspecialchars(mysqli_real_escape_string($link, $_POST['newpw2'])));
	if ($newpw == NULL || $newpw2 == NULL && $_POST['oubli'] != 1)
	{
		echo "champ non remplis\n";
		exit();
	}
	else if ($newpw != $newpw2)
	{
		echo "nouveaux mots de passe différents\n";
		exit();
	}
	else
	{
		mysqli_query($link, "UPDATE users SET passwd='" . $newpw . "' WHERE login='" . $_POST['login'] . "';");
	}
	header('Location: ./index.php');
?>
