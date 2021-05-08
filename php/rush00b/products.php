<?php
	session_start();
	require_once './header.php';
	require_once './fonctions/ft_database.php';

	$link = ft_database_connect();
	$products = ft_get_products($link);
	$categories = ft_get_categories($link);

	if (isset($_POST['filter']) && $_POST['filter'] == "filtrer")
	{
		$tab = NULL;
		foreach ($categories as $key => $value)
			if (isset($_POST[$value['nom']]))
				$tab[] = $_POST[$value['nom']];
	}
	if (isset($_POST['reset']) && $_POST['reset'] == "réinitialiser")
	{
		foreach ($categories as $key => $value)
			unset($_POST[$value['nom']]);
	}
	if(isset($_SESSION['cart']))
		$cart = $_SESSION['cart'];
	else
		$cart = NULL;
?>

<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title>Produits</title>
		<link rel="stylesheet" href="main.css"/>
	</head>
	<body>
		<div>
				<form class="filter" action="./products.php" method="post">
					<h3>Catégories :</h3>
			<?php	if ($categories): ?>
				<?php	foreach ($categories as $key => $value): ?>
							<div><input type="checkbox" name="<?= $value['nom'] ?>" value="<?= $value['id'] ?>" <?= (isset($_POST[$value['nom']]) ? 'checked' : '') ?>><?= $value['nom'] ?></div>
				<?php	endforeach; ?>
						<br />
						<div>
						<input type="submit" name="filter" value="filtrer">
						<input type="submit" name="reset" value="réinitialiser" style="margin-left:10px;">
						</div>
			<?php	endif; ?>
				</form>
		<?php 	if ($products): ?>
					<div class="new">
			<?php	foreach ($products as $key => $value): ?>
				<?php	if (!isset($tab) || ft_check_filter($tab, $value['id_cat'])): ?>
						<div class="item">
							<img src="<?= $value['src'] ?>" style="width:100%; height:auto;">
							<form class="item_form" action="add_product_cart.php" method="post">		
								<div><b><?= $value['name'] ?></b></div>
								<div><b><?= $value['price'] ?> €</b></div>
								<input type="hidden" name="id" value="<?= $value['id'] ?>">
								<input type="text" name="quantity" value="1" style="text-align:center; width:30px; margin:1%;">
								<input type="submit" name="submit" value="Ajouter au panier">
							</form>
						</div>
				<?php	endif; ?>
			<?php	endforeach; ?>
					</div>
		<?php 	endif; ?>
		</div>
	</body>
</html>
