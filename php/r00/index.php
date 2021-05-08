<?php
	if(!isset($_SESSION))
		session_start();

	require_once './install.php';
	require_once './header.php';
	require_once './fonctions/ft_database.php';

	$link = ft_database_connect();
	$new = ft_get_new($link);
?>

<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title></title>
		<link rel="stylesheet" href="main.css"/>
	</head>
	<body>
	<?php	if ($new): ?>
		<div class="new">
			<h2>Nouveautés</h2>
		<?php	foreach ($new as $key => $value): ?>
					<div class="item">
						<img src="<?= $value['src'] ?>" style="position:relative; width:100%; height:auto;">
						<form class="item_form" action="./add_product_cart.php" method="post">						
							<div><b style="font-family: sans-serif; color: white; font-weight:300;"><?= $value['name'] ?></b></div>
							<div><b style="font-family: sans-serif; color: white; font-weight:300;"><?= $value['price'] ?> €</b></div>
							<input type="hidden" name="id" value="<?= $value['id'] ?>">
							<input type="text" name="quantity" value="1" style="text-align:center; width:30px; margin:1%;">
							<input type="submit" name="submit" value="Ajouter au panier">
						</form>
					</div>
		<?php 	endforeach; ?>
		</div>
	<?php	endif; ?>
	</body>
</html>
