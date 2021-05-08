<?php
class Color
{
	const SIZE = 8;
	public static $verbose = False;

	private $pos;
	static function doc()
	{
		return (file_get_contents('Tile.doc.txt'));
	}
	public function __construct(array $kwargs)
	{
	}
	public function __toString()
	{
	}
	public function __destruct()
	{
	}
}
?>
