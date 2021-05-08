<?php
	session_start();

	require_once './fonctions/ft_database.php';

	if ($_SESSION['group'] == "admin")
	{
		$link = ft_database_connect();

		$id = htmlspecialchars(mysqli_real_escape_string($link, $_POST['id']));
		$name = htmlspecialchars(mysqli_real_escape_string($link, $_POST['name']));
		$price = htmlspecialchars(mysqli_real_escape_string($link, $_POST['price']));
		$img = htmlspecialchars(mysqli_real_escape_string($link, $_POST['img']));
		$key = 0;
		while ($_POST[$key])
		{
			if (isset($_POST[$key]))
				$tab[] = $_POST[$key];
			$key++;
		}
		if ($tab)
			$category = implode(";", $tab);
		if (!ft_check_categories($link, $category))
			echo "catégorie invalide\n";
		else
			$category = ft_get_cat_id($link, $category);

		if ($name)
			mysqli_query($link, "UPDATE products SET name = '" . $name . "' WHERE id='" . $id . "';");
		if ($price)
			mysqli_query($link, "UPDATE products SET price = '" . $price . "' WHERE id='" . $id . "';");
		if ($img)
			mysqli_query($link, "UPDATE product SET img = '" . $img . "' WHERE id='" . $id . "';");
		if ($category)
			mysqli_query($link, "UPDATE products SET id_cat = '" . $category . "' WHERE id='" . $id . "';");
		header('Location: ./admin.php');
	}
	else
		header('Location: ./index.php');
?>
