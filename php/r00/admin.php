<?php
	session_start();

	require_once './header.php';
	require_once './fonctions/ft_database.php';

	if ($_SESSION['group'] == "admin")
	{
		$link = ft_database_connect();
		$users = ft_get_users($link);
		$categories = ft_get_categories($link);
		$products = ft_get_products($link);
	}
?>

<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title>administration</title>
		<link rel="stylesheet" href="main.css"/>
	</head>
	<body class="body_admin">
<?php	if ($_SESSION['group'] == "admin"): ?>
			<div class="users">
				<table>
					<tr>
						<th style="width:30px; text-align:center;">id</th>
						<th style="width:350px; text-align:center;">login</th>
						<th style="width:70px; text-align:center;">groupe</th>
					</tr>
			<?php	if ($users): ?>
				<?php	foreach ($users as $key => $value): ?>
							<tr>
								<td style="text-align:center;"><?= $value["id"]; ?></td>
								<td style="text-align:center;"><?= $value["login"]; ?></td>
								<td style="text-align:center;"><?= $value["group"]; ?></td>
								<td style="width:39.5%;"></td>
						<?php 	if ($value['id'] != 1 && $value['login'] != $_SESSION['login']): ?>
									<td><a style="margin-right:20px;" href="./del_user.php?id=<?= $value['id'] ?>"><img src="./img/delete.png" />Supprimer</a><a href="./edit_user.php?id=<?= $value['id'] ?>"><img src="./img/edit.png" />Modifier</a><br /></td>
						<?php 	endif; ?>
							</tr>
				<?php	endforeach; ?>
			<?php	endif; ?>
				</table>
				<div style="margin-bottom:3px;">
					&nbsp<a href="./add_user.php"><img src="./img/add.png"/>Ajouter un utilisateur</a>
				</div>
			</div>
			<div class="categories">
				<table>
					<tr>
						<th style="width:30px; text-align:center;">id</th>
						<th style="width:350px; text-align:center;">nom</th>
					</tr>
			<?php 	if ($categories): ?>
				<?php	foreach ($categories as $key => $value): ?>
							<tr>
								<td style="text-align:center;"><?= $value["id"]; ?></td>
								<td style="text-align:center;"><?= $value["nom"]; ?></td>
								<td style="width:46.5%;"></td>
								<td><a style="margin-right:20px;" href="./del_category.php?id=<?= $value['id'] ?>"><img src="./img/delete.png" />Supprimer</a><a href="./edit_category.php?id=<?= $value['id'] ?>"><img src="./img/edit.png" />Modifier</a></td>
							</tr>
				<?php	endforeach; ?>
			<?php	endif; ?>
				</table>
				<div style="margin-bottom:3px;">
					&nbsp<a href="./add_category.php"><img src="./img/add.png" />Ajouter une catégorie</a>
				</div>
			</div>
			<div class="products">
				<table>
					<tr>
						<th style="width:30px; text-align:center;">Stock</th>
						<th style="width:350px; text-align:center;">nom</th>
						<th style="width:100px; text-align:center;">categorie</th>
						<th style="width:70px; text-align:center;">prix</th>
						<th style="width:150px; text-align:center;">date d'ajout</th>
					</tr>
			<?php	if ($products): ?>
				<?php	foreach ($products as $key => $value): ?>
							<tr>
								<td style="text-align:center;"><?= $value['stock'] ?></td>
								<td style="text-align:center;"><?= $value['name'] ?></td>
								<td style="text-align:center;"><?= ft_get_id_names($link, $value['id_cat']) ?></td>
								<td style="text-align:center;"><?= $value['price'] ?></td>
								<td style="text-align:center;"><?= $value['creation_date'] ?></td>
								<td style="width:15%;"></td>
								<td><a style="margin-right:20px;" href="./del_product.php?id=<?= $value['id'] ?>"><img src="./img/delete.png">Supprimer</a><a href="./edit_product.php?id=<?= $value['id'] ?>"><img src="./img/edit.png">Modifier</a></td>
							</tr>
				<?php	endforeach; ?>
			<?php	endif; ?>
				</table>
				<div style="margin-bottom:3px;">
					&nbsp<a href="./add_product.php"><img src="./img/add.png">Ajouter un produit</a>
				</div>
			</div>
<?php	endif; ?>
	</body>
</html>
