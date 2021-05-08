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
	<?php	$category = ft_get_cat_infos($link, $id);	?>
			<div class="edit">
				<form action="./edit_cat.php" method="post">
					<br />
					nom:&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp<input type="text" name="name" value="<?= $category['nom'] ?>">
					<br />
					<input type="hidden" name="id" value="<?= $id ?>">
					<input type="submit" name="submit" value="OK">
				</form>
				<a href="./admin.php"><button type="button" name="retour">Retour</button></a>
				<br />
			</div>
<?php	endif; ?>
	</body>
</html>
