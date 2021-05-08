<?php
	session_start();
	require_once './fonctions/ft_database.php';

	if ($_SESSION['group'] == "admin")
	{
		$link = ft_database_connect();
		$id = htmlspecialchars(mysqli_real_escape_string($link, $_GET['id']));
		mysqli_query($link, "DELETE FROM categories WHERE id=$id;");
		header('Location: ./admin.php');
	}
	else
		header('Location: ./index.php');
?>
