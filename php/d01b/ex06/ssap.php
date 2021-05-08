#!/usr/bin/php -n
<?php
$tab = implode(' ', $argv);
$res = array();
$i = 0;
$tab = preg_replace('/\s+/', ' ', $tab);
$mytab = explode(" ", $tab);
asort($mytab);
foreach ($mytab as $elem)
{
	if ($i != 0)
		echo "$elem\n";
	$i++;
}
?>
