<?php
	if(!isset($_SESSION))
		session_start();

	function ft_database_connect()
	{
		$link = mysqli_connect("localhost", "root", "nord59490", "db_rush");
		if (mysqli_connect_errno())
		{
			echo "Faied to connect to Mysql error " . mysqli_connect_error();
			exit();
		}
		else
			return ($link);
	}

	function ft_get_categories($link)
	{
		$cat = mysqli_query($link, "SELECT * FROM categories");
		while ($a = mysqli_fetch_array($cat))
			$cat_array[] = $a;
		return ($cat_array);
	}

	function ft_get_new($link)
	{
		$new = mysqli_query($link, "SELECT * FROM products WHERE DATEDIFF(CURDATE(), creation_date) <= 7");
		if ($new)
			while ($a = mysqli_fetch_array($new))
				if ($a)
					$new_array[] = $a;
		return ($new_array);
	}

	function ft_get_past_orders($link, $user)
	{
		$user = mysqli_query($link, "SELECT * FROM users WHERE login='" . $user . "';");
		$user = mysqli_fetch_array($user);
		$order = mysqli_query($link, "SELECT * FROM `order` WHERE user_id='" . $user['id'] . "' ORDER BY order_date;");
		if ($order)
			while ($a = mysqli_fetch_array($order))
				$order_array[] = $a;
		return ($order_array);
	}

	function ft_get_users($link)
	{
		$users = mysqli_query($link, "SELECT * FROM users");
		while ($a = mysqli_fetch_array($users))
			$users_array[] = $a;
		return ($users_array);
	}

	function ft_get_pass($link, $login)
	{
		$pass = mysqli_query($link, "SELECT * FROM users WHERE login='$login';");
		$passwd = mysqli_fetch_array($pass);
		return ($passwd);
	}

	function ft_validmail($mail)
	{
		if (filter_var($mail, FILTER_VALIDATE_EMAIL))
			return (TRUE);
		return (FALSE);
	}

	function ft_check_product($link, $prod)
	{
		$products = ft_get_products($link);
		if ($products)
			foreach ($products as $key => $value)
				if ($value['name'] == $prod)
					return (TRUE);
		return (FALSE);
	}

	function ft_check_category($link, $cat)
	{
		$categories = ft_get_categories($link);
		if ($categories)
			foreach ($categories as $key => $value)
				if ($value['nom'] == $cat)
					return (TRUE);
		return (FALSE);
	}

	function ft_check_categories($link, $cat)
	{
		$tab = explode(";", $cat);
		if ($tab)
		{
			foreach ($tab as $key => $value)
				if(!ft_check_category($link, $value))
					return (FALSE);
			return (TRUE);
		}
		else
			return (FALSE);
	}

	function ft_get_cat_id($link, $cat)
	{
		$categories = ft_get_categories($link);
		$tab = explode(";", $cat);
		if ($tab)
		{
			foreach ($tab as $key => $value1)
				foreach ($categories as $key => $value2)
					if ($value1 == $value2['nom'])
						$str[] = $value2['id'];
			return (implode(";", $str));
		}
		return (NULL);
	}

	function ft_get_id_names($link, $id)
	{
		$categories = ft_get_categories($link);
		$tab = explode(";", $id);
		if ($tab && $categories)
		{
			foreach ($tab as $key => $value1)
				foreach ($categories as $key => $value2)
					if ($value1 == $value2['id'])
						$str[] = $value2['nom'];
			if ($str)
				return (implode(";", $str));
		}
		return (NULL);
	}

	function ft_check_login($link, $login)
	{
		$users = ft_get_users($link);
		if (!ft_validmail($login))
		{
			echo "email invalide\n";
			return (FALSE);
		}
		else
			foreach ($users as $key => $value)
				if ($value == $login)
				{
					echo "l'utilisateur existe deja\n";
					return (FALSE);
				}
		return (TRUE);
	}

	function ft_get_user_infos($link, $id)
	{
		$infos = mysqli_query($link, "SELECT * FROM users WHERE id=$id;");
		if ($infos)
			$a = mysqli_fetch_array($infos);
		return ($a);
	}

	function ft_get_user_id($link, $login)
	{
		$infos = mysqli_query($link, "SELECT * FROM users WHERE login='" . $login . "';");
		if ($infos)
			$a = mysqli_fetch_array($infos);
		return ($a);
	}

	function ft_get_products($link)
	{
		$products = mysqli_query($link, "SELECT * FROM products;");
		if ($products)
			while ($a = mysqli_fetch_array($products))
				$prod[] = $a;
		return ($prod);
	}

	function ft_get_cat_infos($link, $id)
	{
		$category = mysqli_query($link, "SELECT * FROM `categories` WHERE id=$id;");
		if ($category)
			return (mysqli_fetch_array($category));
		else
			return (NULL);
	}

	function ft_get_product_infos($link, $id)
	{
		$infos = mysqli_query($link, "SELECT * FROM products WHERE id=$id;");
		if ($infos)
				$i = mysqli_fetch_array($infos);
		return ($i);
	}

	function ft_check_filter($filter, $id)
	{
		$tab = explode(";", $id);
		if (!$filter)
			return (TRUE);
		if ($tab && $id)
			foreach ($filter as $key => $value1)
			{
				foreach ($tab as $key => $value2)
				{
					if ($value2 == $value1)
						return (TRUE);
				}
			}
		return (FALSE);
	}

	function ft_check_in_cart($cart, $product)
	{
		if ($cart)
			foreach ($cart as $key => $value)
				if ($value['id'] == $product)
					return (TRUE);
		return (FALSE);
	}
?>
