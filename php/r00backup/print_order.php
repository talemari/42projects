<?php
    if (!isset($_SESSION))
        session_start();
    $cart = $_SESSION['cart'];
?>
<html>
    <head>
        <link rel="stylesheet" href="order.css">
    </head>
    <body>
        <div class="user_ord"></div>
        <div >
            <?php	foreach ($cart as $key => $value): ?>
					<?php	if ($cart[$key]): ?>
								<tr>
									<form action="edit_cart.php" method="post">
										<td style="text-align:center;"><?= $value['name'] ?></td>
										<td style="text-align:center;"><?= $value['price'] ?></td>
										<td style="text-align:center;"><?= $value['quantity'] ?></td>
										<td style="text-align:center;">
											<?= $value['quantity'] * $value['price'] ?> €
											<?php $total += $value['quantity'] * $value['price']; ?>
											<?php $_SESSION['total'] = $total; ?>
										</td>
										<td style="width:15%;"></td>
										<td><input type="submit" name="submit" value="+"></td>
										<td style="width:30px; text-align:center;"><?= $value['quantity'] ?></td>
										<td><input type="submit" name="submit" value="-"></td>
										<td><input type="submit" name="submit" value="supprimer"></td>
										<td><input type="hidden" name="id" value="<?= $value['id'] ?>"></td>
									</form>
								</tr>
					<?php	endif; ?>
            <?php	endforeach; ?>
        </div>
    </body>
</html>
<?php       

?>