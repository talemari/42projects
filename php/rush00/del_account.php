<?php
	session_start();
	require_once './fonctions/ft_database.php';

	$link = ft_database_connect();
	$passwd = hash("sha512", htmlspecialchars(mysqli_real_escape_string($link, $_POST['passwd'])));
	$id = $_POST['id'];
	$user = ft_get_user_infos($link, $id);

	if ($passwd == $user['passwd'])
	{
		mysqli_query($link, "DELETE FROM users WHERE id=$id;");
		header('Location: ./logout.php');
	}
	else
		echo "Mot de passe invalide\n";
?>
