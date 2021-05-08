#!/usr/bin/php -n
<?php
if ($argc != 2)
{
	echo "Incorrect Parameters\n";
	return;
}
$a = array();
$argv[1] = trim(preg_replace("/\s/", "", $argv[1]));
$argv[1] = trim(preg_replace("/\t/", "", $argv[1]));
$a = sscanf($argv[1], "%d %c %d %s");
if ($a[0] && $a[1] && $a[2] && !$a[3])
{
	if ($a[1] == "+")
		$res = $a[0] + $a[2];
	else if ($a[1] == "-")
		$res = $a[0] - $a[2];
	else if ($a[1] == "/")
		$res = $a[0] / $a[2];
	else if ($a[1] == "*")
		$res = $a[0] * $a[2];
	else if ($a[1] == "%")
		$res = $a[0] % $a[2];
	echo "$res\n";
}
else
{
	echo "Syntax Error\n";
	return;
}
?>
