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
		<div class="login">
			<form class="log_form" action="reg.php" method="post">
				<div class="log_text"><p>Addresse e-mail:</p><input type="text" name="login" value="<?php if(isset($_SESSION['login'])) echo $_SESSION['login']?>"></div>
				<div class="log_text"><p>Mot de passe:</p><input type="password" name="passwd"></div>
				<div class="log_text"><p>Confirmer mot de passe:</p><input type="password" name="passwd2"></div>
				<input type="submit" name="submit" value="OK">
			</form>
		</div>
	</body>
</html>
