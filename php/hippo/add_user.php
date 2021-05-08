<?php
	session_start();

	require_once './header.php';
	require_once './fonctions/ft_database.php';

	if ($_SESSION['group'] == "admin")
	{
		$link = ft_database_connect();
		$login = htmlspecialchars(mysqli_real_escape_string($link, $_POST['login']));
		$passwd = hash("sha512", htmlspecialchars(mysqli_real_escape_string($link, $_POST['passwd'])));
		$group = htmlspecialchars(mysqli_real_escape_string($link, $_POST['group']));
		if ($login && $passwd && $group && ft_check_login($link, $login))
			mysqli_query($link, "INSERT INTO users (login, passwd, `group`) VALUES $VALUES ('$login', '$passwd', '$group');");
	}
?>

<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title>ajout utilisateur</title>
	</head>
	<body>
<?php	if ($_SESSION['group'] == "admin"): ?>
			<div  class="add">
				<br />
				<form action="./add_user.php" method="post">
					e-mail:&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp<input type="text" name="login">
					<br /><br />
					mot de passe:&nbsp&nbsp&nbsp&nbsp<input type="password" name="passwd">
					<br /><br />
					<div style="text-align:left; margin-left: 9%;">
						groupe:<br />
						&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp<input type="radio" name="group" value="admin"><label for="admin">Administrateur</label>
						<br />
						&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp<input type="radio" name="group" value="user" checked="checked"><label for="user">Utilisateur</label>
					</div>
					<br />
					<input type="submit" name="submit" value="OK">
				</form>
				<a href="./admin.php"><button type="button" name="retour">retour</button></a>
				<br /><br />
			</div>
<?php	endif; ?>
	</body>
</html>
