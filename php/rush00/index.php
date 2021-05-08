<?php
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
		<div class="new">
			<h2>Nouveaux articles</h2>
	<?php	if ($new): ?>
		<?php	foreach ($new as $key => $value): ?>
					<form class="item" action="add_product_cart.php" method="post">
						<img src="<?= $value['src'] ?>" style="width:90%; height:auto; margin-top:5%;">
						<div style="margin:1%"><b><?= $value['name'] ?></b></div>
						<div style="margin:1%"><b><?= $value['price'] ?> €</b></div>
						<input type="hidden" name="id" value="<?= $value['id'] ?>">
						<input type="text" name="quantity" value="1" style="text-align:center; width:30px; margin:1%;">
						<div style="margin-bottom:5%;"><input type="submit" name="submit" value="ajouter au panier"></div>
					</form>
		<?php 	endforeach; ?>
	<?php	endif; ?>
		</div>
	</body>
</html>
