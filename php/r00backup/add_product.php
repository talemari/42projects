<?php
	session_start();

	require_once './header.php';
	require_once './fonctions/ft_database.php';


	$link = ft_database_connect();
	$categories = ft_get_categories($link);

	if ($_SESSION['group'] == "admin")
	{
		if ($_POST['submit'] == "OK")
		{
			$product = htmlspecialchars(mysqli_real_escape_string($link, $_POST['product']));
			$price = htmlspecialchars(mysqli_real_escape_string($link, $_POST['price']));
			$src = htmlspecialchars(mysqli_real_escape_string($link, $_POST['img']));
			$key = 0;
			foreach ($categories as $key => $value)
			{
				if (isset($_POST[$value['nom']]))
					$tab[] = $_POST[$value['nom']];
				$key++;
			}

			if ($tab)
				$category = implode(";", $tab);
			if (!ft_check_categories($link, $category))
				echo "catégorie invalide\n";
			else if ($product != NULL && $price != NULL && $category != NULL && $price > 0 && $src != NULL)
			{
				$category = ft_get_cat_id($link, $category);
				mysqli_query($link, "INSERT INTO products (name, price, id_cat, creation_date, src) VALUES ('" . $product . "', '" . $price . "', '" . $category . "', CURDATE(), '" . $src . "');");
			}
			else if (!$product)
				echo "nom de produit invalide\n";
			else if (!$price || $price <= 0)
				echo "prix invalide\n";
			else if (!$category)
				echo "catégorie invalide\n";
			else if (!$src)
				echo "image invalide\n";
		}
	}
?>

<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title>ajout produit</title>
	</head>
	<body>
<?php	if ($_SESSION['group'] == "admin"): ?>
			<div class="add">
				<form action="./add_product.php" method="post">
					<br />
					nom du produit:&nbsp&nbsp&nbsp<input type="text" name="product" autofocus="on">
					<br /><br />
					prix:&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp<input type="text" name="price">
					<br /><br />
					image:&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp<input type="text" name="img" value="<?= $product['img'] ?>">
					<br /><br />
					<div style="text-align:left; margin-left: 9%;">
						catégories:<br />
				<?php	if ($categories): ?>
					<?php	foreach ($categories as $key => $value): ?>
								&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp<input type="checkbox" name="<?= $value['nom'] ?>" value="<?= $value['nom'] ?>"><?= $value['nom'] ?>
								<br />
					<?php	endforeach; ?>
				<?php	else: ?>
							<a href="./add_category.php"><button type="button" name="ajouter categorie">Ajouter une catégorie</button></a>
				<?php	endif; ?>
					</div>
					<br />
					<input type="submit" name="submit" value="OK">
					<br />
				</form>
				<a href="./admin.php"><button type="button" name="retour">Retour</button></a>
				<br /><br />
			</div>
<?php	endif; ?>
	</body>
</html>
