#!/usr/bin/php -n
<?php
if ($argc != 4)
{
	echo "Incorrect Parameters";
	return;
}
$a = array();
$i = 0;
foreach($argv as $elem)
{
	$elem = trim(preg_replace("/\s/", "", $elem));
	$elem = trim(preg_replace("/\t/", "", $elem));
	$a[$i] = $elem;
	$i++;
}
if ($a[2] == "+")
	$res = $a[1] + $a[3];
if ($a[2] == "-")
	$res = $a[1] - $a[3];
if ($a[2] == "/")
	$res = $a[1] / $a[3];
if ($a[2] == "*")
	$res = $a[1] * $a[3];
if ($a[2] == "%")
	$res = $a[1] % $a[3];
echo "$res\n";

?>
