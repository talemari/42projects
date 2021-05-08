<?php
	session_start();
	require_once './fonctions/ft_database.php';

	if ($_SESSION['group'] == "admin" && $_POST['submit'] == "OK")
	{
		$link = ft_database_connect();
		$id = htmlspecialchars(mysqli_real_escape_string($link, $_POST['id']));
		$mail = htmlspecialchars(mysqli_real_escape_string($link, $_POST['login']));
		$group = htmlspecialchars(mysqli_real_escape_string($link, $_POST['group']));
		print_r ($group);
		if ($group != NULL)
			mysqli_query($link, "UPDATE users SET `group`"."='".$group."' WHERE id='".$id."';");
		if ($mail != NULL)
			mysqli_query($link, "UPDATE users SET login"."='".$mail."' WHERE id='".$id."';");
		header('Location: ./admin.php');
	}
	else
		header('Location: ./index.php');
?>
