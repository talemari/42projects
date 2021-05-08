<?php
	session_start();

	require_once './fonctions/ft_database.php';

	$link = ft_database_connect();
	$categories = ft_get_categories($link);
	if ($_SESSION['cart'])
		$cart = $_SESSION['cart'];
	else
		$cart = array();
	if ($_POST['submit'] == "Ajouter au panier")
	{
		$id = $_POST['id'];
		$product = ft_get_product_infos($link, $id);
		if (ft_check_in_cart($cart, $id))
		{
			foreach ($cart as $key => $value)
				if ($value['id'] == $id)
				{
					$cart[$key]['quantity'] += htmlspecialchars(mysqli_real_escape_string($link, $_POST['quantity']));
					$_SESSION['cart'] = $cart;
					header('Location: ' . $_SERVER['HTTP_REFERER']);
					exit;
				}
		}
		else
		{
			$product['quantity'] = htmlspecialchars(mysqli_real_escape_string($link, $_POST['quantity']));
			$cart[] = $product;
			$_SESSION['cart'] = $cart;
			header('Location: ' . $_SERVER['HTTP_REFERER']);
			exit;
		}
	}
	else
		header('Location: ' . $_SERVER['HTTP_REFERER']);
?>
