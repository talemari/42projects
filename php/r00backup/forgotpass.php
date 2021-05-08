<?php
	session_start();
	require_once './header.php';
?>

<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title>inscription</title>
		<link rel="stylesheet" href="./main.css"/>
	</head>
	<body>
		<div class="register">
			<form action="change_pass.php" method="post">
				adresse e-mail:<input type="text" name="login">
				<br /><br />
				nouveau mot de passe&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp<input type="password" name="passwd">
				<br /><br />
				confirmation mot de passe&nbsp&nbsp<input type="password" name="passwd2">
				<br /><br />
				<input type="hidden" name="oubli" value="1">
				<input type="submit" name="submit" value="OK">
			</form>
		</div>
	</body>
</html>
