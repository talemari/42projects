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
		$date = date("Y-m-d H:i:s");
		mysqli_query($link, "INSERT INTO `order` (user_id, order_date, total) VALUES ('" . $user['id'] . "', '" . $date . "', '" . $_SESSION['total'] . "');");
		$order = mysqli_query($link, "SELECT * FROM `order` WHERE order_date='" . $date . "';");
		$order = mysqli_fetch_array($order);
		$id = $order['id'];
		foreach ($cart as $key => $value)
			mysqli_query($link, "INSERT INTO cart (id, id_article, quantity, price) VALUES ('" . $id . "', '" . $value['id'] . "', '" . $value['quantity'] . "', '" . $value['price'] . "');");
		$cart = NULL;
		$_SESSION['cart'] = $cart;
		$_SESSION['total'] = 0;
	}
?>

<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title></title>
	</head>
	<body>
		commande effectuée
	</body>
</html>
