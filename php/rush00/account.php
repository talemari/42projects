<?php
	session_start();
	require_once './header.php';
	require_once './fonctions/ft_database.php';

	$link = ft_database_connect();
	$past_orders = ft_get_past_orders($link, $_SESSION["login"]);
	$id = ft_get_user_id($link, $_SESSION['login']);
?>

<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title>mon compte</title>
	</head>
	<body>
		<div class="change_info">
			<h3 style="text-align:center;">changer de mot de passe</h3>
			<form action="change_pass.php" method="post">
				<div style="text-align: center;">
					mot de passe actuel:&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp<input type="password" name="oldpw">
					<br /><br />
					nouveau mot de passe:&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp<input type="password" name="newpw">
					<br /><br />
					confirmation nouveau mot de passe:&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp<input type="password" name="newpw2">
					<br /><br />
					<input type="submit" name="submit" value="OK">
				</div>
			</form>
			<br />
			<hr style="width:98%;"/>
			<h3 style="text-align:center;">changer d'addresse e-mail</h3>
			<form action="change_mail.php" method="post">
				<div style="text-align: center;">
					adresse e-mail actuelle:&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp<input type="text" name="oldmail">
					<br /><br />
					nouvelle adresse e-mail:&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp<input type="text" name="newmail">
					<br /><br />
					<input type="submit" name="submit" value="OK">
				</div>
			</form>
			<br />
			<hr style="width:98%;"/>
			<h3 style="text-align:center;">Supprimer le compte</h3>
			<form action="del_account.php" method="post">
				<div class="text-align:center;">
					pour supprimer le compte entrez votre mot de passe: <input type="password" name="passwd">
					<br /><br />
					<input type="hidden" name="id" value="<?= $id['id'] ?>">
					<input type="submit" name="submit" value="supprimer le compte">
					<br /><br />
				</div>
			</form>
		</div>
		<br /><br /><br />
		<h3 style="text-align:center;">historique des commandes</h3>
<?php	if ($past_orders): ?>
		<div class="past_orders">
			<table>
				<tr>
					<th style="text-align:center; width:150px;">nº commande</th>
					<th style="text-align:center; width:200px;">date</th>
					<th style="text-align:center; width:100px;">montant</th>
				</tr>
		<?php	foreach ($past_orders as $key => $value): ?>
					<tr>
						<td style="text-align:center;"><?= $value['id'] ?></td>
						<td style="text-align:center;"><?= $value['order_date'] ?></td>
						<td style="text-align:center;"><?= $value['total'] ?></td>
						<td style="width:250px"></td>
						<td><a href="./order_detail.php?id=<?= $value['id'] ?>&date=<?= $value['order_date'] ?>&total=<?= $value['total'] ?>"><button type="button" name="button">détails</button></a></td>
					</tr>
		<?php	endforeach; ?>
			</table>
		</div>
<?php	else: ?>
			<h3 style="text-align:center;">encore aucune commande effectuée</h3>
<?php	endif; ?>
	</body>
</html>
