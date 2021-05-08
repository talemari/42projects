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
			<form action="reg.php" method="post">
				<br />
				addresse e-mail:&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp<input type="text" name="login" value="<?php if($_SESSION['login'] != NULL) echo $_SESSION['login']?>">
				<br /><br />
				mot de passe&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp<input type="password" name="passwd">
				<br /><br />
				confirmation mot de passe&nbsp&nbsp<input type="password" name="passwd2">
				<br /><br />
				<input type="submit" name="submit" value="OK">
				<br /><br />
			</form>
		</div>
	</body>
</html>
