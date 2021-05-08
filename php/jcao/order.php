<?php
	session_start();

	if ($_SESSION['login'] == NULL)
		header('Location: ./login.php');

	date_default_timezone_set('Europe/Paris');
	require_once './header.php';
	require_once './fonctions/ft_database.php';

	$link = ft_database_connect();
	$cart = $_SESSION['cart'];
	$user = ft_get_user_id($link, $_SESSION['login']);
	if ($cart)
	{
		foreach ($cart as $key => $value)
		{
			$stock = mysqli_query($link, "SELECT `stock` FROM products WHERE name='" . $value['name'] . "';");
			$a_stock[] = mysqli_fetch_array($stock);
			if ($a_stock[0]['stock'] - $value['quantity'] < 0)
				$not_enough[] = $value['name'];
		}
		if (!isset($not_enough))
		{
			$date = date("Y-m-d H:i:s");
			mysqli_query($link, "INSERT INTO `order` (user_id, order_date, total) VALUES ('" . $user['id'] . "', '" . $date . "', '" . $_SESSION['total'] . "');");
			$order = mysqli_query($link, "SELECT * FROM `order` WHERE order_date='" . $date . "';");
			$order = mysqli_fetch_array($order);
			$id = $order['id'];
			foreach ($cart as $key => $value)
			{
				mysqli_query($link, "INSERT INTO cart (id, id_article, quantity, price) VALUES ('" . $id . "', '" . $value['id'] . "', '" . $value['quantity'] . "', '" . $value['price'] . "');");
				mysqli_query($link, "UPDATE products SET `stock`=`stock` - '".$value['quantity']."' WHERE name='" . $value['name'] . "';");
			}
			$_SESSION['cart'] = NULL;
			$_SESSION['total'] = 0;
		}
	}
?>

<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title></title>
	</head>
	<body style="padding: 0; margin: 0; margin-top: 100px;">
		<?php if (isset($not_enough)):?>
				<p>La commande n'a pas pu s'effectuer:</p>
			<?php foreach ($not_enough as $prod_name):?>
					<p>Le produit<?=$prod_name?> n'a pas assez de stock</p>
		<?php endforeach;?>
		<?php else: ?>
			<p style="margin-left: 5%;">Commande effectuée</p>
			<a target="_blank" href="print_order.php?id=<?= $id?>" style="color:blue; margin-left: 5%; text-decoration:none;">Imprimer la facture</a>
		<?php endif; ?>
	</body>
</html>
