#!/usr/bin/php -n
<?php
function ft_is_sort($tab)
{
	$tab2 = $tab;
	$i = 0;
	sort($tab2);
	while ($i != count($tab))
	{
		if ($tab[$i] != $tab2[$i])
			return (0);
		$i++;
	}
	return (1);
}
?>
