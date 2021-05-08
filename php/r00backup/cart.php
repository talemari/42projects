<?php
	session_start();
	require_once './header.php';
	require_once './fonctions/ft_database.php';

	$link = ft_database_connect();
	$cart = $_SESSION['cart'];
	$total = 0.0;
?>

<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title>Panier</title>
		<link rel="stylesheet" href="main.css"/>
	</head>
	<body>
		<div class="order">
	<?php	if ($cart): ?>
				<table>
					<tr>
						<th style="text-align:center; width:300px;">Article</th>
						<th style="text-align:center; width:150px;">Prix unitaire</th>
						<th style="text-align:center; width:150px;">Quantité</th>
						<th style="text-align:center; width:150px;">Sous total</th>
					</tr>
				<?php	foreach ($cart as $key => $value): ?>
					<?php	if ($cart[$key]): ?>
								<tr>
									<form action="edit_cart.php" method="post">
										<td style="text-align:center;"><?= $value['name'] ?></td>
										<td style="text-align:center;"><?= $value['price'] ?></td>
										<td style="text-align:center;"><?= $value['quantity'] ?></td>
										<td style="text-align:center;">
											<?= $value['quantity'] * $value['price'] ?> €
											<?php $total += $value['quantity'] * $value['price']; ?>
											<?php $_SESSION['total'] = $total; ?>
										</td>
										<td style="width:15%;"></td>
										<td><input type="submit" name="submit" value="+"></td>
										<td style="width:30px; text-align:center;"><?= $value['quantity'] ?></td>
										<td><input type="submit" name="submit" value="-"></td>
										<td><input type="submit" name="submit" value="supprimer"></td>
										<td><input type="hidden" name="id" value="<?= $value['id'] ?>"></td>
									</form>
								</tr>
					<?php	endif; ?>
				<?php	endforeach; ?>
					<tr style="height: 10px;"></tr>
					<tr>
						<td></td><td></td><td></td>
						<td style="text-align: center"><b>Total:</b></td>
					</tr>
					<tr>
						<td></td><td></td><td></td>
						<td style="text-align: center"><?= $total ?> €</td>
					</tr>
				</table>
		<?php	if ($_SESSION['login'] != NULL): ?>
					<div style="margin-left:80%;">
						<a href='./order.php'><button type="button" name="button">Passer la commande</button></a>
					</div>
		<?php	else: ?>
					<a href='./login.php'><button type="button" name="button">Se connecter</button></a>";
		<?php	endif; ?>
	<?php	else: ?>
				<div style="text-align:center;">
					<h3>Panier vide</h3>
					<a href='./products.php'><button type="button" name="button">Produits</button></a>
				</div>
	<?php	endif; ?>
		</div>
	</body>
</html>
