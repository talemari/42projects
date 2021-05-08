<?php
	require 'recaptchalib.php';
	$secret_key ='6LeIxAcTAAAAAGG-vFI1TnRWxMZNFuojJ4WifJWe';
	$site_key='6LeIxAcTAAAAAJcZVRqyHh71UMIEGNQ_MXjiZKhI';

	session_start();
	require_once './fonctions/ft_database.php';
	?>
	<html>
		<script src="https://www.google.com/recaptcha/api.js"></script>
	</html>
<?php
	$reCaptcha = new ReCaptcha($secret_key);
	if(isset($_POST["g-recaptcha-response"])) {
		$resp = $reCaptcha->verifyResponse(
			$_SERVER["REMOTE_ADDR"],
			$_POST["g-recaptcha-response"]
			);
		if ($resp == null || !$resp->success){
			header('Location: ./login.php?captcha=false');
			return;
		}
	}

	$link = ft_database_connect();
	$login = htmlspecialchars(mysqli_real_escape_string($link, $_POST['login']));
	$passwd = hash("sha512", htmlspecialchars(mysqli_real_escape_string($link, $_POST['passwd'])));

	if ($login != NULL && $passwd != NULL)
	{
		$info = ft_get_pass($link, $login);
		if ($info["passwd"] === $passwd)
		{
			$_SESSION['login'] = $login;
			$_SESSION['group'] = $info["group"];
			header('Location: ./index.php');
		}
		else
		header('Location: ./login.php?password=false');
	}
?>
