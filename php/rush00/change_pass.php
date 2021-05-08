<?php
	session_start();
	require_once './fonctions/ft_database.php';

	$link = ft_database_connect();

	$login = $_SESSION['login'];
	if (!$login)
		if (!$login = ft_check_login(htmlspecialchars(mysqli_real_escape_string($link, $_POST['login']))))
			echo "email invalide\n";
	$oldpw = hash("sha512", htmlspecialchars(mysqli_real_escape_string($link, $_POST['oldpw'])));
	$newpw = hash("sha512", htmlspecialchars(mysqli_real_escape_string($link, $_POST['newpw'])));
	$newpw2 = hash("sha512", htmlspecialchars(mysqli_real_escape_string($link, $_POST['newpw2'])));
	$oldpw2 = ft_get_pass($link, $login);
	if ($oldpw == NULL || $newpw == NULL || $newpw2 == NULL && $_POST['oubli'] != 1)
	{
		echo "champ non remplis\n";
		exit();
	}
	else if ($newpw != $newpw2)
	{
		echo "nouveaux mots de passe différents\n";
		exit();
	}
	else if ($oldpw != $oldpw2["passwd"] && $_SESSION['forgotten'] != 1)
	{
		echo "ancien mot de passe invalide\n";
		exit();
	}
	else if ($newpw == $oldpw2["passwd"])
	{
		echo "nouveau mot de passe identique a l'ancien\n";
		exit();
	}
	else
	{
		mysqli_query($link, "UPDATE users SET passwd='" . $newpw . "' WHERE login='" . $login . "';");
		if ($oldpw == NULL)
			header('Location: ./login.php');
	}
	header('Location: ./account.php');
?>
