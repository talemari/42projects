<?php
class Color
{
	public static $verbose = False;

	public	$red;
	public	$green;
	public	$blue;

	static function doc()
	{
		return (file_get_contents('Color.doc.txt'));
	}
	static private function hex2rgb($hex)
	{
		$tmp = (int)$hex;
		$tmp = dechex($tmp);
		$len = 6 - strlen($tmp);
		$i = 0;
		while ($i < $len)
		{
			$hexnb = $hexnb . "0";
			$i++;
		}
		$hexnb = $hexnb . $tmp;
		$hexstr = $hexnb;
		$rgbarray = array();
		if (strlen($hexstr) == 6)
		{
			$colorval = hexdec($hexstr);
			$rgbarray['red'] = 0xFF & ($colorval >> 0x10);
			$rgbarray['green'] = 0xFF & ($colorval >> 0x8);
			$rgbarray['blue'] = 0xFF & $colorval;
		}
		elseif (strlen($hexstr) == 3)
		{
			$rgbarray['red'] = hexdec(str_repeat(substr($hexstr, 0, 1), 2));
			$rgbarray['green'] = hexdec(str_repeat(substr($hexstr, 1, 1), 2));
			$rgbarray['blue'] = hexdec(str_repeat(substr($hexstr, 2, 1), 2));
		}
		else
			return (False);
		return ($rgbarray);
	}
	public function __construct(array $kwargs)
	{
		$red = 0;
		$green = 0;
		$blue = 0;
		if (array_key_exists('rgb', $kwargs))
		{
			$hexcolor = self::hex2rgb($kwargs['rgb']);
			$red = $hexcolor['red'];
			$green = $hexcolor['green'];
			$blue = $hexcolor['blue'];
		}
		else if (array_key_exists('red', $kwargs) ||
			array_key_exists('green', $kwargs) || array_key_exists('blue', $kwargs))
		{
			if (array_key_exists('red', $kwargs))
				$red = strval($kwargs['red']);
			if (array_key_exists('green', $kwargs))
				$green = strval($kwargs['green']);
			if (array_key_exists('blue', $kwargs))
				$blue = strval($kwargs['blue']);
		}
		$this->red = round($red);
		$this->green = round($green);
		$this->blue = round($blue);
		if (self::$verbose == True)
			print('Color( red: ' . sprintf("%3s", $this->red) . ', green: '
				. sprintf("%3s", $this->green) . ', blue: '
				. sprintf("%3s", $this->blue) . ') constructed' . PHP_EOL);
	}
	public function __toString()
	{
		return('Color( red: ' . sprintf("%3s", $this->red) . ', green: '
			. sprintf("%3s", $this->green) . ', blue: '
			. sprintf("%3s", $this->blue) . ')');
	}
	public function add($color)
	{
		$res = new Color(array('red'=>$this->red + $color->red,
			'green'=>$this->green + $color->green, 'blue'=>$this->blue +
			$color->blue));
		return ($res);
	}
	public function sub($color)
	{
		$res = new Color(array('red'=>$this->red - $color->red,
			'green'=>$this->green - $color->green, 'blue'=>$this->blue -
			$color->blue));
		return ($res);
	}
	public function mult($color)
	{
		$res = new Color(array('red'=>$this->red * $color->red,
			'green'=>$this->green * $color->green, 'blue'=>$this->blue *
			$color->blue));
		return ($res);
	}
	public function __destruct()
	{
		if (self::$verbose == True)
			print('Color( red: ' . sprintf("%3s", $this->red) . ', green: '
				. sprintf("%3s", $this->green) . ', blue: '
				. sprintf("%3s", $this->blue) . ') destructed' . PHP_EOL);
	}
}
?>
