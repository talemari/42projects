<?php
	session_start();
	require_once './header.php';
	require 'recaptchalib.php';
	$site_key='6LeIxAcTAAAAAJcZVRqyHh71UMIEGNQ_MXjiZKhI';
?>

<!DOCTYPE html>
<html>
	<head>
		<script src="https://www.google.com/recaptcha/api.js"></script>
		<meta charset="utf-8">
		<title>connexion</title>
		<?php if (isset($_GET['captcha']) && $_GET['captcha'] === 'false'){ ?>
		<h1 style="color: red; text-align: center;">Captcha invalide</h1>
		<?php } ?>
		<?php if (isset($_GET['password']) && $_GET['password'] === 'false'){ ?>
		<h1 style="color: red; text-align: center;">Mot de passe ou identifiant invalide</h1>
		<?php } ?>
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
				<div class="g-recaptcha" data-sitekey="<?php echo $site_key; ?>"></div>
				<br/><br/>
				<input type="submit" name="submit" value="OK">
			</form>
			<a href="./forgotpass.php">mot de passe oublié</a>
			<br/><br/>
		</div>
	</body>
</html>
