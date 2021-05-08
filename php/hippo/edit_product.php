<?php
	session_start();

	require_once './header.php';
	require_once './fonctions/ft_database.php';

	$link = ft_database_connect();
	$categories = ft_get_categories($link);
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
	<?php	$product = ft_get_product_infos($link, $id) ?>
	<?php	$_SESSION['id'] = $id; ?>
			<div class="edit">
				<form action="./edit_prod.php" method="post">
					<br />
					nom:&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp<input type="text" name="name" value="<?= $product['name'] ?>">
					<br /><br />
					prix:&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp<input type="text" name="price" value="<?= $product['price'] ?>">
					<br /><br />
					image:&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp<input type="text" name="img" value="<?= $product['src'] ?>">
					<br /><br />
					<div style="text-align:left; margin-left:9%;">
						catégories:<br /><br />
				<?php	if ($categories): ?>
					<?php	foreach ($categories as $key => $value): ?>
								&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp<input type="checkbox" name="<?= $key ?>" value="<?= $value['nom'] ?>" <?= ($value['id'] == $product['id_cat']) ? 'checked' : '' ?>><?= $value['nom'] ?>
								<br />
					<?php	endforeach; ?>
				<?php	else: ?>
							<a href="./add_category.php"><button type="button" name="ajouter categorie">Ajouter une catégorie</button></a>
				<?php	endif; ?>
					</div>
					<br />
					<input type="hidden" name="id" value="<?= $id ?>">
					<input type="submit" name="submit" value="OK">
					<br /><br />
					<a href="./admin.php"><button type="button" name="retour">Retour</button></a>
					<br /><br />
				</form>
			</div>
<?php	endif; ?>
	</body>
</html>
