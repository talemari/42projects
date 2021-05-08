<?php
	if(!isset($_SESSION))
		session_start();

	require_once './header.php';
	require_once './fonctions/ft_database.php';

	$link = ft_database_connect();
	$new = ft_get_new($link);
?>

<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title></title>
		<link rel="stylesheet" href="main.css"/>
	</head>
	<body>
		<div style="text-align:center">
			<?php include_once './chart_price.php' ?>
		</div>
	</body>
</html>
