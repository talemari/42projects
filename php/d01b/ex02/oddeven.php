#!/usr/bin/php -n
<?php
while(1)
{
	echo "Entrez un nombre: ";
	$input = fopen("php://stdin","r");
	$line = fgets($input);
	$line = str_replace("\n","",$line);
	if (is_numeric($line) == TRUE)
	{
		if ($line % 2 == 0)
			echo "Le chiffre $line est Pair";
		else
			echo "Le chiffre $line est Impair";
	}
	else
		echo "'$line' n'est pas un chiffre";
	echo "\n";
}
?>
