<?php
	session_start();
?>

<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title>boutique</title>
		<link rel="stylesheet" href="main.css"/>
	</head>
	<header>
		<a class="header_home" href="./index.php">Accueil</a>
		<a class="header_prod" href="./products.php">Produits</a>
<?php	if ($_SESSION['login'] == NULL): ?>
			<a style='margin-left:4%;' href='./cart.php'>Panier</a>
			<a class='header_login' href='./login.php'>Connexion</a>
			<a class='header_register' href='./register.php'>Inscription</a>
<?php	else: ?>
	<?php	if ($_SESSION['group'] == "admin"): ?>
				<a style="margin-left:-4%;" href='./cart.php'>Panier</a>
				<a class='header_login' href='./admin.php'>Gestion</a>
				<a class="header_login" href="./account.php">Mon compte</a>
	<?php	else: ?>
				<a style='margin-left:2%;' href='./cart.php'>Panier</a>
				<a class='header_login' href='./account.php'>Mon compte</a>
	<?php	endif; ?>
			<a class='header_register' href='./logout.php'>Deconnexion</a>
<?php	endif; ?>
	</header>
</html>
