<?php
	session_start();
	require_once './header.php';
	require_once './fonctions/ft_database.php';

	$link = ft_database_connect();
?>

<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title>editer une categorie</title>
	</head>
	<body>
<?php	if ($_SESSION['group'] == "admin"): ?>
	<?php	$id = htmlspecialchars(mysqli_real_escape_string($link, $_GET['id'])); ?>
	<?php	$link = ft_database_connect();	?>
	<?php	$user = ft_get_user_infos($link, $id);	?>
			<div class="edit">
				<form action="./edit_use.php" method="post">
					<br />
					email:&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp<input type="text" name="login" value="<?= $user['login']?>">
					<br /><br />
					<div style="text-align:left; margin-left: 17%;">
						groupe:<br />
						&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp<input type="radio" name="group" value="admin" <?= (($user['group'] == "admin") ? 'checked' : '') ?>><label for="admin">Administrateur</label>
						<br />
						&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp<input type="radio" name="group" value="user" <?= (($user['group'] == "user") ? 'checked' : '') ?>><label for="user">Utilisateur</label>
					</div>
					<br />
					<input type="hidden" name="id" value="<?= $id ?>">
					<input style="margin-bottom:3px; text-align:center;" type="submit" name="submit" value="OK">
					<br />
					<a href="./admin.php"><button style="margin-bottom:3px; text-align:center;" type="button" name="button">retour</button></a>
				</form>
			</div>
<?php	endif; ?>
	</body>
</html>
