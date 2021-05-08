<?php
	if(!isset($_SESSION))
		session_start();
	require_once './fonctions/ft_database.php';

	$link = mysqli_connect("localhost", "root", "nord59490", "", "3306");
	if (mysqli_connect_errno())
	    echo "Failed to connect to MySQL : " . mysqli_connect_error();

	mysqli_query($link, "CREATE DATABASE IF NOT EXISTS db_rush;");

	mysqli_query($link, "use db_rush");

	mysqli_query($link, "CREATE TABLE IF NOT EXISTS users
	(
		id INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
		login VARCHAR(256) NOT NULL,
		passwd VARCHAR(256) NOT NULL,
		`group` VARCHAR(256) NOT NULL
	);");

	mysqli_query($link, "CREATE TABLE IF NOT EXISTS products
	(
		id INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
		id_cat VARCHAR(256) NOT NULL,
		name TEXT NOT NULL,
		src TEXT NOT NULL,
		price INT NOT NULL,
		stock INT NOT NULL,
		creation_date DATE NOT NULL
	);");

	mysqli_query($link, "CREATE TABLE IF NOT EXISTS categories
	(
		id INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
		nom TEXT NOT NULL
	);");

	mysqli_query($link, "CREATE TABLE IF NOT EXISTS `order`
	(
		id INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
		user_id INT NOT NULL,
		order_date TEXT NOT NULL,
		total INT NOT NULL
	);");

	mysqli_query($link, "CREATE TABLE IF NOT EXISTS cart
	(
		id INT NOT NULL,
		id_article INT NOT NULL,
		quantity INT NOT NULL,
		price INT NOT NULL
	);");

	if (!ft_get_user_infos($link, "1"))
	{
		$pass = hash("sha512", mysqli_real_escape_string($link, "admin"));
		mysqli_query($link, "INSERT INTO users (login, passwd, `group`) VALUES ('admin', '" . $pass . "', 'admin');");
	}

	if (!ft_check_category($link, "Parapentes"))
		mysqli_query($link, "INSERT INTO categories (nom) VALUES ('Parapentes');");
	if (!ft_check_category($link, "Biplaces"))
		mysqli_query($link, "INSERT INTO categories (nom) VALUES ('Biplaces');");
	if (!ft_check_category($link, "Sellettes"))
		mysqli_query($link, "INSERT INTO categories (nom) VALUES ('Sellettes');");
	if (!ft_check_category($link, "Secours"))
		mysqli_query($link, "INSERT INTO categories (nom) VALUES ('Secours');");
	if (!ft_check_category($link, "Casques"))
		mysqli_query($link, "INSERT INTO categories (nom) VALUES ('Casques');");
	if (!ft_check_category($link, "Electronique"))
		mysqli_query($link, "INSERT INTO categories (nom) VALUES ('Electronique');");

	if (!ft_check_product($link, "MacPara Elan - EN C"))
		mysqli_query($link, "INSERT INTO products (id_cat, name, src, price, stock, creation_date) VALUES ('1', 'MacPara Elan - EN C', 'http://www.macpara.com/images/products/gliders/elan/elan-hf.jpg', '3500', '5', '2017-05-11');");
	if (!ft_check_product($link, "MacPara Muse 4 - EN A"))
		mysqli_query($link, "INSERT INTO products (id_cat, name, src, price, stock, creation_date) VALUES ('1', 'MacPara Muse 4 - EN A', 'http://www.macpara.com/images/products/gliders/muse4/muse4-hf.jpg', '2850', '2', CURDATE());");
	if (!ft_check_product($link, "MacPara Pasha 6 - biplace"))
		mysqli_query($link, "INSERT INTO products (id_cat, name, src, price, stock, creation_date) VALUES ('2', 'MacPara Pasha 6 - biplace', 'http://www.macpara.com/images/products/gliders/pasha6/pasha6-hf.jpg', '4200', '10', CURDATE());");
	if (!ft_check_product($link, "MacPara Yukon - EN B"))
		mysqli_query($link, "INSERT INTO products (id_cat, name, src, price, stock, creation_date) VALUES ('1', 'MacPara Yukon - EN B', 'http://www.macpara.com/images/products/gliders/yukon/Yukon.jpg', '2900', '4', '2017-05-11');");
	if (!ft_check_product($link, "Ozone Delta 3 - EN C"))
		mysqli_query($link, "INSERT INTO products (id_cat, name, src, price, stock, creation_date) VALUES ('1', 'Ozone Delta 3 - EN C', 'http://www.xcmag.com/wp-content/uploads/2017/03/Ozone-Delta-3-750-602x602.jpg', '3670', '2', CURDATE());");
	if (!ft_check_product($link, "Ozone Zeno - EN D"))
		mysqli_query($link, "INSERT INTO products (id_cat, name, src, price, stock, creation_date) VALUES ('1', 'Ozone Zeno - EN D', 'http://www.flyozone.com/gallery/d/1/3/134858.jpg', '5610', '1', CURDATE());");
	if (!ft_check_product($link, "Ozone Jomo - EN A"))
		mysqli_query($link, "INSERT INTO products (id_cat, name, src, price, stock, creation_date) VALUES ('1', 'Ozone Jomo - EN A', 'http://www.flyozone.com/gallery/d/1/3/132674.jpg', '3320', '7', '2017-05-11');");
	if (!ft_check_product($link, "Ozone Buzz Z 5 - EN B"))
		mysqli_query($link, "INSERT INTO products (id_cat, name, src, price, stock, creation_date) VALUES ('1', 'Ozone Buzz Z 5 - EN B', 'http://www.flyozone.com/gallery/d/1/3/132876.jpg', '3230', '74', CURDATE());");
	if (!ft_check_product($link, "MacPara Aegis"))
		mysqli_query($link, "INSERT INTO products (id_cat, name, src, price, stock, creation_date) VALUES ('4', 'MacPara Aegis', 'http://www.macpara.com/images/products/rescues/aegis/hf/aegis.jpg', '550', '8', '2017-05-11');");
	if (!ft_check_product($link, "MacPara Levity"))
		mysqli_query($link, "INSERT INTO products (id_cat, name, src, price, stock, creation_date) VALUES ('3', 'MacPara Levity', 'http://www.macpara.com/images/products/harnesses/harnesses-new/levity.png', '650', '42', CURDATE());");
	if (!ft_check_product($link, "Sup'air Delight 2"))
		mysqli_query($link, "INSERT INTO products (id_cat, name, src, price, stock, creation_date) VALUES ('3', 'Sup\'air Delight 2', 'http://www.paraglidingasia.com/uploads/6/4/6/3/64639447/s160722785297518812_p114_i5_w1200.jpeg', '1225', '1', CURDATE());");
	if (!ft_check_product($link, "Sup'air Walibi Lite - pilote biplace"))
		mysqli_query($link, "INSERT INTO products (id_cat, name, src, price, stock, creation_date) VALUES ('3', 'Sup\'air Walibi Lite - pilote biplace', 'http://glider.supair.com/wp-content/uploads/2016/01/walibi_lite_3.jpg', '590', '3', CURDATE());");
	if (!ft_check_product($link, "Icaro Nerv Black"))
		mysqli_query($link, "INSERT INTO products (id_cat, name, src, price, stock, creation_date) VALUES ('5', 'Icaro Nerv Black', 'https://flybubble.com/media/catalog/product/cache/1/image/1000x/b8c9c167d7769d159b8d8ffcb5e3aa7b/i/c/icaro_nerv_black_velvet.jpg', '120', '5', '2017-05-11');");
	if (!ft_check_product($link, "Vario Solaire"))
		mysqli_query($link, "INSERT INTO products (id_cat, name, src, price, stock, creation_date) VALUES ('6', 'Vario Solaire', 'http://glideparapente.com/326-thickbox_default/bip-bip-mini-vario-solaire-ultralight-.jpg', '60', '6','2017-05-11');");
	if (!ft_check_product($link, "Radio VHF Kenwood TH-K20"))
		mysqli_query($link, "INSERT INTO products (id_cat, name, src, price, stock, creation_date) VALUES ('6', 'Radio VHF Kenwood TH-K20', 'http://kasc4.s8.novenaweb.info/files/image/2437/8/600x410-10/TH-K20.png', '175', '7', '2017-05-11');");
?>
