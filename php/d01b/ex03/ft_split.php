#!/usr/bin/php -n
<?php
function ft_split($tab)
{
	$res = array();
	$i = 0;
	$tab = preg_replace('/\s+/', ' ', $tab);
	$mytab = explode(" ", $tab);
	asort($mytab);
	foreach ($mytab as $elem)
	{
		$res[$i] = $elem;
		$i++;
	}
	return ($res);
}
?>
