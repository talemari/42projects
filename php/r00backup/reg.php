<?php
	require_once './fonctions/ft_database.php';

	if ($_POST['submit'] = 'OK')
	{
		$link = ft_database_connect();
		$passwd = hash("sha512", htmlspecialchars(mysqli_real_escape_string($link, $_POST['passwd'])));
		$passwd2 = hash("sha512", htmlspecialchars(mysqli_real_escape_string($link, $_POST['passwd2'])));
		$login = htmlspecialchars(mysqli_real_escape_string($link, $_POST['login']));
		if ($login == NULL)
			echo "identifiant invalide\n";
		else if ($passwd == NULL || $passwd2 == NULL)
			echo "mot de passe invalide\n";
		else if ($passwd != $passwd2)
			echo "les mots de passe ne sont pas identiques\n";
		else if (!ft_validmail($login))
			echo "email invalide\n";
		else if ($login != NULL && $passwd != NULL && $passwd === $passwd2 && ft_check_login($link, $login))
		{
			mysqli_query($link, "INSERT INTO users (login, passwd, `group`) VALUES ('$login', '$passwd', 'user');");
			header('Location: ./index.php');
		}
	}
?>
