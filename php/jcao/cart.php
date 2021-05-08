<?php
	session_start();
	require_once './header.php';
	require_once './fonctions/ft_database.php';

	$link = ft_database_connect();
	if (isset($_SESSION['cart']))
		$cart = $_SESSION['cart'];
	else
		$cart = NULL;
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
				<table class="cart_table">
					<tr>
						<th class="cart_th">Article</th>
						<th class="cart_th">Prix unitaire</th>
						<th class="cart_th">Quantité</th>
						<th class="cart_th">Sous total</th>
					</tr>
				<?php	foreach ($cart as $key => $value): ?>
					<?php	if ($cart[$key]): ?>
								<tr>
									<form class="cart_form" action="edit_cart.php" method="post">
										<td class="cart_td"><?= $value['name'] ?></td>
										<td class="cart_td"><?= $value['price'] ?></td>
										<td class="cart_td"><?= $value['quantity'] ?></td>
										<td class="cart_td">
											<?= $value['quantity'] * $value['price'] ?> €
											<?php $total += $value['quantity'] * $value['price']; ?>
											<?php $_SESSION['total'] = $total; ?>
										</td>
										<td class="cart_td" style="width:15%;"></td>
										<td class="cart_td"><input type="submit" name="submit" value="+"></td>
										<td style="width:30px; text-align:center;"><?= $value['quantity'] ?></td>
										<td class="cart_td"><input type="submit" name="submit" value="-"></td>
										<td class="cart_td"><input type="submit" name="submit" value="Supprimer"></td>
										<td class="cart_td"><input type="hidden" name="id" value="<?= $value['id'] ?>"></td>
									</form>
								</tr>
					<?php	endif; ?>
				<?php	endforeach; ?>
					<tr>
						<td></td><td></td><td></td>
						<td style="text-align: center"><b>Total:</b></td>
					</tr>
					<tr>
						<td></td><td></td><td></td>
						<td style="text-align: center"><?= $total ?> €</td>
					</tr>
				</table>
		<?php	if (isset($_SESSION['login'])): ?>
					<div style="margin-left:80%;">
						<a href='./order.php'><button type="button" name="button">Passer la commande</button></a>
					</div>
		<?php	else: ?>
					<a href='./login.php'><button type="button" name="button">Se connecter</button></a>
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
