<?php
	include("charts/fusioncharts.php");
	require './fonctions/ft_database.php';
?>
	<html>
		<head>
		<script type="text/javascript" src="charts/fusioncharts.js"></script>
		<script type="text/javascript" src="charts/fusioncharts.charts.js"></script>
		</head>
	</html>
<?php
	$link = ft_database_connect();
	$prod = ft_get_products($link);
	if ($prod)
	{
		$arrdata = array("chart"=>array("theme"=>"fint", "caption"=>"prices",
										"subcaption"=>"2019",
										"captionFontSize"=>"24",
										"paletteColors"=>"#41CBE3, #EEDA54, #BB423F",
										"baseFont"=>"Quicksand, sans-serif"));
		$arrdata['data'] = array();
		foreach($prod as $elem)
		{
			array_push($arrdata['data'], array("label"=>$elem['name'],
				"value"=>$elem['price']));
		}
		$jsonEncoded = json_encode($arrdata);
	}
?>
<html>
	<div id="doughnut-chart">chart</div>
</html>
<?php
	$dchart = new FusionCharts("doughnut2d", "itemprices", "100%", "450", "doughnut-chart",
								"json", $jsonEncoded);
	$dchart->render();
?>
