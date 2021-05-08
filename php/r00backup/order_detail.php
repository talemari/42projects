<?php
	session_start();

	require_once './fonctions/ft_database.php';
	require_once './header.php';

	$link = ft_database_connect();
	$order_id = htmlspecialchars(mysqli_real_escape_string($link, $_GET['id']));
	$order = mysqli_query($link, "SELECT * FROM cart WHERE id='" . $order_id . "';");
	while ($a = mysqli_fetch_array($order))
		$orders[] = $a;
?>
<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title></title>
		<link rel="stylesheet" href="main.css"/>
	</head>
	<body>
		<div class="order_details">
	<?php	if ($order): ?>
				<table>
					<tr style="text-align:center;">
						<th>Article</th>
						<th>Quantité</th>
						<th>Prix unitaire</th>
						<th>Sous-total</th>
					</tr>
			<?php	foreach ($order as $key => $value): ?>
						<tr style="text-align:center;">
					<?php	$prod = ft_get_product_infos($link, $value['id_article']) ?>
							<td style="width:50%;"><?= $prod['name'] ?></td>
							<td style="width:20%;"><?= $value['quantity'] ?></td>
							<td style="width:21%;"><?= $value['price'] ?> €</td>
							<td style="width:21%;"><?= $value['quantity'] * $value['price'] ?> €</td>
							<?php $total += $value['quantity'] * $value['price'] ?>
						</tr>
			<?php	endforeach; ?>
					<tr style="height:20px;"></tr>
					<tr style="text-align:center;">
						<td></td>
						<td></td>
						<td><b>Total</b></td>
						<td><?= $total ?> €</td>
					</tr>
				</table>
	<?php	endif; ?>
		</div>
		<a style="margin-left:49%;" href="./account.php"><button type="button" name="button">Retour</button></a>
	</body>
</html>
