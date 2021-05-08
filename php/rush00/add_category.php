<?php
	session_start();

	require_once './header.php';
	require_once './fonctions/ft_database.php';

	if ($_SESSION['group'] == "admin")
	{
		$link = ft_database_connect();
		$category = htmlspecialchars(mysqli_real_escape_string($link, $_POST['cat']));
		if ($category && !ft_check_category($link, $category))
			mysqli_query($link, "INSERT INTO `categories` (nom) VALUES ('" . $category . "');");
		else if ($category)
			echo "nom invalide\n";
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
			<div class="add">
				<form action="./add_category.php" method="post">
					<br/>
					nom categorie:<input type="text" name="cat" autofocus="on"><input type="submit" name="submit" value="OK">
					<br/><br/>
				</form>
				<a href="./admin.php"><button type="button" name="retour">retour</button></a>
				<br/><br/>
			</div>
<?php	endif; ?>
	</body>
</html>
