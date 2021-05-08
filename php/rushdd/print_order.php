<?php
	require_once './fonctions/ft_database.php';
    if (!isset($_SESSION))
        session_start();
    $link = ft_database_connect();
	$order_id = htmlspecialchars(mysqli_real_escape_string($link, $_GET['id']));
	$order = mysqli_query($link, "SELECT * FROM cart WHERE id='" . $order_id . "';");
	$order_date = mysqli_query($link, "SELECT order_date FROM `order` WHERE id='" . $order_id . "';");
	while ($a = mysqli_fetch_array($order))
		$orders[] = $a;
?>
<html>
    <head>
        <link rel="stylesheet" href="order.css">
    </head>
    <body style="font-family:sans-serif;">
        <div class="user_ord"></div>
        <div>
        <?php	if ($order): ?>
                <h2 style="margin-left:200px;">Facture nº <?=$_GET['id']?></h2>
                <h2 style="margin-left:200px;">Compte: <?=$_SESSION['login']?></h2>
				<h3>Date:<?php foreach ($order_date as $key => $value):
					echo ($value['order_date']);
					endforeach;?></h3></h3>
				<table>
					<tr style="text-align:center;">
						<th>Article</th>
						<th>Quantité</th>
						<th>Prix unitaire</th>
						<th>Sous-total</th>
					</tr>
			<?php	foreach ($order as $key => $value): ?>
						<tr style="text-align:center;">
					<?php	$prod = ft_get_product_infos($link, $value['id_article']) ?>
							<td style="width:50%;"><?= $prod['name'] ?></td>
							<td style="width:20%;"><?= $value['quantity'] ?></td>
							<td style="width:21%;"><?= $value['price'] ?> €</td>
							<td style="width:21%;"><?= $value['quantity'] * $value['price'] ?> €</td>
							<?php if (isset($total)): 
									$total += $value['quantity'] * $value['price'];
								else :
									$total = $value['quantity'] * $value['price'];
								endif;?>
						</tr>
			<?php	endforeach; ?>
					<tr style="height:20px;"></tr>
					<tr style="text-align:center;">
						<td></td>
						<td></td>
						<td><b>Total</b></td>
						<td><?= $total ?> €</td>
					</tr>
				</table>
	<?php	endif; ?>
        </div>
    </body>
</html>
<?php       

?>