<?php
	session_start();
	require_once './fonctions/ft_database.php';

	$link = ft_database_connect();
	$newmail = htmlspecialchars(mysqli_real_escape_string($link, $_POST['newmail']));
	$oldmail = htmlspecialchars(mysqli_real_escape_string($link, $_POST['oldmail']));
	$oldmail2 = $_SESSION['login'];

	if (!ft_check_login($link, $newmail))
		exit();
	if ($oldmail == NULL || $newmail == NULL)
	{
		echo "email invalide\n";
		exit();
	}
	if ($oldmail == $newmail)
	{
		echo "e-mails identiques\n";
		exit();
	}
	if ($oldmail != $oldmail2)
	{
		echo "ancien e-mail invalide\n";
		exit();
	}
	else
	{
		mysqli_query($link, "UPDATE users SET login='" . $newmail . "' WHERE login='" . $oldmail . "';");
		$_SESSION['login'] = $newmail;
	}
	header('Location: ./account.php');
?>
