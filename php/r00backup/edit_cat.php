<?php
	session_start();
	require_once './fonctions/ft_database.php';

	if ($_SESSION['group'] == "admin")
	{
		$link = ft_database_connect();
		$name = htmlspecialchars(mysqli_real_escape_string($link, $_POST['name']));
		$name = htmlspecialchars($name);
		$id = htmlspecialchars(mysqli_real_escape_string($link, $_POST['id']));
		if ($name)
			mysqli_query($link, "UPDATE `categories` SET nom ='" . $name . "' WHERE id=$id;");
		header('Location: ./admin.php');
	}
	else
		header('Location: ./index.php');
?>
