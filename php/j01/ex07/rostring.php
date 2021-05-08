#!/usr/bin/php -n
<?php
$tab = $argv[1];
$res = array();
$i = 0;
$tab = preg_replace('/\s+/', ' ', $tab);
$tab = trim($tab, ' ');
$mytab = explode(" ", $tab);
foreach ($mytab as $elem)
{
	$res[$i] = $elem;
	$i++;
}
$i = 0;
foreach ($res as $elem)
{
	if ($i != 0)
		echo "$elem ";
	$i++;
}
echo $res[0];
echo "\n";
?>
