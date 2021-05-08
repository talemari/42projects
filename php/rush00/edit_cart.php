<?php
	session_start();

	require_once './fonctions/ft_database.php';

	$cart = $_SESSION['cart'];
	$id = $_POST['id'];

	if ($_POST['submit'] == "supprimer")
	{
		foreach ($cart as $key => $value)
			if ($value['id'] == $id)
				unset($cart[$key]);

		$_SESSION['cart'] = $cart;
	}
	if ($_POST['submit'] == "-")
	{
		foreach ($cart as $key => $value)
			if ($value['id'] == $id)
			{
				$cart[$key]['quantity'] -= 1;
				if ($cart[$key]['quantity'] <= 0)
					unset($cart[$key]);
				$_SESSION['cart'] = $cart;
			}
	}
	if ($_POST['submit'] == "+")
	{
		foreach ($cart as $key => $value)
			if ($value['id'] == $id)
			{
				$cart[$key]['quantity'] += 1;
				$_SESSION['cart'] = $cart;
			}
	}
	header('Location: ' . $_SERVER['HTTP_REFERER']);
?>
