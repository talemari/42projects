<?php
	session_start();

	$_SESSION['login'] = NULL;
	$_SESSION['group'] = NULL;
	$_SESSION['id'] = NULL;
	header('Location: ./index.php');
?>
