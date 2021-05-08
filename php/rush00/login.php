<?php
	session_start();
	require_once './header.php';
?>

<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title>connexion</title>
		<link rel="stylesheet" href="main.css"/>
	</head>
	<body>
		<div class="login">
			<form action="auth.php" method="post">
				<br/>
				identifiant:&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp<input type="text" name="login">
				<br/><br/>
				mot de passe:&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp<input type="password" name="passwd">
				<br/><br/>
				<input type="submit" name="submit" value="OK">
				<br/><br/>
			</form>
			<a href="./forgotpass.php">mot de passe oublié</a>
			<br/><br/>
		</div>
	</body>
</html>
